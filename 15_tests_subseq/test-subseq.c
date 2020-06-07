#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n);

int main()
{
  
    int a[]={3,4,-3};
  if (maxSeq(a,3) != 2)
    {
    return EXIT_FAILURE;
  }

  int b[]={1,6,8,7,90,102,150,256};
  if (maxSeq(b,8) != 5)
    {
    return EXIT_FAILURE;
  }

  int c[]={-90,-84,-65,4,-123};
  if (maxSeq(c,5) != 4)
    {
    return EXIT_FAILURE;
    }

  int d[]={-34,-31,-12,-56,3,4,5};
  if (maxSeq(d,7) != 3)
    {
    return EXIT_FAILURE;
  }

  int e[]={1,2,1,3,5,7,2,4,6,9};
  if (maxSeq(e,10) != 4)
    {
    return EXIT_FAILURE;
  }
  
return EXIT_SUCCESS;
}
