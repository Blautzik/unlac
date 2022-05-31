#include <stdio.h>
#include <stdlib.h>


void cargararray(int vec[], int tam);
void mostrararr(int vec[], int tam);
int contarimpares(int vec[], int tam);
int cargaraleatorio();


int main()
{
    int vec[8];
    cargararray(vec, 8);
    contarimpares(vec, 8);
    mostrararr(vec, 8);

}

void cargararray(int vec[], int tam)
{

    for(int i=0; i<tam-1; i++)
    {
        vec[i] = cargaraleatorio();
    }

}

int cargaraleatorio()
{
    return rand()%900+100;
}


int contarimpares(int vec[], int tam)
{
    vec[tam-1]=0;
    for(int i=0; i<tam-1; i++)
    {
        if (vec[i]%2 != 0)
        {
            vec[tam-1]++;
        }
    }
}

void mostrararr(int vec[], int tam)
{
    for(int i=0; i<8; i++)
    {
        printf(" %d ", vec[i]);
    }
}
