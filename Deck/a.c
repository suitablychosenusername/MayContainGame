#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "deck.c" // preciso usar esse include pra rodar o debugger aqui
#include "deck.h"

// void imprime_deck(Deck* fi){
//     int i, tam = fi->qtd;
//     for(i = fi->inicio; tam > 0; i = (i + 1) % 30, tam--){
//         printf("Carta %i: %i | ", i, fi->info[i]);
//     }
//     printf("\n");
// }

// void imprime_mao(Mao* mi){
//     int i, tam = 5;
//     printf("Mao:\n");
//     for(i = 0; i < tam; i++)
//         printf("ID: %i | Nome: %s | Elem: %s | Efeito: %s | Mult: %.02f\nDesc:\n%s\n", mi->info[i].ID_carta, mi->info[i].nome_carta, mi->info[i].elemento_carta, mi->info[i].efeito, mi->info[i].multiplicador_carta, mi->info[i].descricao);
// }

int main(void)
{   
    // arquivo de testes so para verificar se as funcoes estao ok
    srand(time(0));
    cria_db_carta(); // OK
    Deck* fi;
    fi = cria_deck(); // OK
    Mao* mi;
    mi = cria_mao(); // OK
    int x, consultaid;
    x = inicializa_deck(fi); // OK
    printf("Deck vazio: %i\n", deck_vazio(fi));
    printf("Deck cheio: %i\n", deck_cheio(fi));
    // imprime_deck(fi);
    x = embaralha_deck(fi); // OK
    // imprime_deck(fi);
    printf("mao 1:\n");
    // imprime_mao(mi);
    x = compra_carta(fi, mi); // OK
    x = compra_carta(fi, mi);
    x = compra_carta(fi, mi);
    x = compra_carta(fi, mi);
    x = compra_carta(fi, mi);
    printf("Mao vazia: %i\n", mao_vazia(mi));
    printf("Mao cheia: %i\n", mao_cheia(mi));
    printf("mao 2:\n");
    // imprime_deck(fi);
    // imprime_mao(mi);
    x = embaralha_deck(fi); // OK
    x = usa_carta(mi, 3, &consultaid); // OK
    printf("Deck vazio: %i\n", deck_vazio(fi)); // OK
    printf("Deck cheio: %i\n", deck_cheio(fi)); // OK
    printf("Mao vazia: %i\n", mao_vazia(mi)); // OK
    printf("Mao cheia: %i\n", mao_cheia(mi)); // OK
    printf("efeito: %s\n", carta_db[consultaid].carta_info.efeito);
    // imprime_mao(mi);
    // imprime_deck(fi);
    reseta_db(); // OK
    esvazia_deck(fi); // OK
    // imprime_deck(fi);
    inicializa_deck(fi); // OK
    // imprime_deck(fi);
    libera_mao(mi); // OK
    libera_deck(fi); // OK
    reseta_db();
    fi = cria_deck();
    x = inicializa_deck(fi);
    mi = cria_mao();
    x = compra_carta(fi, mi);
    x = compra_carta(fi, mi);
    x = compra_carta(fi, mi);
    // imprime_deck(fi);
    // imprime_mao(mi);
    libera_deck(fi);
    libera_mao(fi);
    libera_db_carta(); // OK
    return 0;
}