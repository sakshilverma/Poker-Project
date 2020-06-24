#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned power (unsigned x, unsigned y);

unsigned main()
{
unsigned x2=0;
 unsigned y2=3;
 unsigned z2=1;
 unsigned x1=65789;
 unsigned y1=1;
 unsigned z1=65789;

 if(power(x2,y2) != z2)
   exit(EXIT_FAILURE);

if(power(x1,y1) != z1)
   exit(EXIT_FAILURE);

 exit(EXIT_SUCCESS); 
}
