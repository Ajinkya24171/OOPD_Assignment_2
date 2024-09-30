CXX = g++

CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp Library.cpp LibraryItem.cpp Book.cpp Journals.cpp PublicationRank.cpp User.cpp classFunctions.cpp functions.cpp

DEBUG_BIN = library_debug
RELEASE_BIN = library_release

debug: CXXFLAGS += -g
debug: $(DEBUG_BIN)

release: CXXFLAGS += -O3
release: $(RELEASE_BIN)

$(DEBUG_BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(RELEASE_BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: rm -f $(DEBUG_BIN) $(RELEASE_BIN)

.PHONY: debug release clean
