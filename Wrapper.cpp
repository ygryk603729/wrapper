#include "Wrapper.h"

// Конструктор
Wrapper::Wrapper(Subject* subject, CommandFunction func) : subject_(subject), func_(func) {}

// Выполнение команды
std::string Wrapper::execute(const std::map<std::string, std::string>& args) {
    return func_(args);
}
