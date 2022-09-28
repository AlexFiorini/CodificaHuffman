int **creamat(int **matrix);
void riempi(int **matrix, int array[]);
void mettibitp(int bit, int **matrix);
void stampamat(int **matrix);
int creaerr(int **matrix);
void copiamat(int **orig, int **dest);
int conbitg(int **matrix);
int trovaerr(int bit, int **matrix);
void correrr(int pos, int **matrix);

int **creamat(int **matrix)
{
	int i, j;
	matrix=new int*[4];
	
	for (i=3; i>=0; i--)
    {
        matrix[i] = new int[4];
        for (j=3; j>=0; j--)
        {
        	matrix[i][j]=0;
    	}
  	}
  	

	return matrix;
}

void riempi(int **matrix, int array[])
{
	int j, k=10;
	
	for(j=3;j>=0;j--)
	{
		matrix[3][j]=array[k];
		k--;
	}
	for(j=3;j>0;j--)
	{
		matrix[2][j]=array[k];
		k--;
	}
	for(j=3;j>0;j--)
	{
		matrix[1][j]=array[k];
		k--;
	}
	matrix[0][3]=array[0];
}

void mettibitp(int bit, int **matrix)
{
	int uni=0, i, j;
	switch(bit)
	{
		case 0:
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(matrix[i][j]==1)
					uni+=1;
				}
			}
			if(uni%2==0)
			{
				matrix[0][0]=0;
			}
			else
			{
				matrix[0][0]=1;
			}
		break;
		
		case 1:
			for(i=1;i<4;i++)
			{
				if(matrix[i][1]==1)
				uni+=1;
			}
			for(i=0;i<4;i++)
			{
				if(matrix[i][3]==1)
				uni+=1;
			}
			
			if(uni%2==0)
			{
				matrix[0][1]=0;
			}
			else
			{
				matrix[0][1]=1;
			}
		break;
		
		case 2:
			for(i=1;i<4;i++)
			{
				if(matrix[i][2]==1)
				uni+=1;
			}
			for(i=0;i<4;i++)
			{
				if(matrix[i][3]==1)
				uni+=1;
			}
			
			if(uni%2==0)
			{
				matrix[0][2]=0;
			}
			else
			{
				matrix[0][2]=1;
			}
		break;
		
		case 4:
			for(j=1;j<4;j++)
			{
				if(matrix[1][j]==1)
				uni+=1;
			}
			for(j=0;j<4;j++)
			{
				if(matrix[3][j]==1)
				uni+=1;
			}
		
			if(uni%2==0)
			{
				matrix[1][0]=0;
			}
			else
			{
				matrix[1][0]=1;
			}
		break;
		
		case 8:
			for(j=1;j<4;j++)
			{
				if(matrix[2][j]==1)
				uni+=1;
			}
			for(j=0;j<4;j++)
			{
				if(matrix[3][j]==1)
				uni+=1;
			}
			
			if(uni%2==0)
			{
				matrix[2][0]=0;
			}
			else
			{
				matrix[2][0]=1;
			}	
		break;
		
		default:
		printf("Errore");
		break;
	}
}

void stampamat(int **matrix)
{
	int i, j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int creaerr(int **matrix)
{
	int p=rand()%16;
	
	if(matrix[p/4][p%4]==0)
	{
		matrix[p/4][p%4]=1;
	}
	else
	{
		matrix[p/4][p%4]=0;
	}
	return p;
}

void copiamat(int **orig, int **dest)
{
	int i, j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			dest[i][j]=orig[i][j];
		}
	}
}

int conbitg(int **matrix)
{
	int uni=0, i, j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(matrix[i][j]==1)
			uni+=1;
		}
	}
	uni=uni%2;
	if(uni==matrix[0][0])
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int trovaerr(int bit, int **matrix)
{
	int uni=0, i, j;
	switch(bit)
	{
		case 1:
			for(i=1;i<4;i++)
			{
				if(matrix[i][1]==1)
				uni+=1;
			}
			for(i=0;i<4;i++)
			{
				if(matrix[i][3]==1)
				uni+=1;
			}
			uni=uni%2;
			if(matrix[0][1]==uni)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		break;
		
		case 2:
			for(i=1;i<4;i++)
			{
				if(matrix[i][2]==1)
				uni+=1;
			}
			for(i=0;i<4;i++)
			{
				if(matrix[i][3]==1)
				uni+=1;
			}
			uni=uni%2;
			if(matrix[0][2]==uni)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		break;
		
		case 4:
			for(j=1;j<4;j++)
			{
				if(matrix[1][j]==1)
				uni+=1;
			}
			for(j=0;j<4;j++)
			{
				if(matrix[3][j]==1)
				uni+=1;
			}
			uni=uni%2;
			if(matrix[1][0]==uni)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		break;
		
		case 8:
			for(j=1;j<4;j++)
			{
				if(matrix[2][j]==1)
				uni+=1;
			}
			for(j=0;j<4;j++)
			{
				if(matrix[3][j]==1)
				uni+=1;
			}
			uni=uni%2;
			if(matrix[2][0]==uni)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		break;
		
		default:
		printf("Errore");
		break;
	}
}

void correrr(int pos, int **matrix)
{
	if(matrix[pos/4][pos%4]==0)
	{
		matrix[pos/4][pos%4]=1;
	}
	else
	{
		matrix[pos/4][pos%4]=0;
	}
}
