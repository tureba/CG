MODULES := src

CXXFLAGS := -g -std=c++11 -Wall -Wextra -O2 -Wno-unused-parameter -DILUT_USE_OPENGL

# look for include files in each of the modules
CXXFLAGS += $(patsubst %,-I%,$(MODULES))

# extra libraries if required
LIBS := -lglut -lIL -lILUT -lm -lGL -lGLU

# start with immediate assignment
SRC :=

# include the description for each module
include $(patsubst %,%/module.mk,$(MODULES))

# link the program
CG: $(SRC:.cpp=.o)
	$(CXX) $(LIBS) $^ -o $@

%.o: %.cpp %.h
	$(CXX) -c $(CXXFLAGS) $< -o $@

%.o: %.d

%.d: %.cpp
	$(CXX) -MM -MG -MP $(CXXFLAGS) $< > $@

# include the C include dependencies
include $(SRC:.cpp=.d)

.PHONY: clean depclean
clean:
	@rm -f $(SRC:.cpp=.o) CG

depclean: clean
	@rm -f $(SRC:.cpp=.d)

