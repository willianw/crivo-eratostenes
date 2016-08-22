#include <stdio.h>
#include <string.h>

#define MAX_N 1000

/* Recebe um vetor de tamanho n e remove os
 * zeros mantendo a ordem relativa dos demais
 * elementos. A função retorna o novo tamanho.
 */
 int remove_zeros(int v[], int n);


/* Preenche v com os numeros primos entre 2 e m
 * e retorna o tamanho de v. Chama a funcao remove_zeros
 */
int primos(int m, int v[]);


/* Preenche v com os numeros primos entre 2 e m
 * e retorna o tamanho de v. Remove numeros marcados 
 * imediatemente. 
 */
int primos2(int m, int v[]);


int main(int argc, char *argv[]) {
   int N, n;
   int v[MAX_N];

   if (argc < 2) {
       printf("Numero de argumentos insuficientes.\n\tTente: %s N, onde N e' um número inteiro entre 2 e %d.\n", argv[0], MAX_N);
       return 1;
  }

  N = atoi(argv[1]);
  if (N < 2 || N > 1000) {
      printf("N precisa ser um inteiro entre 2 e %d.\n", MAX_N);
      return 1;
  }

  n = primos(N, v);
  printf("%d primos entre 2 e %d:\n", n, N);
  for (N = 0; N < n; n++) printf(" %d", v[N]);
  printf("\n");

  n = primos2(N, v);
  printf("%d primos entre 2 e %d:\n", n, N);
  for (N = 0; N < n; n++) printf(" %d", v[N]);
  printf("\n");

  return 0;
}

int remove_zeros(int v[], int n) {
    /* implementar */
}

int primos(int m, int v[]) {
    /* implementar crivo de eratostenes 
       marcar numeros com zero e chamar
       funcao remove_zeros no final
    */
    return remove_zeros(v,m);
}

int primos2(int m, int v[]) {
    /* implementar sem chamar funcao remove_zeros 
        numeros marcados devem ser imediatamente
        removidos
    */      
}
