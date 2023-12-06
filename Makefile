CXX = g++-11 -std=c++20
CXXFLAGS = -MMD -Os
SOURCES = $(wildcard *.cc)
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}
EXEC = chess

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) -lX11

%.o: %.cc 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

-include ${DEPENDS}

.PHONY: clean 
clean:
	rm -f $(OBJECTS) $(DEPENDS) $(EXEC)
