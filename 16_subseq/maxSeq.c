#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(size_t * array, size_t n)
{size_t count=1;
  size_t temp=0;
  size_t i;
  if(n==0)
    {return 0;
    }
  if(n==1)
    {return 1;
    }
  else
    { for(i=0;i<n;i++)
	{  if(array[i+1]>array[i])
	  {count++;
	  }
     else if(array[i+1]<=array[i])
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
