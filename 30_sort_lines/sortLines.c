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

char *readData(FILE *input)
{char *line=NULL;
  size_t sz;
  char *ans=0;
  int j=0;
while(getline(&line, &sz, input) >= 0)
  {ans[j]=*line;
    j++;
    }
 free(line);
 return ans;
}

size_t countLines(char **count)
{size_t size= (sizeof(count)) / sizeof(count[0]);
  return size;
}

int main(int argc, char ** argv) {
    //WRITE YOUR CODE HERE!
if(argc<0){
  fprintf(stderr,"Insuficient argc");
  return EXIT_FAILURE;
  }

  if(argc==1)
    { char *d =readData(stdin);
      char **data=&d;
      size_t count=countLines(data);
  
    sortData(data, count);
    char *buffer=NULL;
    size_t sz_buffer;
    for(size_t i=0;i<count;i++)
      {  sz_buffer =strlen(data[i])+1;
	buffer=realloc(buffer, sz_buffer);
	sscanf(data[i], "%[^\t]",buffer);
	    printf("%s", buffer);
	  free(data[i]);
	  sz_buffer=0;
	}
    free(data);
       return EXIT_SUCCESS;}

      if(argc>1)
	{for(int i=1;i<argc;i++)
	{ FILE *f=fopen(argv[i], "r");
	  if(f==NULL)
	    {fprintf(stderr,"Could not open file");
	      continue;
	    }

char *d =readData(f);
      char **data=&d;
      size_t count=countLines(data);
  
    sortData(data, count);
    char *buffer=NULL;
    size_t sz_buffer;
    for(size_t i=0;i<count;i++)
      {  sz_buffer =strlen(data[i])+1;
	buffer=realloc(buffer, sz_buffer);
	sscanf(data[i], "%[^\t]",buffer);
	    printf("%s", buffer);
	  free(data[i]);
	  sz_buffer=0;
	}
    free(data);
    return EXIT_SUCCESS;
	
  if(fclose(f) != 0)
    {perror("Failed to close the input file\n");
      return EXIT_FAILURE;
    	}
	}}
    
  return EXIT_SUCCESS;
}
