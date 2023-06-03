SRCS = SOURCES\Main_Programm.c \
	   SOURCES\Read_Data.c \
	   SOURCES\map_Skill_Contributer.c \
	   SOURCES\Dynamic_Array.c \
	   SOURCES\map_Skill_Level.c \
	   SOURCES\Greedy_approach.c

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


