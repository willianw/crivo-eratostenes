#include <stdio.h>
#define MAX 50
/*
int main(){
	int v[MAX], n = 20;
	int i, j, passo, dx;
	int m = n;
	for(i = 0; i <= n; i++)
		v[i] = i;
	for(passo = 2; passo * passo < n; passo++){
		dx = 0;
		printf("passo %d\n", passo);
		for(j = 0; j <= n; j++)
			printf("%d ", v[j]);
		printf("\n");
		for(i = 0; i <= n; i++){
			if((! v[i] % passo) && (v[i] / passo != 1)){
				dx++;
				m--;
			}
			else
				v[i - dx] = v[i];
			for(j = 0; j <= n; j++)
				printf("%d ", v[j]);
			printf("\n");
		}
	}
	return 0;
}
*/

int main(){
	int v[MAX], n = 20;
	int i, j, passo, dx=0;
	int m = n;
	for(i = 0; i <= n; i++){
		v[i] = i;
		printf("%d ", v[i]);
	}
	printf("\n");
	for(i = 0; i <= n; i++){
		printf("%d", v[i]);
		if((v[i] % 2 == 0) && (v[i] / 2 != 1)){
			printf("[%d]++ ", v[i]);
			dx++;
			m--;
		}
		else{
			v[i - dx] = v[i];
			printf("->(%d) ", i+1-dx);
		}
	}
	for(i = 0; i <= m; i++){
		printf("%d ", v[i]);
	}
	return 0;
}