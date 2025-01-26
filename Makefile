# Author: Gladys Monagan
# Do post anywhere

.PHONY: all unit run check clean remove 

DEBUG  = -g

VERSION = -std=c++17

CXX = g++

CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DEBUG)

LFLAGS = $(VERSION) $(DEBUG)

SRC = inflation

INCS = $(SRC).h

SRCS = $(SRC).cpp

OBJS = $(SRCS:.cpp=.o)

# make object files (.o) from sources (.cpp)
%.o:%.cpp $(INCS)
	$(CXX) $(CFLAGS) -c $< -o $@

# an executable without any doctests
TEST_PROG = test_$(SRC)

# an executable produced with doctests
UNITTEST = unittest_$(SRC)

all: $(SRCS) $(TEST_PROG)

# goal should be called unittest but to prevent so much typing use unit
unit: $(SRCS) $(UNITTEST)

# for Windows, execute the goal unit and run the program
run: unit
	$(UNITTEST).exe

# for PowerShell, Linux and MacOS, execute the goal unit and run the program
check: unit
	./$(UNITTEST)

$(UNITTEST).o : $(INCS) $(UNITTEST).cpp
	$(CXX) $(CFLAGS) -c $(UNITTEST).cpp -o $@

$(UNITTEST) : $(OBJS)  $(UNITTEST).o
	$(CXX) $(LFLAGS) $^ -o $@

$(TEST_PROG).o : $(INCS) $(TEST_PROG).cpp
	$(CXX) $(CFLAGS) -c $(TEST_PROG).cpp -o $@

$(TEST_PROG) : $(OBJS) $(TEST_PROG).o
	$(CXX) $(LFLAGS) $^ -o $@

# for Windows and PowerSehll
clean:
	del $(UNITTEST).exe $(TEST_PROG).exe *.o  /Q
	@echo clean done

# for Linux and MacOS
remove:
	\rm -f $(UNITTEST) $(TEST_PROG) *.o
	@echo remove done

# This content is protected and may not be shared, uploaded, or distributed.
# 2024 copyright Gladys Monagan
