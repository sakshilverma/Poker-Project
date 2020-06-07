#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n);

int main()
{
  int a[]={1,3,5,4,9};
  if (maxSeq(a,5) != 3)
    {
    return EXIT_FAILURE;
  }

  int b[]={1,5,3,6,4,7,2,9,8};
  if (maxSeq(b,9) != 2)
    {
      return EXIT_FAILURE;
    }

  int c[]={1};
  if (maxSeq(c,1) != 1)
    {
      return EXIT_FAILURE;
    }
  
  int d[]={-5,-4,-3,-2,-1,0};
  if (maxSeq(d,6) != 6)
    {
      return EXIT_FAILURE;
    }

  int f[]={};
  if (maxSeq(f,0) != 0)
    {
      return EXIT_FAILURE;
    }

  int g[]={-1000,-11,-2,-2000};
  if (maxSeq(g,4) != 3)
    {
      return EXIT_FAILURE;
    }

  int h[]={2,1000};
  if (maxSeq(h,2) != 2)
    {
      return EXIT_FAILURE;
    }
  int i[]={0,50,1000};
  if (maxSeq(i,3) != 3)
    {
      return EXIT_FAILURE;
    }
  int j[]={2,4,6,6};
  if (maxSeq(j,4) != 3)
    {
      return EXIT_FAILURE;
    }

  int k[]={1,2,7,3,8,12,16};
  if (maxSeq(k,7) != 4)
    {
      return EXIT_FAILURE;
    }
  
  return EXIT_SUCCESS;
}
