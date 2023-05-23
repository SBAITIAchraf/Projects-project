SRCS = SOURCES\Main_Programm.c \
	   SOURCES\Read_Data.c

OBJS = ${SRCS:%.c=%.o}

NAME = Main_Programm.exe


#Linking step:
${NAME}: ${OBJS}
	gcc ${SRCS} -o ${NAME}

#Compilation step:
%.o: %.c
	gcc -c $< -o $@

clean:
	del -f ${OBJS}

fclean: clean
	del -f ${NAME}

re: fclean ${NAME}


