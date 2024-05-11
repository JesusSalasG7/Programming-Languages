CXX = clang++ -std=c++17

INCLUDE = -I.

BUILD_DIR = build

OBJ_RULES = Settings.o Game.o Player.o World.o ControlPanel.o Instructions.o Play.o PlayButton.o

LIBS = -lsfml-graphics -lsfml-window -lsfml-system $(BUILD_DIR)/*.o

main: $(BUILD_DIR) $(OBJ_RULES) main.cpp
	$(CXX) $(INCLUDE) $@.cpp -o $@ $(LIBS)

Settings.o: $(BUILD_DIR) Settings.hpp Settings.cpp
	$(CXX) -c $(INCLUDE) Settings.cpp -o $(BUILD_DIR)/$@

Game.o: $(BUILD_DIR) src/Game.hpp src/Game.cpp
	$(CXX) -c $(INCLUDE) src/Game.cpp -o $(BUILD_DIR)/$@

Player.o: $(BUILD_DIR) src/Player.hpp src/Player.cpp
	$(CXX) -c $(INCLUDE) src/Player.cpp -o $(BUILD_DIR)/$@

World.o: $(BUILD_DIR) src/World.hpp src/World.cpp
	$(CXX) -c $(INCLUDE) src/World.cpp -o $(BUILD_DIR)/$@

ControlPanel.o: $(BUILD_DIR) src/ControlPanel.hpp src/ControlPanel.cpp
	$(CXX) -c $(INCLUDE) src/ControlPanel.cpp -o $(BUILD_DIR)/$@

Instructions.o: $(BUILD_DIR) src/Instructions.hpp src/Instructions.cpp
	$(CXX) -c $(INCLUDE) src/Instructions.cpp -o $(BUILD_DIR)/$@
	
Play.o: $(BUILD_DIR) src/Play.hpp src/Play.cpp
	$(CXX) -c $(INCLUDE) src/Play.cpp -o $(BUILD_DIR)/$@


PlayButton.o: $(BUILD_DIR) src/PlayButton.hpp src/PlayButton.cpp
	$(CXX) -c $(INCLUDE) src/PlayButton.cpp -o $(BUILD_DIR)/$@

$(BUILD_DIR):
	mkdir -p $@

.PHONY:
clean:
	$(RM) $(BUILD_DIR)/*.o main