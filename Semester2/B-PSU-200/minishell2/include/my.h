/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "../include/structs.h"
    #define SRST  "\x1B[0m"
    #define SRED  "\x1B[91m"
    #define SGRN  "\x1B[92m"
    #define SPUR  "\x1B[95m"
    #define OUT_FLAGS (O_WRONLY | O_CREAT | O_TRUNC)
    #define OUT_APPEND_FLAGS (O_WRONLY | O_CREAT | O_APPEND)
int display_prompt(sh_infos *shell);
int read_user_input(sh_infos *shell);
int init_custom_commands(custom_commands **commands_list);
int run_command(custom_commands *commands_list, sh_infos *shell,
my_env **env_list);
int destroy_custom_commands_list(custom_commands *commands_list);
int destroy_my_str_to_word_array(char **str);
int custom_exit(sh_infos *shell, my_env **env_list);
int custom_cd(sh_infos *shell, my_env **env_list);
int set_home_directory(sh_infos *shell, my_env *env_list);
int set_path(sh_infos *shell, my_env *env_list);
int other_command_checker(char *command_name);
int path_commands_checker(char *command_name, sh_infos *shell);
my_env *get_value_of_variable(my_env *env_list, char *variable_name,
int variable_len);
int pid_signal_handler(sh_infos *shell, pid_t pid);
int my_error(char *path, unsigned int mode_index);
int destroy_env_list(my_env *env_list);
int fill_env_list(my_env **env_list, char **env, sh_infos *shell);
char *replace_custom_variables(sh_infos *shell, my_env *env_list);
int custom_env(sh_infos *shell, my_env **env_list);
int get_alphanum_len(char *str);
void set_return_code(sh_infos *shell, int return_code);
int custom_setenv(sh_infos *shell, my_env **env_list);
int custom_unsetenv(sh_infos *shell, my_env **env_list);
int signal_handler(void);
int custom_command_checker(custom_commands *commands_list, char *command_name,
sh_infos *shell, my_env **env_list);
int check_for_variable(char **temp, my_env *env_list, int *len,
sh_infos *shell);
my_env *get_value(char *str, my_env *env_list);
int my_array_len(char **array);
int commands_checker(sh_infos *shell, custom_commands *commands_list,
my_env **env_list);
int free_node_in_env(my_env *temp);
int edit_node_in_env(my_env *node_to_edit, char *key, char *value);
int add_node_to_env_list(my_env **env_list, char *key, char *value);
int check_if_node_exist(my_env **env_list, char *key, char *value);
int delete_node_in_env(my_env **head, my_env *node_to_delete, sh_infos *shell);
int env_list_manager(sh_infos *shell, my_env **env_list, char *key,
char *value);
int env_array_manager(sh_infos *shell, my_env **env_list);
int check_if_buffer_is_alpha(sh_infos *shell);
int check_eligibility_of_string(sh_infos *shell, my_env **env_list);
int set_shell_variables(sh_infos *shell);
int get_new_len(char *str, my_env *env_list, sh_infos *shell);
int replace_tilde_user(char **str, char **new_str, int *len, sh_infos *shell);
int pre_handle_variables_in_new_str(char **temp, int *len, my_env *env_list,
sh_infos *shell);
int variable_exist_checker(my_env *current, char *str);
int check_tilde_user(char **temp, int *len, sh_infos *shell);
int handle_error_variable_not_found(char *temp);
int check_if_malloc_is_null(void);
void command_not_found(sh_infos *shell, int left_or_right);
int check_if_file_is_executable(char *command_name, sh_infos *shell);
int run_multiple_commands(sh_infos *shell, my_env **env_list,
custom_commands *commands_list);
void check_chevrons(char *command_string, sh_infos *shell);
void handle_chevrons(char *command_string, redirection *red);
int check_pipes(const char *command_string, sh_infos *shell);
int handle_pipes(char *command_string, pipe_t *pipe);
int parse_redirectors(char *command_string, sh_infos *shell);
int check_for_file_permission(char *command_name, sh_infos *shell);
void init_dup(sh_infos *shell, int pipefd[2]);
int return_to_pipe_if_exists(sh_infos *shell, int pipefd[2]);
#endif /* !MY_H_ */
