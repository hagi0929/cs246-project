CXX = g++-11 -std=c++20
INC_DIR = ./include
BUILD_DIR = ./build
CXXFLAGS = -Wall -g -MMD -I$(INC_DIR)
SOURCES = $(wildcard src/*.cc)
SOURCES += $(wildcard src/**/*.cc)
SOURCES += $(wildcard src/**/**/*.cc)
OBJS = $(patsubst src/%.cc,$(BUILD_DIR)/%.o,$(SOURCES))
DEPENDS = $(OBJS:.o=.d)
EXEC = chess
D = 0

$(EXEC): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -lX11 -o $(EXEC)
	@echo "compiled successfully"

$(BUILD_DIR)/%.o: src/%.cc
	@echo "compiling $<"
	@mkdir -p $(dir $@)
	@$(CXX) -c -o $@ $< $(CXXFLAGS) -DDEBUG=$(D)

-include $(DEPENDS)

.PHONY: clean superclean run runs test vtest

clean:
	@rm -f -r $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d $(BUILD_DIR)/**/*.o $(BUILD_DIR)/**/*.d $(BUILD_DIR)/**/**/*.o $(BUILD_DIR)/**/**/*.d

superclean:
	@rm -f -r /S $(BUILD_DIR)/*

runs:
	@if [ -f "$(EXEC)" ]; then ./$(EXEC); else make; ./$(EXEC); fi

run: $(EXEC)
	@./$(EXEC)

test: $(EXEC)
	./$(EXEC) < ./tests/test.in

vtest: $(EXEC)
	@valgrind ./$(EXEC) < ./tests/test.in
