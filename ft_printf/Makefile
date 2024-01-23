#===========[ VARIABLE ]===========#
#
CC = gcc
NAME = ../printf.a
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_digit.c ft_hexa_uplow.c ft_print_string.c ft_putchar_ptr.c ft_unsigned.c
SRC = $(addprefix src/, $(SRCS))
OBJ = $(SRC:.c=.o)
#
#=========[ EXPECTED_FILES ]=========#
#
EXPECTED_FILES = c h
EXPECTED_FILES_REPO1 = ft_digit.c|ft_hexa_uplow.c|ft_print_string.c|ft_printf.c|ft_putchar_ptr.c|ft_unsigned.c
EXPECTED_FILES_REPO2 = ft_printf.h
EXPECTED_FILES_REPO3 = c h|Makefile
EXPECTED_FILES_REPO4 = pdf
#
#==========[ REPOSITORIES ]==========#
#
REPO1 = src
REPO2 = include
REPO3 = libft
REPO4 = test_uwu
#
#===========[ CHECK_CMD ]===========#
#
UNEXPECTED_FILES_CMD = $(shell ls -1 | grep -vEw 'Makefile|include|libft|src')
UNEXPECTED_FILES_CMD_REPO1 = $(shell ls -1 $(REPO1) | grep -vE '$(EXPECTED_FILES_REPO1)')
UNEXPECTED_FILES_CMD_REPO2 = $(shell ls -1 $(REPO2) | grep -vE '$(EXPECTED_FILES_REPO2)')
UNEXPECTED_FILES_CMD_REPO3 = $(shell ls -1 $(REPO3) | grep -vE '$(EXPECTED_FILES_REPO3)')
UNEXPECTED_FILES_CMD_REPO4 = $(shell ls -1 $(REPO4) | grep -vE '$(EXPECTED_FILES_REPO4)')
#
#
#=============[ Custom ]============#
#																    #
DEF					= \033[0m#					   	#
ROUGE 			= \033[38;2;255;0;0m# 	#
VERT 				= \033[38;2;0;255;0m#  	#
JAUNE 			= \033[33m#			    		#
BLEU 				= \033[34m#			   			#
MAGENTA 		= \033[38;2;255;38;253m##	
ROSE 	  	  = \033[38;2;255;155;254m#
CYAN				= \033[36m#			    		#
BLANC				= \033[37m#			    		#
NOIR				= \033[30m#							#
#								    								#
BG_ROUGE 		= \033[41m#			   			#
BG_BLANC		= \033[47m#							#
#																		#
GRAS				= \033[1m#							#
SOULIGNE		= \033[4m#							#
ITALIQUE		= \033[3m#							#
#																		#
SPEED				= 0.005#								#
SPEED_W			= 0.005#								#
SLEEP_SPEED = 0.005#								#
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

%.o : %.c
	@$(CC) -c $< $(CFLAGS) -I./include -o $@

$(NAME) : $(OBJ)
	@make -C libft
	@ar -rcs $(NAME) $(OBJ)
	@$(COMPILE)
	@sleep $(SLEEP_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(VERT)$(V) compilation OK$(DEF)"
#
#
#=======[ CMD_COLOR_PROGRESS ]======#
#
COMPILE        = printf "$(JAUNE)$(PROCESS) " && \
		sleep $(SPEED) && \
		printf "c" && \
		sleep $(SPEED) && \
		printf "o" && \
		sleep $(SPEED) && \
		printf "m" && \
		sleep $(SPEED) && \
		printf "p" && \
		sleep $(SPEED) && \
		printf "i" && \
		sleep $(SPEED) && \
		printf "l" && \
		sleep $(SPEED) && \
		printf "a" && \
		sleep $(SPEED) && \
		printf "t" && \
		sleep $(SPEED) && \
		printf "i" && \
		sleep $(SPEED) && \
		printf "o" && \
		sleep $(SPEED) && \
		printf "n" && \
		sleep $(SPEED) && \
		printf " " && \
		sleep $(SPEED) && \
		printf "p" && \
		sleep $(SPEED) && \
		printf "r" && \
		sleep $(SPEED) && \
		printf "o" && \
		sleep $(SPEED) && \
		printf "c" && \
		sleep $(SPEED) && \
		printf "e" && \
		sleep $(SPEED) && \
		printf "s" && \
		sleep $(SPEED) && \
		printf "s" && \
		sleep $(SPEED) && \
		printf "." && \
		sleep $(SPEED) && \
		printf "." && \
		sleep $(SPEED) && \
		printf ".\033[0m\n" 
#
CHECK_PROGRESS = printf "      $(BLEU)╔═════════════╗\n" && \
		printf "      ║  $(DEF)$(ROSE)FT_PRINTF  $(BLEU)║\n" && \
		printf "      $(BLEU)╚═════════════╝$(DEF)\n" && \
		printf "$(JAUNE)$(PROCESS)" && \
		sleep $(SPEED) && \
		printf "C" && \
		sleep $(SPEED) && \
		printf "h" && \
		sleep $(SPEED) && \
		printf "e" && \
		sleep $(SPEED) && \
		printf "c" && \
		sleep $(SPEED) && \
		printf "k" && \
		sleep $(SPEED) && \
		printf "i" && \
		sleep $(SPEED) && \
		printf "n" && \
		sleep $(SPEED) && \
		printf "g" && \
		sleep $(SPEED) && \
		printf " " && \
		sleep $(SPEED) && \
		printf "f" && \
		sleep $(SPEED) && \
		printf "o" && \
		sleep $(SPEED) && \
		printf "r" && \
		sleep $(SPEED) && \
		printf " " && \
		sleep $(SPEED) && \
		printf "u" && \
		sleep $(SPEED) && \
		printf "n" && \
		sleep $(SPEED) && \
		printf "e" && \
		sleep $(SPEED) && \
		printf "x" && \
		sleep $(SPEED) && \
		printf "p" && \
		sleep $(SPEED) && \
		printf "e" && \
		sleep $(SPEED) && \
		printf "c" && \
		sleep $(SPEED) && \
		printf "t" && \
		sleep $(SPEED) && \
		printf "e" && \
		sleep $(SPEED) && \
		printf "d" && \
		sleep $(SPEED) && \
		printf " " && \
		sleep $(SPEED) && \
		printf "f" && \
		sleep $(SPEED) && \
		printf "i" && \
		sleep $(SPEED) && \
		printf "l" && \
		sleep $(SPEED) && \
		printf "e" && \
		sleep $(SPEED) && \
		printf "/" && \
		sleep $(SPEED) && \
		printf "r" && \
		sleep $(SPEED) && \
		printf "e" && \
		sleep $(SPEED) && \
		printf "p" && \
		sleep $(SPEED) && \
		printf "o" && \
		sleep $(SPEED) && \
		printf "s" && \
		sleep $(SPEED) && \
		printf "i" && \
		sleep $(SPEED) && \
		printf "t" && \
		sleep $(SPEED) && \
		printf "o" && \
		sleep $(SPEED) && \
		printf "r" && \
		sleep $(SPEED) && \
		printf "y" && \
		sleep $(SPEED) && \
		printf " " && \
		sleep $(SPEED) && \
		printf "i" && \
		sleep $(SPEED) && \
		printf "n" && \
		sleep $(SPEED) && \
		printf " " && \
		sleep $(SPEED) && \
		printf "f" && \
		sleep $(SPEED) && \
		printf "t" && \
		sleep $(SPEED) && \
		printf "_" && \
		sleep $(SPEED) && \
		printf "p" && \
		sleep $(SPEED) && \
		printf "r" && \
		sleep $(SPEED) && \
		printf "i" && \
		sleep $(SPEED) && \
		printf "n" && \
		sleep $(SPEED) && \
		printf "t" && \
		sleep $(SPEED) && \
		printf "f" && \
		sleep $(SPEED) && \
		printf "." && \
		sleep $(SPEED) && \
		printf "." && \
		sleep $(SPEED) && \
		printf ".\n" && \
		sleep $(SLEEP_SPEED)
#
WARN_PROGRESS  = sleep 0.1 && \
		printf "$(GRAS)$(MAGENTA)$(WARNING)" && \
		sleep $(SPEED_W) && \
		printf " " && \
		sleep $(SPEED_W) && \
		printf "W" && \
		sleep $(SPEED_W) && \
		printf "a" && \
		sleep $(SPEED_W) && \
		printf "r" && \
		sleep $(SPEED_W) && \
		printf "n" && \
		sleep $(SPEED_W) && \
		printf "i" && \
		sleep $(SPEED_W) && \
		printf "n" && \
		sleep $(SPEED_W) && \
		printf "g" && \
		sleep $(SPEED_W) && \
		printf ":" && \
		sleep $(SPEED_W) && \
		printf "$(DEF) $(ROSE)" && \
		sleep $(SPEED_W) && \
		printf "t" && \
		sleep $(SPEED_W) && \
		printf "h" && \
		sleep $(SPEED_W) && \
		printf "i" && \
		sleep $(SPEED_W) && \
		printf "s" && \
		sleep $(SPEED_W) && \
		printf " " && \
		sleep $(SPEED_W) && \
		printf "c" && \
		sleep $(SPEED_W) && \
		printf "o" && \
		sleep $(SPEED_W) && \
		printf "m" && \
		sleep $(SPEED_W) && \
		printf "m" && \
		sleep $(SPEED_W) && \
		printf "a" && \
		sleep $(SPEED_W) && \
		printf "n" && \
		sleep $(SPEED_W) && \
		printf "d" && \
		sleep $(SPEED_W) && \
		printf " " && \
		sleep $(SPEED_W) && \
		printf "d" && \
		sleep $(SPEED_W) && \
		printf "o" && \
		sleep $(SPEED_W) && \
		printf "e" && \
		sleep $(SPEED_W) && \
		printf "s" && \
		sleep $(SPEED_W) && \
		printf " " && \
		sleep $(SPEED_W) && \
		printf "n" && \
		sleep $(SPEED_W) && \
		printf "o" && \
		sleep $(SPEED_W) && \
		printf "t" && \
		sleep $(SPEED_W) && \
		printf " " && \
		sleep $(SPEED_W) && \
		printf "s" && \
		sleep $(SPEED_W) && \
		printf "e" && \
		sleep $(SPEED_W) && \
		printf "a" && \
		sleep $(SPEED_W) && \
		printf "r" && \
		sleep $(SPEED_W) && \
		printf "c" && \
		sleep $(SPEED_W) && \
		printf "h" && \
		sleep $(SPEED_W) && \
		printf " " && \
		sleep $(SPEED_W) && \
		printf "f" && \
		sleep $(SPEED_W) && \
		printf "o" && \
		sleep $(SPEED_W) && \
		printf "r" && \
		sleep $(SPEED_W) && \
		printf " " && \
		sleep $(SPEED_W) && \
		printf "h" && \
		sleep $(SPEED_W) && \
		printf "i" && \
		sleep $(SPEED_W) && \
		printf "d" && \
		sleep $(SPEED_W) && \
		printf "d" && \
		sleep $(SPEED_W) && \
		printf "e" && \
		sleep $(SPEED_W) && \
		printf "n" && \
		sleep $(SPEED_W) && \
		printf " " && \
		sleep $(SPEED_W) && \
		printf "f" && \
		sleep $(SPEED_W) && \
		printf "i" && \
		sleep $(SPEED_W) && \
		printf "l" && \
		sleep $(SPEED_W) && \
		printf "e" && \
		sleep $(SPEED_W) && \
		printf "s$(DEF)\n" && \
		sleep $(SPEED_W)
#
#=================[ CHECK_FILES ]=================#
#
check-unexpected-files :
	@$(CHECK_PROGRESS)
ifeq ($(strip $(UNEXPECTED_FILES_CMD)),)
	@sleep $(SLEEP_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(VERT)$(V) No unexpected f/r in ft_printf$(DEF)"
	@sleep $(SLEEP_SPEED)
else
	@sleep $(SLEEP_SPD_X)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf:$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(X) unexpected f/r in ft_printf:$(DEF) $(BG_BLANC)$(NOIR)$(UNEXPECTED_FILES_CMD)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf:$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(X) unexpected f/r in ft_printf:$(DEF) $(BG_BLANC)$(NOIR)$(UNEXPECTED_FILES_CMD)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf:$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD)$(DEF)"
endif
ifeq ($(strip $(UNEXPECTED_FILES_CMD_REPO1)),)
	@sleep $(SLEEP_SPEED)
	@echo "$(VERT)$(V) No unexpected f/r in ft_printf/$(REPO1)$(DEF)"
	@sleep $(SLEEP_SPEED)
else
	@sleep $(SLEEP_SPD_X)
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf/$(REPO1):$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD_REPO1)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(X) unexpected f/r in ft_printf/$(REPO1):$(DEF) $(BG_BLANC)$(NOIR)$(UNEXPECTED_FILES_CMD_REPO1)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf/$(REPO1):$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD_REPO1)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(X) unexpected f/r in ft_printf/$(REPO1):$(DEF) $(BG_BLANC)$(NOIR)$(UNEXPECTED_FILES_CMD_REPO1)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf/$(REPO1):$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD_REPO1)$(DEF)"
endif
ifeq ($(strip $(UNEXPECTED_FILES_CMD_REPO2)),)
	@sleep $(SLEEP_SPEED)
	@echo "$(VERT)$(V) No unexpected f/r in ft_printf/$(REPO2)$(DEF)"
	@sleep $(SLEEP_SPEED)
else
	@sleep $(SLEEP_SPD_X)
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf/$(REPO2):$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD_REPO2)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(X) unexpected f/r in ft_printf/$(REPO2):$(DEF) $(BG_BLANC)$(NOIR)$(UNEXPECTED_FILES_CMD_REPO2)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf/$(REPO2):$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD_REPO2)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(X) unexpected f/r in ft_printf/$(REPO2):$(DEF) $(BG_BLANC)$(NOIR)$(UNEXPECTED_FILES_CMD_REPO2)$(DEF)"
	@sleep $(FLASH_SPEED)
	@printf '\033[1A\033[K'
	@echo "$(GRAS)$(ROUGE)$(X) unexpected f/r in ft_printf/$(REPO2):$(DEF) $(BG_ROUGE)$(UNEXPECTED_FILES_CMD_REPO2)$(DEF)"
endif
	@echo "\n"
	@$(WARN_PROGRESS)
	@echo "\n"
#
#===========================================#

clean :
	@rm -rf $(OBJ)
	@make clean -C libft
	@echo "$(VERT)$(V) cleaning OK$(DEF)"

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo "$(VERT)$(V) fcleaning OK$(DEF)"

re : fclean all

re_silent :
	@make re --silent

silent :
	@make --silent

check : check-unexpected-files

big :
	@make fclean --silent
	@make check
	@make silent

.PHONY: all clean fclean re silent check big re_silent

# variables speciales
#ffff
# $@ nom cible
# $< nom premiere dependance
# $^ liste des dependances
# $* nom fichier, sans extension
# @echo "$(JAUNE)Checking for unexpected file/repository...$(DEF)"
# @echo "$(MAGENTA)/!\\ this command does not search for hidden files$(DEF)"
# @echo "$(JAUNE)compilation process...$(DEF)"
#Makefile|ft_atoi.c|ft_bzero.c|ft_calloc.c|ft_isalnum.c|ft_isalpha.c|ft_isascii.c|\
						|ft_isdigit.c|ft_isprint.c|ft_itoa.c|ft_memchr.c|ft_memcmp.c|ft_memcpy.c|ft_memmove.c|\
						|ft_memset.c|ft_putchar_fd.c|ft_putendl_fd.c|ft_putnbr_fd.c|ft_putstr_fd.c|ft_split.c|\
						|ft_strchr.c|ft_strdup.c|ft_striteri.c|ft_strjoin.c|ft_strlcat.c|ft_strlcpy.c|ft_strlen|\
						|ft_strncmp.c|ft_strmapi.c|ft_strnstr.c|ft_strtrim.c|ft_substr.c|ft_tolower.c|ft_toupper.c|\
						|ft_strrchr.c|libft.h