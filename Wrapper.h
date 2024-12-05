#pragma once
#ifndef WRAPPER_H
#define WRAPPER_H

#include "Subject.h"
#include <functional>
#include <map>
#include <string>

class Wrapper {
public:
    using CommandFunction = std::function<std::string(const std::map<std::string, std::string>&)>;

    // Конструктор
    Wrapper(Subject* subject, CommandFunction func);

    // Вызов команды
    std::string execute(const std::map<std::string, std::string>& args);

private:
    Subject* subject_;  // Указатель на Subject
    CommandFunction func_;  // Функция для выполнения
};

#endif // WRAPPER_H
