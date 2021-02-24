#ifndef _REMOVE__
#define _REMOVE_

#include "Arvore.h"
#include "Rotacoes.h" 
#include"Exibe.h"

void RemoveTree(Tree **t, capsule c);
void Predecessor(Tree **t, Tree *aux);


void RemoveTree(Tree **t, capsule c){
            
    Tree *aux;
    if( *t == NULL){
        printf("\n\nERRO: Dado inexistente ou nao gravado");
        return;
    }
    if((*t)->dado.key > c.key){ RemoveTree(&(*t)->esq, c); return; }
    if((*t)->dado.key < c.key){ RemoveTree(&(*t)->dir, c); return; }
    if((*t)->dir == NULL){
        aux = *t;
        *t = (*t)->esq;
        free(aux);
        return;
    }
    if((*t)->esq != NULL){ Predecessor(&(*t)->esq, *t); return; }
    
    aux = *t;  
    *t = (*t)->dir;
    free(aux);
    }
void Predecessor(Tree **t, Tree *aux){
    if((*t)->dir != NULL){
        Predecessor(&(*t)->dir, aux);
        return;
    }
    aux->dado = (*t)->dado;
    aux = *t;
    *t = (*t)->esq;
    free(aux);
}

#endif