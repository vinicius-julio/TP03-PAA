#include "LeituraArquivo.h"

void LeituraArquivo(char *arqEntrada, char **arqSaida){
    FILE *f = NULL;
    char c;
    (*arqSaida) = (char*) malloc(MAXTAMTEXTO * sizeof(char));
    f = fopen(arqEntrada, "rt");
    if(f == NULL){
        printf("Erro na abertura de arquivo!\n");
    } else{
        int i = 0;
        while(fscanf(f, "%c", &c) != EOF){
            (*arqSaida)[i] = c;
            i++;
            if(i > MAXTAMTEXTO)
                break;
        }
        (*arqSaida)[i] = '\0';
        fclose(f);        
    }
}