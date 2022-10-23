#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <windows.h>
#define N 99

using namespace std;

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

int main ()
{
	char s[100], ch;
	int i, r=0, c=0, freccia=26, j, k, tempc[100], tempv, max, shift=0, car=0, ultimo;
	int **mat=new int *[100];
	string l;
	COORD coord;
	
	for(i=0;i<100;i++)
	{
		*(mat+i)=new int[100];
	}
	
	
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
	gets(s);
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
			printf("%c -> %d\n", mat[r][0],  mat[r][N]);
		}
	}
	
	printf("\n");
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
	
	printf("\n\n\n\n");										//Separa
	
	
	do
	{
		shift=0;
		car=0;

		do
		{
			shift++;
		}while(mat[max-1][shift]!=0);							//Lunghezza penultima riga
		
		do
		{
			car++;
		}while(mat[max][car]!=0);								//Lunghezza ultima riga
		
		for(i=0;i<shift;i++)									//Shift orizzontale
		{
			for (j=N-1;j>0;j--)
			{
				mat[max][j]=mat[max][j-1];
			}
			mat[max][i]=0;
		}

		for(i=0;i<=98;i++)										//Shift verticale
		{
			if(mat[max][i]!=0 && mat[max-1][i]==0)
			{
				mat[max-1][i]=mat[max][i];
			}
		}

		mat[max-1][N]=mat[max-1][N]+mat[max][N];				//Somma valori
		
		for(i=0;i<=99;i++)										//Azzeramento ultima riga
		{
			mat[max][i]=0;
		}
		
        for(k=0; k<100; k++)
        {
	        for(j=0;j<N;j++)
	        {
	            if (mat[j][N]<mat[j+1][N])
	            {
	                tempv=mat[j][N];
	                mat[j][N]=mat[j+1][N];
	                mat[j+1][N]=tempv;
	                
					for(i=0;i<=98;i++)
	                {
						tempc[i]=mat[j][i];
					}
					
					for(i=0;i<=98;i++)
					{
						mat[j][i]=mat[j+1][i];
					}
					for(i=0;i<=98;i++)
					{
						mat[j+1][i]=tempc[i];
					}
	            }
	        }
    	}
		
		for(r=0;r<max;r++)										//Stampa matrice a video				
		{
			for(c=0;c<99;c++)
			{
				if(mat[r][N]!=0 && mat[r][c]!=0)
				{
					printf("'%c'", mat[r][c]);
				}
			}
			
			if(mat[r][N]!=0)
			{
				printf(" -> %d\n", mat[r][N]);
			}
		}
		
		max=0;
		do
		{
			max++;
		}while(mat[max][0]!=0);
		max--;
		
		printf("\n\n");
	}while(mat[1][N]!=0);
}
