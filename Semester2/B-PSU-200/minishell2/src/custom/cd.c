/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cd
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../lib/my/libmy.h"
#include "../../include/my.h"

static int check_if_cd_dash(char **path_to_go, sh_infos *shell)
{
    int cd_is_dash = 0;

    if (!my_strcmp(*path_to_go, "-")) {
        *path_to_go = my_strdup(shell->old_pwd);
        cd_is_dash = 1;
    }
    return (cd_is_dash);
}

static int handle_not_found_file(char *path_to_go, struct stat *st,
sh_infos *shell, int cd_is_dash)
{
    if (access(path_to_go, X_OK) != 0 && stat(path_to_go, st) == 0) {
        my_error(path_to_go, 8);
        set_return_code(shell, 1);
        return (1);
    }
    if (chdir(path_to_go) == -1) {
        if (shell->args_len == 1)
            write(2, "cd: Can't change to home directory.\n", 36);
        else
            my_error(path_to_go, 0);
        set_return_code(shell, 1);
        if (cd_is_dash)
            free(path_to_go);
        return (1);
    }
    return (0);
}

static int file_path_choice_handling(char **path_to_go, sh_infos *shell,
struct stat *st, int *stat_code)
{
    *path_to_go = (shell->args_len == 1) ? shell->home_backup : shell->args[1];
    *stat_code = stat(*path_to_go, st);
    if (!S_ISDIR((*st).st_mode) && !access(*path_to_go, X_OK)) {
        my_error(*path_to_go, 10);
        set_return_code(shell, 1);
        return (1);
    }
    return (0);
}

int custom_cd(sh_infos *shell, my_env **env_list)
{
    char *path_to_go = NULL;
    int cd_is_dash = 0;
    int stat_code = 0;
    struct stat st = {0};

    if (shell->args_len > 2) {
        my_error("cd", 5);
        set_return_code(shell, 1);
        return (1);
    }
    if (file_path_choice_handling(&path_to_go, shell, &st, &stat_code))
        return (1);
    cd_is_dash = check_if_cd_dash(&path_to_go, shell);
    if (!stat_code || cd_is_dash)
        shell->old_pwd = getcwd(shell->old_pwd, 1000);
    set_return_code(shell, 0);
    if (handle_not_found_file(path_to_go, &st, shell, cd_is_dash))
        return (1);
    free((cd_is_dash) ? path_to_go : NULL);
    return (1);
}
