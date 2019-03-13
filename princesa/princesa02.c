#include<stdio.h>

void printa_vetor(int tam, int vet[]){
    int i = 0;

    printf("[");
    for(i = 0; i < tam; i++){
        printf(" %d", vet[i]);
    }
    printf(" ]");
}

void proximo_vivo(int tam, int vet, int esc){
    int i  = 0;

    for(i = 0; i < tam; i++){

    }

}

int main(){
    int tam = 0;
    int esc = 0;
    int fase = 1;

    scanf("%d %d %d", &tam, &esc, &fase);

    esc = esc - 1;

    int vet[tam];

    int i = 0;
    for(i = 0; i < tam; i++){
        vet[i] = (i + 1) * fase;
        fase *= -1;
    }

    int vao_morrer = tam - 1; 

    while(vao_morrer > 0){

    int dir = vet[esc] > 0 ? 1 : -1;

    vet[esc] > 0 ? vet[esc] : -vet[esc];


        vao_morrer--;
    }        
}