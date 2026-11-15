# Vaïty TAYLLAMIN Manon WEISS

CC = g++
SRCS = main.cpp Menu/menu.cpp Menu/menuoption.cpp Consigne/consigne.cpp Instruction/instruction.cpp Turtle/turtle.cpp SvgDrawer/svgdrawer.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main.exe


$(EXEC): $(OBJS)
	$(CC) -o $@ $^
	$(MAKE) clean

%.o: %.cpp
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

