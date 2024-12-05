#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>
#include <map>

class Subject {
public:
    // Замена слов
    std::string replace_word(const std::string& text, const std::string& old_word, const std::string& new_word);

    // Поиск словосочетаний
    std::vector<size_t> find_phrases(const std::string& text, const std::string& phrase);

    // Преобразование первых букв слов в заглавные
    std::string capitalize_words(const std::string& text);

    // Преобразование первой буквы предложений в заглавные
    std::string capitalize_sentences(const std::string& text);

    // Нумерация предложений
    std::string enumerate_sentences(const std::string& text);
};

#endif // SUBJECT_H
