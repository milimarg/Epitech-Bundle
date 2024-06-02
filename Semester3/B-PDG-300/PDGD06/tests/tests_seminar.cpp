/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD06-florent.guittre
** File description:
** tests_seminar.cpp
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <fstream>
#include "../seminar/Seminar.hpp"

Test(seminar, main)
{
    std::srand(42);

    Dean dean_thaynam("Thay-Nam");
    Dean assistant_to_the_dean_devoille("Devoille");
    Assistant ass_42(42);
    Assistant ass_24(24);
    Assistant ass_2077(2077);
    Student stud_jennifer("Jennifer");
    Student stud_brian("Brian");
    Student stud_kevin("Kevin");
    Student stud_dwayne("Dwayne");
    Student stud_priscilla("Priscilla");
    Student stud_stewie("Stewie");

    {
        Seminar seminar;

        seminar.run();
        seminar.addDean(&dean_thaynam);
        seminar.addDean(&assistant_to_the_dean_devoille);
        seminar.addAssistant(&ass_42);
        seminar.addAssistant(&ass_24);
        seminar.addAssistant(&ass_42);
        seminar.addAssistant(&ass_2077);
        seminar.addStudent(&stud_jennifer);
        seminar.addStudent(&stud_brian);
        seminar.addStudent(&stud_kevin);
        seminar.addStudent(&stud_dwayne);
        seminar.addStudent(&stud_brian);
        seminar.addStudent(&stud_priscilla);
        seminar.addStudent(&stud_stewie);
        seminar.run();

        cr_assert_not_null(&seminar);
    }
}
