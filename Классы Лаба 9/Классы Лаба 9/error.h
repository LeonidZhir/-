#pragma once
#include <exception>
#include <string>

class Error : public std::exception 
{
public:
    explicit Error(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override 
    {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

class IndexOutOfBounds : public Error 
{
public:
    IndexOutOfBounds() : Error("������ ��������� �� ��������� ����������� ���������") {}
};

class ElementNotFound : public Error 
{
public:
    ElementNotFound() : Error("������� �� ������") {}
};

class AlreadyExists : public Error 
{
public:
    AlreadyExists() : Error("������� ��� ���������� � ������") {}
};