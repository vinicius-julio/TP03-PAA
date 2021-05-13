#include "LeituraArquivo.h"
char* LeituraArquivo(char *arqEntrada){
  FILE *f;
  char buffer[33];  //Buffer para leitura de palavra por palavra
  char *arqSaida = (char*)calloc(1000000, sizeof(char)); //Variavel para armazenamento de texto, com até 1000000 caracteres;
  f = fopen(arqEntrada, "r");
  if(f == NULL){
    printf("Erro na abertura de arquivo!\n");
    return NULL;
  }
  else{
    strcpy(arqSaida, "\0");  //Inicializa as strings como vazias.
    strcpy(buffer, "\0");
    while(fscanf(f, "%s", buffer)!=EOF){
      strcat(arqSaida, buffer); //Cada palavra lida é concatenada na variavel de texto
      strcat(arqSaida,  " "); //Depois de cada palavra é escrito um espaço
      strcpy(buffer, "\0"); //Em seguida variavel buffer é vazia
    }
    strcat(arqSaida, "\0"); //Ao final da leitura, é escrito no fim da variavel de texto \0 para indicar fim do texto;
    return arqSaida; //Endereço da variavel texto é retornado.
  }
}
