/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_203_team_created_successfully
*/

#include "client.h"

static int get_team_count(char *message, char **teams_start)
{
    int num_teams = 0;

    *teams_start = strstr(message, "teams (");
    if (!(*teams_start)) {
        dprintf(1, "Error: User count not found.\n");
        return -1;
    }
    if (sscanf(*teams_start, "teams (%d):", &num_teams) != 1) {
        dprintf(1, "Error: Failed to retrieve team count.\n");
        return -1;
    }
    return num_teams;
}

static int scan_client(char *token, int team_count)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char teamname[MAX_NAME_LENGTH + 1] = {0};
    char description[MAX_DESCRIPTION_LENGTH + 1] = {0};

    if (sscanf(token, "UUID:%37[^,], name:%32[^,], description:%255[^\4]\4",
        uuid, teamname, description) == 3) {
        client_print_teams(uuid, teamname, description);
        ++team_count;
    }
    return team_count;
}

static void retrieve_teams(char *message, int num_teams)
{
    char *token = strtok(message, "\1");
    int team_count = 0;

    while (token != NULL && team_count < num_teams) {
        team_count = scan_client(token, team_count);
        token = strtok(NULL, "\1");
    }
}

void resp_210_list_teams(client_t *client, char *message)
{
    char *teams_start = NULL;
    int num_teams = get_team_count(message, &teams_start);

    (void)client;
    if (num_teams == -1)
        return;
    retrieve_teams(teams_start, num_teams);
}
