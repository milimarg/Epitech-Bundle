/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** new.c
*/

#include "new.h"

Object *new(const Class *class, ...)
{
    va_list ap;

    va_start(ap, class);
    return va_new(class, &ap);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *ptr = NULL;

    if (class == NULL) {
        raise("class is null");
    }
    ptr = malloc(class->__size__);
    if (ptr == NULL) {
        raise("out of memory");
    }
    ptr = memcpy(ptr, class, class->__size__);
    if (class->__ctor__) {
        class->__ctor__(ptr, ap);
    }
    va_end(*ap);
    return ptr;
}

void delete(Object *ptr)
{
    if (ptr == NULL) {
        raise("object is null");
    }
    if (((Class *)ptr)->__dtor__) {
        ((Class *)ptr)->__dtor__(ptr);
    }
    free(ptr);
}
