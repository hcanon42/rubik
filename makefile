##---------------------------------MAKEFILE-------------------------------------

#====================================OBJS=======================================
OBJS		=	${SRCS:.cpp=.o}
OBJS_SHUFFLE=	${SRCS_SHUFFLE:.cpp=.o}


#====================================SRCS=======================================
SRCS			=	srcs/rubik.cpp			\
					srcs/main.cpp			\
					srcs/solve_brute.cpp	\
					srcs/solve_steps.cpp
SRCS_SHUFFLE	=	srcs/shuffle/shuffle.cpp


#=============================FLAGS AND COMPILERS===============================
CCPP			=	clang++
CPPFLAGS		=	-Wall -Wextra -Werror -I .includes/
NAME			=	rubik
NAME_SHUFFLE	=	shuffle


#================================AVAILABLE RULES================================
#-----
all:		$(NAME) shuffle

#-----
$(NAME):	${OBJS}
		${CCPP} ${CPPFLAGS} -o ${NAME} ${OBJS}

#-----
shuffle:	${OBJS_SHUFFLE}
		${CCPP} ${CPPFLAGS} -o ${NAME_SHUFFLE} ${OBJS_SHUFFLE}

#-----
clean:
		rm -f ${OBJS}
		rm -f ${OBJS_SHUFFLE}

#-----
fclean:		clean
		rm -f ${NAME}
		rm -f ${NAME_SHUFFLE}

#-----
re:		fclean all

#-----
.PHONY:		all clean fclean re shuffle
