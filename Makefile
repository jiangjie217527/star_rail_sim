all: char.o skill.o status.o stream.o
	g++ main.cpp char.o skill.o status.o stream.o

char.o: character_info.cpp
	g++ -c character_info.cpp -o char.o

skill.o: skill.cpp
	g++ -c skill.cpp -o skill.o

status.o: Status.cpp
	g++ -c Status.cpp -o status.o

stream.o: stream.cpp
	g++ -c stream.cpp -o stream.o

clean:
	rm -rf *.o
