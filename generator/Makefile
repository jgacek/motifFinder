#flags from 225 make file tutorial

EXENAME = generate
OBJS = main.o data_generator.o

CXX = clang++
CXXFLAGS = -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp 
	$(CXX) $(CXXFLAGS) main.cpp

 
data_generator.o : data_generator.cpp data_generator.h
	$(CXX) $(CXXFLAGS) data_generator.cpp

 
clean :
	-rm -f *.o $(EXENAME)
