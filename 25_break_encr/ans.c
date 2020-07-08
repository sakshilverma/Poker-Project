#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int freq(FILE *f)
{ int a[26]={0},b,k;
  while((b=fgetc(f)) != EOF)
    {if(isalpha(b))
	{
	  k=b-'a';
      a[k]+=1;
    }
    }
   int countmax=a[0];

  for(int i=0;i<26;i++)
    {if(countmax<a[i])
     {countmax=a[i];
		}
	    }
    
  int m = countmax - 'e';
  if(m<0)
    {if(m==-4)
	{m=22;}
      else if(m==-3)
	{m=23;}
      else if(m==-2)
	{m=24;}
      else if(m==-1)
	{m=25;}
    }
  return m;
}

int main(int argc, char ** argv)
{
  if(argc != 2)
    {fprintf(stderr,"Invalid argc\n");
      return EXIT_FAILURE;
    }

  FILE *f=fopen(argv[1], "r");
  if(f==NULL)
    {fprintf(stderr,"Could not open the file\n");
      return EXIT_FAILURE;
    }

  int k=freq(f);

  if(k>=0 && k<26)
    {printf("%d\n",k);
    }
  if(k<0 && k>=26)
    { fprintf(stderr,"Key not in range\n");
      return EXIT_FAILURE;
    }
  if(fclose(f) != 0) {
    fprintf(stderr,"Failed to close the input file!\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

