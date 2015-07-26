#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100


//defineção de aresta
struct Aresta
{
	int dest, ori, peso;
	
	Aresta()
	{
	}
	
	Aresta(int o, int d, int p)
	{
		ori = o;
		dest = d;
		peso = p;
	}
};

//mergesort
int redes[MAXN], rank[MAXN];

int min(int a, int b) {
        return a < b ? a : b;
}

int max(int a, int b) {
        return a > b ? a : b;
}

int mergesort( int x){
        if (redes[x] == x)
                return x;
        redes[x] = mergesort(redes[x]);
        return redes[x];
}
bool compare(Aresta e1, Aresta e2) {
        return e1.peso < e2.peso; 
}

void intercala(int x, int y)
{
	int raizX = mergesort(x);
	int raizY = mergesort(y);
	
	if(rank[raizX] > rank[raizY])
		redes[raizY] = raizX;
	else if (rank[raizX] < rank[raizY])
		redes[raizX] = raizY;
  else if (raizX != raizY)
 	 redes[raizY] = raizX, rank[raizX] = rank[raizX] + 1;
}

void kruskal(vector<Aresta> arestas, int n) {
        int vertices = n, m = arestas.size();
        for (int i = 0; i <= n; i++)
                redes[i] = i, rank[i] = 0;

        sort(arestas.begin(), arestas.end(), compare);
        for (int i = 0; vertices > 1 && i < m; i++) {
                Aresta e = arestas[i];
                int parenteA = mergesort(e.ori);
                int parenteB = mergesort(e.dest);
                if (parenteA != parenteB) {
                        printf("%d %d\n", min(e.ori, e.dest), max(e.ori, e.dest)); 
                        intercala(e.ori, e.dest);
                        vertices--;
                }
        }
}



int main() {
	int N, M;
	int teste = 0;

	while (1) {
		scanf("%d %d", &N, &M);
		teste++;
		if (N == 0 && M == 0)
			break;

		vector<Aresta> arestas;
		for (int i = 0; i < M; i++) {
		  Aresta e;
		  scanf("%d %d %d", &e.ori, &e.dest, &e.peso);
		  arestas.push_back(e);
		}

		printf("Teste %d\n", teste);
		kruskal(arestas, N);
		printf("\n");
	}

	return 0;
}


