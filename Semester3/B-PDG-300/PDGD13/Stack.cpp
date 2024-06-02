/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD13-florent.guittre
** File description:
** Stack.cpp
*/

#include "Stack.hpp"

Stack::Error::Error(std::string name)
     : _name(name) {}

const char *Stack::Error::what() const noexcept
{
    return _name.c_str();
}

void Stack::push(double value)
{
    stack.push(value);
}

double Stack::pop()
{
    double element = 0;

    if (size() == 0) {
        throw Stack::Error("Empty stack");
    }
    element = top();
    stack.pop();
    return element;
}

double Stack::top() const
{
    if (size() == 0) {
        throw Stack::Error("Empty stack");
    }
    return stack.top();
}

size_t Stack::size() const
{
    return stack.size();
}

void Stack::add()
{
    double a = 0;
    double b = 0;

    if (size() <= 1) {
        throw Stack::Error("Not enough operands");
    }
    a = pop();
    b = pop();
    push(a + b);
}

void Stack::sub()
{
    double a = 0;
    double b = 0;

    if (size() <= 1) {
        throw Stack::Error("Not enough operands");
    }
    a = pop();
    b = pop();
    push(a - b);
}

void Stack::mul()
{
    double a = 0;
    double b = 0;

    if (size() <= 1) {
        throw Stack::Error("Not enough operands");
    }
    a = pop();
    b = pop();
    push(a * b);
}

void Stack::div()
{
    double a = 0;
    double b = 0;

    if (size() <= 1) {
        throw Stack::Error("Not enough operands");
    }
    a = pop();
    b = pop();
    push(a / b);
}
