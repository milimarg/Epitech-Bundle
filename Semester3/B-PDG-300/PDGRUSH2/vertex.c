/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "vertex.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = malloc(sizeof(char *) * 100);

    if (str == NULL)
        raise("malloc failed");
    snprintf(str, 100, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return str;
}

static Object *Vertex_add(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        raise("class is NULL");
    return new(Vertex, (this->x + other->x), (this->y + other->y), (this->z + other->z));
}

static Object *Vertex_sub(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        raise("class is NULL");
    return new(Vertex, (this->x - other->x), (this->y - other->y), (this->z - other->z));
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Vertex = (const Class *)&_description;
