/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    this->x = 0;
}

static char *Int_str(IntClass *this)
{
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL) {
        raise("malloc has failed");
    }
    snprintf(str, 100, "<Int (%d)>", this->x);
    return str;
}

static Object *Int_add(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL) {
        raise("input is NULL");
    }
    return new(Int, this->x + other->x);
}

static Object *Int_sub(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL) {
        raise("input is NULL");
    }
    return new(Int, this->x - other->x);
}

static Object *Int_mul(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL) {
        raise("input is NULL");
    }
    return new(Int, this->x * other->x);
}

static Object *Int_div(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL) {
        raise("input is NULL");
    }
    if (other->x == 0) {
        raise("Cannot divide by zero");
    }
    return new(Int, this->x / other->x);
}

static bool Int_equal(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL) {
        raise("input is NULL");
    }
    return this->x == other->x;
}

static bool Int_greater_than(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL) {
        raise("input is NULL");
    }
    return this->x > other->x;
}

static bool Int_lower_than(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL) {
        raise("input is NULL");
    }
    return this->x < other->x;
}

// Create additional functions here

static const IntClass _description = {
        {   /* Class struct */
                .__size__ = sizeof(IntClass),
                .__name__ = "Int",
                .__ctor__ = (ctor_t)&Int_ctor,
                .__dtor__ = (dtor_t)&Int_dtor,
                .__str__ = (to_string_t)&Int_str,
                .__add__ = (binary_operator_t)&Int_add,
                .__sub__ = (binary_operator_t)&Int_sub,
                .__mul__ = (binary_operator_t)&Int_mul,
                .__div__ = (binary_operator_t)&Int_div,
                .__eq__ = (binary_comparator_t)&Int_equal,
                .__gt__ = (binary_comparator_t)&Int_greater_than,
                .__lt__ = (binary_comparator_t)&Int_lower_than
        },
        .x = 0
};

const Class   *Int = (const Class *)&_description;
