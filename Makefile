CC=g++

OBJS=main.o\
	 NNC.o\
	 tools.o

main: $(OBJS)
%.o:%.c
	$(CC) -c $^ -o $@


.PHONY:clean
clean:
	rm -r *.o



