#include<stdio.h>

const int TREE = '#';
const int EMPTY = '.';
const int FIRE = 'o';
const int a = 0;
void mostrar_matriz(int numL, int numC, char matriz[numL][numC]){

    int i = 0;
    int j = 0;

    for(i = 0; i < numL; i++){
        for(j = 0; j < numC; j++){
            printf(" %c", matriz[i][j]);
        }
        puts("");
    }
    printf("\n");

}

void queimar(int numL, int numC, int l, int c, char matriz[numL][numC]){
    
    // ação de parada
    if((l < 0) || (l >= numL) || (c < 0) || (c >= numC)) return;
    if(matriz[l][c] != TREE) return;

    matriz[l][c] = FIRE; // toca fogo

    getchar();
    mostrar_matriz(numL, numC, matriz);

    queimar(numL, numC, l, c + 1, matriz);  // queima direita
    queimar(numL, numC, l, c - 1, matriz);  // queima esquerda
    queimar(numL, numC, l - 1, c, matriz);  // queima para cima
    queimar(numL, numC, l + 1, c, matriz);  // queima para baixo

}



int main(){

    int numL = 0;
    int numC = 0;
    int l = 0;
    int c = 0;

    scanf("%d", &numL);
    scanf("%d", &numC);
    scanf("%d", &l);
    scanf("%d", &c);

    char matriz[numL][numC];

    int i = 0;
    int j = 0;

    for(i = 0; i < numL; i++){
        for(j = 0; j < numC; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }

    mostrar_matriz(numL, numC, matriz);
    queimar(numL, numC, l, c, matriz);

}

