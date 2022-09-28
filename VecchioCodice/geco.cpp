#include <bits/stdc++.h>

void binario(int t[]);
void decimale(int t[]);
void exa(int dec);
char resti(int decimale);
void ottieni(int r[], int **matrix);

void binario(int t[])
{
	int i;
	
	for(i=0;i<11;i++)
	{
		t[i]=rand()%2;
		printf(" %d ", t[i]);
	}
	printf("\n");
	for(i=0;i<11;i++)
	{
		printf("(%d)", i);
	}
	printf("\n");
	decimale(t);
}

void decimale(int t[])
{
	int dec=0, i;
	
	for(i=0;i<11;i++)
	{
		dec+=t[10-i]*pow(2,i);
	}
	printf("Il suo equivalente in decimale e': %d\n", dec);
	exa(dec);
}

void exa(int dec)
{
	int i, resto=0;
	char exa[3];
	
	for(i=0;i<3;i++)
	{
		resto=dec%16;
		dec=dec/16;
		exa[2-i]=resti(resto);
	}
	
	printf("Il suo equivalente in esadecimale e': 0x");
	
	for(i=0;i<3;i++)
	{
		printf("%c", exa[i]);
	}
	printf("\n");
}

char resti(int decimale)
{
	char l;
	switch(decimale)
	{
		case 0:
			l='0';
			break;
		case 1:
			l='1';
			break;
		case 2:
			l='2';
			break;
		case 3:
			l='3';
			break;
		case 4:
			l='4';
			break;
		case 5:
			l='5';
			break;
		case 6:
			l='6';
			break;
		case 7:
			l='7';
			break;
		case 8:
			l='8';
			break;
		case 9:
			l='9';
			break;
		case 10:
			l='A';
			break;
		case 11:
			l='B';
			break;
		case 12:
			l='C';
			break;
		case 13:
			l='D';
			break;
		case 14:
			l='E';
			break;
		case 15:
			l='F';
			break;		
	}
	return l;
}

void ottieni(int r[], int **matrix)
{
	int i, j=10, cont=0;
	for(i=15;i>=0;i--)
	{
		if(i!=0 && i!=1 && i!=2 && i!=4 && i!=8)
		{
			r[j]=matrix[i/4][i%4];
			j--;
		}
	}
}
