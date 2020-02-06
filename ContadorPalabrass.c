/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContadorPalabrass.c
 * Author: Enamorado
 *
 * Created on 6 de febrero de 2020, 0:06
 */

#include <stdio.h>
#include <stdlib.h>


int main () 
{ 
  char c;
  int dentroPalabra = 0, numeroPalabras = 0;
   int dentroNumero = 0, cantidadNumero = 0;
   FILE * flujo=fopen("pruebas.txt", "rb");
    if(flujo==NULL){
        perror("Error al abrir el archivo");
    }
  while ((c = getc(flujo)) != EOF)
  {
    if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
	{
	  if (dentroPalabra==0)
	  {
	    numeroPalabras += 1;
		dentroPalabra = 1;
	  }
	}
	else if (dentroPalabra == 1)
      dentroPalabra = 0;
  }
   int valor=0;
   while ( feof(flujo)==0)
  {
   fscanf(flujo,"%d",&valor);
   if((valor>=0)&(valor<=9))
    {
         if (dentroNumero==0)
	  {
	    cantidadNumero += 1;
		dentroNumero = 1;
	  }
         else if (dentroNumero == 1)
         dentroNumero = 0;
    }
   }
  printf("\n\nEl número de palabras del fichero es: %d\n%d\n", numeroPalabras, cantidadNumero);
  printf("%d",valor);

  // fclose(flujo);
  //  printf("\n\nSe ha leido el archivo correctamente ...");
    return 0;
}
