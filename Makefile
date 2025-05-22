
# Nome do Compilador C++
CXX = g++

# Flags de Compilação
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Bibliotecas a serem linkadas
# Se você tem pkg-config instalado, instale com: sudo apt-get install pkg-config
ALLEGRO_LIBS = $(shell pkg-config --libs allegro-5 allegro_primitives-5 allegro_dialog-5 allegro_main-5)
# Se precisarmos de mais bibliotecas do allegro pode adicionar no futuro

# Adicione outras bibliotecas
LIBS = $(ALLEGRO_LIBS)

# Nome do Executável Final
TARGET = flappyBird

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include # Se você tiver seus próprios cabeçalhos em um diretório 'include'

# Adiciona o diretório de includes ao CXXFLAGS
CXXFLAGS += -I$(INC_DIR)


# Encontra todos os arquivos .cpp no diretório SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Gera a lista de arquivos objeto a partir dos arquivos fonte, colocando-os em OBJ_DIR
# Ex: src/main.cpp -> obj/main.o
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))


all: $(TARGET)

# Regra para linkar o executável final
$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	$(CXX) $^ -o $@ $(LIBS)
	@echo "$(TARGET) built successfully."

# Regra para compilar arquivos .cpp em arquivos .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR) # Cria o diretório obj se não existir
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	@echo "Cleaning up..."
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	@echo "Cleanup complete."

# Regra "phony" para evitar conflitos com arquivos chamados 'all' ou 'clean'
.PHONY: all clean

