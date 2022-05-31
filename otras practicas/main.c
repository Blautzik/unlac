#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Ejercicio de practica integrador: Realicen un menú semejante al anterior, donde se
//salga con el cero nuevamente, donde las opciones del 1 a 5 sean el cuadrado, triangulo,
//triangulo invertido, pirámide y pirámide invertida. Pero el tamaño de las figuras sea
//elegido por pantalla, es decir se tiene que poder elegir la cantidad de renglones y de
//columnas de las figuras. Las figuras no deben ser estáticas. Si se ingresa por pantalla un
//numero negativo debe salir la frase “No se puede dibujar ninguna figura así”. Una vez
//realizado hagan una prueba de escritorio


int filas, columnas, dato, opcion;

void bienvenida();
int cargarDatos();
int mostrarMenuYElegir();
void mostrarResultado(int o, int f, int c);
void mostrarRectangulo(int f, int c);
void mostrarTriangulo(int f, int c);
void mostrarTrianguloInvertido(int f, int c);



int main(){

    bienvenida();
    filas = cargarDatos();
    columnas = cargarDatos();
    opcion = mostrarMenuYElegir();
    mostrarResultado(opcion, filas, columnas);


    return 0;
}


void bienvenida(){
    printf("A dibujar figuras! \n");
    printf("Ingrese la cantidad de filas y luego la cantidad de columnas que quiere en su figura \n");
}

int cargarDatos(){

    scanf("%d", &dato);
    if (dato <= 0){
        printf("asi no se puede dibujar una figura!\n");
        printf("carga tu dato nuevamente\n");
        cargarDatos();
    }
    return dato;
}


int mostrarMenuYElegir(){
    int opcion;
    printf("selecciona tu figura con el numero de opcion \n");
    printf("opcion 1 \n");
    printf("cuadrado\n ----------\n");
    printf("opcion 2 \n");
    printf("triangulo\n ----------\n");
    printf("opcion 3 \n");
    printf("triangulo invertido\n ----------\n");
    printf("opcion 4 \n");
    printf("piramide\n ----------\n");
    printf("opcion 5 \n");
    printf("piramide invertida\n ----------\n \n\n");
    printf("ingresa 0 para terminar el programa");
    scanf("%d", &opcion);
    return opcion;
}

void mostrarResultado(int opcion, int f, int c){
    while(opcion!=0){
        switch(opcion){
        case 1:
            mostrarRectangulo(filas, columnas);
            break;
        case 2:
            mostrarTriangulo(filas, columnas);
            break;
        case 3:
            mostrarTrianguloInvertido(filas, columnas);
            break;
        case 4:
            mostrarPiramide(filas, columnas);
            break;
        case 5:
            mostrarPiramideInvertida(filas, columnas);
            break;
        default:
            printf("elegi una opcion valida");
        }
    opcion = mostrarMenuYElegir();
    }
}


void mostrarRectangulo(int f, int c){
    for(int i=0; i<f; i++){
        for (int j=0; j<c; j++){
            printf("x");
        }
        printf("\n");
    }
}


void mostrarTriangulo(int f, int c){
    for(int i=0; i<f; i++){
        for (int j=0; j<i; j++){
            printf("x");
        }
        printf("\n");
    }
}


void mostrarTrianguloInvertido(int f, int c){
    for(int i=0; i<f; i++){
        for (int j=c-i-1; j>=0; j--){
            printf("x");
        }
        printf("\n");
    }
}


void mostrarPiramide(int c){
    if(c%2 == 0){
       c = c+1;
    }
    for (int i=0; i<c/2; i++){
        for(int j=0; j<c; j++){
            if(j>c/2-1-i && j<c-c/2+i){
                printf("x");
            }
            else printf(" ");
        }
        printf("\n");
    }

}



void mostrarPiramideInvertida(int c){
    if(c%2 == 0){
       c = c+1;
    }
    for (int i=0; i<c/2; i++){
        for(int j=0; j<c; j++){
            if(j<c-1-i && j>c-c+i){
                printf("x");
            }
            else printf(" ");
        }
        printf("\n");
    }

}
