/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD11-florent.guittre
** File description:
** UniquePointer.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_UNIQUEPOINTER_HPP
    #define B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_UNIQUEPOINTER_HPP
    #include "IObject.hpp"
    #include <iostream>

class UniquePointer : virtual public IObject {
public:
    UniquePointer();
    UniquePointer(UniquePointer &uniquePointer) = delete;
    UniquePointer(IObject *object);
    ~UniquePointer() override;
    void touch() override;
    void reset();
    void reset(IObject *object);
    void swap(UniquePointer &object);
    UniquePointer &operator=(IObject *element);
    IObject *operator->() const;
    IObject &operator*() const;
private:
    IObject *ptr = nullptr;
};

#endif //B_PDG_300_STG_3_1_PDGD11_FLORENT_GUITTRE_UNIQUEPOINTER_HPP
