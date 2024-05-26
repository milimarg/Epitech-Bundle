/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** openfile.h
*/
#ifndef OPENFILE_H_
    #define OPENFILE_H_
void open_file(void *values);
void add_open_file_popup(my_paint *p);
int handle_open_popup(my_paint *p);
void destroy_openfile_popup(open_popup *s);
int check_ext(char *filename);
void set_file_explorer(open_popup *o, sfFont *font);
void dummy(void *values);
void add_directory_to_path(open_popup *o, char *current_path);
int get_files_infos(open_popup *o, sfFont *font, int register_buttons,
sfIntRect *rect);
void destroy_file_explorer(path *fp);
int open_image(char *path_to_file, drawing_area_t *d);
int detect_click_on_button(my_paint *p, int i);
void scroll_in_directory_fp(open_popup *o, int is_scrolling_down);
int display_buttons_events_fp(open_popup *o, my_paint *p);
int refresh_current_dir(my_paint *p, char *element);
int file_explorer_file_filter(struct dirent *pdirent);
void update_sizes_openfile(open_popup *o);
void get_full_filepath(my_paint *p, char *element);
int check_file_is_valid(my_paint *p);
#endif /*OPENFILE_H_*/
