CXX = clang++ -std=c++17

INCLUDE = -I.

LIBS = -lsfml-graphics -lsfml-window -lsfml-system Settings.o src/*.o

main: Player.o Settings.o main.cpp
	$(CXX) $(INCLUDE) $@.cpp -o $@ $(LIBS)

Settings.o: Settings.hpp Settings.cpp
	$(CXX) -c $(INCLUDE) Settings.cpp -o Settings.o

Player.o: src/Player.hpp src/Player.cpp
	$(CXX) -c $(INCLUDE) src/Player.cpp -o src/Player.o

.PHONY:
clean:
	$(RM) src/*.o *.o main