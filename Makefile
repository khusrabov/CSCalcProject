CC=g++
WX_COMPILE_FLAGS=`wx-config --cxxflags`
WX_LINKING_FLAGS=`wx-config --libs`

FE=frontend
BE=backend
BLD=build

all: CalculatorApp

CalculatorApp: $(BLD)/CalculatorApp.o $(BLD)/CalculatorMain.o $(BLD)/RequestHandler.o $(BLD)/FNum.o $(BLD)/MemManager.o
	$(CC) -o $(BLD)/$@ $(BLD)/CalculatorApp.o $(BLD)/CalculatorMain.o $(BLD)/RequestHandler.o $(BLD)/FNum.o $(BLD)/MemManager.o $(WX_LINKING_FLAGS)

$(BLD)/CalculatorApp.o: $(FE)/CalculatorApp.cpp $(FE)/CalculatorApp.h $(FE)/CalculatorMain.h | $(BLD)
	$(CC) -o $@ -c $(FE)/CalculatorApp.cpp $(WX_COMPILE_FLAGS)

$(BLD)/CalculatorMain.o: $(FE)/CalculatorMain.cpp $(FE)/CalculatorMain.h | $(BLD)
	$(CC) -o $@ -c $(FE)/CalculatorMain.cpp $(WX_COMPILE_FLAGS)

$(BLD)/RequestHandler.o: $(BE)/RequestHandler.cpp | $(BLD)
	$(CC) -o $@ -c $(BE)/RequestHandler.cpp $(WX_COMPILE_FLAGS)

$(BLD)/FNum.o: $(BE)/FNum.cpp | $(BLD)
	$(CC) -o $@ -c $(BE)/FNum.cpp

$(BLD)/MemManager.o: $(BE)/MemManager.cpp | $(BLD)
	$(CC) -o $@ -c $(BE)/MemManager.cpp

$(BLD):
	mkdir $(BLD)