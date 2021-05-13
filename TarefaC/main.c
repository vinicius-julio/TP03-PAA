#include "ShiftAndAproximado.h"
#include "LeituraArquivo.h"

int main(int argc, char const *argv[]) {
  int k;
  char *padrao = (char*)malloc(sizeof(char)); //memoria dinamicamente alocada para o padrao que será inserido
  char nomeArq[35];

  printf("Digite o nome do arquivo de entrada (.txt): ");
  scanf("%s", nomeArq);
  char* texto = LeituraArquivo(nomeArq); //le o arquivo de entrada.
  printf("");
  printf("Digite o padrão: ");
  scanf("%s",padrao);
  printf("");
  int operacoes[3];
  int P = strlen(padrao); //Atribuindo tamanho do padrao.
  printf("Digite o tamanho de k: ");
  scanf("%d",&k);
  //se k for maior ou igual ao tamanho do padrao, o programa informa sobre condicao de busca
  if(k>=P){
    printf("O tamanho de k é maior ou igual ao tamanho do padrão!\n");
  }
  printf("Utilizar a operacao de insercao?\n1 - Sim\n0 - Nao\n");
  do{
    printf("Digite: ");
    scanf("%d",&operacoes[0]); //Recebe escolha do uso da operacao de insercao
    if(operacoes[0] != 1 && operacoes[0] != 0){
      printf("Entrada invalida!\n");
    }
  }while(operacoes[0] != 1 && operacoes[0] != 0);

  printf("Utilizar a operacao de remocao?\n1 - Sim\n0 - Nao\n");
  do{
    printf("Digite: ");
    scanf("%d", &operacoes[1]); //Recebendo escolha do uso da operacao de remocao
    if(operacoes[1] != 1 && operacoes[1] != 0){
      printf("Entrada invalida!\n");
    }
  }while(operacoes[1]!=1 && operacoes[1]!=0);

  printf("Utilizar a operacao de substituicao?\n1 - Sim\n0 - Nao\n");
  do{
    printf("Digite: ");
    scanf("%d",&operacoes[2]); //Recebe escolha do uso da operacao de substituicao
    if(operacoes[2] != 1 &&operacoes[2] != 0){
      printf("Entrada invalida!\n");
    }
  }while(operacoes[2] != 1 && operacoes[2] != 0);
  printf("\nAlgoritmo Shift-And Aproximado: \n");
  ShiftAndAproximado(texto,strlen(texto), padrao , P, k, operacoes); //Chama o algoritmo ShiftAnd aproximado
  return 0;
}
