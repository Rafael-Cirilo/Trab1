#include<stdio.h>

int find_smallest(int vet[], int h, int n) {
  int menor = h;
  if (h < n - 1) {
    int tail_menor = find_smallest(vet, h + 1, n);
    if (vet[tail_menor] < vet[menor]) {
      return tail_menor;
    }
  }
  return menor;
}
void selection (int vet[], int h, int n){
  int i, menor, tmp;
  if (h < n - 1) {
     menor = find_smallest(vet, h+1, n);
     if(vet[menor]<vet[h]){          
         tmp=vet[menor];        
         vet[menor]=vet[h];          
         vet[h]=tmp;
     }
     selection(vet, h+1, n);
  }
}
int main(){
	int n,j=0, i=0,k,l,freq;
	puts("Entre com um valor inteiro maior que 0");
	scanf("%i", &n);
		if(n==0){
			puts("Entre com um valor inteiro maior que 0");
			scanf("%i", &n);
		}
	
	
	int* vet =(int*)malloc(n*sizeof (int));
	while (i<n){
		printf("\nQual o numero %i\n",i+1);
		scanf("%d",&vet[i]);
		i++;
	}// Esse while apenas pega os valores para um vetor
	
	selection (vet, 0, n);//Aqui ordenamos o vetor assim como visto em sala
	
	freq=1;
	for( i = 0 ;i < n; i++ ){
		k=1;
		while(vet[j]==vet[j+1]){
			k++;
			if(freq<=k){
				freq=k;
			}
			j++;
		}
		i=j++;
	};//Esse for descobre a moda do vetor
	

	if(freq==1){
		for (i = 0 ; i < n ; i++)
		printf("%d,",vet[i]);
	}//Para o caso de todos os valores aparecerem apenas uma vez
	if(freq>1){
	
	j=0;
	
		for( i = 0 ;i < n; i++ ){
			k=1;
			while(vet[i]==vet[i+1]){
				k++;
				if(k>freq){
					l=j;
					printf("%d,",vet[i]);
				}
				i=j++;
			}
	
		};//Esse for descobre quais os valores do vetor possuem a moda descoberta antes 
	}
	printf(" tem maior frequencia no vetor");
	free(vet);
}
