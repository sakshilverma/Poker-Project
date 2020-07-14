#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int main(int argc, char **argv)
{
  if(argc!=2)
    {fprintf(stderr,"Invalid argc\n");
      return EXIT_FAILURE;
    }
  FILE *f=fopen(argv[1],"r");
  if(f==NULL)
    {fprintf(stderr,"Invalid file\n");
      return EXIT_FAILURE;
    }

  char matrix[10][10];
  char a[12];
  int l=0;
  while(fgets(a,12,f))
    {
      if(l>9)
	{fprintf(stderr,"Too many lines\n");
      return EXIT_FAILURE;
	}

      if (strchr(a,'\0') != &a[11]){

	fprintf(stderr,"Few arguments\n");
	exit(EXIT_FAILURE);

      }

      if(strchr(a,'\n') != &a[10])
	{ if (strchr(a,'\n') == NULL){
	  fprintf(stderr,"Line too long\n");
	  exit(EXIT_FAILURE);
	}

	else
	{ fprintf(stderr,"Too short lines\n");
      return EXIT_FAILURE;
	}}
      for(int i=0;i<10;i++)
	{matrix[l][i]=a[i];
	}
      l++;
    }
  if(l!=10)
    {fprintf(stderr,"Too few lines\n");
      return EXIT_FAILURE;
    }

  rotate(matrix);
  for(int j=0;j<10;j++)
    {
      for(int k=0;k<10;k++)
	{printf("%c",matrix[j][k]);
	}
      printf("\n");
    }

  if(fclose(f) != 0)
    {fprintf(stderr,"Failed to close the input file\n");
      return EXIT_FAILURE;
    }
}
