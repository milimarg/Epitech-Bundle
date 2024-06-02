/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "new.h"
#include "float.h"

typedef struct
{
    Class   base;
    float     value;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->value = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    this->value = 0;
}

static char *Float_str(FloatClass *this)
{
    char *str = malloc(sizeof(char *) * 100);

    if (str == NULL)
        raise("malloc failed");
    snprintf(str, 100, "<Float (%f)>", this->value);
    return str;
}

static Object *Float_add(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("class is NULL");
    return new(Float, (this->value + other->value));
}

static Object *Float_sub(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("class is NULL");
    return new(Float, (this->value - other->value));
}

static Object *Float_mul(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("class is NULL");
    return new(Float, (this->value * other->value));
}

static Object *Float_div(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL || other->value == 0)
        raise("class is NULL");
    return new(Float, (this->value / other->value));
}

static bool Float_eq(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("class is NULL");
    return (this->value == other->value);
}

static bool Float_gt(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("class is NULL");
    return (this->value > other->value);
}

static bool Float_lt(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("class is NULL");
    return (this->value < other->value);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .value = 0
};

const Class   *Float = (const Class *)&_description;
