#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include "Wrapper.h"
#include <map>
#include <string>

class Engine {
public:
    // Регистрация команды
    void register_command(Wrapper* wrapper, const std::string& name);

    // Выполнение команды
    std::string execute(const std::string& name, const std::map<std::string, std::string>& args);

private:
    std::map<std::string, Wrapper*> commands_;  // Карта команд
};

#endif // ENGINE_H
