#===========[ VARIABLE ]============#
#
CC = gcc
NAME = philo
CFLAGS = -g -O3 -Wall -Wextra -fsanitize=address #
SRCS = utils.c check_input.c init.c acces_mutex.c action.c put_status.c secure_utils.c synchro.c monitor.c free_utils.c main.c
SRC = $(addprefix src/, $(SRCS))
OBJ = $(SRC:.c=.o)

#=============[ Custom ]============#
#																    #
DEF					= \033[0m#			  		  #
ROUGE 			= \033[38;2;255;0;0m#   #
VERT 				= \033[38;2;0;255;0m#   #
JAUNE 			= \033[33m#			  			#
BLEU 				= \033[34m#			    		#
MAGENTA 		= \033[38;2;255;38;253m##	
ROSE 	    	= \033[38;2;255;155;254m#
CYAN				= \033[36m#			    		#
BLANC				= \033[37m#			    		#
NOIR				= \033[30m#							#
#								    								#
BG_ROUGE 		= \033[41m#			    		#
BG_BLANC		= \033[47m#							#
#																		#
GRAS				= \033[1m#							#
SOULIGNE		= \033[4m#							#
ITALIQUE		= \033[3m#							#
#																		#
SPEED				= 0.005#								#
SLEEP_SPEED = 0.01#									#
SLEEP_SPD_X = 0.005#								#
SLEEP_TEST  = 0.001#								#
FLASH_SPEED = 0.08#									#
#																		#
V						= \xE2\x9C\x93# 	(✓)		#
WARNING			= \xE2\x9A\xA0# 	(⚠)		#
X 					= \xE2\x9C\x97# 	(✗)		#
PROCESS			= \xF0\x9F\x94\x84# (🔄)#
#																		#
#===================================#

all : $(NAME)

%.o : %.c include/philo.h
	$(CC) -c $< $(CFLAGS) -I./include -o $@

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) libft.a

clean :
	rm -rf $(OBJ)
	make clean -C libft


fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all

.PHONY: all clean fclean re
