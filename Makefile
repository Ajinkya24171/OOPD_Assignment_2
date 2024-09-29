CXX = g++

CXXFLAGS = -std=c++17 -Wall

SRC = first.cpp

DEBUG_BIN = first_debug
RELEASE_BIN = first_release

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
