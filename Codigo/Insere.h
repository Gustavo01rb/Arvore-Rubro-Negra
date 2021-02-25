#ifndef __INSERE__
#define __INSERE__

#include "Arvore.h"
#include "Rotacoes.h" 
#include"Exibe.h"


void Caso1(Tree **no);
void Caso2(Tree **no);
void Caso3(Tree **no);
void Caso4(Tree **no);
void Caso5(Tree **no);

void Insere(Tree **t, Tree *pai, capsule c){
    if(*t == NULL){
        *t = (Tree *)malloc(sizeof(Tree));
        (*t)->dado.key = c.key;
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->pai = pai;
        (*t)->cor = false;
    }else{
        if((*t)->dado.key > c.key){ Insere(&(*t)->esq, (*t), c); }
        if((*t)->dado.key < c.key){ Insere(&(*t)->dir, (*t), c); }
    }
   Caso1(t);
}

void Caso1(Tree **t){
    Tree *no = (*t);
    if(no->pai == NULL)
        no->cor = true;
    else 
        Caso2(t);
}

void Caso2(Tree **t){
    Tree *no = (*t);
    if(no->pai->cor == true)
        return;
    else 
        Caso3(t);
}

void Caso3(Tree **t){
    Tree *no = (*t);
    Tree *ti = tio(no);
    if( (ti != NULL) && ti->cor == false){
        no->pai->cor = true;
        ti->cor = true;
        Tree *av = avo(no);
        av->cor = false;
        Caso1(&av);
    }else
        Caso4(t);
}

void Caso4(Tree **t){
    Tree *no = (*t);
    Tree *vo = avo(no);

    if( (no->pai->esq == no) && (vo->dir == no->pai) ){ RSD(&no->pai); no = no->dir;} 
    if( (no->pai->dir == no) && (vo->esq == no->pai) ){ RSE(&no->pai); no = no->esq;}

    Caso5(&no);
}

void Caso5(Tree **t){
    Tree *no = (*t);
    Tree *vo = avo(no);
    Tree *pai = no->pai;

    if(vo == NULL ) return;

    
    if(vo->pai != NULL){ 
        vo->cor = false;
        pai->cor = true;
    }

    if( (no->pai->dir == no) && (vo->dir == no->pai)) RSE(&no->pai);
    else RSD(&no->pai);

}

#endif