#CS 225 has nice flags to use 
EXENAME1 = overlap
EXENAME2 = relative_entropy
OBJS1 = overlap.o 
OBJS2 = relative_entropy.o

CXX = clang++
CXXFLAGS = -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++

all : $(EXENAME1) $(EXENAME2)

$(EXENAME1) : $(OBJS1)
	$(LD) $(OBJS1) $(LDFLAGS) -o $(EXENAME1)

$(EXENAME2) : $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o $(EXENAME2)

overlap.o : overlap.cpp
	$(CXX) $(CXXFLAGS) overlap.cpp

relative_entropy.o : relative_entropy.cpp
	$(CXX) $(CXXFLAGS) relative_entropy.cpp

clean :
	-rm -f *.o $(EXENAME)
