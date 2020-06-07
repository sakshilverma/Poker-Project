#include<stdio.h>

size_t maxSeq(int * array, size_t n)
{int count=1;
  int temp=0;
  if(n==0)
    {return 0;
    }
  if(n==1)
    {return 1;
    }
  else
    { for(int i=0;i<n;i++)
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
