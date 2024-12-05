#include "Wrapper.h"

// �����������
Wrapper::Wrapper(Subject* subject, CommandFunction func) : subject_(subject), func_(func) {}

// ���������� �������
std::string Wrapper::execute(const std::map<std::string, std::string>& args) {
    return func_(args);
}
