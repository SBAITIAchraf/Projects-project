SRCS = SOURCES\Main_Programm.c \
	   SOURCES\Read_Data.c

OBJS = ${SRCS:%.c=%.o}

NAME = Main_Programm.exe

#Linking step:
${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

#Compilation step:

%.o: %.c INCLUDE\Functions.h INCLUDE\Structs.h
	gcc -c $< -o $@

clean:
	rm -f math.o main.o

fclean: clean
	rm -f problem_c

re: fclean ${NAME}


