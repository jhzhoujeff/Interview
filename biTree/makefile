# this is a makefile of the c++ project hello

      TARGET = .
          CC = g++
      CFLAGS = -g
      CFLAGC = -c
      
      MAINC	= main.cpp
      HELLO	= hello.cpp
      HELLOOBJ	= hello.o
      TOOL	= tools.cpp
      TOOLOBJ	= tools.o
      TREE	= tree.cpp
      TREEOBJ	= tree.o

      INCLUDE = -I$(TARGET)
         EXEC = $(TARGET)/main


all: $(EXEC)
$(EXEC): $(HELLOOBJ) $(TOOLOBJ) $(TREEOBJ) $(MAINC)
	$(CC) $(HELLOOBJ) $(TOOLOBJ) $(TREEOBJ) $(MAINC) $(INCLUDE) -o $@
	@echo "<<<<<< $@ is created successfully! >>>>>>"
$(OBJ): $(HELLO) $(BOOL)
	$(CC) $(CFLAGC) $(HELLO) $(TOOL) $(TREE) -o $@
clean:
	rm -f $(EXEC)

