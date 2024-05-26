/*
** EPITECH PROJECT, 2023
** my_csfml
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <SFML/System.h>
    #include "../animation/animation.h"
typedef struct items_list {
    char *name_tag;
    char *display_name;
    char *description;
    int effects;
    sfTexture *texture;
    sfSprite *sprite;
    struct items_list *next;
} items_list;
typedef struct my_container {
    char type;
    char *display_name;
    int current_items_nb;
    int max_items_nb;
    items_list *items;
} my_container;
typedef struct item_infos {
    char *name_tag;
    char *display_name;
    char *description;
    int effects;
} item_infos;

// @brief Init a container.
// @param type type of container ('I' for inventory and 'C' for container)
// @param display_name name to display
// @param max_items_nb maximum number of items that can be added to the
// container
my_container *init_container(char type, char *display_name,
unsigned int max_items_nb);

// @brief Destroy a container.
// @param container container structure
int destroy_container(my_container *container);

// @brief Add an item to a container.
// @param container container structure
// @param name_tag name_tag to match for texture
// @param display_name name to display
// @param textures_list textures linked list
// @return 84 on error
int add_item(my_container *container, item_infos *infos,
my_textures_list *textures_list);

// @brief Remove an item from a container.
// @param container container structure
// @param index index of item
// @return 84 on error
int remove_item(my_container *container, unsigned int index);

// @brief Move an item from a container to another.
// @param container_src container structure (source)
// @param index index of item in source container
// @param container_dest container structure (destination)
// @return 84 on error
int move_item_to_container(my_container *container_src, unsigned int index,
my_container *container_dest);

// ...
items_list *remove_node(my_container *container, int index);

// ...
int set_item_texture(items_list *new_item, my_textures_list *textures_list,
char *name_tag);
#endif /* !INVENTORY_H_ */
