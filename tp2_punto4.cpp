#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
    int velocidad;//entre 1 y 3 Gherz 
    int anio;//entre 2000 y 2017 
    int cantidad;//entre 1 y 4 
    char *tipo_cpu;//valores del arreglo tipos
}PC;

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void cargarPc(PC *cargar, int cantPc);
void mostrarPc(PC *mostrar, int cantPc);
void pcAntigua(PC *vieja, int cantPc);
void pcVelocidad(PC *veloz, int cantPc);

int main ()
{

    srand(time(NULL));
    int cantPc;
    printf("ingrese la cantidad de computadoras: ");
    scanf("%d", &cantPc);
    printf("\n");

    PC *compu = (PC *) malloc(cantPc * sizeof(PC));

    cargarPc(compu, cantPc);
    mostrarPc(compu, cantPc);
    pcAntigua(compu, cantPc);
    pcVelocidad(compu, cantPc);

    getchar();
    return 0;
}

void cargarPc(PC *cargar, int cantPc)
{
    int i;

    for(i=0; i<cantPc; i++){
        (*(cargar + i)).velocidad = rand()%3 + 1;
        (*(cargar + i)).anio = rand()%18 + 2000;
        (*(cargar + i)).cantidad = rand()%4 + 1;
        (*(cargar + i)).tipo_cpu = *(tipos + (rand()%6));
    }
}

void mostrarPc(PC *mostrar, int cantPc)
{
    int k;
    for(k=0; k<cantPc; k++){
        printf("CPU: %s.\n", (*(mostrar + k)).tipo_cpu);
        printf("Año: %d.\n", (*(mostrar + k)).anio);
        printf("Velocidad: %dGHz.\n", (*(mostrar + k)).velocidad);
        printf("cantidad de nucleos: %d.\n", (*(mostrar + k)).cantidad);
        printf("\n");
    }
}

void pcAntigua(PC *vieja, int cantPc)
{
    int j, anio1 = 2018;
    PC aux;

    for (j=0; j<cantPc; j++)
    {
        if (anio1 == 2018)
        {
            aux = *(vieja + j);
            anio1 = 0;
        } else
        {
            if((*(vieja + j)).anio < aux.anio)
            {
                aux = *(vieja + j);
            }
        }
    }
    printf("\n");
    printf("La PC mas vieja es:\n");
    mostrarPc(&aux, 1);
}

void pcVelocidad(PC *veloz, int cantPc)
{
    int n, vel = 5;
    PC aux;

    for (n=0; n<cantPc; n++)
    {
        if (vel == 5)
        {
            aux = *(veloz + n);
            vel = 0;
        } else
        {
            if((*(veloz + n)).velocidad > aux.velocidad)
            {
                aux = *(veloz + n);
            }
        }
    }
    printf("\n");
    printf("La PC mas veloz es:\n");
    mostrarPc(&aux, 1);
}