#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int freq(FILE *f)
{ int a[26]={0};
  int b,k,n=0;
  while((b=fgetc(f)) != EOF && n<10000)
    {if(isalpha(b))
	{b=tolower(b); 
	  k=b-'a';
      a[k]=a[k]+1;
    }
      n++;
    }
   int countmax=0;

  for(int i=0;i<26;i++)
    {if(countmax<a[i])
     {countmax=i;
		}
	    }
    
  return ((countmax+22)%26);
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

