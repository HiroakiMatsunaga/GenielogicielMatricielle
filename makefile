CC = g++
CFLAGS = -Wall 
EXEC_NAME = Matrice
INCLUDES =
LIBS = 
OBJ_FILES = main.cpp MatCreuse.o MatPleine.o Matrice.o
INSTALL_DIR = 
all : $(EXEC_NAME)
# clean :
# 	rm $(EXEC_NAME) $(OBJ_FILES)
$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)
%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

