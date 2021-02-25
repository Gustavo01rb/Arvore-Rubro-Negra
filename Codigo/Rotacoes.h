#ifndef __ROTACOES__
#define __ROTACOES__

#include "Arvore.h"

/*Funções*/
void RSD(Tree **t); //Rotação Simples a Direita
void RSE(Tree **t); //Rotação Simples a Esquerda
void RDD(Tree **t); //Rotação Dupla a Direita
void RDE(Tree **t); // Rotação Dupla a Esquerda
/*Fim Funções*/


/*Rotaçẽos Simples*/

void RSD(Tree **t){
    Tree *no = (*t);
    Tree *aux = no->pai;
    Tree *vo = avo(no);
    if(no->pai->esq == no){
        if( avo(no) != NULL){
            Tree *sub = (Tree *)malloc(sizeof(Tree));
            vo->esq = no;
            no->pai = vo;
            sub->pai = no;
            sub->dado = aux->dado;
            sub->esq = no->dir;
            sub->dir = aux->dir;
            no->dir = sub;
            free(aux);
        }else{
            /*Swap*/
                capsule temp;
                temp = aux->dado;
                aux->dado = no->dado;
                no->dado = temp;
            /*Fim Swap*/
            aux->esq = no->esq;
            aux->esq->pai = aux;
            no->esq = no->dir;
            no->dir = aux->dir;
            if(no->dir != NULL)
                no->dir->pai = no;
            aux->dir = no;
        }
    }else if(no->pai->dir == no){
        aux = no->esq;
        no->pai->dir = aux;
        aux->pai = no->pai;
        no->esq = aux->dir;
        aux->dir = no;     
        no->pai = aux;   
    }
}

void RSE(Tree **t){
    Tree *no = (*t);
    Tree *aux = no->pai;
    Tree *vo = avo(no);
    if(no->pai->dir == no){
        if( vo != NULL){
            Tree *sub = (Tree *)malloc(sizeof(Tree));
            vo->dir = no;
            no->pai = vo;
            sub->pai = no;
            sub->cor = aux->cor;
            sub->dado = aux->dado;
            sub->dir = no->esq;
            sub->esq = aux->esq;
            no->esq = sub;
            free(aux);
        }else{
            /*Swap*/
                capsule temp;
                temp = aux->dado;
                aux->dado = no->dado;
                no->dado = temp;
            /*Fim Swap*/
            aux->dir = no->dir;
            aux->dir->pai = aux;
            no->dir = no->esq;
            no->esq = aux->esq;
            if(no->esq != NULL)
                no->esq->pai = no;
            aux->esq = no;
        }
    }else if(no->pai->esq == no){
        aux = no->dir;
        no->pai->esq = aux;
        aux->pai = no->pai;
        no->dir = aux->esq;
        aux->esq = no;     
        no->pai = aux;   
    }

}

/*Fim Rotações Simples*/

/*Rotações Duplas*/

void RDD(Tree **t){
    RSE(t);
    RSD(&(*t)->esq);
}

void RDE(Tree **t){
    RSD(t);
    RSE(&(*t)->dir);
}

/*Fim Rotações Duplas*/
#endif