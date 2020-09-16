#ifndef DECK_H
#define DECK_H

typedef struct carta {
    int ID_carta; // id utilizado para procurar cartas no array carta_db; ID = index da carta no array
    char nome_carta[31]; // nome da carta, para display
    char elemento_carta[5]; // elemento da carta, para o calculo de dano
    float multiplicador_carta; // valor do multiplicador para o calculo de dano
    char efeito[8]; // tipo da carta, usado para definir acao no combate
    char descricao[120]; // descricao da carta, para display
} Carta; // estrutura da carta

typedef struct databasecarta{
    int qtleft; // qtd restante da carta a ser embaralhada
    int qtdefault; // qtd padrao para resetar 
    Carta carta_info; // dados da carta
} DatabaseCarta; // estrutura do array global que servira de banco de dados das cartas

typedef struct deck Deck; // ponteiro de fila estatica para o Deck
typedef struct mao Mao; // ponteiro de lista estatica para a Mao

DatabaseCarta* carta_db;

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
int insere_deck(Deck* fi, int cartaid);

// remove carta do deck
int remove_deck(Deck* fi);

// consulta o valor da primeira carta no deck e salva por referencia
int consulta_deck(Deck* fi, int *cartaid);

// prepara e embaralha o deck a primeira vez na luta
int inicializa_deck(Deck* fi);

// embaralha o deck a partir da condicao atual do mesmo
int embaralha_deck(Deck* fi);

// esvazia o deck apos a batalha para uma nova inicializacao
int esvazia_deck(Deck* fi);

// reseta o array banco de dados de cartas para uma nova inicializacao
int reseta_db();

// cria o ponteiro para a mao
Mao* cria_mao();

// libera o ponteiro da mao
void libera_mao(Mao* mi);

// testa se mao esta cheia
int mao_cheia(Mao* mi);

// testa se mao esta vazia
int mao_vazia(Mao* mi);

// remove carta da mao
int descarta_carta(Mao* mi, int index);

// adiciona carta a mao
int insere_mao(Mao* mi, int cartaid);

// consulta a carta de indice index da mao
int consulta_mao(Mao* mi, int index, int *idconsulta);

// adicionar carta a mao e remove do deck
int compra_carta(Deck* f1, Mao* m1);

// utiliza a carta do indice index e a remove da mao
// (copia o id para idconsulta para extrair info do array carta_db)
int usa_carta(Mao* mi, int index, int *idconsulta);

#endif