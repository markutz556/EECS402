all: proj3.exe

proj3.exe: constants.h ColorClass.o ColorImageClass.o RowColumnClass.o \
	RectangleClass.o PatternClass.o ensureChoiceValid.o ensureInputValid.o \
	chooseColor.o main.o
					g++ -g -Wall ColorClass.o RowColumnClass.o ColorImageClass.o \
					RectangleClass.o PatternClass.o ensureChoiceValid.o ensureInputValid.o \
					chooseColor.o main.o -o proj3.exe

ColorClass.o: constants.h ColorClass.h ColorClass.cpp
					g++ -c -g -Wall ColorClass.cpp -o ColorClass.o

RowColumnClass.o: constants.h RowColumnClass.h RowColumnClass.cpp
					g++ -c -g -Wall RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: constants.h ColorClass.h RowColumnClass.h \
	ensureChoiceValid.h ensureInputValid.h ColorImageClass.h ColorImageClass.cpp
					g++ -c -g -Wall ColorImageClass.cpp -o ColorImageClass.o 

RectangleClass.o: constants.h ColorClass.h RectangleClass.h RectangleClass.cpp
					g++ -c -g -Wall RectangleClass.cpp -o RectangleClass.o 

PatternClass.o: constants.h PatternClass.h PatternClass.cpp
					g++ -c -g -Wall PatternClass.cpp -o PatternClass.o

ensureChoiceValid.o: constants.h ensureChoiceValid.h ensureChoiceValid.cpp
					g++ -c -g -Wall ensureChoiceValid.cpp -o ensureChoiceValid.o

ensureInputValid.o: constants.h ensureInputValid.h ensureInputValid.cpp
					g++ -c -g -Wall ensureInputValid.cpp -o ensureInputValid.o

chooseColor.o: constants.h chooseColor.h chooseColor.cpp
					g++ -c -g -Wall chooseColor.cpp -o chooseColor.o

main.o: constants.h ensureChoiceValid.h ensureInputValid.h \
	chooseColor.h ColorClass.h RowColumnClass.h ColorImageClass.h \
	PatternClass.h RectangleClass.h main.cpp
					g++ -c -g -Wall main.cpp -o main.o

clean:
					rm -rf ColorClass.o ColorImageClass.o RowColumnClass.o \
					RectangleClass.o PatternClass.o ensureChoiceValid.o \
					ensureInputValid.o chooseColor.o main.o proj3.exe