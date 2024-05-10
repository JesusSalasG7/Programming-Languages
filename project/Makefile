CXX = clang++ -std=c++17

INCLUDE = -I.

LIBS = -lsfml-graphics -lsfml-window -lsfml-system Settings.o

main: Settings.o main.cpp
	$(CXX) $(INCLUDE) $@.cpp -o $@ $(LIBS)

Settings.o: Settings.hpp Settings.cpp
	$(CXX) -c $(INCLUDE) Settings.cpp -o Settings.o

.PHONY:
clean:
	$(RM) src/*.o *.o main