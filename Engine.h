#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include "Wrapper.h"
#include <map>
#include <string>

class Engine {
public:
    // ����������� �������
    void register_command(Wrapper* wrapper, const std::string& name);

    // ���������� �������
    std::string execute(const std::string& name, const std::map<std::string, std::string>& args);

private:
    std::map<std::string, Wrapper*> commands_;  // ����� ������
};

#endif // ENGINE_H
