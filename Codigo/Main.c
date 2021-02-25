#include "Arvore.h"
#include "Exibe.h"
#include "Insere.h"
#include "Rotacoes.h"
#include "Remove.h"


int menu();

int main(){

    int escolha = 0;
    int aux = 0;
    int dados3[] = {56,45,65,23,70,98,100,32,10,50};
    
    capsule temp;
    Tree *raiz;

    printf("\n\n--------------------------------------------------------------------------------------------");
    printf("\n\t Arvore Rubro-Negra");
    printf("\n\t Aluno: Gustavo Rodrigues Barcelos");
    printf("\n---------------------------------------------------------------------------------------------");

    printf("\n\n1-> Criando arvore com a funcao create tree");
    raiz = CreateTree();
    printf("\n\tArvore Criada com sucesso!");

    printf("\n\n2->Inserindo a seguinte base de dados: ");
    for(int i = 0; i < 10; i++){
        printf("[%d] ",dados3[i]);
        temp.key = dados3[i];
        Insere(&raiz,raiz,temp);
    }
    printf("\n\tDados Inseridos!");

    printf("\n\n3-> Exibindo arvore a partir de numeros:\n\n");
    draw_arvore_hor(raiz,true);

    printf("\n\n\n\n4-> Exibindo arvore a partir de cores:\n\n");
    draw_arvore_hor(raiz,false);

    printf("\n\n\n\n5-> Exibindo metodos de exibicao convencionais:\n\n");
    printf("\n\t Metodos de exibicao:");
    printf("\n\n\t  Central: ");
    Central(&(*raiz));
    printf("\n\t  Pre-Ordem: ");
    PreOrdem(&(*raiz));
    printf("\n\t  Pos-Ordem: ");
    PosOrdem(&(*raiz));

    printf("\n\n\n\n6->Exibindo o elemento 70 em detalhes:");
    temp.key = 70;
    Pesquisa(&raiz, temp);

    printf("\n\n\n\n7->Removendo os elementos [100] [50] [10]:");
    temp.key = 100;
    RemoveTree(&raiz,temp);
    temp.key = 50;
    RemoveTree(&raiz,temp);
    temp.key = 10;
    RemoveTree(&raiz,temp);
    printf("\n\n\n\n");
    draw_arvore_hor(raiz,true);

    printf("\n\nFim de exibicao, para mais detalhes execute 'Testes.c'\n\n");


}
