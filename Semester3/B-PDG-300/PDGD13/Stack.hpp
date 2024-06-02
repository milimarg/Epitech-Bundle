/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD13-florent.guittre
** File description:
** Stack.hpp
*/


#ifndef B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_STACK_HPP
    #define B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_STACK_HPP
    #include <exception>
    #include <iostream>
    #include <stack>

class Stack {
public:
    class Error : public std::exception {
    public:
        Error(std::string name);
        const char *what() const noexcept override;
    private:
        std::string _name;
    };
    void push(double value);
    double pop();
    double top() const;
    size_t size() const;
    void add();
    void sub();
    void mul();
    void div();
private:
    std::stack<double> stack;
};

#endif //B_PDG_300_STG_3_1_PDGD13_FLORENT_GUITTRE_STACK_HPP
