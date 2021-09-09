/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Acer
 *
 * Created on 3 de septiembre de 2021, 09:30 AM
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char temporal[100];

char ***matrizCSV = NULL; //Crea matriz para leer archivo CSV
int *contador = NULL;
char ***nuevaMatriz = NULL;
char *centro = NULL;
int lineas = 0, tamanio = 0, campos = 0;


int i, j;

int main() {
    FILE *lectura = NULL;
    lectura = fopen("peliculasFavoritasESD135_2021.csv", "r");
    if (lectura != NULL) {
        do {
            memset(temporal, 0, 100);
            fgets(temporal, 100, lectura);
            lineas++;
            matrizCSV = realloc(matrizCSV, lineas * sizeof (char*));
            nuevaMatriz = realloc(nuevaMatriz, lineas * sizeof (char*));
            contador = realloc(contador, lineas * sizeof (int));
            matrizCSV[lineas - 1] = NULL;
            centro = strtok(temporal, ",");
            campos = 0;
            while (centro != NULL) {
                campos++;
                matrizCSV[lineas - 1] = realloc(matrizCSV[lineas - 1], sizeof (char*)*campos);
                tamanio = strlen(centro);
                matrizCSV[lineas - 1][campos - 1] = calloc(tamanio + 1, sizeof (char));
                strncpy(matrizCSV[lineas - 1][campos - 1], centro, tamanio);
                centro = strtok(NULL, ",");
            }
            contador[lineas - 1] = campos;
        } while (feof(lectura) == 0);
        fclose(lectura);
        printf("Mostrando valores de archivo CSV\n");
        i = 0;
        while (i < lineas) {
            j = 0;

            while (j < contador[i]) { // Aqui se transforman los valores
                printf(" %s\t", matrizCSV[i][j]);
                j++;
            }
            i++;
        }
    } else {
        printf("Error leyendo el archivo CSV\n");
    }

   
        printf("Mostrando Matriz Transpuesta\n");
        for (int j = 1; j < 6; j++) {

            for (int i = 1; i < 58; i++)

                printf(" %s", matrizCSV[i][j]);
            printf("\n");
        }
        void transpuesta(){
     printf("Matriz transpuesta\n");
    for (int j = 1; j < 6;j++) {
        
        for (int  i= 1; i < 58; i++)
          
            printf(" %s", matrizCSV[i][j]);
            printf("\n");
        } 
        }
    
}

