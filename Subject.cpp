#include "Subject.h"
#include <sstream>
#include <cctype>

// Замена слов
std::string Subject::replace_word(const std::string& text, const std::string& old_word, const std::string& new_word) {
    std::string result = text;
    size_t pos = 0;
    while ((pos = result.find(old_word, pos)) != std::string::npos) {
        result.replace(pos, old_word.length(), new_word);
        pos += new_word.length();
    }
    return result;
}

// Поиск словосочетаний
std::vector<size_t> Subject::find_phrases(const std::string& text, const std::string& phrase) {
    std::vector<size_t> positions;
    size_t pos = text.find(phrase);
    while (pos != std::string::npos) {
        positions.push_back(pos);
        pos = text.find(phrase, pos + phrase.length());
    }
    return positions;
}

// Преобразование первых букв слов в заглавные
std::string Subject::capitalize_words(const std::string& text) {
    if (text.empty()) return text;  // Проверка на пустую строку

    std::string result = text;
    bool new_word = true;
    for (char& ch : result) {
        if (std::isspace(ch)) {
            new_word = true;
        }
        else if (new_word && std::isalpha(ch)) {
            ch = std::toupper(ch);
            new_word = false;
        }
    }
    return result;
}

// Преобразование первой буквы предложений в заглавные
std::string Subject::capitalize_sentences(const std::string& text) {
    std::string result = text;
    bool new_sentence = true;
    for (char& ch : result) {
        if (new_sentence && std::isalpha(ch)) {
            ch = std::toupper(ch);
            new_sentence = false;
        }
        if (ch == '.' || ch == '!' || ch == '?') {
            new_sentence = true;
        }
    }
    return result;
}

// Нумерация предложений
std::string Subject::enumerate_sentences(const std::string& text) {
    std::stringstream result;
    std::stringstream input(text);
    std::string sentence;
    int counter = 1;
    while (std::getline(input, sentence, '.')) {
        if (!sentence.empty()) {
            result << counter++ << ". " << sentence << ".\n";
        }
    }
    return result.str();
}
