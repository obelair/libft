# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 13:31:58 by obelair           #+#    #+#              #
#    Updated: 2020/12/18 17:01:01 by obelair          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# === Global === #

NAME = libft.a

NAME_BONUS = libft.a

CC =	clang

CFLAGS =  -Wall -Wextra -Werror

RM = 	rm -f

# === Sources === #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c \
	ft_strtrim.c ft_substr.c ft_itoa.c ft_strmapi.c ft_split.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# === Objects === #

OBJS = ${SRCS:.c=.o}

# === Include === #

INCS = libft.h

# === Colors === #

_END = \033[0m
_BOLD = \033[1m
_DIM = \033[2m
_UNDERLINE = \033[3m

_RED = \033[31m
_GREEN = \033[32m
_YELLOW = \033[33m
_CYAN = \033[36m
_LIGHTGRAY = \033[37m
_DARKGRAY = \033[90m
_LIGHTRED = \033[91m

# === Default === #

all :	${NAME}

# === Compil === #

%.o : %.c ${INCS}
	@echo " ${_GREEN}${_DIM}\\\\\ ${_END}${_GREEN}Compilation done!${_DIM} //${_CYAN}   --->   ${_END}${_YELLOW}| ${_BOLD}${_CYAN}$<${_END} "
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	@echo "\n${_LIGHTRED}${_BOLD}${_DIM}$?${_END}\n" \
	"\t ${_YELLOW}${_DIM}${_BOLD}Add to ${NAME}!${_END} \n" 
	@ar rcs ${NAME} $?

# === Clean === #

clean :	
	@${RM} ${OBJS}

fclean :	clean
	@echo "${_LIGHTRED}${_DIM}${NAME} clean!${_END}"
	@${RM} ${NAME}

re :	fclean all

.PHONY :	all clean fclean re bonus
