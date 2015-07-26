#include <stdio.h>
#include <iostream>
#define max_n 100
#define max_m 4950

using namespace std;
int main(void)
{
	
	int n,m;
	int i,j;
	int v1,v2;
	int matriz[max_n][max_m];
	int cores[max_n];
	int flag = 0;
	int instancia =0;
	
	
	while(cin >> n >>m ){
		
		for(i=1; i< n+1; i++){
			for(j =1; j<n+1; j++){
				matriz[i][j] = 0;
			}
		}
	
		for (i= 1; i< n+1; i++)
			cores[i] = 0;
		instancia++;
		
		for(i =0; i<m; i++){
			scanf("%d%d", &v1,&v2);
			matriz[v1][v2] = 1;
			matriz[v2][v1] = 1;
		}	
		
		for(i= 1; i < n+1; i++){
			for(j = 1; j < n+1; j++){
				if( i != j){
					if(matriz[i][j] == 1){
						if(cores[i] == 0 && cores[j] == 0){
							cores[i] = 1;
							cores[j] = 2;
						}
						else if (cores[i] != 0 && cores[j] == 0){ 
							if(cores[i] == 1)
								cores[j] = 2;
							else
								cores[j] = 1;
								}
						else if(cores[j] != 0 && cores[i] == 0 ){
							if(cores[j] == 1)
								cores[i] = 2;
							else
								cores[i] = 1;
						}
						else {
							if(cores[i] != 0 && cores[j] != 0){
								if(cores[i] == cores[j]){
									flag = 1;
								}
							}
						}				 	
					}
				}
			}
		}
		
		if(flag == 0){
			printf("Instancia %d\nsim\n\n", instancia);
		}
		else{
			printf("Instancia %d\nnao\n\n", instancia);
		}
		
		for(i= 1; i< n+1; i++){
			for(j = 1; j<n+1; j++){
				matriz[i][j] = 0;
			}
		}
	
		for (i= 1; i< n+1; i++)
			cores[i] = 0;
		flag = 0;
		
		
	}
	
	return 0;
}

