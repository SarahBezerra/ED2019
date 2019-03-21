#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const char WALL = '#';
const char PATH = ' ';

int moveL[] = {0, -1, 0, 1};
int moveC[] = {-1, 0, 1, 0};
int sides = sizeof(moveL)/sizeof(int);

void shuffle(int vet[], int size){
    int i = 0;
    for( i = 0; i < size; i++){
        int esc = rand() % size;
        int temp = vet[i];
        vet[i] = vet[esc];
        vet[esc] = temp;
    }
}

void show_maze(int linha, int coluna, char maze[linha][coluna]){
    int l = 0;  int c = 0;
    for( l = 0; l < linha; l++){
        for( c = 0; c < coluna; c++){
            printf("%c ", maze[l][c]);
        }
        printf("\n");
    }
    //getchar();
}

bool find_exit(int nlinha, int ncoluna, char maze[nlinha][ncoluna], bool walked[nlinha][ncoluna], int linha, int coluna, int lsaida, int csaida){
    if(maze[linha][coluna] != PATH){
        return false;
    }
    if(walked[linha][coluna] == true){
        return false;
    }
    walked[linha][coluna] = true;
    maze[linha][coluna] = '.';
    if((linha == lsaida)&&(coluna == csaida)){
        return true;
    }
    int i = 0;
    for( i = 0; i < sides; i++){
        bool caminho = find_exit(nlinha, ncoluna, maze, walked, linha + moveL[i], coluna + moveC[i], lsaida, csaida);
        if(caminho){
            return true;
        }
    }
    maze[linha][coluna] = PATH;
    return false;
}

void create_maze(int nlinha, int ncoluna, char maze[nlinha][ncoluna], int linha, int coluna){
    if((linha < 1) ||(linha >= nlinha - 1) ||(coluna <  1) ||(coluna >= ncoluna - 1)){
        return;
    }
    if(maze[linha][coluna] != WALL){
        return;
    }
    int cont = 0;
    int i = 0; 
    int tmp1 = 0; 
    int tmp2 = 0;
    for( i = 0; i < sides; i++){
        tmp1 = linha + moveL[i];
        tmp2 = coluna + moveC[i];
        if(maze[tmp1][tmp2] == PATH) cont++;
    }
    if(cont > 1){
        return;
    }
    maze[linha][coluna] = PATH;
    //show_maze(nlinha, ncoluna, maze);
    int neib[] = {0, 1, 2, 3};
    shuffle(neib, sides);
    int v = 0; 
    for(v = 0; v < sides; v++){
        i = neib[v];
        create_maze(nlinha, ncoluna, maze, linha + moveL[i], coluna + moveC[i]);
    }
    //show_maze(nlinha, ncoluna, maze);
}

int main() {
    srand(time(NULL));
    int linha = 0;
    int coluna = 0;
    printf("Digite o tamanho do labirinto:\n");
    scanf("%d%d", &linha, &coluna);
    getchar();
    char maze[linha][coluna];
    bool walked[linha][coluna];
    int l = 0; int c = 0;
    for(l = 0; l < linha; l++){
        for(c = 0; c < coluna; c++){
            maze[l][c] = WALL;
            walked[l][c] = false;
        }
    }
    //show_maze(linha, coluna, maze);
    create_maze(linha, coluna, maze, 1, 1);
    show_maze(linha, coluna, maze);
    int linicio = 0;
    int cinicio = 0;
    int lfim = 0;
    int cfim = 0;
    do{
        printf("Digite a posição inicial:\n");
        scanf("%d%d", &linicio, &cinicio);
    }while((maze[linicio][cinicio] == WALL)||(linicio < 0 )||(linicio >= linha)||(cinicio < 0)||(cinicio >= coluna));
    do{
        printf("Digite a posição final:\n");
        scanf("%d%d", &lfim, &cfim);
    }while((maze[lfim][cfim] == WALL)||(lfim < 0)||(lfim >= linha)||(cfim < 0)||(cfim >= coluna));
    bool exit = find_exit(linha, coluna, maze, walked, linicio, cinicio, lfim, cfim);
    show_maze(linha, coluna, maze);
}
