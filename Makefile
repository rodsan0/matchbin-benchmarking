# Project-specific settings
PROJECT := FILLIN
EMP_DIR := Empirical/source

# Flags to use regardless of compiler
CFLAGS_all := -Wall -Wno-unused-function -pedantic -std=c++17 -I$(EMP_DIR)/ -I./source/

# Native compiler information
CXX_nat := g++
CFLAGS_nat := -O3 -msse4.2 -DNDEBUG $(CFLAGS_all)

benchmark: main.cc
	$(CXX_nat) $(CFLAGS_nat) main.cc -o benchmark.out

# Debugging information
print-%: ; @echo '$(subst ','\'',$*=$($*))'
