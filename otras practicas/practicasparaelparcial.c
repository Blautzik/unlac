#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Declaraciones de las funciones o procedimientos
//PRE: El tama�o que ingresa el usuario debe ser mayor a cero en caso que se use este tama�o
//para un vector o figura
//POST: Se devulve un entero
int elegirTamanio();

//PRE:El tama�o debe ser mayor a cero, y menor a 170, srand(time(0)) y #include <time.h> deben estarn en el main
//POST:Se sobreescribe el vector con numeros aleatorios, entre -70 y 100
void cargarVectorAleatorio(int v[], int tam);

//PRE:El tama�o debe ser mayor a cero
//POST:se muestra por pantalla el vector v
void mostrarVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve la posicion donde esta el valor minimo
int posMin(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve la posicion donde esta el valor maximo
int posMax(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve  el valor minimo
int minVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve el valor maximo
int maxVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve el promedio del vector
float promVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector resultado con la suma vectorial
void sumaVectores(int v[], int w[], int resultado[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector resultado con la resta vectorial
void restaVectores(int v[], int w[], int resultado[], int tam);

//PRE: Mini debe ser menor  a maxi... SI o si .. srand(time(0)) y #include <time.h> deben estarn en el main
//POST: Se devuelve un valor aleatroio entre mini y maxi
int aleatorioEntre(int mini, int maxi);

//PRE: mini debe ser menor que maxi y el tama�o mayor a cero.
//POST: se sobreescriben los valores del vector v con valores aleatorios entre mini y maxi
void cargarVectorConAleatorios(int v[], int tam, int mini,int maxi);

//PRE: mini debe ser menor que maxi y el tama�o mayor a cero. Tam debe ser mayor a maxi - mini
//POST: se sobreescriben los valores del vector v con valores aleatorios entre mini y maxi, sin repetidos
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini,int maxi);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoBurbuja(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoSeleccion(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoInsercion(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se devuelve la posicion en caso que se encontro el numero, o -1 en caso de no encontrarlo
int busquedaSecuencial(int v[], int tam, int buscar);

//PRE: El tama�o debe ser mayor a cero, el vector v debe estar ordenado.
//POST: Se devuelve la posicion en caso que se encontro el numero, o -1 en caso de no encontrarlo
int busquedaBinaria(int v[], int tam, int buscar);


//Para repasar previo al primer parcial
//PRE: el tama�o debe ser positivo
//POST: Se devuelve uno o menos uno si son iguales o no respectivamente.
int sonIguales(char nombre1[], char nombre2[], int tam);


//Realizar todos los mismos algoritmos pero para arrays de float o incluso de char
//Realizar la funcion que devuelve la moda del vector
//Realizar el procedimiento que carga un nuevo vector con la frecuenca de cada componente del vector inicial
//Realizar la fucion que devuelve el desvio standart (float) del vector.





int main()

{
    #include <time.h>
    srand(time(0));

    int tam, mini, maxi;
    tam = elegirTamanio();
    int vec[tam];
    int vec2[tam];
    int vec3[tam];
    cargarVectorAleatorio(vec, tam);
    mostrarVector(vec, tam);
    posMin(vec, tam);
    posMax(vec,tam);
    mini = minVector(vec,tam);
    maxi = maxVector(vec,tam);
    cargarVectorAleatorio(vec2, tam);
    mostrarVector(vec2,tam);
    sumaVectores(vec, vec2, vec3, tam);
    mostrarVector(vec3,tam);
    restaVectores(vec,vec2,vec3,tam);
    mostrarVector(vec3, tam);
    aleatorioEntre(mini, maxi);
    cargarVectorConAleatorios(vec, tam, mini, maxi);
    mostrarVector(vec, tam);
    cargarVectorConAleatoriosSinRepetir(vec, tam, mini, maxi);
    mostrarVector(vec, tam);
    ordenamientoBurbuja(vec, tam);
    mostrarVector(vec,tam);
    cargarVectorConAleatoriosSinRepetir(vec, tam, mini, maxi);
    mostrarVector(vec,tam);
    ordenamientoSeleccion(vec,tam);
    mostrarVector(vec, tam);
    ordenamientoInsercion(vec,tam);
    mostrarVector(vec, tam);
    busquedaSecuencial(vec,tam, 25);
    busquedaBinaria(vec, tam, 25);




    return 0;
}



int elegirTamanio(){
    int tam = 0;
    printf("Ingresa el tamanio del vector");
    scanf("%d", &tam);
    while(tam<=0 || tam>=170){
        printf("\n El valor debe estar entre 0 y 170 \n");
        elegirTamanio();
    }
    return tam;
}


void cargarVectorAleatorio( int arr[], int tam){
    for(int i=0; i<tam ; i++){
        arr[i] = rand() % 240 -70;
    }
    printf("\n Se cargo un vector aleatorio \n");
}


void mostrarVector(int v[], int tam){
    for(int i =0; i<tam ; i++){
       printf(" |%d| " , v[i]);
    }
    printf("\n");
}


int posMin(int v[], int tam){
    int min = v[0];
    int res = 0;
    for(int i=0; i<tam; i++){
        if (v[i] < min){
            min = v[i];
            res = i;
        }
    }
    printf("\n El minimo esta en la posicion %d \n", res);

    return res;
}

int posMax(int v[], int tam){
    int max = v[0];
    int res = 0;
    for(int i=0; i<tam; i++){
        if (v[i] > max){
            max = v[i];
            res = i;
        }
    }
    printf("\n El maximo esta en la posicion %d \n", res);

    return res;

}

int minVector(int v[], int tam){
    int min = v[0];
    int res;
    for(int i=0; i<tam; i++){
        if (v[i] < min){
            min = v[i];
            res = i;
        }
    }
    printf("\n El minimo es %d \n", min);

    return min;

}

int maxVector(int v[], int tam){
    int max = v[0];
    int res = 0;
    for(int i=0; i<tam; i++){
        if (v[i] > max){
            max = v[i];
            res = i;
        }
    }
    printf("\n El maximo es %d \n", max);

    return max;

}


float promVector(int v[], int tam){
    float suma = 0;
    for (int i=0; i<tam; i++){
        suma += v[i];
    }

    printf("El promedio es %d", suma/tam);
    return suma/tam;
}


void sumaVectores(int v[], int w[], int resultado[], int tam){
    for(int i=0; i<tam; i++){
        resultado[i] = v[i]+w[i];
    }
    printf("\n Se realizo la suma de vectores\n\n");
}

void restaVectores(int v[], int w[], int resultado[], int tam){
        for(int i=0; i<tam; i++){
        resultado[i] = v[i]-w[i];
    }
    printf("\n Se realizo la resta de vectores\n\n");
}

int aleatorioEntre(int mini, int maxi){
    int resultado = rand() %maxi + mini;
    return resultado;
}


void cargarVectorConAleatorios(int v[], int tam, int mini,int maxi){
    for(int i=0; i<tam ; i++){
            v[i] = aleatorioEntre(mini, maxi-1);
    }
    printf("\n Se cargo el vector con numeros aleatorios entre mini y maxi \n");
}


void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini,int maxi){
    int len = maxi-mini;
    int aux[len];
    int rIndex;
    for (int i=0; i<len; i++){
        aux[i] = mini+i;
    }
    for (int i=0; i<maxi-mini; i++){
        int rIndex = rand() % len;
        int temp = aux[i];
        aux[i]= aux[rIndex];
        aux[rIndex] = temp;
    }


    for (int i=0; i<tam; i++){
        v[i] = aux[i];
    }
    printf("\n Se cargo el vector con numeros aleatorios sin repetir \n");

}


void ordenamientoBurbuja(int v[], int tam){
    int i, j, temp;
    for (i = 0; i<tam; i++){
        for (j=0; j<tam-1; j++){
            if(v[j]>v[j+1]){
               temp = v[j+1];
               v[j+1]=v[j];
               v[j]=temp;
            }
        }
    }
    printf("\nSe ordeno el vector(burbuja)\n");

}


void ordenamientoSeleccion(int v[], int tam){
    int i, min, j ,temp;
    for (i=0; i<tam-1; i++){
        min=i;
        for(j=0; j<tam; j++){
            if(v[j]> v[min]){
                min=j;
            }
            temp=v[min];
            v[min]=v[j];
            v[j]=temp;
        }
    }
    printf("\nSe ordeno el vector(Selección)\n");
}

void ordenamientoInsercion(int v[], int tam){
    int i, k, j;
    for(i=0; i<tam; i++){
        k = v[i];
        j=i-1;
        while(j>=0 && v[j]>k){
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1]=k;
    }
    printf("\nSe ordeno el vector(insercion)\n");
}

int busquedaSecuencial(int v[], int tam, int buscar){
    int i;
    for(i=0; i<tam; i++){
        if(v[i] == buscar){
            printf("\n se encontro el valor en la posicion: %d",i);
            return i;
        }
    }
    printf("\n no se encontro el valor \n");
    return -1;
}


int busquedaBinaria(int v[], int tam, int buscar){
    int medio, inicio, fin;
    inicio=0;
    fin = tam;
    while(inicio<=fin){
        medio = (inicio+fin)/2;
        if(v[medio] == buscar){
            printf("Se encontro el valor en la posicion %d con el metodo binario", medio);
            return medio;
        }
        if(v[medio] < buscar){
            inicio = medio+1;
        }
        else{
            fin=medio-1;
        }
    }
    printf("no se encontro el valor");
    return -1;
}

