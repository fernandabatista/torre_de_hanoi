/**********************************************************************************/
/******************TORRE DE HANOI COM 4 PINOS E 8 DISCOS***************************/
/**********Fernanda Batista de Oliveira e Tatiane Portela Medeiros*****************/
/**********************************************************************************/
/*********************DISCOS: tamanho total da torre (8)***************************/
/*********intervalo: espaço de uma torre ate outra pra usar no gotoxy**************/
/**A, B, C, D: variaveis que guardam quantos discos tem em cada pino (pro gotoxy)**/
/**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define DISCOS 8

int intervalo, A, B, C, D;

void hanoi(int disco, char inicio, char aux1, char aux2, char fim);
void checapinos(char origem, char destino, int n);
void pop(int i, int n);
void push(int i,int n);

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}

int main()
{
    int i, j;
    intervalo=18;


//desenha torres
    for(i=0; i<DISCOS; i++)
    {
        gotoxy(DISCOS,i+1);//A
        printf("|");
        gotoxy(DISCOS + intervalo, i+1);//B
        printf("|");
        gotoxy(DISCOS + intervalo*2, i+1);//C
        printf("|");
        gotoxy(DISCOS + intervalo*3, i+1);//D
        printf("|");
    }
    //desenha discos na torre A
    for(i=0; i<DISCOS; i++)
    {
        gotoxy(DISCOS-i,i+1);
        for(j=0; j<=i*2; j++)
        {
            if(j==i)
                printf("\xDC");
            else
                printf("\xDC");
        }
    }


    //id das torres
    gotoxy(DISCOS, DISCOS+2);
    printf("A");
    gotoxy(DISCOS+intervalo, DISCOS+2);
    printf("B");
    gotoxy(DISCOS+(intervalo*2), DISCOS+2);
    printf("C");
    gotoxy(DISCOS+(intervalo*3), DISCOS+2);
    printf("D");

    A = DISCOS;
    B=C=D=0;

    _sleep(1000);

    hanoi(DISCOS, 'A', 'B', 'C', 'D');
    gotoxy(1, DISCOS + 4);
}

void hanoi(int disco, char inicio, char aux1, char aux2, char fim)
{
    if ( disco == 1 )
        checapinos(inicio, fim, disco);
    else if ( disco == 2 )
    {
        checapinos(inicio, aux1, 1);
        checapinos(inicio, fim, 2);
        checapinos(aux1, fim, 1);
    }
    else
    {
        hanoi(disco - 2, inicio, aux2, fim, aux1);
        checapinos(inicio, aux2, disco-1);
        checapinos(inicio, fim, disco);
        checapinos(aux2, fim, disco-1);
        hanoi(disco - 2, aux1, inicio, aux2, fim);
    }
}
void checapinos(char origem, char destino, int n)
{
    int i,j,x;
    if(origem == 'A')
        A--;
    else if(origem == 'B')
        B--;
    else if(origem == 'C')
        C--;
    else if(origem == 'D')
        D--;
    for(i=0; i<n; i++)
    {
        if(origem == 'A')
            gotoxy(DISCOS - i,DISCOS - A);
        else if(origem == 'B')
            gotoxy((DISCOS-i) + intervalo, DISCOS-B);
        else if(origem == 'C')
            gotoxy(DISCOS-i+(intervalo*2), DISCOS-C);
        else if(origem == 'D')
            gotoxy(DISCOS-i+(intervalo*3), DISCOS-D);
        pop(i,n);
    }
    if(destino=='A')
        A++;
    else if(destino=='B')
        B++;
    else if(destino=='C')
        C++;
    else if(destino=='D')
        D++;
    for(i=0; i<n; i++)
    {
        if(destino=='A')
            gotoxy(DISCOS-i, DISCOS-A+1);
        else if(destino=='B')
            gotoxy((DISCOS-i)+intervalo, DISCOS-B+1);
        else if(destino=='C')
            gotoxy(DISCOS-i+(intervalo*2 ),DISCOS-C+1);
        else if(destino=='D')
            gotoxy(DISCOS-i+(intervalo*3), DISCOS-D+1);


        push(i, n);
    }
    _sleep(500);
}
void pop(int i, int n)
{
    int j;
    for(j=0; j<=i*2; j++)
    {
        if(j+1==n)
            printf("|");
        printf(" ");
    }
}
void push(int i,int n)
{
    int j;
    for(j=0; j<=i*2; j++)
        printf("\xDC");
}
