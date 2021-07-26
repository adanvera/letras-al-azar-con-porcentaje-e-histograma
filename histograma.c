

/* ITEM 4
Ejercicio 4: Histograma en C
Para entregar: Archivo fuente de la solución
Escriba un programa C que permita generar un array aleatorio de letras mayúsculas del
abecedario inglés. El tamaño del array debe ser de 1000 posiciones.
Finalmente debe imprimirse en pantalla la cantidad de veces que se repite cada letra en el
array como porcentajes de un histograma.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define cant 1000


int aleatorioEnRango(int , int );
void cadenaAleatoria(int, char []);
void contar(char [], int );

int main(void) {
    srand(getpid());
    int i;
    char *aux;
    char destino[cant + 1] = "";// El +1 es por el carácter nulo que marca el fin de la cadena
    cadenaAleatoria(cant, destino);

    /*
    descomentar si quiere ver toda la lista de LETRAS generadas
    
    printf("%s", destino);
    */

    printf("\n\n");
    for (i=0;i<26;i++){
      contar(destino, i);
    }
    printf("\n");
}


// maximo y minimo son inclusivos
int aleatorioEnRango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void cadenaAleatoria(int longitud, char *destino) {// Funcion que crea las letras aleatorias en cuestion
	int x;
    char muestra[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for ( x = 0; x < longitud; x++) {
        int indiceAleatorio = aleatorioEnRango(0, (int) strlen(muestra) - 1);
        destino[x] = muestra[indiceAleatorio];
    }
}
void contar(char aux[], int i)//funcion para contar cuantas veces se repite una letra, la misma devuelve la cantidad, procentaje y represantacion de histograma
{
  char muestra[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int j, num,contador;
  float pt;
  char letra;
  contador = 0;
  num = strlen(aux);
  for (j = 0; j < num; j++){//ciclo donde recorre para sumar las veces que se repite una letra
    if (aux[j] == muestra[i]){
      contador+=1;
      letra = muestra[i];
    }       
  }
  if (contador != 0)//si el contador es diferente de cero procede a imprimir la cantidad y los datos correspondientes a la misma
    pt = contador*100.0/1000;
    printf(" %c Repite %d veces, el %.2f %% aprox.\t", letra, contador, pt);
    for(i=0;i<contador;i++){
        printf("*");
    }
    printf(" \n");
}
