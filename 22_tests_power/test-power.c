#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned power (unsigned x, unsigned y);

void main()
{
  if(power(0,0) != 1)
   {exit(EXIT_FAILURE);
   }

  if(power(25,2) != 625)
   {exit(EXIT_FAILURE);
   }

 if(power(121345,1) != 121345)
   {exit(EXIT_FAILURE);
   }

 else exit(EXIT_SUCCESS);
}
