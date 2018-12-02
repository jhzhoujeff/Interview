#this is the test program c++ make file

	TARGET = .
		CC = g++
	CFLAGG = -g
	CFLAGC = -c

	MAINC  = main.cpp
	TRIEC  = trieTree.cpp
	TRIEO  = trieTree.o
	GAMEC  = game.cpp
	GAMEO  = game.o

	INCLUDE = -I$(TARGET)
	EXEC = $(TARGET)/main


all: $(EXEC)
$(EXEC): $(TRIEO) $(GAMEO) $(MAINC)
	$(CC) $(CFLAGG) $(TRIEO) $(GAMEO) $(MAINC) $(INCLUDE) -o $@
	@echo "--------------$@ is created successfully--------------"
$(OBJ): $(TRIEC) $(GAMEC)
	$(CC) $(CFLAGC) $(CFLAGG) $(TRIEC) $(GAMEC) $(INCLUDE) -o $@ 

clean:
	rm -rf $(EXEC)
