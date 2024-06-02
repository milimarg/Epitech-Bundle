/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD13-florent.guittre
** File description:
** Array.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_ARRAY_HPP
    #define B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_ARRAY_HPP
    #include <iostream>
    #include <array>
    #include <functional>
    #include <exception>

template <typename T, size_t Size>
class Array {
public:
    class Error : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Out of range";
        }
    };
    Array() {
        for (auto &element : array) {
            element = 0;
        }
    }
    const T &operator[](size_t index) const {
        if (index > Size - 1) {
            throw Array::Error();
        }
        return array.at(index);
    }
    std::size_t size() const {
        return Size;
    }
    void forEach(const std::function<void(const T &)> &task) const {
        for (auto &element : array) {
            task(element);
        }
    }
    template <typename U>
    Array<U, Size> convert(const std::function<U(const T &)> &converter) const {
        Array<U, Size> newArray;

        for (size_t i = 0; i < Size; i++) {
            newArray[i] = converter(array[i]);
        }
        return newArray;
    }
private:
    T array[Size];
};

template <typename T, size_t Size>
static std::ostream &operator<<(std::ostream &out, const Array<T, Size> &array) {
    out << "[";
    for (size_t i = 0; i < Size; i++) {
        out << array[i];
        if (i < Size - 1) {
            out << ", ";
        }
    }
    return out << "]";
}

#endif //B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_ARRAY_HPP
