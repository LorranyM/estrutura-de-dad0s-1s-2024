#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    
    int qtd_n = argc - 1;
    int soma_n = 0;
    float med_n = 0;
    int menor_n = atoi(argv[1]);
    int maior_n = atoi(argv[1]);
    int vetor_ord_n[qtd_n];

    for(int i = 1; i <= qtd_n; i++){
        int n = atoi(argv[i]);
        vetor_ord_n[i-1] = n;
        soma_n += n;

        if(menor_n > n){
            menor_n = n;
        }

        if(n > maior_n){
            maior_n = n;
        }

    }
    med_n = (float) soma_n/ qtd_n;

    printf("quantidade de numeros recebidos: %d\n", qtd_n);
    printf("valor medio dos numeros: %.2f\n", med_n);
    printf("menor numero: %d\n", menor_n);
    printf("maior numero:%d\n", maior_n);

    for(int i = 0; i < qnt_n; i++){

        for( int j = i; j < qnt_n; j++){
            if(n > vetor_ord_n[j]){
                int aux = vetor_ord_n[j];
                vetor_ord_n[j] = vetor_ord_n[i];
                vetor_ord_n[i] = aux;
            }
        }
    }

    for(int i = 0; i < qtd_n; i++){
        printf("%d", vetor_ord_n[i]);
    }

    exit(0);
}