#include "BMH.h"

void BMH(TipoTexto t, long n, TipoPadrao P, long m){    
    int i, j, k, d[257];
    int g;
    long num_casamentos = 0;    
    
    for(j = 0; j <= 256; j++){
        d[j] = m;
    }
    
    for(j = 1; j < m; j++){
        d[P[j-1]] = m - j;
    }
    
    i = m;
    
    while(i <= n){
        k = i;
        j = m;
        while(j > 0 && t[k-1] == P[j-1]){
            k--;
            j--;
        }
        if(j == 0){
            printf("\tCasamento na posicao: %d\n", k + 1);
            num_casamentos++;
        }
        
        g = t[i - 1];
        if(g < 0 || g > 256)
            g = 0;
        
        i += d[g];
    }
    printf("Nº de casamentos: %ld\n", num_casamentos);
}
