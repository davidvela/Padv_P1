/* 
 * Author: David Vela Tirado
 * Software Developer
 * email:  david.vela.tirado@gmail.com
 * 
 *  */

//#include "MemoryManager.h"
#include<stdio.h>
#include <memory.h>
#include <stdlib.h>

struct matfloat  //definicion de la estructura matfloat
{
    int nfilas; //numero de filas
    int ncolumnas; //numero de columnas
    float **ppmatrizf; //puntero a puntero a float
};
//tanto a,b,d  me permiten controlar si se ha ejecutado o no algun paso anterior necesario
int a=0; //para ver si la matriz esta creada
int b=0; //para ver si en la matriz se han introducido datos
int d=0; //permite ver si hay alguna matriz declarada
struct matfloat principal;


float **construirmatriz(int ncolumnas, int nfilas) //desarrollo de la funcion construir matriz
{

 int i=0;
a=1; //pone a 1 la variable  que indica que se ha creado matriz
 float **p; //puntero a puntero float
 p=(float**)malloc( nfilas*(sizeof (float*))); //reserva de memoria para la matriz  de punteros (filas)
 if(p==NULL)printf("fallo de memoria");
 for( i=0; i<nfilas; i++)
 { p[i]=(float*)malloc(ncolumnas*(sizeof (float))); //reseva de memoria de las columnas unida a la matriz de punteros(filas)
 if (p[i]==  NULL) printf("fallo de memoria");
 }
 return p; //retorno del puntero a puntero P

}

void introducirdatos(matfloat* pdestino) //desarrollo de la funcion introducir datos en la matriz
{
    int i=0,j=0;
    printf("introduzca los datos en la matriz\n");
for(i=0;i<pdestino->nfilas;i++)
for(j=0;j<pdestino->ncolumnas;j++)
{
printf("dato [ %d][ %d]",i,j);
scanf("%f",&pdestino->ppmatrizf[i][j]); //introduccion de datos en la matriz en la pisicion i j
}
}

void mostrar(matfloat* pdestino) //desarrollo de la funcion para mostrar los datos de la matriz
{
    printf("los datos son:");
    int i=0,j=0;
for(i=0;i<pdestino->nfilas;i++)
{
printf("\n");

for(j=0;j<pdestino->ncolumnas;j++)
{
printf("dato [ %d][ %d]= %f",i,j,pdestino->ppmatrizf[i][j]); //impresion por pantalla de la posicion i j de la amtriz
}
}
printf("\n");
}


void destruir(matfloat* pvictima) //desarrollo de la funcion destruir matriz
{
    a=0;
    b=0;
    d=0;
    int i=0;
for(i=0;i<pvictima->nfilas;i++)
{
free(pvictima->ppmatrizf[i]); //liberacion de memoria de la matriz de columnas
}
free(pvictima->ppmatrizf); //liberacion de la memoria de la matriz de punteros (puntero a puntero)
}





int main()
{
    {
    int opcion;
    do // ejecuta el menu hasta que no se pulse salir
    {

printf("seleccione opcion deseada:\n\n");
printf("1.-Construir matriz\n2.-Introducir Matriz\n3.-Volcar matriz\n4.-Destruir matriz\n5.-Terminar\n\n");
scanf("%d",&opcion); //sentencia para crear menus
switch(opcion)
{
 case 1: //opcion 1 del menu
 {
     if(a==1)
    {
        printf("existe ya una matriz se va a sobreescribir con la nueva dimension\n");
        b=0;
        d=0;

    }
  printf("dame numero de columnas\n");
  scanf("%d",&principal.ncolumnas); //guarda en numero de columnas
  printf("dame numero de filas\n");
  scanf("%d",&principal.nfilas); //guarda en numero de filas
  principal.ppmatrizf=construirmatriz(principal.ncolumnas,principal.nfilas);//llamada a la funcion contruir matriz
 }
  break;
 case 2: //opcion 2 del menu
  {
      if (a==1)
      {
        b=1; //pone a 1 la variable  que indica que se han introducido datos en la matriz
        printf(" opcion2 \n");
        introducirdatos(&principal); //llamada a la funcion introducir datos
      }
      else
      {
          printf("no ha creado la matriz  primero ha de ser creada\n");
          printf("dame numero de columnas\n");
          scanf("%d",&principal.ncolumnas); //guarda el numero de columnas
          printf("dame numero de filas\n");
          scanf("%d",&principal.nfilas); //guarda en numero de filas
          principal.ppmatrizf=construirmatriz(principal.ncolumnas,principal.nfilas);//llamada a la funcion contruir matriz
          introducirdatos(&principal);
      }
  }

  break;
 case 3://opcion 3
 {
     printf(" opcion3\n");
     if (b==1) //permite controlar si se han introducido datos en la matriz para ser mostrados
     {
     mostrar(&principal); //llamada a la funcion mostrar
     }
     else
     {
         if(a==1 & b==0) //controla si la matriz ha sido creada pero no contiene datos
         {
             b=1;
            printf("no ha introducido datos en la matriz hagalo\n");
            introducirdatos(&principal);
            mostrar(&principal);
         }
         if (a!=1) //controla si la matriz ha sido creada
         {
          printf("no ha creado la matriz  primero ha de ser creada\n");
          printf("dame numero de columnas\n");
          scanf("%d",&principal.ncolumnas); //guarda en numero de columnas
          printf("dame numero de filas\n");
          scanf("%d",&principal.nfilas); //guarda en numero de filas
          principal.ppmatrizf=construirmatriz(principal.ncolumnas,principal.nfilas);//llamada a la funcion contruir matriz
          introducirdatos(&principal);
            mostrar(&principal);

         }


     }



 }
  break;
 case 4: //opcion 4 menu
 {
  printf(" opcion4\n");
  destruir(&principal); //llamada a la funcion destruir matriz
 }
  break;

 case 5: //opcion 5 menu
  printf(" opcion5\n");
  break;

 default:
  printf(" SOLO N⁄MEROS ENTRE 1 Y 5"); //se muestra en caso de introducir una opcion incorrecta
 }
    }
    while (opcion!=5);
}
//MemoryManager::dumpMemoryLeaks();
}

