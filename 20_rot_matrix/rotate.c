#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void rotate(char matrix[10][10])
{
  char mat[10][10];
  for(int k=0;k<10;k++)
    {
      for(int l=0;l<10;l++)
	{
	  mat[k][l]=matrix[k][l];
	}
    }
 
  for(int j=0;j<10;j++)
    {int m=0;
      for(int i=9;i>=0;i--)
	{  matrix[j][m]=mat[i][j];
	  m++;
    }
    }
}
