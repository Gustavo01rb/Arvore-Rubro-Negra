#ifndef _ARVORE_
#define _ARVORE_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct capsule capsule;
typedef struct Tree Tree;

struct capsule{
    int key;
    int value;
};
struct Tree{
    capsule dado;
    bool cor; // false = vermelho; true = preto
    Tree *esq;
    Tree *dir;
    Tree *pai;
};

/*Funções*/
Tree* avo(Tree *t);
Tree* tio(Tree *t);
Tree* irmao(Tree *t);
Tree* CreateTree();
void Pesquisa(Tree **t, capsule c);
void InfoElemento(Tree *t);
/*Fim FUnções*/

Tree* CreateTree(){
    return NULL;
}

/*Parentes do nó*/
Tree* avo(Tree *t){
    if(  (t != NULL) && (t->pai != NULL) )
        return t->pai->pai;
    else
        return NULL;
}

Tree* tio(Tree *t){
    Tree *aux = avo(t);
    if( aux == NULL)
        return NULL;
    if( t->pai == aux->dir)
        return aux->esq;
    else
        return aux->dir;
}
Tree* irmao(Tree *t){
    if(t->pai->dir == t) return t->pai->esq;
    else return t->pai->dir;
}

/*Fim Parentes do nó*/

void Pesquisa(Tree **t, capsule c){
    if( *t == NULL){
        printf("\n\nERRO: Dado inexistente ou nao gravado\n");
        return;
    }

    if((*t)->dado.key > c.key){ Pesquisa(&(*t)->esq, c); return; }
    if((*t)->dado.key < c.key){ Pesquisa(&(*t)->dir, c); return; }
    
    InfoElemento( (*t) );
}
void InfoElemento(Tree *t){
    printf("\n\n\t\tElemento encontrado:");
    printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
    printf("\n\n\t\t  Endereco do elemento: %p", t);
    printf("\n\t\t  Conteúdo (Key) do elemento : %d", t->dado.key);
    printf("\n\t\t  Cor do elemento: ");
    if( t->cor == true)
        printf("Preto");
    else
        printf("Vermelho");

    printf("\n\n\t\t  Filho Direito: %p", t->dir);
    if(t->dir != NULL)
        printf("\tConteudo: %d",t->dir->dado.key);
    printf("\n\t\t  Filho Esquerdo : %p",t->esq);
    if(t->esq != NULL)
        printf("\tConteudo: %d",t->esq->dado.key);
    printf("\n\t\t  Elemento pai: %p", t->pai);
    if(t->pai != NULL)
        printf("\tConteudo: %d",t->pai->dado.key);
    printf("\n\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n\n ");
}

#endif