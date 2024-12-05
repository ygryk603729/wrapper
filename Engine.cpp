#include "Engine.h"

// ����������� �������
void Engine::register_command(Wrapper* wrapper, const std::string& name) {
    commands_[name] = wrapper;
}

// ���������� �������
std::string Engine::execute(const std::string& name, const std::map<std::string, std::string>& args) {
    if (commands_.find(name) != commands_.end()) {
        return commands_[name]->execute(args);
    }
    return "Command not found!";
}
