/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** tests_assistant.cpp
*/

#include <fstream>
#include <criterion/criterion.h>
#include "../seminar/Assistant.hpp"

static void generateStudentDrinkFile(const std::string name)
{
    std::ofstream out;

    out.open(name + ".drink");
    out << "Monster" << std::endl;
    out.close();
}

Test(assistant, create)
{
    Assistant assistant(42);

    cr_assert_eq(assistant.getId(), 42);
    cr_assert_eq(assistant.isWorking(), false);

    assistant.timeCheck();
    cr_assert_eq(assistant.isWorking(), true);

    assistant.timeCheck();
    cr_assert_eq(assistant.isWorking(), false);
}

Test(assistant, give_drink)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Assistant assistant(42);
    Student student("miaou");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    assistant.giveDrink(&student, "Red Bull");

    std::cout.rdbuf(original_cout);

    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Assistant 42: drink this, miaou *sip coffee*\n"
                                     "Student miaou: Red Bull gives you wings!\n");
}

Test(assistant, read_drink)
{
    Assistant assistant(42);

    generateStudentDrinkFile("miaou_alpha");

    std::string drinkName = assistant.readDrink("miaou_alpha");

    cr_assert_str_eq(drinkName.c_str(), "Monster");
}

Test(assistant, read_drink_not_found)
{
    Assistant assistant(42);
    std::string drinkName = assistant.readDrink("zorglub");

    cr_assert_str_eq(drinkName.c_str(), "");
}

Test(assistant, help_student_drunk)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    generateStudentDrinkFile("miaou_beta");

    Assistant assistant(42);
    Student student("miaou_beta");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    assistant.helpStudent(&student);

    std::cout.rdbuf(original_cout);

    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Assistant 42: miaou_beta needs a Monster *sip coffee*\n"
                                     "Assistant 42: drink this, miaou_beta *sip coffee*\n"
                                     "Student miaou_beta: Unleash The Beast!\n");
    cr_assert_null(NULL);
}

Test(assistant, help_student_not_drunk)
{
    std::stringstream ss;
    std::string string;
    std::streambuf *original_cout = nullptr;

    Assistant assistant(42);
    Student student("zorglub");

    original_cout = std::cout.rdbuf(ss.rdbuf());

    assistant.helpStudent(&student);

    std::cout.rdbuf(original_cout);

    string = ss.str();
    cr_assert_str_eq(string.c_str(), "Assistant 42: zorglub seems fine *sip coffee*\n");
}
