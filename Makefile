# Compiler and flags
CXX = g++
CXXFLAGS = -g --std=c++20 -Wall

# Phony targets (not actual files)
.PHONY: all clean tests

# Default target
all: game game_set

# Build game_set using card and main_set
game_set: card.o main_set.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build game using card, card_list, and main
game: card.o card_list.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build and run tests
tests: card.o card_list.o tests.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	./tests

# Pattern rule for compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f game_set game tests *.o
