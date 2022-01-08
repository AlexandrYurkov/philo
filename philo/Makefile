NAME		=	philo

HEADER		=	philosophers.h

SRCS		= 	main.c \
				check_number.c \
				ft_life.c \
				ft_print_message.c \
				ft_time.c \
				philos.c \
				struct_init.c

OBJS		=	$(SRCS:.c=.o)

PHILO_FLAGS	=	-pthread -lpthread
FLAGS		=	-Wall -Wextra -Werror -g 
CC			=	gcc
GCC			=	$(CC) $(FLAGS)


all:			$(NAME)

%.o:			%.c $(HEADER)
				$(GCC) -c -o $@ $<
 
$(NAME):		$(OBJS)
				$(GCC) $(PHILO_FLAGS) $(OBJS) -o $(NAME)

clean:				
				rm -f $(OBJS)
			
fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re