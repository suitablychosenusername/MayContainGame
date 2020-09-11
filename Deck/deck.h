#ifndef DECK_H
#define DECK_H
#define MAX 30
#define RAND_MAX 15

// TODO:
// Funcao de embaralhar deck
// Funcao de resetar o inventario para nova batalha

typedef struct carta {
    int ID_carta; // id utilizado para procurar cartas no array db
    char nome_carta[31]; // nome da carta, para display
    char elemento_carta[5]; // elemento da carta, para o calculo de dano
    float multiplicador_carta; // valor do multiplicador para o calculo de dano
    char efeito[8]; // tipo da carta, usado para definir acao no combate
    char descricao[120]; // descricao da carta. para display
} Carta; // estrutura da carta

typedef struct inventario{
    int qtleft; // qtd restante da carta para ser embaralhadas
    int qtdefault; // qtd padrao para resetar 
    Carta ivcarta; // criar um vetor Inventario e uma funcao random pra montar o deck
} Inventario; // estrutura do array que servira de banco de dados das cartas

typedef struct deck Deck; // ponteiro de fila estatica para o Deck
typedef struct mao Mao; // ponteiro de lista estatica para a Mao

// cria o db de cartas para ser puxado no deck
void cria_db_carta();

// libera o db de cartas
void libera_db_carta();

// cria o ponteiro para o deck
Deck* cria_deck();

// libera o ponteiro;
void libera_deck(Deck* fi);

// testa se deck esta cheio
int deck_cheio(Deck* fi);

// testa se deck esta vazio
int deck_vazio(Deck* fi);

// insere carta no deck
int insere_deck(Deck* fi, Carta cartaid);

// remove carta do deck
int remove_deck(Deck* fi);

// consulta o valor da primeira carta no deck
int consulta_deck(Deck* fi, Carta* i);

// embaralha o deck
int embaralha_deck(Deck* fi);

// cria o ponteiro para a mao
Mao* cria_mao();

// libera o ponteiro da mao
void libera_mao(Mao* mi);

// testa se mao esta cheia
int mao_cheia(Mao* mi);

// testa se mao esta vazia
int mao_vazia(Mao* mi);

// utiliza a carta, remove da mao, ativa seu efeito
int usa_carta(Mao* mi, Carta ci);

// remove carta da mao
int descarta_carta(Mao* mi, int index);

// adiciona carta a mao
int insere_mao(Mao* mi, Carta ci);

// adicionar carta a mao e remove do deck
int compra_carta(Deck* f1, Mao* l1);

#endif