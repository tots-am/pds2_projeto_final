# Diretórios
SRC_DIR = ../src
INC_DIR = ../include
OBJ_DIR = ../obj
BUILD_DIR = ../build
TEST_DIR = ./testes

TARGET = $(BUILD_DIR)/test_exec

# Coleta de arquivos fonte (EXCETO main.cpp)
SRC_FILES := $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

# Arquivos objeto
SRC_OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_OBJ := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_FILES))

OBJ := $(SRC_OBJ) $(TEST_OBJ)
DEP := $(OBJ:.o=.d)

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -I$(INC_DIR) -MMD -MP

LDLIBS = -lallegro -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_image -lallegro_main

# Regra principal
all: $(TARGET)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

# Compilação de arquivos .cpp de src e testes
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar diretórios
$(OBJ_DIR) $(BUILD_DIR):
	mkdir -p $@

# Dependências automáticas
-include $(DEP)

# Limpar tudo
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(TARGET)

# Rodar os testes
run: $(TARGET)
	./$(TARGET)
