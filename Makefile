CXX = g++-11 -std=c++20
INC_DIR = ./include
CXXFLAGS = -Wall -g -MMD -lX11 -I$(INC_DIR)
SOURCES = $(wildcard **/*.cc)
OBJS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJS:.o=.d}
EXEC=chess
D = 0

$(EXEC): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) 
	@rm -f $(OBJS) $(DEPENDS)
	@echo "compiled successfully"

%.o: %.cc
	@echo "compiling..."
	@$(CXX) -c -o $@ $< $(CXXFLAGS) -DDEBUG=$(D)

-include ${DEPENDS}

.PHONY: clean run runs

clean:
	@rm -f $(OBJS) $(DEPENDS)

superclean:
	@rm -f $(OBJS) $(DEPENDS) $(EXEC)

run:
	@if [ -f "$(EXEC)" ]; then ./$(EXEC); else make; ./$(EXEC); fi

runs: $(EXEC)
	@./$(EXEC)
