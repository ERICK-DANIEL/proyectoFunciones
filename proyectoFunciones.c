#include <stdio.h>

void bubblesort(int numeros[], int n);
void insertionsort(int numeros[], int n);
void selectionsort(int numeros[], int n);
void numOrdenados(int numeros[], int n);

int main(){
    int opcion;
    int n;

    printf("Introduzca el numero de elementos a ordenar: ");
    scanf("%d", &n);

    int numeros[n];

    for(int i = 0; i < n; i++){
        printf("Ingese el valor[%d]: ", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("Metodo de ordenamiento que desea usar: \n");

    do{
        printf("\n1. Ordenamineto burbuja\n");
        printf("2. Ordenamineto por insercion\n");
        printf("3. Ordenamineto por seleccion\n");
        printf("4. Salir");

        printf("\n");

        scanf("%d", &opcion);

        switch(opcion){
        case 1: printf("Numeros ordenados:\n");
            bubblesort(numeros, n);
            numOrdenados(numeros, n);
            break;
        case 2: printf("Numeros ordenados:\n");
            insertionsort(numeros, n);
            numOrdenados(numeros, n);
            break;
        case 3: printf("Numeros ordenados\n");
            selectionsort(numeros, n);
            numOrdenados(numeros, n);
            break;
        }
    } while (opcion != 4);

}

void bubblesort(int numeros[], int n){
    int i, j;

    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(numeros[j] > numeros[j+1]){
                int aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
}

void insertionsort(int numeros[], int n){
    int i, j, aux;

    for(i = 0; i < n; i++){
        j = i;
        aux = numeros[j];

        while(j > 0 && aux < numeros[j-1]){
            numeros[j] = numeros[j-1];
            j--;
        }
        numeros[j] = aux;
    }
}

void selectionsort(int numeros[], int n){
    int i, j, aux, menor;

    for(i = 0; i < n; i++){
        menor = numeros[i];
        aux = i;

        for(j = i+1; j < n; j++){
            if(numeros[j] < menor){
                menor = numeros[j];
                aux = j;
            }
        }
        numeros[aux] = numeros[i];
        numeros[i] = menor;
    }
}

void numOrdenados(int numeros[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");
}


