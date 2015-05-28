CC = g++
CXX = ar rv
CFLAGS = -Wall -pg
EXEC_NAME = Matrice
INCLUDES =
LIBS = matLib.a
OBJ_FILES = main.cpp
NAME_LIB = matLib.a
OBJ_LIB = MatCreuse.o MatPleine.o Matrice.o
INSTALL_DIR = 

all : $(EXEC_NAME) $(NAME_LIB)
# clean :
# 	rm $(EXEC_NAME) $(OBJ_FILES)
$(EXEC_NAME): $(OBJ_FILES) $(LIBS)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

$(NAME_LIB): $(OBJ_LIB)
	$(CXX) $(NAME_LIB) $(OBJ_LIB);

%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
