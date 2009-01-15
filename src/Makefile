
fontes = $(wildcard *.cpp)

objetos = $(patsubst $.cpp,$.o,$(fontes))

CXXFLAGS=-g -Wall -Wextra -O2 -Wno-unused-parameter
LDFLAGS=-lglut -lILUT -lm

all: $(objetos) main
	mv main ../CG

$(objetos):
	echo $(objetos)

%.o: %.cpp %.h

main: $(objetos)

clear: clean

clean:
	rm *.o main ../CG -fr

