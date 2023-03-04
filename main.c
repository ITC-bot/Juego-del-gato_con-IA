#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void loop (char c [3][3]);
void matriz (char c [3][3]);
void mapa (char c [3][3]);
void introducir_jugada(char c [3][3]);
void introducir_ia (char c [3][3]);
int quien_gana (char c[3][3]);

int main()
{
    char c [3][3];
    loop (c);
    system ("pause");
    return 0;
}

void loop (char c [3][3])
{
    int contador,ganador;
    contador = 0;

    matriz(c);
    do {
        system("cls");
        mapa(c);

    if (contador % 2 == 0)
    {
        introducir_jugada(c);
    }else
    {
        introducir_ia(c);
    }

    ganador = quien_gana(c);
    contador++;
    }while (ganador == 2 && contador < 9);

// Cambio de línea para separar la matriz del resultado final
    printf("\n");

    if (ganador == 0) {
        printf("Ganador\n\n");
    } else if (ganador == 1) {
        printf("Perdiste\n\n");
    } else {
        printf("Empate\n\n");
}


}

void matriz (char c [3][3])
{
    int i, j;
    char aux;

    aux = '1';

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            c[i][j] = aux++;
        }
    }
}

void introducir_jugada(char c [3][3])
{
    int i, j, k;
    char aux;

    do{
        do{
            printf("Elige tu casilla: ");
            fflush(stdin);
            scanf("%c",&aux);
        }while(aux < '1' || aux > '9');

        k = 0;

        switch(aux){
            case '1' : {
                i = 0;
                j = 0;
                if (c [i][j] == 'X' || c[i][j]== 'O'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
             case '2' : {
                i = 0;
                j = 1;
                if (c [i][j] == 'X' || c[i][j]== '0'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
             case '3' : {
                i = 0;
                j = 2;
                if (c [i][j] == 'X' || c[i][j]== '0'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
            case '4' : {
                i = 1;
                j = 0;
                if (c [i][j] == 'X' || c[i][j]== '0'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
            case '5' : {
                i = 1;
                j = 1;
                if (c [i][j] == 'X' || c[i][j]== '0'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
            case '6' : {
                i = 1;
                j = 2;
                if (c [i][j] == 'X' || c[i][j]== '0'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
            case '7' : {
                i = 2;
                j = 0;
                if (c [i][j] == 'X' || c[i][j]== '0'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
             case '8' : {
                i = 2;
                j = 1;
                if (c [i][j] == 'X' || c[i][j]== '0'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
            case '9' : {
                i = 2;
                j = 2;
                if (c [i][j] == 'X' || c[i][j]== '0'){
                    k = 1;
                    printf("Lugar ocupado, elige otra casilla\n\n");
                }
                break;
            }
        }
    }while(k == 1);

    c[i][j]= 'X';
}

void mapa (char c [3][3])
{
    int i, j;

     for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (j<2){
                printf(" %c |",c[i][j]);
            }else{
                printf(" %c  ",c[i][j]);
            }
        }
        if (i < 2){
            printf ("\n-----------\n");
        }
    }
    printf("\n\n");
}

void introducir_ia (char c [3][3]){
    int i, j, k;

    srand (time(NULL));
    do{
        i = rand() % 3;
        j = rand() % 3;
        k = 0;

        if(c[i][j] == 'X' || c[i][j] == 'O'){
            k = 1;
        }
    }while(k == 1);

    c[i][j]= 'O';
}

int quien_gana(char c[3][3])
{
    int i;
    for (i = 0; i < 3; i++) {
        if (c[i][0] == c[i][1] && c[i][0] == c[i][2]) {
            if (c[i][0] == 'X') {
                return 0;
            } else if (c[i][0] == 'O') {
                return 1;
            }
        }
        if (c[0][i] == c[1][i] && c[0][i] == c[2][i]) {
            if (c[0][i] == 'X') {
                return 0;
            } else if (c[0][i] == 'O') {
                return 1;
            }
        }
    }
    if (c[0][0] == c[1][1] && c[0][0] == c[2][2]) {
        if (c[0][0] == 'X') {
            return 0;
        } else if (c[0][0] == 'O') {
            return 1;
        }
    }
    if (c[0][2] == c[1][1] && c[0][2] == c[2][0]) {
        if (c[0][2] == 'X') {
            return 0;
        } else if (c[0][2] == 'O') {
            return 1;
        }
    }
    return 2;
}
