# Nome do Compilador C++
CXX = g++

# Flags de Compilação
CXXFLAGS = -std=c++11 -Wall -Wextra -g -Iinclude

# Bibliotecas a serem linkadas
ALLEGRO_LIBS = $(shell pkg-config --libs allegro-5 allegro_primitives-5 allegro_image-5 allegro_audio-5 allegro_dialog-5 allegro_main-5 allegro_ttf-5)
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

# Lista de arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos objeto correspondentes
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Regra principal
all: $(BUILD_DIR) $(OBJ_DIR) $(TARGET_PATH)

# Criação de diretórios
$(BUILD_DIR):
	@mkdir -p $@

$(OBJ_DIR):
	@mkdir -p $@

# Linka o executável
$(TARGET_PATH): $(OBJS)
	@echo "Linking $@..."
	$(CXX) $^ -o $@ $(LIBS)
	@echo "Build successful: $@"

# Compila arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regras de dependência manual
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/birdClass.hpp $(INC_DIR)/canos.hpp
$(OBJ_DIR)/canos.o: $(SRC_DIR)/canos.cpp $(INC_DIR)/canos.hpp
$(OBJ_DIR)/birdClass.o: $(SRC_DIR)/birdClass.cpp $(INC_DIR)/birdClass.hpp

# Limpeza
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR) $(BUILD_DIR)
	@echo "Cleanup complete."

.PHONY: all clean
