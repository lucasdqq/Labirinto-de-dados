#include <stdio.h>
#include <stdlib.h>

typedef struct sComandosFila{

    int movimento, quantidade;

}ComandosFila;

typedef struct sNo{

    ComandosFila info;
    struct sNo *prox;

}NOFila;

typedef struct sFila{

    NOFila *inicio;
    NOFila *final;

}Fila;

NOFila* alocaNoFila(){

    return (NOFila*) malloc(sizeof(NOFila));

}

void inicializaFila(Fila *ptrF){

    ptrF->inicio = NULL;
    ptrF->final = NULL;

}

int filaVazia(Fila *ptrF){

    if (ptrF->inicio == NULL) return 1;
    
    return 0;

}

void enfileirar(Fila *ptr, ComandosFila elem){

    NOFila *novo;
    novo = alocaNoFila();
    
    if (novo != NULL){
        
        novo->info = elem;
        novo->prox = NULL;
        
        if (filaVazia(ptr)){

            ptr->inicio = novo;
            ptr->final = novo;
        
        }
        else{
        
            (ptr->final)->prox = novo;
            ptr->final = novo;
        
        }
    
    }
    else{
        
        printf("Problema na alocacao\n");
    
    }
}

void desenfilera(Fila *ptrF){
 
    if(!filaVazia(ptrF)){

        NOFila *novo;
        novo = alocaNoFila();
        
        novo = ptrF->inicio;
        ptrF->inicio = ptrF->inicio->prox;

        if(ptrF->inicio == NULL){
            ptrF->final = NULL;
        }    
        free(novo);

    }else{
        printf("Fila vazia!\n");
    }
    
}

void listaClassico(Fila *ptrF){
    
    if(!filaVazia(ptrF)){

        while (!filaVazia(ptrF)){
            printf("movimento %d %dx\n", ptrF->inicio->info.movimento,ptrF->inicio->info.quantidade);
            desenfilera(ptrF);
        }
        
    }else{
        printf("Fila vazia!\n");
    }

}
