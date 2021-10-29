SRC	    := src
INCLUDE	:= include
OUTPUT	:= output
CXX 	:= g++

RM := del /q /f

compile_running_main: clean compile running

running:
	$(OUTPUT)/run.exe

compile: $(SRC)/main.cpp
	$(CXX) $(SRC)/main.cpp -o $(OUTPUT)/run.exe -I$(INCLUDE)

clean:
	$(RM) $(OUTPUT)\*.exe