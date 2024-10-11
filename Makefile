# All object files are to be linked to the final exceutable.
all: Cow.o Corn.o Wheat.o Pig.o Field.o Barn.o Farm.o Farmer.o main.o
	g++ main.o Farmer.o Farm.o Barn.o Field.o Pig.o Wheat.o Corn.o Cow.o -o FarmSim

# compile source files into object files.
# As most of the source files do not have a main file, -c is used to compile them into object files. 
Cow.o: Cow.cpp Cow.h
	g++ -c Cow.cpp

Corn.o: Corn.cpp Corn.h
	g++ -c Corn.cpp

Wheat.o: Wheat.cpp Wheat.h
	g++ -c Wheat.cpp

Pig.o: Pig.cpp Pig.h
	g++ -c Pig.cpp

Barn.o: Barn.cpp Barn.h
	g++ -c Barn.cpp

Field.o: Field.cpp Field.h
	g++ -c Field.cpp

Farm.o: Farm.cpp Farm.h
	g++ -c Farm.cpp

Farmer.o: Farmer.cpp Farmer.h
	g++ -c Farmer.cpp

main.o: main.cpp
	g++ -c main.cpp

# Remove the objects files and executable.
Clean: 
	rm -f Cow.o Corn.o Wheat.o Pig.o Field.o Barn.o Farm.o Farmer.o main.o FarmSim