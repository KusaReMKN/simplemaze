CXX=CC
CXXFLAGS=-O -Wall

all: simplemaze

simplemaze: main.cc
	$(CXX) -o simplemaze $(CXXFLAGS) main.cc

clean:
	rm -f simplemaze

distclean: clean
