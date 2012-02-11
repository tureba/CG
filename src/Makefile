
fontes = $(wildcard *.cpp)

objetos = $(patsubst %.cpp,%.o,$(fontes))

CXXFLAGS=-g -Wall -Wextra -O2 -Wno-unused-parameter -DILUT_USE_OPENGL
LDFLAGS=-lglut -lIL -lILUT -lm -lGL -lGLU

all: CG

%.o: %.cpp %.h

CG: $(objetos)
	-g++ -o CG $(objetos) $(LDFLAGS)
	-mv CG ..

clear: clean

clean:
	-rm -f *.o CG

