# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wvan-ees <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/25 15:07:57 by wvan-ees      #+#    #+#                  #
#    Updated: 2019/02/07 12:13:15 by wvan-ees      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_memalloc.c \
ft_memcmp.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memdel.c ft_memmove.c ft_memset.c ft_putnbr_fd.c \
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strlcat.c ft_strchr.c \
ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strjoin.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
ft_toupper.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
ft_lstnew.c ft_iswhitespace.c ft_nbrlen.c ft_splithelp.c ft_char_ignore.c \
ft_countwords.c ft_strndup.c ft_count_nline.c ft_put_u_long.c \
x_power_y.c ft_itoabase.c ft_strrev.c ft_strlchr.c ft_strsub.c ft_max.c ft_min.c \
ft_findchar.c ft_findspace.c ft_strfndup.c

OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
ft_isprint.o ft_itoa.o ft_memalloc.o \
ft_memcmp.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
ft_memdel.o ft_memmove.o ft_memset.o ft_putnbr_fd.o \
ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strlcat.o ft_strchr.o \
ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o \
ft_striter.o ft_striteri.o ft_strjoin.o ft_strlen.o ft_strmap.o ft_strmapi.o \
ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o \
ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o \
ft_toupper.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o \
ft_lstnew.o ft_iswhitespace.o ft_nbrlen.o ft_splithelp.o ft_char_ignore.o \
ft_countwords.o ft_strndup.o ft_count_nline.o ft_put_u_long.o \
x_power_y.o ft_itoabase.o ft_strrev.o ft_strlchr.o ft_strsub.o ft_max.o ft_min.o \
ft_findchar.o ft_findspace.o ft_strfndup.o

RM = rm -f

all: $(NAME)

$(NAME):
	@echo COMPILING LIBFT
	@gcc -c $(SRCS) -Wall -Wextra -Werror	
	@ar rc $(NAME) $(OBJ)
	@make -C ./ft_printf/
	@mv ft_printf/libftprintf.a ./$(NAME)

clean: 
	@echo CLEANING LIBFT
	@$(RM) $(OBJ)
	@make -C ./ft_printf/ clean

fclean: clean
	@echo F_CLEANING LIBFT
	@$(RM) $(NAME)
	@make -C ./ft_printf/ fclean

re: fclean all
