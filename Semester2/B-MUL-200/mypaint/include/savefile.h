/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** savefile.h
*/
#ifndef SAVEFILE_H_
    #define SAVEFILE_H_
void add_save_file_popup(my_paint *paint);
void save_file(void *values);
void handle_save_popup(my_paint *paint);
void set_jpg(void *values);
void set_bmp(void *values);
void set_png(void *values);
void validate_filename_popup(void *values);
void handle_field(my_paint *p);
void destroy_savefile_popup(save_popup *s);
#endif /*SAVEFILE_H_*/
