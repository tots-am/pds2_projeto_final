# Nome do Compilador C++
CXX = g++

# Flags de Compilação
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Bibliotecas a serem linkadas
ALLEGRO_LIBS = $(shell pkg-config --libs allegro-5 allegro_primitives-5 allegro_dialog-5 allegro_main-5)

# Outras bibliotecas
LIBS = $(ALLEGRO_LIBS)

# Nome do Executável Final
TARGET = flappyBird

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BUILD_DIR = build

# Caminho completo do executável
TARGET_PATH = $(BUILD_DIR)/$(TARGET)

# Adiciona o diretório de includes ao CXXFLAGS
CXXFLAGS += -I$(INC_DIR)

# Encontra todos os arquivos .cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Gera os arquivos .o em OBJ_DIR
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Regra padrão
all: $(BUILD_DIR) $(OBJ_DIR) $(TARGET_PATH)

# Criação de diretórios
$(BUILD_DIR):
	@mkdir -p $@

$(OBJ_DIR):
	@mkdir -p $@

# Regra para linkar o executável no diretório build
$(TARGET_PATH): $(OBJS)
	@echo "Linking $@..."
	$(CXX) $^ -o $@ $(LIBS)
	@echo "Build successful: $@"

# Compilar .cpp para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR) $(BUILD_DIR)
	@echo "Cleanup complete."

.PHONY: all clean
