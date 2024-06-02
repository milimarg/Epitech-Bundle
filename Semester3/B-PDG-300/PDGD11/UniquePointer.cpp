/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD11-florent.guittre
** File description:
** UniquePointer.cpp
*/

#include "UniquePointer.hpp"

UniquePointer::UniquePointer() {}

UniquePointer::UniquePointer(IObject *object)
{
    ptr = object;
}

UniquePointer::~UniquePointer()
{
    if (ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    }
}

void UniquePointer::touch() {}

void UniquePointer::reset()
{
    if (ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    }
}

void UniquePointer::reset(IObject *object)
{
    if (ptr != nullptr) {
        delete ptr;
    }
    ptr = object;
}

void UniquePointer::swap(UniquePointer &object)
{
    std::swap(ptr, object.ptr);
}

UniquePointer &UniquePointer::operator=(IObject *object)
{
    if (ptr != nullptr) {
        delete ptr;
    }
    ptr = object;
    return *this;
}

IObject *UniquePointer::operator->() const
{
    return this->ptr;
}

IObject &UniquePointer::operator*() const
{
    return *(this->ptr);
}
