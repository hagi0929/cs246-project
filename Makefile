CXX = g++-11 -std=c++20
INC_DIR = ./include
BUILD_DIR = ./build
CXXFLAGS = -Wall -g -MMD -lX11 -I$(INC_DIR)
SOURCES = $(wildcard src/*.cc)
SOURCES += $(wildcard src/**/*.cc)
SOURCES += $(wildcard src/**/**/*.cc)
OBJS = $(patsubst src/%.cc,$(BUILD_DIR)/%.o,$(SOURCES))
DEPENDS = $(OBJS:.o=.d)
EXEC = chess
D = 0

$(EXEC): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)
	@echo "compiled successfully"

$(BUILD_DIR)/%.o: src/%.cc
	@echo "compiling $<"
	@mkdir -p $(dir $@)
	@$(CXX) -c -o $@ $< $(CXXFLAGS) -DDEBUG=$(D)

-include $(DEPENDS)

.PHONY: clean superclean run runs

clean:
	@rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d $(BUILD_DIR)/**/*.o $(BUILD_DIR)/**/*.d $(BUILD_DIR)/**/**/*.o $(BUILD_DIR)/**/**/*.d

superclean:
	@rm -f /S $(BUILD_DIR)/*

runs:
	@if [ -f "$(EXEC)" ]; then ./$(EXEC); else make; ./$(EXEC); fi

run: $(EXEC)
	@./$(EXEC)
