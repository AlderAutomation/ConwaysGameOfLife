all: ConwayGOL.out

ConwayGOL.out: ConwayGOL.o GOLWorld.o LifeForm.o
	g++ ConwayGOL.o GOLWorld.o LifeForm.o -o ConwayGOL.out -lsfml-graphics -lsfml-window -lsfml-system

ConwayGOL.o: ConwayGOL.cpp
	g++ -c ConwayGOL.cpp -o ConwayGOL.o

GOLWorld.o: GOLWorld.cpp
	g++ -c GOLWorld.cpp -o GOLWorld.o

LifeForm.o: LifeForm.cpp
	g++ -c LifeForm.cpp -o LifeForm.o

clean:
	rm -f ConwayGOL.out *.o