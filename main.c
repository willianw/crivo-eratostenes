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
/* Para cada elemento i da array, se i é não nulo, o elemento i é deslocado dx casas para a 'esquerda' no vetor
   Caso contrário (i nulo), significa que i deve ser removido, ou seja, dx é aumentado uma unidade. Isso significa que os próximos valores não nulos serão deslocado uma posição a mais, além das posições que já seriam deslocadas devido aos zeros anteriores
*/
	/*Valor de deslocamento de cada elemento da array*/
	int dx = 0;
	/*m: número de elementos na array
	  n: número de elementos não nulos na array
	  i: iterador
	*/
	int i, m = ++n;/*Acréscimo pois o zero também conta*/
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
	/*passo: valor cujos múltiplos inteiros serão 'marcados'
	  K: iterador*/
    int passo = 2, k;
	for(k = 0; k <= m; k++)
		v[k] = k;
	v[1] = 0; /*pois 1 não é primo*/
	/*Para cada passo, marca-se os k*passo, int k != 2
	Condição: para verificar os primos basta marcar os valores com passo² <= m, pois:
		-se passo² > m: 
			- ou passo é não-primo, e todos os seus múltiplos já foram marcados (pois já houve a marcação dos fatores menores)
			- ou passo é primo, e seus múltiplos da forma k*passo
				- ou têm k < passo, logo já foram marcados quando passo valia k
				- ou têm k >= passo, e como passo² > m, k*passo > m (logo não estaria na lista para ser marcado)
	*/
	while(passo * passo <= m){
		for(k = 2; k <= m/passo; k++)
			v[passo*k] = 0;
		passo++;
	}
    return remove_zeros(v,m);
}

int primos2(int m, int v[]) {
	/*Mesmos significados que na maneira anterior*/
	int i, passo, dx=0;
	int n, M;
	for(i = 2; i <= m; i++)
		v[i-2] = i;
	/*M serve para critério de parada,
	e m serve para contar quantos primos existem.
	Tem-se a lista inicial com todos os valores, e a cada valor marcado,
	remove-se uma unidade de m;
	Como 1 não é primo, e não estará presente no vetor, remove-se uma unidade automaticamente
	*/
	M = m;
	n = --m;
	/*Mesma lógica que no estado an
	for(passo = 2; passo * passo <= M; passo++){
		dx = 0;
		for(i = 0; i < n; i++){
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
	return m;
} 	