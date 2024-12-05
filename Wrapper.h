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

    // �����������
    Wrapper(Subject* subject, CommandFunction func);

    // ����� �������
    std::string execute(const std::map<std::string, std::string>& args);

private:
    Subject* subject_;  // ��������� �� Subject
    CommandFunction func_;  // ������� ��� ����������
};

#endif // WRAPPER_H
