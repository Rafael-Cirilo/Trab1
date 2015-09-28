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
	int n, i=0,m;
	printf("Quantos números devem ser analisados?");
	scanf("%i", &n);//Descobrimos o tamanho do vetor
	int* vet=malloc(n*sizeof(int)) ;//criamos um vetor para os possiveis valores
	while (i<n){
		printf("\nQual o numero %i\n",i);
		scanf("%d",&vet[i]);
		i++;
	}//Neste while descobrimos os valores a serem analisados
	
	selection (vet, 0, n);//Aqui colocamos o vetro em ordem

	m=vet[1]-vet[0];//consideramos a diferença entre o primeiro e o segundo como maior
	for(i=1 ; i<n-1; i++ ){
		if(m>vet[i+1]-vet[i]){//
			m=vet[i+1]-vet[i];
			//como o valor ou está na "cauda" ou na "cabeça", podemos passare de dois a dois no vetor ordenado se há uma difernça maior do que a anterior
		};
	};
	printf("A menor diferenca eh %d",m);
	for(i=0;i<n;i++){
		if(vet[i+1]-vet[i]==m){
			printf("%d",i);
		}
	}
	free(vet);
}
