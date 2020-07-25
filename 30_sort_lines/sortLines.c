#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
    //WRITE YOUR CODE HERE!
if(argc<0){
  fprintf(stderr,"Insuficient argc");
  return EXIT_FAILURE;
  }

  if(argc==1)
	{ char *line=NULL;
  size_t sz=0;
  int j=0;
  char *all={0};
  while(getline(&line, &sz, stdin) >= 0)
    { all=malloc(sz);
      strcpy(all, line);
      j++;
      all++;
    }
  free(line);
    char ** data=&all;
      size_t count=j;
      sortData(data, count);
      for(int m=0;m<j;m++)
	{  printf("%s", all);
	  free(all);
	  all++;
	}
       return EXIT_SUCCESS;}

      if(argc>1)
	{for(int i=1;i<argc;i++)
	{ FILE *f=fopen(argv[i], "r");
	  if(f==NULL)
	    {fprintf(stderr,"Could not open file");
	      continue;
	    }
	  char *line1=NULL;
  size_t sz1=0;
  int k=0;
  char *all1={0};
  while(getline(&line1, &sz1, f) >= 0)
    { all1=malloc(sz1);
      strcpy(all1, line1);
      k++;
      all1++;
    }
  free(line1);
  char ** data1=&all1;
      size_t count1=k;
      sortData(data1, count1);
      int n1;
      {for(n1=0;n1<k;n1++)
      printf("%s", all1);
	  free(all1);
	  all1++;
      }
  if(fclose(f) != 0)
    {perror("Failed to close the input file\n");
      return EXIT_FAILURE;
    	}
	}}
    
  return EXIT_SUCCESS;
}
