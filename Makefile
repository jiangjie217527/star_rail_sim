all: char.o skill.o status.o stream.o
	g++ -std=c++17 main.cpp char.o skill.o status.o stream.o

char.o: character_info.cpp
	g++ -std=c++17 -c character_info.cpp -o char.o

skill.o: skill.cpp
	g++ -std=c++17 -c skill.cpp -o skill.o

status.o: Status.cpp
	g++ -std=c++17 -c Status.cpp -o status.o

stream.o: stream.cpp
	g++ -std=c++17 -c stream.cpp -o stream.o

clean:
	rm -rf *.o
