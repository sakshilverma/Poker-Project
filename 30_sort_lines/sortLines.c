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
 if(argc==1)
{char *line=NULL;
  size_t sz;
  size_t j=0;
  char **ans=NULL;
while(getline(&line, &sz, stdin) >= 0)
  { ans=realloc(ans, (j+1)*sizeof(*line));
    ans[j]=line;
    line=NULL;
     j++;
  }
 free(line);
     sortData(ans, j);
for(size_t i=0;i<j;i++)
      {	    printf("%s", ans[i]);
	  free(ans[i]);
	        }
     free(ans);
     return EXIT_SUCCESS;}

 else if(argc>1)
	{for(int i=0;i<argc;i++)
	{ FILE *f=fopen(argv[i], "r");
	  if(f==NULL)
	    { perror("Could not open file\n");
	      exit(EXIT_FAILURE);
	    }
char *line=NULL;
  size_t sz;
  size_t j=0;
  char **ans=NULL;
while(getline(&line, &sz, f) >= 0)
  { ans=realloc(ans, (j+1)*sizeof(*ans));
    ans[j]=line;
line=NULL;
 j++;
  }
  free(line);
    sortData(ans, j);
    char *buffer=NULL;
    size_t sz_buffer;
    for(size_t i=0;i<j;i++)
      {  sz_buffer =strlen(ans[i])+1;
	buffer=realloc(buffer, sz_buffer);
	sscanf(ans[i], "%[^\t]",buffer);
	printf("%s", buffer);
	free(ans[i]);
	sz_buffer=0;
      }
    free(ans);
    if(fclose(f) != 0)
      {perror("Failed to close the input file\n");
	exit(EXIT_FAILURE);
      }
   }
return EXIT_SUCCESS;
	}

 else if(argc<1){
  fprintf(stderr,"Insuficient argc");
  exit(EXIT_FAILURE);
 }	
}
