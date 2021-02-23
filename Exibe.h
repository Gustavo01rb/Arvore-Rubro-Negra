#ifndef _EXIBE_
#define _EXIBE_

#include "Arvore.h"

/*Funções*/
void PreOrdem(Tree **t);
void Central(Tree *t);
void PosOrdem(Tree *t);
void InfoElemento(Tree *t);
void desenha_arvore_horiz(Tree *t, int depth, char *path, int direita, bool x);
void draw_arvore_hor(Tree *arvore, bool x);
/*Fim Funções*/

#include "Exibe.h"

void PreOrdem(Tree **t){
    if(!(*t == NULL)){
        printf("[%d] ", (*t)->dado.key);
        PreOrdem(&(*t)->esq); 
        PreOrdem(&(*t)->dir); 
    }
}
void Central(Tree *t){
    if(!(t == NULL)){
        Central(t->esq); 
        InfoElemento(t);
        Central(t->dir); 
    }
}
void PosOrdem(Tree *t){
    if(!(t == NULL)){
        PosOrdem(t->esq); 
        printf("[%d] ", t->dado.key);
        PosOrdem(t->dir); 
    }
}
void InfoElemento(Tree *t){
    if(t == NULL)
        printf("Saporra nao existe nao o jumento ");
    printf("\n╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
    printf("\n\n\t  Endereco do elemento: %p", t);
    printf("\n\t  Conteúdo (Key) do elemento : %d", t->dado.key);
    printf("\n\t  Cor do elemento: ");
    if( t->cor == true)
        printf("Preto");
    else
        printf("Vermelho");
    printf("\n\n\t  Elemento Direito: %p", t->dir);
    printf("\n\t  Elemento Esquerdo : %p",t->esq);
    printf("\n\t  Elemento pai: %p", t->pai);
    printf("\n╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯ ");
}


void desenha_arvore_horiz(Tree *t, int depth, char *path, int direita, bool x){
    if ( t == NULL)
        return;
    depth++;
    desenha_arvore_horiz( t->dir, depth, path, 1,x);
    path[depth-2] = 0;
    if(direita){ path[depth-2] = 1; } 
    if(t->esq){ path[depth-1] = 1; }
    printf("\n");
    for(int i=0; i<depth-1; i++){
        if(i == depth-2){ printf(" +"); }  
        else if(path[i]){ printf(" |"); }
        else { printf("  "); }
    
        for(int j=1; j<5; j++)
            if(i < depth-2){ printf("  "); }
            else{ printf(" -"); }
        }

        if (x == true ) printf("[%d]\n", t->dado.key);
        else 
            if(t->cor == true) printf("[Preto]\n");
            else if(t->cor == false) printf("[Vermelho]\n");
        
        for(int i = 0; i < depth; i++){
            if(path[i]){ printf(" |"); }
            else{ printf("  "); }
            for(int j = 1; j < 5; j++)
                printf("  ");
        }
    desenha_arvore_horiz(t->esq, depth, path, 0,x);
}

void draw_arvore_hor(Tree *arvore, bool x){
    //true Números 
    //false cores
    char path[255] = {};
        desenha_arvore_horiz(arvore, 0, path, 0,x );
}

#endif