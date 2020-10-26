# MayContainGame
Feito por:
* Cinthia Mie Nagahama Ungefehr
* Fabio Henrique Ayres Lapa
* Maycon Douglas Medeiros<br>
----------------------------------------
Projeto final da disciplina de EDA

## Instruções de Compilação:
    
    Utilizado a biblioteca Simple DirectMedia Layer (SDL).
    Licenciada sob direitos zlib (http://www.zlib.net/zlib_license.html)
    E disponibilizada gratuitamente em: https://www.libsdl.org/
    
    ! Para a compilação, será necessário a instalação do SDL2 e de suas extensões, SDL2_image, SDL2_ttf e SDL2_mixer !
    
    | Para instalar os pacotes do SDL2 e de suas extensões no Ubuntu:
    |        
    |    sudo apt install libsdl2-dev libsdl2-2.0-0 libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 \
    |        libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev \
    |        libsdl2-mixer-2.0-0 libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0
    |
    
    Extraia os arquivos em uma pasta e abra o diretório onde extraiu os arquivos no terminal;
    Utilize a seguinte linha de comando:
    
        gcc Sound.c deck.c Inimigo.c main.c -o main -Wall -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
        
    Depois execute o arquivo main criado
    
    ! OBS: Já existe um arquivo main compilado na raiz do projeto. !
    
    | As dev-tools do SDL também se encontram na pasta SDL do projeto, teoricamente para facilitar a compilação no Windows (embora não obtivemos sucesso).
    | É possível, entretanto, compilar um código para o Windows por meio de compilação cruzada no Linux, utilizando o MinGW w64. Para isso, basta executar
    | o seguinte comando (assumindo que você está no diretório do projeto):

        {$PLAT}-w64-mingw32-gcc {$ARQUIVOSC} -o NOMESAIDA -Wall \
            -I./SDL/SDL2-2.0.12/{$PLAT}-w64-mingw32/include/SDL2 -L./SDL/SDL2-0.2.12/{$PLAT}-w64-mingw32/lib \
            -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -mwindows

        De acordo com o sistema, PLAT e ARQUIVOSC deverão ser substituídos conforme o seguinte:
        - Para 32-bits:
            PLAT = i686
            ARQUIVOSC = Soundwin.c deckwin.c Inimigowin.c mainwin.c
        - Para 64-bits:
            PLAT = x86_64
            ARQUIVOSC = Soundwin64.c deckwin64.c Inimigowin64.c mainwin64.c
     
     ! OBS: Já existem dois arquivos compilados para Windows: mainwin.exe para 32-Bits e mainwin64.exe para 64-bits. !
     
     Para rodar no Windows, é necessário que todos os respectivos arquivos *.dll estejam na pasta raiz.
     Basta copiar todos os arquivos da pasta dll_X-bits (X de acordo com o sistema) e os colar na raiz do projeto.
     
     Alternativamente, adicione a pasta dll_X-bits na variável de ambiente PATH padrão do Windows (NÃO-RECOMENDADO).
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
