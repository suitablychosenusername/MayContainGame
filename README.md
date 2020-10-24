# MayContainGame
Feito por:
* Cinthia Mie Nagahama Ungefehr
* Fabio Henrique Ayres Lapa
* Maycon Douglas Medeiros<br>
----------------------------------------
Projeto final da disciplina de EDA

## Instruções de Compilação:
    Até o momento, funcionando somente no Linux (Ubuntu 16.04);
    
    Utilizado a biblioteca Simple DirectMedia Layer (SDL).
    Licenciada sob direitos zlib (http://www.zlib.net/zlib_license.html)
    E disponibilizada gratuitamente em: https://www.libsdl.org/
    
    Extraia os arquivos em uma pasta e, através do terminal, navegue até o diretório onde extraiu os arquivos.
    Utilize a seguinte linha de comando:
    
        gcc deck.c Inimigo.c main.c -o main -Wall -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
        
    Depois execute o arquivo main criado
----------------------------------------
## Objetivos:

- [ ] ~~História (textual)~~
    - [ ] ~~Passagem de tempo (4 partes)~~
    - [X] Implementação de Função para Impressão
    - [ ] ~~Escrita dos Diálogos das Quests~~
        - [ ] ~~Quest 1~~
        - [ ] ~~Quest 2~~
        - [ ] ~~Quest 3~~
    - [ ] ~~Implementação dos Diálogos das Quests~~
        - [ ] ~~Quest 1~~
        - [ ] ~~Quest 2~~
        - [ ] ~~Quest 3~~
    - [ ] ~~Definição dos Pontos de Possíveis Batalhas~~
        - [ ] ~~Quest 1~~
        - [ ] ~~Quest 2~~
        - [ ] ~~Quest 3~~
- [X] Cartas (9 de Ataque | 3 de Defesa | 3 de Cura)
- [X] Inimigos (4 tipos de inimigos)
    - [X] Stats
    - [X] Comportamento
- [X] Fluxo de Batalha
    - [X] Preparação do Deck
    - [X] Geração de Inimigos
    - [X] Funções de Controle do Deck
    - [X] Implementação dos Efeitos das Cartas
        - [X] Ataque
        - [X] Cura
        - [X] Saque
        - [X] Previne
        - [X] Escudo
    - [X] Cálculo de Dano Player
    - [X] Cálculo de Dano Inimigos
    - [X] Funções de Operações do Player
    - [X] Funções de Operações dos Inimigos<br>
----------------------------------------
* Opcionais:

- [ ] UI
    - [ ] ~~Historia~~
        - [ ] ~~Sprites~~
            - [ ] ~~Background~~
            - [ ] ~~Menu~~
            - [ ] ~~Player~~
            - [ ] ~~NPCs~~
            - [X] ~~Textboxes~~
    - [X] Batalha
        - [X] Sprites
            - [X] Cartas
            - [X] Inimigos
            - [X] Menu
            - [X] Background
            - [X] Textboxes
            - [X] Efeitos
        - [x] Animações
            - [X] Início da batalha
                - [X] Fade-in background
                - [X] Fade-in inimigos
            - [X] Ataque Player
            - [ ] ~~Cartas~~
            - [X] Ataque Inimigo
            - [X] Inimigo Derrotado
            - [X] Fim da batalha# MayContainGame
