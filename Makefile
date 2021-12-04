
NAME		=	libftprintf.a

LIBFT_PATH	=	srcs/libft/

CC			=	gcc

SRCS		=	ft_printf.c\
				srcs/clean_struct.c \
				srcs/init_2.c \
				srcs/init.c \
				srcs/itoa_base_ll.c \
				srcs/itoa_base.c \
				srcs/itoa_et_itoa_long.c \
				srcs/manage_c.c\
				srcs/manage_i.c \
				srcs/manage_i_2.c \
				srcs/manage_s.c\
				srcs/manage_s_2.c\



OBJS		=	$(SRCS:.c=.o)

FLAGS		=	-c -Wall -Wextra -Werror

HEADER		=	includes/ft_printf.h

all			:	$(NAME)

$(NAME) 	:	$(HEADER) $(OBJS)
				make -C $(LIBFT_PATH)
				cp $(LIBFT_PATH)/libft.a $(NAME)
				$(CC) $(FLAGS) $(SRCS)
				ar -rcs $(NAME) $(OBJS)
				ranlib $(NAME)

clean		:	
				make -C $(LIBFT_PATH) clean
				rm -rf $(OBJS)
				rm -rf *.o

fclean		:	clean
				make -C $(LIBFT_PATH) fclean
				rm -rf $(NAME)

re			:	fclean all

