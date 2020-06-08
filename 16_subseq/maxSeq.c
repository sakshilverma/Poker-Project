#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n)
{int count=1;
  size_t temp=0;
  int i;
int *array1=&array[0]
  if(n==0)
    {return 0;
    }
  if(n==1)
    {return 1;
    }
  else
    { for(i=0;i<n;i++)
	{  if(array1[i+1]>array1[i])
	  {count++;
	  }
     else if(array1[i+1]<=array1[i])
       { if(count>temp)
	 {temp=count;
	  count=1;
	}
       else count=1;
       }
    }
      if(temp>=count)
	{ return temp;
    }
      else return count;
      
}
}
