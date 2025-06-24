
# Flappy Bird 

## Visão Geral

Este projeto é uma recriação do clássico jogo *Flappy Bird*, desenvolvido em **C++** utilizando a biblioteca **Allegro 5**. O objetivo é conduzir um pássaro por entre obstáculos móveis (canos), evitando colisões e acumulando pontos. O jogo possui um sistema de perfis, placar de líderes (scoreboard), diferentes skins para o pássaro e uma interface visual completa. 

## Principais dificuldades

Durante o desenvolvimento, tivemos bastante dificuldade inicialmente em dividir a tarefa em problemas menores, e que pudessem ser delegados para os membros.
Isso foi resolvido com a criação do notion do nosso trabalho, que ajudou consideravelmente na nossa organização. Lá, fizemos a modelagem das classes e a criação das histórias de Usuário, que foram transformadas em Cards de tarefas que foram atribuidas a cada membro, o que era feito nas reuniões de planning semanais. Além disso, no notion fizemos o compartilhamento de arquivos, tutoriais, links importantes, e documentos que pudessem ajudar no projeto. Eles podem ser encontrados na aba de materiais.

Outro problema que enfrentamos foi utilizar a biblioteca allegro da maneira correta, e desenvolver no ambiente WSL, uma vez que as funções de tempo do allegro dependem
do time do computador para funcionar. 
Isso foi resolvido quando descobrimos essa funcionalidade e sincronizamos o relogio do computador, eliminando o problema (Inclusive recomendo fazer antes de jogar!).

## Estrutura e Funcionamento

### Arquitetura do Projeto

O código está dividido em múltiplas classes para garantir organização, modularidade e manutenibilidade:

- **`main.cpp`**: Ponto de entrada do jogo. Controla os estados do jogo (menu, jogando, game over, perfil, placar), inicializa o Allegro, os componentes gráficos, dispositivos, também controla o gameloop, onde ocorre a triagem dos eventos na fila de eventos, a lógica de pontuação, e as chamadas de desenho dos elementos graficos de alguns menus, e das entidades que são desenhaveis.
- **`Bird` (`birdClass.cpp`)**: Responsável por representar o pássaro, incluindo física (gravidade e pilo), desenho com spritesheets e detecção de colisão com canos.
- **`Canos` (`canos.cpp`)**: Implementa os obstáculos que o pássaro deve evitar. Gera posições aleatórias e aumenta a velocidade dos canos a medida que o tempo passa.
- **`Scoreboard` (`scoreboard.cpp`)**: Lê, grava e exibe pontuações dos jogadores a partir de um banco de dados simples em arquivo (`db.txt`).
- **`Button` (`button.cpp`)**: Componente de interface gráfica para botões clicáveis com texto.
- **`Imagem` (`Imagem.cpp`)**: Facilita o uso e desenho dos sprites.
- **`FontesClass` (`fontesClass.cpp`)**: Facilita o uso e desenho de fontes com diferentes tamanhos e estilos.
- **`DB` (`db.cpp`)**: Interage com o arquivo database e realiza as operações de CRUD.
- **`constants.hpp`**: Arquivo que guarda todas as constantes usadas no jogo, como caminhos para assets, fps, velocidade do cano, gravidade, e etc.

### Estados do Jogo

O jogo alterna entre os seguintes estados:

- `inStartMenu`: Tela inicial com título, instruções e opções para acessar o placar e o perfil.
- `inGame`: Tela de jogo com física e lógica ativa.
- `inGameOver`: Exibe pontuação final e opções de reinício.
- `inScoreBoard`: Mostra os cinco melhores jogadores e suas maiores pontuações.
- `inProfileScreen`: Permite personalizar o nome e a skin do jogador.

### Funcionalidades Base

- Sistema de eventos via teclado.
- Colisões com canos.
- Entrada de nome.
- Armazenamento de pontuação persistente.

### Funcionalidades Extras

- Sistema de perfil com nome e caixa de textos funcionais.
- Menu de customização do Passaro.
- Implementação de uma UI completa com botões, graficos, e imagens.
- Sprites do passaro atraves de uma spritesheet.
- Sistema de dificuldade que aumenta a velocidade do cano com base no tempo que o usuario sobreviveu.

## Como Rodar o Projeto

### Requisitos

Antes de compilar o jogo, você deve ter instalado:

- **C++ Compilador** (ex: `g++`)
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

Também é recomendado que se atualize o tempo do computador com a internet (No windows, é feito em Configurações -> Data e Hora -> Horario na Internet -> Sincrinizar), para garantir que as funções do allegro que definem a framerate e o timer funcionem adequadamente.

### Compilação

O projeto inclui um `Makefile` para facilitar a construção. Execute os seguintes comandos no terminal:

```bash
make
./build/flappyBird
```

### Limpeza

Para remover os arquivos gerados:

```bash
make clean
```

## Estrurura de Diretorórios

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


