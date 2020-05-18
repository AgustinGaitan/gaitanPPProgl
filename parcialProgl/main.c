#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMNOTE 4

typedef struct
{
    int id;
    char procesador[30];
    char marca[30];
    float precio;

}eNotebook;



float aplicarDescuento(float precioProducto);
int contarCaracteres(char* cadena, char caracter);
void ordenarNotebooks(eNotebook lista[], int tam);
void mostrarNotebooks(eNotebook* x,int tam);
void mostrarNotebook(eNotebook x);


int main()
{
   float precio = 105;
   char cadena[30] = "Los arboles verdes";
   char caracter = 's';
   eNotebook listaNotebooks[TAMNOTE] = {{1,"i5 9400f", "hp", 40000},{2,"amd athlon x4","hitachi",45000}, {3,"i9 9800k", "hp", 60000}, {4,"amd phenom x4", "lenovo",50000 }};

    printf("***************************\n\n");
    printf("Descuento\n\n");
    printf("%f", aplicarDescuento(precio));

    printf("\n\n");
    printf("***************************\n\n");

    printf("Contador caracteres\n\n");
    printf("%d", contarCaracteres(cadena,caracter));


     printf("\n\n");
    printf("***************************\n\n");

    printf("Ordenamiento array\n\n");

    ordenarNotebooks(listaNotebooks,TAMNOTE);
    mostrarNotebooks(listaNotebooks,TAMNOTE);


}



float aplicarDescuento(float precioProducto)
{
    float total = 0;

    total = precioProducto - (precioProducto *0.05);

    return total;
}

int contarCaracteres(char* cadena, char caracter)
{
    int cant = 0;

    for(int i = 0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] == caracter)
        {
            cant++;
        }
    }

    return cant;
}

void ordenarNotebooks(eNotebook lista[], int tam)
{
    eNotebook aux;
     for(int i = 0; i < tam -1 ; i++)
    {
        for(int j = i + 1; j < tam ; j ++)
        {
               if(strcmp(lista[i].marca,lista[j].marca) == -1)
               {
                 aux = lista[i];
                 lista[i] = lista[j];
                 lista[j] = aux;


               }
               else if(strcmp(lista[i].marca,lista[j].marca) == 0 && lista[i].precio < lista[j].precio )
               {

                 aux = lista[i];
                 lista[i] = lista[j];
                 lista[j] = aux;

               }

        }

    }//fin del for principal



}


void mostrarNotebooks(eNotebook* lista,int tam)
{


    printf("**Lista de Notebooks**\n");
    printf("ID         Marca           Precio                Procesador\n");
    for(int i = 0; i < tam ; i++)
    {

            mostrarNotebook(lista[i]);

    }

}
void mostrarNotebook(eNotebook lista)
{

    printf("%d     %10s      %.2f     %20s\n",lista.id,lista.marca,lista.precio,lista.procesador);

}
