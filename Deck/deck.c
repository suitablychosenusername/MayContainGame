#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "deck.h"

// TODO:
// Struct Carta                                         OK
// Struct Deck                                          OK
// Struct Mao                                           OK
// Struct Inventario                                    OK
// Funcao de embaralhar deck
// Funcao de inserir carta do deck                      OK
// Funcao de remover carta do deck                      OK
// Funcao de comprar carta do deck
// Funcao de inserir carta da mao                       OK
// Funcao de remover carta da mao                       OK
// Funcao de usar carta da mao
// Funcao de resetar o inventario para nova batalha

struct deck {
    int inicio, final, qtd;
    Carta info[MAX];
}; // estrutura da fila (Deck)

struct mao {
    Carta info[5];
    int qtd_cartas;
}; // estrutura da lista (Mao)

Inventario *carta_db[16]; // array global que servira de banco de dados das cartas

void cria_db_carta(){
    *carta_db = (Inventario*) malloc(sizeof(Inventario) * 16);

    carta_db[0]->ivcarta.ID_carta = 0;
    strcpy(carta_db[0]->ivcarta.nome_carta, "");
    strcpy(carta_db[0]->ivcarta.elemento_carta, "");
    carta_db[0]->ivcarta.multiplicador_carta = 0;
    strcpy(carta_db[0]->ivcarta.efeito, "");
    strcpy(carta_db[0]->ivcarta.descricao, "");
    carta_db[0]->qtdefault = 99;
    carta_db[0]->qtleft = 99;

    carta_db[1]->ivcarta.ID_carta = 1;
    strcpy(carta_db[1]->ivcarta.nome_carta, "Labareda");
    strcpy(carta_db[1]->ivcarta.elemento_carta, "Fogo");
    carta_db[1]->ivcarta.multiplicador_carta = 1.15;
    strcpy(carta_db[1]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[1]->ivcarta.descricao, "Nivel 1. Serio que voce precisa de uma explicacao pra uma magia com esse nome? Conjura uma labareda. Uau.");
    carta_db[1]->qtdefault = 3;
    carta_db[1]->qtleft = 3;

    carta_db[2]->ivcarta.ID_carta = 2;
    strcpy(carta_db[2]->ivcarta.nome_carta, "Fogo Amigo");
    strcpy(carta_db[2]->ivcarta.elemento_carta, "Fogo");
    carta_db[2]->ivcarta.multiplicador_carta = 1.30;
    strcpy(carta_db[2]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[2]->ivcarta.descricao, "Nivel 2. Conjura um redemoinho de fogo que prende o alvo. Isso que e um abraco caloroso!");
    carta_db[2]->qtdefault = 2;
    carta_db[2]->qtleft = 2;

    carta_db[3]->ivcarta.ID_carta = 3;
    strcpy(carta_db[3]->ivcarta.nome_carta, "Presente dos Ceus");
    strcpy(carta_db[3]->ivcarta.elemento_carta, "Fogo");
    carta_db[3]->ivcarta.multiplicador_carta = 2;
    strcpy(carta_db[3]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[3]->ivcarta.descricao, "Nivel 3. Conjura um meteoro acima da cabeca do alvo. Uuh, fogos de artificio!");
    carta_db[3]->qtdefault = 1;
    carta_db[3]->qtleft = 1;

    carta_db[4]->ivcarta.ID_carta = 4;
    strcpy(carta_db[4]->ivcarta.nome_carta, "Fica Frio Ai");
    strcpy(carta_db[4]->ivcarta.elemento_carta, "Gelo");
    carta_db[4]->ivcarta.multiplicador_carta = 1.15;
    strcpy(carta_db[4]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[4]->ivcarta.descricao, "Nivel 1. Conjura um campo magico de baixa temperatura em volta do alvo, congelando toda a umidade do ar dentro dele.");
    carta_db[4]->qtdefault = 3;
    carta_db[4]->qtleft = 3;

    carta_db[5]->ivcarta.ID_carta = 5;
    strcpy(carta_db[5]->ivcarta.nome_carta, "Rajada Congelante");
    strcpy(carta_db[5]->ivcarta.elemento_carta, "Gelo");
    carta_db[5]->ivcarta.multiplicador_carta = 1.30;
    strcpy(carta_db[5]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[5]->ivcarta.descricao, "Nivel 2. Conjura uma rajada de gelo contra o alvo. Mas nao deixe o nome de enganar, e so um raio frio.");
    carta_db[5]->qtdefault = 2;
    carta_db[5]->qtleft = 2;

    carta_db[6]->ivcarta.ID_carta = 6;
    strcpy(carta_db[6]->ivcarta.nome_carta, "Tempestade de Neve");
    strcpy(carta_db[6]->ivcarta.elemento_carta, "Gelo");
    carta_db[6]->ivcarta.multiplicador_carta = 2;
    strcpy(carta_db[6]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[6]->ivcarta.descricao, "Nivel 3. Conjura uma nevasca sob o alvo. Melhor vestir um casaco!");
    carta_db[6]->qtdefault = 1;
    carta_db[6]->qtleft = 1;

    carta_db[7]->ivcarta.ID_carta = 7;
    strcpy(carta_db[7]->ivcarta.nome_carta, "Choque");
    strcpy(carta_db[7]->ivcarta.elemento_carta, "Elec");
    carta_db[7]->ivcarta.multiplicador_carta = 1.15;
    strcpy(carta_db[7]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[7]->ivcarta.descricao, "Nivel 1. Tao potente quanto uma enfiar o dedo na tomada.");
    carta_db[7]->qtdefault = 3;
    carta_db[7]->qtleft = 3;

    carta_db[8]->ivcarta.ID_carta = 8;
    strcpy(carta_db[8]->ivcarta.nome_carta, "Desfibrilar");
    strcpy(carta_db[8]->ivcarta.elemento_carta, "Elec");
    carta_db[8]->ivcarta.multiplicador_carta = 1.30;
    strcpy(carta_db[8]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[8]->ivcarta.descricao, "Nivel 2. Conjura um relampago diretamente sob o alvo. Alguem pediu por churrasco?");
    carta_db[8]->qtdefault = 2;
    carta_db[8]->qtleft = 2;

    carta_db[9]->ivcarta.ID_carta = 9;
    strcpy(carta_db[9]->ivcarta.nome_carta, "Furia dos Ceus");
    strcpy(carta_db[9]->ivcarta.elemento_carta, "Elec");
    carta_db[9]->ivcarta.multiplicador_carta = 2;
    strcpy(carta_db[9]->ivcarta.efeito, "Ataque");
    strcpy(carta_db[9]->ivcarta.descricao, "Nivel 3. Conjura uma tempestade de relampagos diretamente sob o alvo. Parece que Zeus esta de mau humor!");
    carta_db[9]->qtdefault = 1;
    carta_db[9]->qtleft = 1;

    carta_db[10]->ivcarta.ID_carta = 10;
    strcpy(carta_db[10]->ivcarta.nome_carta, "Luz Divina");
    strcpy(carta_db[10]->ivcarta.elemento_carta, "Cura");
    carta_db[10]->ivcarta.multiplicador_carta = 2;
    strcpy(carta_db[10]->ivcarta.efeito, "Cura");
    strcpy(carta_db[10]->ivcarta.descricao, "Nivel 1. Regenera seu HP muito pouco. Agora voce entende quando dizem \"melhor prevenir do que remediar\", nao e?");
    carta_db[10]->qtdefault = 4;
    carta_db[10]->qtleft = 4;

    carta_db[11]->ivcarta.ID_carta = 11;
    strcpy(carta_db[11]->ivcarta.nome_carta, "Bencao Divina");
    strcpy(carta_db[11]->ivcarta.elemento_carta, "Cura");
    carta_db[11]->ivcarta.multiplicador_carta = 5;
    strcpy(carta_db[11]->ivcarta.efeito, "Cura");
    strcpy(carta_db[11]->ivcarta.descricao, "Nivel 2. Regenera seu HP. Mas nao tem nada de divino aqui. Devo lembra-lo de que voce e um clerigo?");
    carta_db[11]->qtdefault = 2;
    carta_db[11]->qtleft = 2;

    carta_db[12]->ivcarta.ID_carta = 12;
    strcpy(carta_db[12]->ivcarta.nome_carta, "Relaxa, to Full Life");
    strcpy(carta_db[12]->ivcarta.elemento_carta, "Cura");
    carta_db[12]->ivcarta.multiplicador_carta = 999;
    strcpy(carta_db[12]->ivcarta.efeito, "Cura");
    strcpy(carta_db[12]->ivcarta.descricao, "Nivel 3. Cura completamente. So pode ser usada uma vez por dia! Nada melhor do que um dia apos o outro, nao e mesmo?");
    carta_db[12]->qtdefault = 1;
    carta_db[12]->qtleft = 1;

    carta_db[13]->ivcarta.ID_carta = 13;
    strcpy(carta_db[13]->ivcarta.nome_carta, "Escudo Magico");
    strcpy(carta_db[13]->ivcarta.elemento_carta, "Supp");
    carta_db[13]->ivcarta.multiplicador_carta = 0;
    strcpy(carta_db[13]->ivcarta.efeito, "Escudo");
    strcpy(carta_db[13]->ivcarta.descricao, "Conjura um escudo que te protege por 2 turnos. Bem util.");
    carta_db[13]->qtdefault = 2;
    carta_db[13]->qtleft = 2;

    carta_db[14]->ivcarta.ID_carta = 14;
    strcpy(carta_db[14]->ivcarta.nome_carta, "Truque do Coelho na Manga");
    strcpy(carta_db[14]->ivcarta.elemento_carta, "Supp");
    carta_db[14]->ivcarta.multiplicador_carta = 0;
    strcpy(carta_db[14]->ivcarta.efeito, "Saque");
    strcpy(carta_db[14]->ivcarta.descricao, "Lhe permite sacar até duas cartas. O que? Cartola? Nao, nao, nao, voce e um mago, nao um magico!");
    carta_db[14]->qtdefault = 2;
    carta_db[14]->qtleft = 2;

    carta_db[15]->ivcarta.ID_carta = 15;
    strcpy(carta_db[15]->ivcarta.nome_carta, "Punho Firme");
    strcpy(carta_db[15]->ivcarta.elemento_carta, "Supp");
    carta_db[15]->ivcarta.multiplicador_carta = 0;
    strcpy(carta_db[15]->ivcarta.efeito, "Prev");
    strcpy(carta_db[15]->ivcarta.descricao, "Previne que cartas sejam descartadas por 4 turnos. Afinal de contas, como eles te obrigam a fazer isso!?");
    carta_db[15]->qtdefault = 1;
    carta_db[15]->qtleft = 1;

}

void libera_db_carta(){
    free(*carta_db);
}

Deck* cria_deck(){
    Deck* fi = (Deck*) malloc (sizeof(Deck));
    if (fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_deck(Deck* fi){
    free(fi);
}

int deck_cheio(Deck* fi){
    if (fi == NULL)
        return -1;
    return (fi->qtd == MAX);
}

int deck_vazio(Deck* fi){
    if (fi == NULL)
        return -1;
    return (fi->qtd == 0);
}

int insere_deck(Deck* fi, Carta cartaid){
    if (fi == NULL) return -1;
    if (fi->qtd == MAX) return 0;
    fi->info[fi->final] = cartaid;
    fi->final++;
    fi->final%= MAX;
    fi->qtd++;
    return 1;
}

int remove_deck(Deck* fi){
    if (fi == NULL || fi->qtd == 0) return 0;
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qtd--;
    return 1;
}

int consulta_deck(Deck* fi, Carta* i){
    if (fi == NULL || fi->qtd == 0) return 0;
    *i = fi->info[fi->inicio];
    return 1;
}

int embaralha_deck(Deck* fi){
    
}

Mao* cria_mao(){
    Mao* mi = (Mao*) malloc(sizeof(Mao));
    if (mi != NULL)
        mi->qtd = 0;
    return mi;
}

void libera_mao(Mao* mi){
    free(mi);
}

int mao_cheia(Mao* mi){
    if(mi == NULL)
        return -1;
    return (mi->qtd == 5);
}

int mao_vazia(Mao* mi){
    if(mi == NULL)
        return -1;
    return (mi->qtd == 0);
}

int usa_carta(Mao* mi, Carta ci){

}

int descarta_carta(Mao* mi, int index){
    if(mi == NULL)
        return 0;
    if(mao_vazia(mi))
        return 0;
    int i;
    if(index != 4){
        for(i = index; i < mi->qtd - 1; i++)
            mi->info[i].ID_carta = mi->info[i + 1].ID_carta;
    }
    mi->info[i].ID_carta = 00;
    mi->qtd--;
    return 1;
}

int insere_mao(Mao* mi, Carta ci){
    if(mi == NULL)
        return 0;
    if(mao_cheia(mi))
        return 0;
    int j, i;
    for(i = 0; i < mi->qtd; i++){
        if (ci.ID_carta < mi->info[i].ID_carta)
            break;
    }
    for(j = mi->qtd - 1; j >= i; j--)
        mi->info[j + 1] = mi->info[j];
    mi->info[i] = ci;
    mi->qtd++;
    return 1;
}

int compra_carta(Deck* f1, Mao* l1){

}