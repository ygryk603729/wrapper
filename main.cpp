#include <iostream>
#include <fstream>
#include <sstream>
#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"

int main() {
    // Создаём экземпляры классов
    Subject subject;
    Engine engine;

    // Считываем входной файл
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error: Unable to open input.txt" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string text = buffer.str();
    input_file.close();

    // Настраиваем команды
    Wrapper replace_wrapper(&subject, [&subject](const std::map<std::string, std::string>& args) {
        return subject.replace_word(args.at("text"), args.at("old_word"), args.at("new_word"));
        });

    Wrapper find_wrapper(&subject, [&subject](const std::map<std::string, std::string>& args) {
        std::vector<size_t> positions = subject.find_phrases(args.at("text"), args.at("phrase"));
        std::ostringstream result;
        for (size_t pos : positions) {
            result << pos << " ";
        }
        return result.str();
        });

    Wrapper capitalize_words_wrapper(&subject, [&subject](const std::map<std::string, std::string>& args) {
        return subject.capitalize_words(args.at("text"));
        });

    Wrapper capitalize_sentences_wrapper(&subject, [&subject](const std::map<std::string, std::string>& args) {
        return subject.capitalize_sentences(args.at("text"));
        });

    Wrapper enumerate_wrapper(&subject, [&subject](const std::map<std::string, std::string>& args) {
        return subject.enumerate_sentences(args.at("text"));
        });

    // Регистрируем команды
    engine.register_command(&replace_wrapper, "replace");
    engine.register_command(&find_wrapper, "find");
    engine.register_command(&capitalize_words_wrapper, "capitalize_words");
    engine.register_command(&capitalize_sentences_wrapper, "capitalize_sentences");
    engine.register_command(&enumerate_wrapper, "enumerate");

    // Выполняем команды
    std::string result = text;

    while (true) {
        // Меню для выбора операции
        std::cout << "Choose an operation:\n";
        std::cout << "1. Replace word\n";
        std::cout << "2. Find phrase\n";
        std::cout << "3. Up Register words\n";
        std::cout << "4. Up Register sentences\n";
        std::cout << "5. Enumerate sentences\n";
        std::cout << "6. Exit\n";

        int choice;
        std::cin >> choice;
        std::cin.ignore();  // Очищаем буфер ввода

        if (choice == 6) break;

        switch (choice) {
        case 1: {
            std::string old_word, new_word;
            std::cout << "Enter word to replace: ";
            std::getline(std::cin, old_word);
            std::cout << "Enter new word: ";
            std::getline(std::cin, new_word);
            result = engine.execute("replace", { {"text", result}, {"old_word", old_word}, {"new_word", new_word} });
            break;
        }
        case 2: {
            std::string phrase;
            std::cout << "Enter phrase to find: ";
            std::getline(std::cin, phrase);
            std::cout << "Phrase positions: "
                << engine.execute("find", { {"text", result}, {"phrase", phrase} })
                << std::endl;
            continue;  // Переходим к следующему циклу, чтобы не перезаписывать результат
        }
        case 3: {
            result = engine.execute("capitalize_words", { {"text", result} });
            break;
        }
        case 4: {
            result = engine.execute("capitalize_sentences", { {"text", result} });
            break;
        }
        case 5: {
            result = engine.execute("enumerate", { {"text", result} });
            break;
        }
        default:
            std::cout << "Invalid choice, try again." << std::endl;
            continue;
        }

        // Записываем результат в файл после выполнения операции
        std::ofstream output_file("output.txt");
        if (!output_file.is_open()) {
            std::cerr << "Error: Unable to open output.txt" << std::endl;
            return 1;
        }

        output_file << result;
        output_file.close();

        std::cout << "Operation completed. Check output.txt for results.\n";
    }

    return 0;
}