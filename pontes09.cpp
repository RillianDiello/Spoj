#include <stdio.h>
#include <iostream>
#define MAX_N 1000

#define MAX_M 10000

#define MAX_PESO 1000000

using namespace std;

int m,n;

void dijkstra(int vertices, int matriz[MAX_N][MAX_N], int distancia[MAX_N], int visitados[MAX_N])
{
	
	int v;
	for (int i = 0 ;i< vertices; i++)
		distancia[i] = MAX_PESO;
	for(int i=0; i< vertices; i++)
		visitados[i]= 0;
	distancia[0] = 0;
	
	while(true)
	{
		v = -1;
		for (int i=0; i < vertices; i++){
			if(!visitados[i] && (v == -1 || distancia[i] < distancia[v]))
					v = i;	
		}
		
		if(v == -1)			
			break;
	
		
		visitados[v] = 1;
		
		for (int i = 0; i< vertices; i++)
		{

				int u = i;
				if(distancia[u] > distancia[v]+ matriz[v][i] )
					{
						
						distancia[u] = distancia[v]+matriz[v][i];
					}	
		}
		
	}

		printf("%d\n", distancia[vertices-1]);

}

int main()
{

	int t,s, b;
	int matriz[MAX_N][MAX_N];
	int visitados[MAX_N];
	int distancia[MAX_N];
	
	
	while(cin >>n >>m){
		n += 2;
		
		for(int i = 0; i< n; i++)
			for(int j = 0; j< n; j++)
				matriz[i][j] = MAX_PESO;
		
		for(int i =0; i< m; i++)
		{
			scanf("%d%d%d", &s, &t, &b);
			matriz[s][t] = b;
			matriz[t][s] = b;	
		}

		dijkstra(n, matriz, distancia, visitados);
		printf("\n");
	}
	
	return 0;
}




