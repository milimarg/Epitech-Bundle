/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** tests_dean.cpp
*/

#include <criterion/criterion.h>
#include "../seminar/Dean.hpp"

Test(dean, create)
{
    Dean dean("rulietta");

    cr_assert_eq(dean.isWorking(), false);
    dean.timeCheck();
    cr_assert_eq(dean.isWorking(), true);
    dean.timeCheck();
    cr_assert_eq(dean.isWorking(), false);

    cr_assert_str_eq(dean.getName().c_str(), "rulietta");
}

Test(dean, learn_student)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Dean dean("rulietta");
    Student student("miaou");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    dean.teachStudent(&student, "drinking milk");

    std::cout.rdbuf(original_cout);
    string = ss.str();
    cr_assert_eq(string, "Student miaou: drinking milk\n");
}

Test(dean, learn_lazy_student)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Dean dean("rulietta");
    Student student("miaou");

    student.learn("ah");
    student.learn("ah");
    original_cout = std::cout.rdbuf(ss.rdbuf());

    dean.teachStudent(&student, "drinking milk");

    std::cout.rdbuf(original_cout);
    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Student miaou: drinking milk\n"
                                     "Dean rulietta: All work and no play makes miaou a dull student.\n");
}
