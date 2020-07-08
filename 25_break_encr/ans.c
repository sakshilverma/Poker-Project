#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int freq(char a[])
{int count=1;
  int countmax=1;
  char max=a[0];
  for(int i=0;i<100;i++)
    {count=1;
      for(int j=i+1;j<100;j++)
	{if(a[i]==a[j])
	    {count++;
	      if(count>countmax)
		{countmax=count;
		  max=a[i];
		}
	    }
	    }
    }
  int m = max - 'e';
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
    {perror("Could not open the file\n");
      return EXIT_FAILURE;
    }

  char a[100];
  for(int i=0;i<100;i++)
    {a[i]=fgetc(f);
    }

 int k=freq(a);

 if(k>=0 && k<26)
   {fprintf(stdout,"%d\n",k);
   }
 else if(k<0 && k>=26)
   { fprintf(stderr,"Key not in range\n");
   return EXIT_FAILURE;
 }
 
 return EXIT_SUCCESS;
}
