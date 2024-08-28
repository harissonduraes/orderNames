// A função `strcmp` compara duas strings caractere por caractere usando a tabela ASCII (American Standard Code for Information Interchange). Cada caractere tem um valor numérico correspondente na tabela ASCII. Aqui está como isso se aplica à sua linha de código:

// 1. **Tabela ASCII**: Cada caractere em uma string tem um valor ASCII. Por exemplo, 'A' tem o valor 65, 'B' tem 66, 'a' tem 97, e assim por diante.

// 2. **`strcmp(cidades[i], cidades[j])`**: A função `strcmp` compara os caracteres das strings `cidades[i]` e `cidades[j]` um por um:
//    - Se encontrar um caractere diferente, retorna a diferença entre os valores ASCII desses caracteres.
//    - Se as strings forem iguais até o final de uma delas, retorna a diferença no comprimento das strings.

// 3. **Resultado da comparação**:
//    - Se `strcmp` retorna 0, as strings são iguais.
//    - Se retorna um valor negativo, `cidades[i]` é lexicograficamente menor que `cidades[j]`.
//    - Se retorna um valor positivo, `cidades[i]` é lexicograficamente maior que `cidades[j]`.

// No seu código, a variável `comparacao` armazenará o resultado da comparação. Se `comparacao` for:
// - **0**: As strings são iguais.
// - **Negativo**: `cidades[i]` vem antes de `cidades[j]` na ordem alfabética.
// - **Positivo**: `cidades[i]` vem depois de `cidades[j]` na ordem alfabética.

// Isso é útil em algoritmos de ordenação para determinar a ordem correta dos elementos.

#include <stdio.h>
#include <string.h>

const int MAX = 10;
int main(void) {

  

  char cidades[MAX][15] = {
      "São Paulo", "Curitiba", "Januaria", "São José", "Campinas", 
       "Rio de Janeiro", "Belo Horizonte", "Porto Alegre", "Recife", "Salvador"
  };
  int maiorASCII = 0;
  int comparacao = 0;
  char troca [50];

  printf("Algoritmo de Inserção com Cidades:\n");
  
  for (int i = 0; i < MAX; i++) {
    printf("%s\n", cidades[i]);
  }

  printf("\n");

  for(int i = 0; i < MAX-1; i++){
    for(int j = i+1; j < MAX; j++){
      comparacao = (strcmp(cidades[i], cidades[j]));
      // DEBUG
      //printf("Index:%d Diferença de %s e %s é %d\n", i, cidades[i],cidades[j], comparacao);
      if(maiorASCII < comparacao){
      //DEBUG
      //printf("Houve a troca\n");
      maiorASCII = comparacao;
      strcpy(troca, cidades[i]);
      strcpy(cidades[i], cidades[j]);
      strcpy(cidades[j], troca);
      }
      maiorASCII = 0;
    }
  }

  printf("\nCidades em ordem alfabética:\n");

  for(int i =0; i < MAX; i++) {
    printf("%s\n", cidades[i]);
  }
  
  return 0;
}