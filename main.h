#ifndef MAIN_H
#define MAIN_H

#include "SDL/SDL2-2.0.12/i686-w64-mingw32/include/SDL2/SDL.h"
#include "SDL/SDL2-2.0.12/i686-w64-mingw32/include/SDL2/SDL_image.h"
#include "SDL/SDL2-2.0.12/i686-w64-mingw32/include/SDL2/SDL_mixer.h"
#include "SDL/SDL2-2.0.12/i686-w64-mingw32/include/SDL2/SDL_ttf.h"
#include "deck.h"
#include "Inimigo.h"

const int SCR_WID = 1280;
const int SCR_HEI = 750;

enum ICON_NUM {
    SHIELD_ICON,
    PREV_ICON
};

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
} Seletor;

typedef struct animation{
    int alpha;
    int r;
    int g;
    int b;
    SDL_Rect clip;
    SDL_Rect size;
} Animation;

// window
SDL_Window *gWindow = NULL;
// window surface
SDL_Surface *gSurface = NULL;
// imagem atual
SDL_Surface *gCurrentSurface = NULL;
// Renderer
SDL_Renderer *gRenderer = NULL;
// Texturas
SDL_Texture *gTexture = NULL;
SDL_Texture *gBGTexture = NULL;
SDL_Texture **gEnemyTexture = NULL;
SDL_Texture *gBoxTexture = NULL;
SDL_Texture *gNameBoxTexture = NULL;
SDL_Texture *gMenuBoxTexture = NULL;
SDL_Texture *gBattleBoxTexture = NULL;
SDL_Texture **gIconTexture = NULL;
SDL_Texture **gCardTexture = NULL;
SDL_Texture *gModTexture = NULL;
SDL_Texture *gExpressionBoxTexture = NULL;
SDL_Texture *gFakeRect = NULL;
SDL_Texture *gCurrentScene = NULL;
// Fonte
TTF_Font *gFont = NULL;
// rendered texture
SDL_Texture *gFontTexture = NULL;
// Viewports
    const SDL_Rect battleBGVP = {0, 0, 1280, 582};
    const SDL_Rect menuVP = {0, 562, 1280, 187};
    const SDL_Rect statsVP = {0, 562, 213, 187};
    const SDL_Rect stockVP = {248, 562, 1056, 187};
    const SDL_Rect enemyAreaVP = {120, 30, 1040, 532};
    const SDL_Rect msgAreaTopVP = {190, 30, 900, 160};
    const SDL_Rect msgAreaBottomVP = {190, 570, 900, 160};
// Cores
    const SDL_Color color = {200,200,200};
    const SDL_Color black = {0,0,0};
    const SDL_Color blue = {20,20,204};
    const SDL_Color green = {0,128,0};
    const SDL_Color red = {204,0,0};
    const SDL_Color yellow = {204,204,0};

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