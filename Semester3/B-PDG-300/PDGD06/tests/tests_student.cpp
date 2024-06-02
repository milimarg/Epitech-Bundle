/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** tests_student.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../seminar/Student.hpp"

Test(student, create)
{
    Student student("miaou");

    cr_assert_eq(student.getName(), "miaou");
}

Test(student, learn)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Student student("miaou");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    student.learn("Learning C++...");

    std::cout.rdbuf(original_cout);

    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Student miaou: Learning C++...\n");
}

Test(student, lazy_learn)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Student student("miaou");
    student.learn("Learning C++...");
    student.learn("Learning C++...");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    student.learn("Learning C++...");

    std::cout.rdbuf(original_cout);

    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Student miaou: Learning shit...\n");
}

Test(student, drink_red_bull)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Student student("miaou");
    student.learn("ahahah");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    student.drink("Red Bull");

    std::cout.rdbuf(original_cout);

    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Student miaou: Red Bull gives you wings!\n");
}

Test(student, drink_monster)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Student student("miaou");
    student.learn("ahahah");
    student.learn("ahahah");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    student.drink("Monster");

    std::cout.rdbuf(original_cout);

    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Student miaou: Unleash The Beast!\n");
}

Test(student, drink_other_thing)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Student student("miaou");
    student.learn("ahahah");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    student.drink("Coke");

    std::cout.rdbuf(original_cout);

    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Student miaou: ah, yes... enslaved moisture.\n");
}
