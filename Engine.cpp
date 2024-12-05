#include "Engine.h"

// Регистрация команды
void Engine::register_command(Wrapper* wrapper, const std::string& name) {
    commands_[name] = wrapper;
}

// Выполнение команды
std::string Engine::execute(const std::string& name, const std::map<std::string, std::string>& args) {
    if (commands_.find(name) != commands_.end()) {
        return commands_[name]->execute(args);
    }
    return "Command not found!";
}
