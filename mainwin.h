#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "SDL\\SDL2-2.0.12\\i686-w64-mingw32\\include\\SDL2\\SDL.h"
#include "SDL\\SDL2-2.0.12\\i686-w64-mingw32\\include\\SDL2\\SDL_image.h"
#include "SDL\\SDL2-2.0.12\\i686-w64-mingw32\\include\\SDL2\\SDL_mixer.h"
#include "SDL\\SDL2-2.0.12\\i686-w64-mingw32\\include\\SDL2\\SDL_ttf.h"

/* DECK */

typedef struct carta {
    int ID_carta; // id utilizado para procurar cartas no array carta_db; ID = index da carta no array
    char nome_carta[31]; // nome da carta, para display
    char elemento_carta[5]; // elemento da carta, para o cálculo de dano
    int multiplicador_carta; // valor do multiplicador para o cálculo de dano
    char efeito[8]; // tipo da carta, usado para definir ação no combate
    char descricao[151]; // descrição da carta, para 
    char path[35]; // caminho da textura
    int range;
    int rangemin;
    int sfx;
} Carta; // estrutura da carta

typedef struct databasecarta{
    int qtleft; // qtd restante da carta a ser embaralhada
    int qtdefault; // qtd padrao para resetar 
    Carta carta_info; // dados da carta
} DatabaseCarta; // estrutura do array global que servirá de banco de dados das cartas

typedef struct elemento{
    int info;
    struct elemento* prox;
} Elem;

struct fila_deck {
    int qtd;
    Elem* inicio;
    Elem* final;
}; // estrutura da fila (Deck)

struct mao {
    Carta info[5];
    int qtd_cartas;
}; // estrutura da lista (Mao)

typedef struct fila_deck Deck; // ponteiro de fila estática para o Deck
typedef struct mao Mao; // ponteiro de lista estática para a Mao

extern DatabaseCarta* carta_db; // variável global que será usada como database das cartas

// cria o db de cartas
void cria_db_carta();

// libera o db de cartas
void libera_db_carta();

// cria o ponteiro para o deck
Deck* cria_deck();

// libera o ponteiro;
void libera_deck(Deck* fi);

// testa se deck está cheio
int deck_cheio(Deck* fi);

// testa se deck está vazio
int deck_vazio(Deck* fi);

// insere carta no deck
int insere_deck(Deck* fi, int idcarta);

// remove carta do deck
int remove_deck(Deck* fi);

// consulta o valor da primeira carta no deck e o salva por referência
int consulta_deck(Deck* fi, int *idcarta);

// retorna quantidade de cartas no deck
int qtd_deck(Deck* fi);

// prepara e embaralha o deck a primeira vez na luta
int inicializa_deck(Deck* fi);

// embaralha o deck à partir da condição atual do mesmo
int embaralha_deck(Deck* fi);

// esvazia o deck após a batalha para uma nova inicialização
// (pode ser usado o libera_deck, porém, será necessário utilizar cria_deck novamente)
int esvazia_deck(Deck* fi);

// reseta o array banco de dados de cartas para uma nova inicialização
void reseta_db();

// cria o ponteiro para a mão
Mao* cria_mao();

// libera o ponteiro da mão
void libera_mao(Mao* mi);

// testa se mão está cheia
int mao_cheia(Mao* mi);

// testa se mão está vazia
int mao_vazia(Mao* mi);

// remove carta da mao
int descarta_carta(Mao* mi, int index);

// adiciona carta à mão
int insere_mao(Mao* mi, int idcarta);

// consulta a carta de índice = index da mão
int consulta_mao(Mao* mi, int index, int *idconsulta);

// retorna quantidade de cartas na mao
int qtd_mao(Mao* mi);

// adiciona carta à mão e remove do deck
int compra_carta(Deck* f1, Mao* m1);

// utiliza a carta de índice = index e a remove da mão
// (copia o id para idconsulta para extrair info do array carta_db)
int usa_carta(Mao* mi, int index, int *idconsulta);

// coloca uma carta da mao no deck
int mao_para_deck(Deck* fi, Mao* mi, int index);

// imprime mao (desnecessario in-game; só para testes mesmo)
void imprime_mao(Mao* mi);

// imprime deck (desnecessario in-game; só para testes mesmo)
void imprime_deck(Deck* fi);

/* INIMIGO */

enum MOVES{
    ATTACK,
    MUG,
    FLEE,
    SPECIAL_MOVE,
    DEFEND,
    SHUFFLE,
};

typedef struct moveset{
    int mult_atk;
    int discard_num;
    int steal_chance;
    int mult_special;
    int flee_chance;
    int mult_defend;
    char nome_special[35];
} Moveset;

typedef struct chance{
    int min;
    int max;
} Chance;

typedef struct inimigo{
    char nome[15];
    int HP;
    int ATK;
    int DEF;
    int buffdefault;
    int RElemento[3];
    char path[40];
    int w;
    int h;
    Chance chance[6];
    Moveset comportamento;
    int scream;
} Inimigo;

typedef struct inimigoBatalha{
    int hp;
    int id;
    int buff;
    int buffCount;
    int bolado;
    int turno;
    int derrotado;
    int alpha;
    int fleeCount;
} InimigoBatalha;

Inimigo* inimigo_db;

void cria_db_inimigo();

void libera_db_inimigo();

void imprime_inimigo();

/* AUDIO */

enum commands{
    PLAY,
    PAUSE,
    STOP,
};

enum bgm{
    MENU,
    BATTLE,
    BATTLE_CRISIS,
    BOSS_THEME,
    BOSS_CRISIS,
    BATTLE_WON,
    GAME_OVER,
    TOTAL_BGM,
};

enum sfx{
    TITLE_START,
    HIT,
    HIT_CRIT,
    HIT_PROTEC,
    CAST,
    HEAL,
    HEAL_FULL,
    FIRE1,
    FIRE2,
    FIRE3,
    ICE1,
    ICE2,
    ICE3,
    ELEC1,
    ELEC2,
    ELEC3,
    SUPP_ESCUDO,
    SUPP_PREV,
    SUPP_TRICK,
    HP_LOW,
    MONSTER_HIT,
    MONSTER_CRIT,
    MONSTER_STEAL,
    MONSTER_FLEE,
    DEATH_PINGUIM,
    DEATH_LADRAO,
    DEATH_GOBLIN,
    DEATH_ABU,
    TOTAL_SFX,
};

// Audio
Mix_Music **gBGM;

// SFX
Mix_Chunk **gSFX;

int loadSounds();

void closeSounds();

void controlBGM(int bgmID, int command);

void playSFX(int sfxID);

/* MAIN */

typedef struct player{
    int hp;
    int hpmax;
    int atk;
    int def;
    int turno;
    int tutorial;
    int mainMenu;
    int gameOver;
} Player;

typedef struct seletor{
    int ativoc;
    int ativoe;
    int indexc;
    int indexe;
    int escudo;
    int prev;
    int animation;
    int absorb;
    int primeiroTurno;
    int crisis;
    int playerDMG;
} Seletor;

enum ICON_NUM {
    SHIELD_ICON,
    PREV_ICON
};

typedef struct animation{
    int alpha;
    int r;
    int g;
    int b;
    SDL_Rect clip;
    SDL_Rect size;
} Animation;

extern const int SCR_WID;
extern const int SCR_HEI;

// window
SDL_Window *gWindow;
// window surface
SDL_Surface *gSurface;
// imagem atual
SDL_Surface *gCurrentSurface;
// Renderer
SDL_Renderer *gRenderer;
// Texturas
SDL_Texture *gLogo1;
SDL_Texture *gLogo2;
SDL_Texture *gArrow;
SDL_Texture *gBGTexture;
SDL_Texture **gEnemyTexture;
SDL_Texture *gBoxTexture;
SDL_Texture *gNameBoxTexture;
SDL_Texture *gMenuBoxTexture;
SDL_Texture *gBattleBoxTexture;
SDL_Texture **gIconTexture;
SDL_Texture **gCardTexture;
SDL_Texture *gModTexture;
SDL_Texture *gFakeRect;
SDL_Texture *gCurrentScene;
// Fonte
TTF_Font *gFont;
// rendered texture
SDL_Texture *gFontTexture;
// Viewports    
    extern const SDL_Rect logo1VP;
    extern const SDL_Rect logo2VP;
    extern const SDL_Rect battleBGVP;
    extern const SDL_Rect menuVP;
    extern const SDL_Rect statsVP;
    extern const SDL_Rect stockVP;
    extern const SDL_Rect enemyAreaVP;
    extern const SDL_Rect msgAreaTopVP;
    extern const SDL_Rect msgAreaBottomVP;
    SDL_Rect arrowVP;
// Cores
    extern const SDL_Color color;
    extern const SDL_Color black;
    extern const SDL_Color blue;
    extern const SDL_Color sky;
    extern const SDL_Color green;
    extern const SDL_Color red;
    extern const SDL_Color yellow;

// SDL basico - inicializa API
int init();

// SDL basico - Carrega textura
SDL_Texture* loadTexture(char* path);

// renderiza text sem wrap
int renderTexto(char *string, SDL_Color cor);

// renderiza texto com wrap
int renderTextoWrapped(char *string, SDL_Color cor);

// SDL Basic - carrega midia (imagens, sprites, sons, etc)
int loadMediaBasic();

// Carrega textura on-demand
void loadMediaCurrentTexture(char *path);

// Basico SDL - fecha janela e libera memoria alocada para as midias
void closeWindow();

// Detecta se cursor esta sobre o objeto
int mouseOver(SDL_Rect *button, SDL_Event *e);

// Detecta clique sobre inimigo
int mouseOverClickEnemy(SDL_Rect *button, SDL_Event *e);

// Detecta clique sobre carta
int mouseOverClickCard(SDL_Rect *button, SDL_Event *e);

// Converte Itoa
void antiMingwItoa(char *string, int x);

// Limpa render
void renderClear();

// Render com wrapping
void renderMessageWrapped(char *msg, SDL_Rect *Viewport);

// Render texto com contorno
void renderPrintOutline(char* msg, const SDL_Color *cor, const SDL_Color *corOutline, int sizeOutline, SDL_Rect *textArea);

// Fade In e Fade Out
void fadeInOut(int r, int g, int b, int alpha);

// Tela de Titulo
void mainMenu(Player *player, SDL_Event *e, int* quit);

// Tela de Game Over
void gameOver(SDL_Event *e);

// Funcao render mensagem de batalha
void renderBattleMessage(char *msg, const SDL_Rect *Viewport, int center);

// Funcao render cena de batalha
void renderBattle(Player *player, SDL_Event *e, Deck **deck, Mao **mao, SDL_Rect *enemyVP, SDL_Rect *cardAreaVP, InimigoBatalha* inimigos, int numeroInimigos, Seletor* select);

// Inicializa ponteiros de deck e mao
void battleInit(Deck **fi, Mao **li);

// Reseta ponteiros de Deck e Mao apos batalha
void battleEnd(Deck **fi, Mao **li);

// Calculo de dano
int calculoDano(Player *player, int idcarta, InimigoBatalha *inimigos, Seletor *select, int *critical);

// Funcao batalha
int battleOn(Player *player, SDL_Event *e, int *quit, int boss);

#endif