CXX = g++-11 -std=c++20
CXXFLAGS = -Wall -g -MMD -Werror=vla -I/opt/X11/include # use -MMD to generate dependencies (Also might have to add -Werror=vla for graphics)
LDFLAGS = -L/opt/X11/lib     # Added X11 library path
SOURCES = $(wildcard *.cc)   # list of all .cc files in the current directory
OBJECTS = ${SOURCES:.cc=.o}  # .o files depend upon .cc files with same names
DEPENDS = ${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
EXEC=chess

# First target in the makefile is the default target. (Might have to add -lX11 after '-o $(EXEC) for graphics)
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $(EXEC) -lX11

%.o: %.cc 
	$(CXX) -c -o $@ $< $(CXXFLAGS)

-include ${DEPENDS}

.PHONY: clean tests
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)

