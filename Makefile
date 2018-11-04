CC = g++
PROGRAMME = ALPHA_BETA  
CCFLAGS = -Wall -g
HEADERS = alpha_beta.h 
SOURCES = main.cpp alpha_beta.cpp game.cpp 
OBJ = $(SOURCES:.cpp=.o)
RM=rm 
all: $(PROGRAMME)
$(PROGRAMME):$(OBJ)
	$(CC) $(OBJ) $(CCFLAGS) -o $(PROGRAMME)
%.o: %.cpp 
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	$(RM) -r ./$(PROGRAMME) ./*~ ./$(OBJ)
