# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 13:31:58 by obelair           #+#    #+#              #
#    Updated: 2021/01/11 14:40:13 by obelair          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# === Name === #

NAME		=	libft.a

# === Directories === #

PATH_INC	=	incs
PATH_SRC	=	srcs
PATH_OBJ	=	objs

# === Commands === #

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

# === Sources === #

SRCS_CMP	=	${addprefix ft_cmp/, ft_isdigit.c ft_isprint.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_min.c ft_max.c}
SRCS_INT	=	${addprefix ft_int/, ft_itoa.c ft_atoi.c ft_intlen.c}
SRCS_LST	=	${addprefix ft_lst/, ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c}
SRCS_MEM	=	${addprefix ft_mem/, ft_bzero.c ft_calloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c}
SRCS_PUT	=	${addprefix ft_put/, ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c}
SRCS_STR	=	${addprefix ft_str/, ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_strmapi.c ft_split.c}
SRCS_PTF	=	${addprefix ft_printf/, ft_printf.c ft_scan_str.c ft_displ_addr.c ft_displ_chr.c ft_displ_int.c ft_displ_str.c ft_displ_util.c ft_init_struct.c ft_lencmp.c ft_nptr.c}
SRCS_GNL	=	${addprefix gnl/, get_next_line.c}
SRCS		=	${addprefix ${PATH_SRC}/, ${SRCS_CMP} ${SRCS_INT} ${SRCS_LST} ${SRCS_MEM} ${SRCS_PUT} ${SRCS_STR} ${SRCS_PTF} ${SRCS_GNL}}

# === Objects === #

OBJS		=	${addprefix ${PATH_OBJ}/, ${notdir ${SRCS:.c=.o}}}

# === Include === #

INCS		=	${addprefix ${PATH_INC}/, ft_cmp.h ft_int.h ft_lst.h ft_mem.h ft_put.h ft_str.h}

# === Colors === #

_END		=	\033[0m
_BOLD		=	\033[1m
_DIM		=	\033[2m
_UNDERLINE	=	\033[3m

_RED		=	\033[31m
_GREEN		=	\033[32m
_YELLOW		=	\033[33m
_CYAN		=	\033[36m
_LIGHTGRAY	=	\033[37m
_DARKGRAY	=	\033[90m
_LIGHTRED	=	\033[91m

# === Default === #

all:	init ${NAME}

# === Compil === #

${PATH_OBJ}/%.o: ${PATH_SRC}/*/%.c ${PATH_INC}/*.h
	@ echo " ${_GREEN}${_DIM}\\\\\ ${_END}${_GREEN}Compilation done!${_DIM} //${_CYAN}   --->   ${_END}${_YELLOW}| ${_BOLD}${_CYAN}$<${_END} "
	@ ${CC} ${CFLAGS} -c $< -o $@

init:	
	@ ${shell mkdir -p ${PATH_OBJ}}

${NAME}: ${OBJS}
	@ echo "\n${_LIGHTRED}${_BOLD}${_DIM}$?${_END}\n" \
		"\t ${_YELLOW}${_DIM}${_BOLD}Add to ${NAME}!${_END} \n" 
	@ ar rcs ${NAME} $?

# === Clean === #

clean:	
	@ ${RM} ${PATH_OBJ}

fclean:	clean
	@ echo "${_LIGHTRED}${_DIM}${NAME} clean!${_END}"
	@ ${RM} ${NAME}

re:	fclean all

.PHONY:		all clean fclean re bonus
