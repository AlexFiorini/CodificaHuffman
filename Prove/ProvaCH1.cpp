#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <windows.h>
#define N 99

using namespace std;

int Lunghezza (char s[100]);
void Caratteri (char s[100]);

int Lunghezza (char s[100])				//Calcola la lunghezza della stringa (spazi compresi)
{
	int i;
	i=0;
	do
	{
		i++;
	}while(s[i]!='\0');
	
	return i;
}

char* readinput()
{
#define CHUNK 200
	char* input = NULL;
	char tempbuf[CHUNK];
	size_t inputlen = 0, templen = 0;
	do {
    	fgets(tempbuf, CHUNK, stdin);
    	templen = strlen(tempbuf);
    	input = (char*)realloc(input, inputlen+templen+1);
    	strcpy(input+inputlen, tempbuf);
    	inputlen += templen;
	} while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');
	int size = strlen(input);
	input[size-1] = '\0';
	return input;
}

int main ()
{
	char ch;
	int i, r=0, c=0, mat[100][100], freccia=26, j, k, tempc[100], tempv, max, shift=0, car=0, ultimo;
	string l;
	COORD coord;
	
	for(r=0;r<100;r++)
	{
		for(c=0;c<100;c++)
		{
			mat[r][c]=0;
		}
	}
	r=0;
	c=0;
	
	for(i=0;i<=N;i++)
	{
		tempc[i]=0;
	}
	
	
	printf("Inserisci la tua parola\n");
	char* s = readinput();
	i=Lunghezza(s);
	l=s;
	
	for(i=0;i<=255;i++)										//Conta caratteri
	{
		ch=i;
		
		int count= std::count(l.begin(), l.end(), ch);
		
		if(count!=0)
		{
			mat[r][0]=i;
			mat[r][N]=count;
			r++;
		}
	}
	
	printf("\n");
	
	for(r=0;r<100;r++)										//Mostra matrice non ordinata
	{
		if(mat[r][N]!=0)
		{
			printf("%c -> %d\n", mat[r][0], mat[r][N]);
		}
	}
	
	for(k=0;k<100;k++)
	{
		for(j=0;j<N;j++)	//Ordina matrice
		{
			if (mat[j][N]<mat[j+1][N])
			{
				tempv=mat[j][N];
				tempc[0]=mat[j][0];
				
				mat[j][N]=mat[j+1][N];
				mat[j][0]=mat[j+1][0];
				
				mat[j+1][N]=tempv;
				mat[j+1][0]=tempc[0];
				tempc[0]=0;
			}
		}	
	}
	
	max=0;
	coord.X=10;
	coord.Y=3;
	
	for(r=0;r<100;r++)										//Mostra matrice riordinata a fianco
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if(mat[r][N]!=0)
		{
			printf("%c -> %d\n", mat[r][0],  mat[r][N]);
			coord.Y=coord.Y+1;
			max++;
		}
	}
	max--;
	free(s);
}
