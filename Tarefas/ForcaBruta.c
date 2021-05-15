#include "ForcaBruta.h"

void ForcaBruta(TipoTexto t, long n, TipoPadrao P, long m){    
    int i, j, k;
    long num_casamentos = 0;
    for(i = 0; i <= (n-m+1); i++){
        k = i;
        j= 1;
        while(j <= m && t[k-1] == P[j-1]){
            j++;
            k++;
        }
        if(j > m){
            printf("\tCasamento na posicao: %d\n", k + 1);
            num_casamentos++;
        }
    }
    printf("Nº de casamentos: %ld\n", num_casamentos);
}