#include <stdbool.h>
#include <stdio.h>

void imprimirTabuleiro(int tabuleiro[3][3]);
bool menu(int continuar);

int main(){
    int tabuleiro[3][3] = {0};
    int vez = 0;
    bool continuar;

    imprimirTabuleiro(tabuleiro);
    
    //perguntar se o usuário deseja começar um jogo novo ou sair.
    if(menu(continuar)){

    }
    
    return 0;
}

void imprimirTabuleiro(int tabuleiro[3][3]){
    int j = 0;
    int a = 0;

    for(int k = 0; k < 3; k++){     
        for(int i = 0; i < 3; i++){     
            j = 0;  
            a = 0;    
                
            while(j<3){     
                printf(" ");
                j++ ;       
            }       
                
            if(i < 2){      
                printf("|") ;    
            }       
        }
        printf("\n"); 
        while(a < 11 && k < 2){
            printf("-");
            a++;
        }
        printf("\n");
    }      
}

bool menu(int continuar){
    printf("Deseja jogar um jogo novo ou sair?\n");
    printf("1. JOGAR\n2. SAIR\n");
}