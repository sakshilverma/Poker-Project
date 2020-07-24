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
  if(argc>=0)
    {
      if(argc==1)
	{ FILE *f=fopen(argv[0], "r");
	  char *line=0;
  size_t sz=0;
  while(getline(&line, &sz, f) >= 0)
    {char ** data=&line;
      size_t count=sz;
      sortData(data, count);
      printf("%s", line);
      }
  free(line);
  if(fclose(f) != 0)
    {perror("Failed to close the input file\n");
      return EXIT_FAILURE;
    }}

      if(argc>1)
	{for(int i=0;i<argc;i++)
	{ FILE *f=fopen(argv[i], "r");
	  char *line=0;
  size_t sz=0;
  while(getline(&line, &sz, f) >= 0)
    {char ** data=&line;
      size_t count=sz;
      sortData(data, count);
      printf("%s", line);
      }
  free(line);
  if(fclose(f) != 0)
    {perror("Failed to close the input file\n");
      return EXIT_FAILURE;
    	}
	}}
    }
  if(argc<0){
  return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
