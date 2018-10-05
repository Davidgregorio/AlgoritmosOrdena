                            /*
    ALGORITMOS QUE FAZEM A ORDENAÇÃO ***********************
                            */


                            /*
    INSERTION SORT          ***********************
                            */
void insertion (int vet[], int tam){
    int i = 0, j, aux;

    for ( j = 1; j < tam ; j++){
		aux = vet[j];
		i = j - 1;
		while ((i > -1) && ( aux < vet[i])){
			vet[i + 1] = vet[i];
			i = i - 1;
		}vet[i + 1] = aux;
    }
 }

                            /*
    SELECTION SORT          ***********************
                            */
void selection(int vet[], int tam){

    for (int i = 0; i < tam; ++i) {
        int Vminimo = i;

        for (int j = i+1; j < tam; ++j) {
            if (vet[j] < vet[Vminimo]) {
            Vminimo = j;}
        }
        int aux = vet[i];
        vet[i] = vet[Vminimo];
        vet[Vminimo] = aux;
    }
}
                            /*
    BUBLE SORT              ***********************
                            */
void buble(int vet[], int tam){
    int aux, i, j;
    for (i = 0; i < (tam - 1); i++) {
        for (j = 0; j < (tam-(i+1)); j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j]= vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

                            /*
    SHELL SORT              ***********************
                            */
void shellS(int vet[], int tam){
    int h = tam/2;
    int i, j, aux;

    while (h > 0){
        i = h;
        while (i < tam){
            aux = vet[i];
            j = i;
            while (j >= h && aux < vet[j-h]){
                vet[j] = vet[j-h];
                j = j - h;
            }vet[j] = aux;
            i = i + 1;
        }h = h/2;
    }
}

                            /*
    MERGE SORT              ***********************
                            */

void Intercala(int inicio, int fim, int vet[], int meio){
    int i = inicio, j = meio + 1, k = 0;
    int *temp = (int *) malloc(sizeof(int) * (fim - inicio + 1));

   while( i < meio + 1 || j  < fim + 1 ){
      if ( i == meio+1 ){
         temp[k] = vet[j];
         j++;   k++;
      }else{
         if (j==fim+1){
            temp[k] = vet[i];
            i++;  k++;
         }else{
            if (vet[i] < vet[j]){
               temp[k] = vet[i];
               i++; k++;
            }else{
              temp[k] = vet[j];
              j++;  k++;
            }
         }
      }
   }

   for( i = inicio; i <= fim; i++ ){
      vet[i] = temp[i-inicio];
    }free(temp);
}

void mergeH( int vet[], int inicio, int fim){
    int meio;
    if ( inicio == fim )
    return;

    meio = ( inicio + fim )/2;
    mergeH( vet, inicio, meio);
    mergeH( vet, meio+1, fim );
    Intercala(inicio, fim, vet, meio);
}

                        /*
    QUICK SORT              ***********************
                            */

int particiona (int vet [], int p, int r){
	int k = p + rand() % (r-p+1); // retorna um num aleatorio
 	int pivo, d, i, j;
 	pivo = vet [k]; vet [k] = vet[p]; vet[p] = pivo;
 	i = p;
 	for (j = p+1; j <= r; j++){
 		if (vet[j]<pivo){ i++;
 		d = vet [i]; vet[i] = vet [j]; vet[j] = d;}
    }d = vet [i]; vet[i] = vet[p]; vet [p] = d;
    return i;
}

void quick(int vet[],int p, int r){
   if (p < r){
   	int meio;
   		meio = particiona (vet, p, r);
      	quick (vet, p, meio-1);
     	quick (vet, meio + 1, r);
    }
}
                            /*
    HEAP SORT               ***********************
                            */
void min_heapify(int vet[], int tam, int i){
    int menor;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq < tam && vet[esq] > vet[i])
		menor = esq;
	else menor = i;
	if (dir < tam && vet[dir] > vet[menor])
		menor = dir;
    if (menor != i){
		int temp = vet[i];
		vet[i] = vet[menor];
		vet[menor] = temp;
		min_heapify(vet, tam, menor);
   }
}

void heapS(int vet[], int tam){

    for (int i = tam / 2 - 1; i >= 0; i--)
        min_heapify(vet, tam, i);

    for (int i=tam-1; i>=0; i--){
        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;
        min_heapify(vet, i, 0);
    }
}
