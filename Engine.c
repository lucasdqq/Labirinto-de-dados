#include "BBT_FilaD.c"
#include "BBT_PilhaD.c"
#include "Tabuleiro.c"



int fase_1(Tabuleiro **tabuleiro, Jogador **jogador){

    ComandosFila aux;
    aux.movimento = 0;
    
    Fila *ptrFila;
    ptrFila = (Fila *)malloc(sizeof(Fila));
    
    inicializaFila(ptrFila); 
    inicializaTabuleiro( tabuleiro );
    
    strcpy((*tabuleiro)->comandos[0], "F, F, F");
    strcpy((*tabuleiro)->comandos[1], "F, F, D");
    strcpy((*tabuleiro)->comandos[2], "F, F, E");
    strcpy((*tabuleiro)->comandos[3], "D, D");
    imprimeTabuleiro(*tabuleiro, *jogador);

    printf("Informe suas jogadas para a fase 1, para finalizar insira -1 no comando a ser utilizado.\n");
    while(aux.movimento != -1){   
        do{
            printf("Qual o comando ira utilizar?\n");
            scanf("%d", &aux.movimento);
            if(aux.movimento < -1 || aux.movimento > 4) printf("Comando nao existe. Tente novamente.\n");
        }while (aux.movimento < -1 || aux.movimento > 4);
            if( aux.movimento == -1 ) break;
        
        
        do{
            printf("Quantas vezes ira utilizar o %do comando?\n", aux.movimento);
            scanf("%d", &aux.quantidade);
            if(aux.quantidade < 1) printf("Quantidade invalida, tente novamente\n");
        } while (aux.quantidade < 1);
        
        
        enfileirar(ptrFila, aux);
        
        imprimeTabuleiro(*tabuleiro, *jogador);
        
    }

    while (!filaVazia(ptrFila)){

        for (int i = 0; i < ptrFila->inicio->info.quantidade; i++){
            int j = 0;
            while ((*tabuleiro)->comandos[ptrFila->inicio->info.movimento - 1][j] != '\0') {
                executaMovimento( tabuleiro, jogador,(*tabuleiro)->comandos[ptrFila->inicio->info.movimento - 1][j]);
                j++;
            }
        }
        desenfilera(ptrFila);
    }

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && 
        (*jogador)->posicaoV == tam_tabuleiro-1) return 0;
    else{
        (*jogador)->vidas -= 1;
        (*jogador)->jogadorDirecao = jogador_direita;
        imprimirFraseFinal(4);
        return (*jogador)->vidas;
    } 

}

int fase_2(Tabuleiro **tabuleiro, Jogador **jogador){

    ComandosPilha aux;
    aux.movimento = 0;
    
    Pilha *ptrPilha;
    inicializarPilha(&ptrPilha);
    
    inicializaTabuleiro( tabuleiro );
    
    strcpy((*tabuleiro)->comandos[0], "F, F, F");
    strcpy((*tabuleiro)->comandos[1], "D, F");
    strcpy((*tabuleiro)->comandos[2], "E, F");
    strcpy((*tabuleiro)->comandos[3], "D, D");
    imprimeTabuleiro(*tabuleiro, *jogador);
    
    printf("Informe suas jogadas para a fase 2, para finalizar insira -1 no comando a ser utilizado.\n");
    while(aux.movimento != -1){   

        printf("Qual o comando ira utilizar?\n");
        scanf("%d", &aux.movimento);
        if( aux.movimento == -1 ) break;
        
        printf("Quantas vezes ira utilizar o %do comando?\n", aux.movimento);
        scanf("%d", &aux.quantidade);
        
        empilhar(&ptrPilha, aux);
        
        imprimeTabuleiro(*tabuleiro, *jogador);
        
    }
    while (ptrPilha != NULL){

        for (int i = 0; i < ptrPilha->info.quantidade; i++){
            int j = 0;
            while ((*tabuleiro)->comandos[ptrPilha->info.movimento - 1][j] != '\0') {
                executaMovimento( tabuleiro, jogador,(*tabuleiro)->comandos[ptrPilha->info.movimento - 1][j]);
                j++;
            }
        }
        desempilhar(&ptrPilha);
    }

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && (*jogador)->posicaoV == tam_tabuleiro-1) 
        return 0;
    else{
        (*jogador)->vidas -= 1;
        (*jogador)->jogadorDirecao = jogador_direita;
        imprimirFraseFinal(4);
        return (*jogador)->vidas;
    } 

}

int fase_3(Tabuleiro **tabuleiro, Jogador **jogador){

    ComandosFila aux;
    aux.movimento = 0;
    
    Fila *ptrFila;
    ptrFila = (Fila *)malloc(sizeof(Fila));
    
    inicializaFila(ptrFila); 
    inicializaTabuleiro( tabuleiro );
    
    strcpy((*tabuleiro)->comandos[0], "F, F");
    strcpy((*tabuleiro)->comandos[1], "D, F, F");
    strcpy((*tabuleiro)->comandos[2], "E, F, E");
    strcpy((*tabuleiro)->comandos[3], "E, E");
    imprimeTabuleiro(*tabuleiro, *jogador);

    printf("Informe suas jogadas para a fase 3.1 (ida), para finalizar insira -1 no comando a ser utilizado.\n");
    while(aux.movimento != -1){   
        
        printf("Qual o comando ira utilizar?\n");
        scanf("%d", &aux.movimento);
        if( aux.movimento == -1 ) break;
        
        printf("Quantas vezes ira utilizar o %do comando?\n", aux.movimento);
        scanf("%d", &aux.quantidade);
        
        enfileirar(ptrFila, aux);
        
        imprimeTabuleiro(*tabuleiro, *jogador);
        
    }

    while (!filaVazia(ptrFila)){

        for (int i = 0; i < ptrFila->inicio->info.quantidade; i++){
            int j = 0;
            while ((*tabuleiro)->comandos[ptrFila->inicio->info.movimento - 1][j] != '\0') {
                executaMovimento( tabuleiro, jogador,(*tabuleiro)->comandos[ptrFila->inicio->info.movimento - 1][j]);
                j++;
            }
        }
        desenfilera(ptrFila);
    }

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && 
        (*jogador)->posicaoV == tam_tabuleiro-1){

            ComandosPilha aux;
            aux.movimento = 0;
            
            Pilha *ptrPilha;
            inicializarPilha(&ptrPilha);
            inicializaTabuleiro( tabuleiro );
            (*jogador)->posicaoH = tam_tabuleiro-1;
            (*jogador)->posicaoV = tam_tabuleiro-1;
            (*tabuleiro)->local[tam_tabuleiro-1][tam_tabuleiro-1] = player;
            (*tabuleiro)->local[0][0] = objetivo;
                
            strcpy((*tabuleiro)->comandos[0], "F, F, F");
            strcpy((*tabuleiro)->comandos[1], "F, F, D");
            strcpy((*tabuleiro)->comandos[2], "F, F, E");
            strcpy((*tabuleiro)->comandos[3], " ");
            imprimeTabuleiro(*tabuleiro, *jogador);
                
            printf("Informe suas jogadas para a fase 3.2 (volta), para finalizar insira -1 no comando a ser utilizado.\n");
            while(aux.movimento != -1){   

                printf("Qual o comando ira utilizar?\n");
                scanf("%d", &aux.movimento);
                if( aux.movimento == -1 ) break;
                    
                printf("Quantas vezes ira utilizar o %do comando?\n", aux.movimento);
                scanf("%d", &aux.quantidade);
                    
                empilhar(&ptrPilha, aux);
                    
                imprimeTabuleiro(*tabuleiro, *jogador);
                    
            }
            while (ptrPilha != NULL){

                for (int i = 0; i < ptrPilha->info.quantidade; i++){
                    int j = 0;
                    while ((*tabuleiro)->comandos[ptrPilha->info.movimento - 1][j] != '\0') {
                        executaMovimento( tabuleiro, jogador,(*tabuleiro)->comandos[ptrPilha->info.movimento - 1][j]);
                        j++;
                    }
                }
                desempilhar(&ptrPilha);
            }


            if ((*jogador)->posicaoH == 0 && (*jogador)->posicaoV == 0) 
                return 0;
            else{
                (*jogador)->vidas -= 1;
                (*jogador)->jogadorDirecao = jogador_esquerda;
                imprimirFraseFinal(4);
                return (*jogador)->vidas;
            } 
        } 
    else{
        (*jogador)->vidas -= 1;
        (*jogador)->jogadorDirecao = jogador_direita;
        imprimirFraseFinal(4);
        return (*jogador)->vidas;
    } 

}

void executa(Tabuleiro **tabuleiro, Jogador **jogador){

    int continuar;
    
    inicializaJogador(jogador);
    
    while (continuar){
    
        continuar = fase_1( tabuleiro, jogador );
        if (continuar == -3) {
            imprimirFraseFinal(5);
            break;
        }
    
    }
    if (continuar != -3){
    
        // system("cls");
        imprimirFraseFinal(1);
        inicializaJogador(jogador);
        
        do{
            continuar = fase_2( tabuleiro, jogador );
            if (continuar == -3) {
                imprimirFraseFinal(5);
                break;
            }
        }while (continuar);
        
    }
    if (continuar != -3){
    
        // system("cls");
        imprimirFraseFinal(2);
        inicializaJogador(jogador);
    
        do{
            continuar = fase_3( tabuleiro, jogador );
            if (continuar == -3) {
                imprimirFraseFinal(5);
                break;
            }
        }while (continuar);
        
    }
    if (continuar != -3){
        
    
        system("cls");
        imprimirFraseFinal(3);
    
    }

}

