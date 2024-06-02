##
## EPITECH PROJECT, 2024
## B-NWP-400-STG-4-1-myteams-noe.tritsch
## File description:
## Makefile
##


SRC_SERVER		=	src/server/main.c      \
					src/server/setup_server.c      \
					src/server/add_user.c   \
					src/server/loop_server.c       \
					src/server/handle_server.c     \
					src/server/free_all.c  \
					src/server/commands/handle_commands.c  \
					src/server/commands/login.c     \
					src/server/commands/help.c     \
					src/server/commands/logout.c     \
					src/server/commands/user.c     \
					src/server/commands/message.c     \
					src/server/commands/use.c	\
					src/server/commands/create.c	\
					src/server/commands/info.c	\
					src/server/commands/list.c	\
					src/server/commands/subscribe.c	\
					src/server/commands/unsubscribe.c	\
					src/server/commands/subscribed.c	\
					src/server/utils.c     \
					src/server/utils_2.c \
					src/server/server_utils.c

OBJ_SERVER		=		$(SRC_SERVER:.c=.o)

NAME_SERVER		=       myteams_server

SRC_CLIENT		=       src/client/main.c	\
						src/client/cli.c	\
						src/client/loop.c	\
						src/server/utils.c	\
						src/server/utils_2.c	\
						src/client/handle_response.c	\
						src/client/loop_actions.c	\
						src/client/resp/resp_001_connected.c	\
						src/client/resp/resp_002_disconnected.c	\
						src/client/resp/resp_003_logged_in.c	\
						src/client/resp/resp_004_logged_out.c	\
						src/client/resp/resp_005_help.c	\
						src/client/resp/resp_101_message_sent.c	\
						src/client/resp/resp_102_message_received.c	\
						src/client/resp/resp_103_thread_sent.c	\
						src/client/resp/resp_104_thread_received.c	\
						src/client/resp/resp_105_team_created.c	\
						src/client/resp/resp_106_channel_created.c	\
						src/client/resp/resp_107_thread_created.c	\
						src/client/resp/resp_201_subscribed.c	\
						src/client/resp/resp_202_unsubscribed.c	\
						src/client/resp/resp_203_team_created_success.c	\
						src/client/resp/resp_204_channel_created_success.c	\
						src/client/resp/resp_205_thread_created_success.c	\
						src/client/resp/resp_206_reply_created_success.c	\
						src/client/resp/resp_207_user_info.c	\
						src/client/resp/resp_208_list_users.c	\
						src/client/resp/resp_209_team_info.c	\
						src/client/resp/resp_210_list_teams.c	\
						src/client/resp/resp_211_channel_info.c	\
						src/client/resp/resp_212_list_channels.c	\
						src/client/resp/resp_213_thread_info.c	\
						src/client/resp/resp_214_list_threads.c	\
						src/client/resp/resp_215_list_replies.c	\
						src/client/resp/resp_216_list_messages.c	\
						src/client/resp/resp_301_already_logged_in.c	\
						src/client/resp/resp_302_not_logged_in.c	\
						src/client/resp/resp_303_unknown_team.c	\
						src/client/resp/resp_304_unknown_channel.c	\
						src/client/resp/resp_305_unknown_thread.c	\
						src/client/resp/resp_306_unknown_user.c	\
						src/client/resp/resp_307_unauthorized.c	\
						src/client/resp/resp_308_already_exist.c	\
						src/client/resp/resp_309_error.c	\
						src/client/resp/resp_310_syntax_error.c	\
						src/client/resp/resp_311_bad_command.c	\

OBJ_CLIENT		=       $(SRC_CLIENT:.c=.o)

NAME_CLIENT		=       myteams_cli

LDFLAGS		+=		-L ./libs/myteams -lmyteams -luuid

CFLAGS	=	-g -I./include
CFLAGS	+=	-I./libs/myteams
CFLAGS	+=	-Wall -Wextra -Werror

all: server client

server: $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SERVER)
	gcc $(OBJ_SERVER) -o $(NAME_SERVER) $(CFLAGS) $(LDFLAGS)

client: $(NAME_CLIENT)

$(NAME_CLIENT):        $(OBJ_CLIENT)
	gcc $(OBJ_CLIENT) -o $(NAME_CLIENT) $(CFLAGS) $(LDFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	rm -rf log_folder

re: fclean all

.PHONY: all clean fclean re
