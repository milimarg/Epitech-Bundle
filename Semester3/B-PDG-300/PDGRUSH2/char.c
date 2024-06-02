/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** char
*/

#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    this->x = 0;
}

static char *Char_str(CharClass *this)
{
    char *str = NULL;

    if (this == NULL)
        raise("Class is NULL");    
    str = malloc(sizeof(char) * 100);
    if (str == NULL)
        raise("malloc has failed");
    snprintf(str, 100, "<Char (%c)>", this->x);
    return str;
}

static Object *Char_add(CharClass *this, CharClass *other)
{
    Object *result = NULL;

    if (this == NULL || other == NULL)
        raise("Class is NULL"); 
    result = new(Char, this->x + other->x);
    return result;
}

static Object *Char_sub(CharClass *this, CharClass *other)
{
    Object *result = NULL;
    
    if (this == NULL || other == NULL)
        raise("Class is NULL");
    result = new(Char, this->x - other->x);
    return result;
}

static Object *Char_mul(CharClass *this, CharClass *other)
{
    Object *result = NULL;
    
    if (this == NULL || other == NULL)
        raise("Class is NULL");
    result = new(Char, this->x * other->x);
    return result;
}

static Object *Char_div(CharClass *this, CharClass *other)
{
    Object *result = NULL;

    if (this == NULL || other == NULL)
        raise("Class is NULL");
    if (other->x == 0)
        raise("error : division by zero");
    result = new(Char, this->x / other->x);
    return result;
}

static bool Char_eq(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Class is NULL");
    if (this->x == other->x)
        return true;
    return false;
}

static bool Char_gt(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Class is NULL");
    if (this->x > other->x)
        return true;
    return false;
}

static bool Char_lt(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Class is NULL");
    if (this->x < other->x)
        return true;
    return false;
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0,
};

const Class   *Char = (const Class *)&_description;