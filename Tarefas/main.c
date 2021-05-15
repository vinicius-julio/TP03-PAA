#include "ShiftAndAproximado.h"
#include "LeituraArquivo.h"
#include "ForcaBruta.h"
#include "BMH.h"

double finalizarTempo(clock_t tempo_inicial){
    clock_t tempo_final;
    
    tempo_final = clock();    
    return (double)((tempo_final - tempo_inicial)* 1000.0)/CLOCKS_PER_SEC; 
}

int main(int argc, char const *argv[]) {
  int k, algoritmo;
  char *padrao = (char*)malloc(MAXTAMPADRAO*sizeof(char)); //memoria dinamicamente alocada para o padrao que será inserido
  char nomeArq[35];
  int P, operacoes[3]; 
  clock_t t_inicio;
  double t_duracao = -1;

  printf("Digite o nome do arquivo de entrada (.txt): ");
  scanf("%s", nomeArq);
  char* texto;  
  LeituraArquivo(nomeArq, &texto); //le o arquivo de entrada.
  getc(stdin);
  
  printf("Digite o padrão: ");
  scanf("%[^\n]250",padrao);  
  
  P = strlen(padrao); //Atribuindo tamanho do padrao.
  
  printf("Escolha o algoritmo:\n");
  printf("1 - Força Bruta\n");
  printf("2 - BMH\n");
  printf("3 - Shift-And Aproximado\n");
  scanf("%d", &algoritmo);
  
  
  switch(algoritmo){
      case 1:
            t_inicio = clock();
            ForcaBruta(texto, strlen(texto), padrao, P);
            t_duracao = finalizarTempo(t_inicio);
          break;
      case 2:
            t_inicio = clock();
            BMH(texto, strlen(texto), padrao, P);
            t_duracao = finalizarTempo(t_inicio);
          break;
      case 3:
                       
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
            t_inicio = clock();
            ShiftAndAproximado(texto,strlen(texto), padrao , P, k, operacoes); //Chama o algoritmo ShiftAnd aproximado
            t_duracao = finalizarTempo(t_inicio);
          break;
      default:
          printf("Opcao invalida!");
          return 0;
  }
  
  if(t_duracao > 0 && DEBUG){
      printf("Tempo de duracao: %lf milissegundos\n", t_duracao);
  }
  
  printf("FIM DA EXECUCAO\n");
  
  return 0;
}
