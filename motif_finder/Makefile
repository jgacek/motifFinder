#Thank you 225 for letting me use your flags
EXENAME = find
OBJS = main.o motif_finder.o

CXX = clang++
CXXFLAGS = -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y 

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp


motif_finder.o : motif_finder.cpp motif_finder.h
	$(CXX) $(CXXFLAGS) motif_finder.cpp


clean :
	-rm -f *.o $(EXENAME)
