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
Tree* CreateTree();
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
/*Fim Parentes do nó*/

#endif