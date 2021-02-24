#include "Arvore.h"
#include "Exibe.h"
#include "Insere.h"
#include "Rotacoes.h"


int menu();

int main(){

    int escolha = 0;
    int aux = 0;
    int dados1[] = {1,2,3,4,5,6,7,8,9,10};
    int dados2[] = {10,9,8,7,6,5,4,3,2,1};
    int dados3[] = {56,45,65,23,70,98,100,32,10,50};
    
    capsule temp;
    Tree *raiz;

    raiz = CreateTree();
    
    while(escolha != 10){
        escolha = menu();
        switch(escolha){
            
            case 1:
                printf("\tInforme o numero que deseja inserir: ");
                scanf("%d",&temp.key);
                Insere(&raiz,raiz,temp);
                printf("\n\n\n\n");
                draw_arvore_hor(raiz,true);
            break;
            
            case 2:
                printf("\n\tInforme a quantidade de numeros que deseja inserir: ");
                scanf("%d",&aux);
                while( aux <= 0){
                    printf("\n\tValor invalido, tente somente numeros maiores que 0.\n");
                    scanf("%d",&aux);
                }
                
                printf("\n\tInforme os numeros e em seguida aperte enter. Ira terminar ao atingir %d numeros coletados\nInforme o primeiro: ",aux);
                for(int i = 0; i < aux; i++){ 
                    scanf("%d",&temp.key);
                    Insere(&raiz,raiz,temp);
                }
            break;
            
            case 3:
                printf("\n\t Os seguintes vetores estao pre-definifdos:");
                printf("\n\t Vetor 1: ");
                for(int i = 0; i < 10; i++) printf("[%d] ",dados1[i]);
                printf("\n\t Vetor 2: ");
                for(int i = 0; i < 10; i++) printf("[%d] ",dados2[i]);
                printf("\n\t Vetor 3: ");
                for(int i = 0; i < 10; i++) printf("[%d] ",dados3[i]);
                printf("\n\t Escolha um dos vetores: ");
                scanf("%d",&aux);

                if(aux == 1)
                    for(int i = 0; i < 10; i++){
                        temp.key = dados1[i];
                        Insere(&raiz,raiz,temp);
                    }
                else if(aux == 2)
                    for(int i = 0; i < 10; i++){
                        temp.key = dados2[i];
                        Insere(&raiz,raiz,temp);
                    }
                else
                    for(int i = 0; i < 10; i++){
                        temp.key = dados3[i];
                        Insere(&raiz,raiz,temp);
                    }

                printf("\n\n\n\n");
                draw_arvore_hor(raiz,true);
            break;

            case 4:
                printf("\n\n\n\n");
                draw_arvore_hor(raiz,true);
            break;

            case 5:
                printf("\n\n\n\n");
                draw_arvore_hor(raiz,false);
            break;

            case 6:
                printf("\n\t Metodos de exibicao:");
                printf("\n\n\t  Central: ");
                Central(&(*raiz));
                printf("\n\t  Pre-Ordem: ");
                PreOrdem(&(*raiz));
                printf("\n\t  Pos-Ordem: ");
                PosOrdem(&(*raiz));

            break;

            case 7:
                printf("\n\tInforme o elemento que deseja procurar: ");
                scanf("%d",&temp.key);
                Pesquisa(&raiz, temp);
            break;
        }
    }    
}

int menu(){
    int x;
    printf("\n\n\n╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
    printf("\n\n\t\t  Menu de opcoes ");
    printf("\n\n\t Insercoes:");
    printf("\n\t   [1]-> Inserir um elemento.");
    printf("\n\t   [2]-> Inserir varios elementos.");
    printf("\n\t   [3]-> Inserir Elementos pre definidos");
    printf("\n\n\t Exibicao:");
    printf("\n\t   [4]-> Exibir arvore desenhada com numeros.");
    printf("\n\t   [5]-> Exibir arvore desenhada com cores.");
    printf("\n\t   [6]-> Exibir metodos: Central, Pre-ordem e Pos-Ordem.");
    printf("\n\t   [7]-> Procurar e exibir um elemento em especifico");

    printf("\n╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯ ");
    
    printf("\n\n\tInforme sua escolha: ");
    scanf("%d",&x);
    return x;
}
