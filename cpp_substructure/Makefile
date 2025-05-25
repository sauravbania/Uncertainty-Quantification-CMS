# Compiler and flags
CXX = g++
CXXFLAGS = -O2 -std=c++11

# FastJet installation paths
FASTJET_INC = /Users/sauravbania/fastjet-install/include
FASTJET_LIB = /Users/sauravbania/fastjet-install/lib

# Source files and output
SRC = compute_tauN.cpp
OUT = compute_tauN

# Libraries to link
LIBS = -lfastjet -lNsubjettiness

# Default target
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -I$(FASTJET_INC) -L$(FASTJET_LIB) $(SRC) -o $(OUT) $(LIBS)

# Clean target
clean:
	rm -f $(OUT) *.o