
# Flappy Bird em C++ com Allegro

## 🎮 Visão Geral

Este projeto é uma recriação do clássico jogo *Flappy Bird*, desenvolvido em **C++** utilizando a biblioteca **Allegro 5**. O objetivo é conduzir um pássaro por entre obstáculos móveis (canos), evitando colisões e acumulando pontos. O jogo possui um sistema de perfis, placar de líderes (scoreboard), diferentes skins para o pássaro e uma interface visual completa.

## 🧩 Estrutura e Funcionamento

### Arquitetura do Projeto

O código está dividido em múltiplas classes para garantir organização, modularidade e manutenibilidade:

- **`main.cpp`**: Ponto de entrada do jogo. Controla os estados do jogo (menu, jogando, game over, perfil, placar), inicializa o Allegro e os componentes gráficos.
- **`Bird` (`birdClass.cpp`)**: Responsável por representar o pássaro, incluindo física (gravidade e salto), desenho com spritesheets e detecção de colisão com canos.
- **`Canos` (`canos.cpp`)**: Implementa os obstáculos que o pássaro deve evitar. Gera posições aleatórias e atualiza a movimentação horizontal.
- **`Scoreboard` (`scoreboard.cpp`)**: Lê, grava e exibe pontuações dos jogadores a partir de um banco de dados simples em arquivo (`db.txt`).
- **`Button` (`button.cpp`)**: Componente de interface gráfica para botões clicáveis com texto.
- **`Imagem` (`Imagem.cpp`)**: Facilita o uso e desenho dos sprites.
- **`FontesClass` (`fontesClass.cpp`)**: Facilita o uso e desenho de fontes com diferentes tamanhos e estilos.
- **`DB` (`db.cpp`)**: Gerencia persistência das pontuações em arquivo.

### Estados do Jogo

O jogo alterna entre os seguintes estados:

- `inStartMenu`: Tela inicial com título, instruções e opções para acessar o placar e o perfil.
- `inGame`: Tela de jogo com física e lógica ativa.
- `inGameOver`: Exibe pontuação final e opções de reinício.
- `inScoreBoard`: Mostra os melhores jogadores e suas pontuações.
- `inProfileScreen`: Permite personalizar o nome e a skin do jogador.

### Funcionalidades 

- Sistema de eventos via teclado e mouse.
- Colisões precisas com canos.
- Alteração de skin do pássaro.
- Entrada de nome com edição dinâmica.
- Armazenamento de pontuação persistente.

## ▶️ Como Rodar o Projeto

### 🔧 Requisitos

Antes de compilar o jogo, você deve ter instalado:

- **C++ Compiler** (ex: `g++`)
- **Biblioteca Allegro 5** com os seguintes módulos:
  - `allegro`
  - `allegro_primitives`
  - `allegro_image`
  - `allegro_audio`
  - `allegro_dialog`
  - `allegro_main`
  - `allegro_ttf`

Você pode instalar a Allegro no Ubuntu com:

```bash
sudo apt install liballegro5-dev
```

### 🏗️ Compilação

O projeto inclui um `Makefile` para facilitar a construção. Execute os seguintes comandos no terminal:

```bash
make
./build/flappyBird
```

### 🧹 Limpeza

Para remover os arquivos gerados:

```bash
make clean
```

## 📁 Estrurura de Diretorórios

```
.
├── include/           # Arquivos .hpp
├── src/               # Arquivos .cpp
├── db/
│   └── db.txt         # Arquivo de pontuações
├── obj/               # Objetos compilados
├── build/             # Executável gerado
├── assets/            # Imagens e fontes 
├── tests/             # Doctests das classes
├── Makefile
└── README.md
```


