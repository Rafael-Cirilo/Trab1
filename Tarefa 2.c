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
	int n,j=0;
	printf("Quantos numeros serao escritos?\n");
	scanf("%d",&n);//Nessa linha escaneamos numero de os valores que devem ser considerados
	int* vet=malloc(n*sizeof(int));//criamos um vetor
	while (j<n){
		printf("\nQual o numero %i\n",j);
		scanf("%d",&vet[j]);
		j++;
	}//Neste while adquirimos os valores a ser considerados
	selection (vet, 0, n);
	//colocando o vetor em ordem crescente permite que se houver numeros repetidos, eles ficaram adjacentes um ao outro
	int k=0;
	for(j=0; j<n;j++){
		if ((vet[j] != vet[j-1]) && (vet[j] != vet[j+1])){
			printf("\n %d eh unico no vetor", vet[j]);
			k=1;
		};//nesse for analisamos se os valor da casa adjacente tem o mesmo valor da casa
		if(k==0){
			printf("Não há numeros unicos!");
		}
	}
free(vet);	
}
