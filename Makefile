
SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/oculta $(BIN)/revela

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/codificar.o: $(SRC)/codificar.cpp $(INC)/codificar.h
	$(CXX) $(CPPFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o

$(OBJ)/oculta.o: $(SRC)/oculta.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/oculta.cpp -o $(OBJ)/oculta.o

$(OBJ)/revela.o: $(SRC)/revela.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/revela.cpp -o $(OBJ)/revela.o

# ************ Compilación de los dos apartados principales ************

$(BIN)/oculta: $(OBJ)/imagenES.o $(OBJ)/codificar.o $(OBJ)/oculta.o 
	$(CXX) $(OBJ)/imagenES.o $(OBJ)/codificar.o $(OBJ)/oculta.o -o $(BIN)/oculta

$(BIN)/revela: $(OBJ)/imagenES.o $(OBJ)/codificar.o $(OBJ)/revela.o 
	$(CXX) $(OBJ)/imagenES.o $(OBJ)/codificar.o $(OBJ)/revela.o -o $(BIN)/revela

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm $(BIN)/* doc/html/*
