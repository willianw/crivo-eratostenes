#include <stdio.h>

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


int main(void) {
   int N = 0, n, i;
   int v[MAX_N];

  scanf("%d", &N);
  if (N < 2 || N > 1000) {
      printf("N precisa ser um inteiro entre 2 e %d.\n", MAX_N);
      return 1;
  }

  n = primos(N, v);
  printf("%d primos entre 2 e %d:\n", n, N);
  for (i = 0; i < n; i++) printf(" %d", v[i]);
  printf("\n");

  n = primos2(N, v);
  printf("%d primos entre 2 e %d:\n", n, N);
  for (i = 0; i < n; i++) printf(" %d", v[i]);
  printf("\n");

  return 0;
}

int remove_zeros(int v[], int n) {
	int dx = 0, i, m = n;
	for(i = 0; i < m; i++){
		if(v[i])
			v[i - dx] = v[i];
		else{
			dx++;
			n--;
		}
	}
    return n;
}

int primos(int m, int v[]) {
    int passo = 2, i;
	for(i = 0; i <= m; i++)
		v[i] = i;
	v[1] = 0;
	while(passo * passo < m){
		for(i = 2 * passo; i < m; i += passo)
			v[i] = 0;
		passo++;
	}
    return remove_zeros(v,m);
}

int primos2(int m, int v[]) {
	int i, passo, dx=0;
	int *p;
	int n = m, M = m;
	for(i = 2; i <= m; i++)
		v[i-2] = i;
	for(passo = 2; passo * passo < M; passo++){
		dx = 0;
		for(i = 0; i <= n; i++){
			if((v[i] % passo == 0) && (v[i] / passo != 1)){
				dx++;
				m--;
			}
			else{
				v[i - dx] = v[i];
			}
		}
		n = m;
	}
	return m+1;
} 	