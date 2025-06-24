# Diretórios
SRC_DIR = ../src
INC_DIR = ../include
OBJ_DIR = ../obj
BUILD_DIR = ../build
TEST_DIR = ./testes

TARGET = $(BUILD_DIR)/test_exec

# Coleta de fontes
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
ALL_CPP = $(SRC_FILES) $(TEST_FILES)

# Converte para nomes de objeto únicos no mesmo diretório obj/
OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(ALL_CPP)))
DEP = $(OBJ:.o=.d)

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -I$(INC_DIR) -MMD -MP

LDLIBS = -lallegro -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_image -lallegro_main

# Regra principal
all: $(TARGET)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

# Compilação
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar diretórios se não existirem
$(OBJ_DIR) $(BUILD_DIR):
	mkdir -p $@

# Inclusão de dependências
-include $(DEP)

# Limpeza
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(TARGET)

# Rodar testes
run: $(TARGET)
	./$(TARGET)
