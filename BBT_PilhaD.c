#include <stdio.h>
#include <stdlib.h>

typedef struct sComandosPilha{

    int movimento, quantidade;

}ComandosPilha;

typedef struct sPilha{
    
    ComandosPilha info;
    struct sPilha *prox;
 
}Pilha;

void inicializarPilha( Pilha **ptrLista ){
    
    *ptrLista = NULL;

}

Pilha *alocarNoPilha()
{

    return (Pilha*) malloc ( sizeof(Pilha) );
}

void desalocarNoPilha( Pilha *ptrLista ){   

    free(ptrLista);

}

int pilhaVazia( Pilha *ptrLista ){

    if( ptrLista == NULL ) return 1;
    else return 0;

}

void empilhar(Pilha **topo, ComandosPilha elem){

    Pilha *novo;

    novo = alocarNoPilha();

    if(novo != NULL){

        novo->info = elem;
        novo->prox = *topo;
        *topo = novo;

    }else{
        printf("Erro ao alocar no\n");
    }

}

ComandosPilha desempilhar(Pilha **topo){
    
    if(!pilhaVazia(*topo)){

        ComandosPilha L;
        Pilha *aux;
        aux = *topo;

        *topo = aux->prox;

        L = aux->info;

        desalocarNoPilha(aux);

        return L;

    }else{
        
        printf("Pilha vazia!\n");
    
    }
    
}

void impressaoClassicaPilha(Pilha **topo){
    
    if(!pilhaVazia(*topo)){
        printf("Sua solucao para esse problema foi:\n");
        while(!pilhaVazia(*topo)){
            printf("Movimento 1: %d\nRepetir: %dx\n", (*topo)->info.movimento, (*topo)->info.quantidade);
            desempilhar(topo);
        }
    }else{
        printf("Lista vazia!\n");
    }

}

void impressaoNaoClassicaPilha(Pilha *pilha){
    
    if(!pilhaVazia(pilha)){
        
        Pilha *aux;
        aux = pilha;

        while (aux != NULL){
            printf("Comando: %d executara %dx\n", aux->info.movimento, aux->info.quantidade);
            aux = aux->prox;
        }
        
    }else{
        printf("Pilha vazia!\n");
    }

}

void retornaTopo(Pilha *topo){

    if(!pilhaVazia(topo)) printf("Comando: %d executara %dx\n", topo->info.movimento, topo->info.quantidade);
    else printf("\nLista vazia!\n"); 

}