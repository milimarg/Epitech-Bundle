#!/bin/bash
gcc -c *.c
ar rc libmy.a *.o
find -type f -name "*.o" -delete
