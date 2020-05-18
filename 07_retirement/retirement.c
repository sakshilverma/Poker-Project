#include<stdio.h>
#include<stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;

};
typedef struct _retire_info retire_info;

double account_balance (int startAge, double initial, retire_info x)
{ for(int i=startAge;i<=x.months;i++)
    { printf("Age %3d month %2d you have $%.2lf\n", i/12, i%12, initial);
      initial= (initial*x.rate_of_return) + initial;
      initial= initial+x.contribution;
    }
  return initial;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired)
{ double y=account_balance (startAge, initial, working);
  account_balance (startAge+working.months, y, retired);



}
int main()
{
  retire_info working;
  retire_info retired;

  working.months=489;
  working.contribution=10000;
  working.rate_of_return=0.045/12;

  retired.months=384;
  retired.contribution=-40000;
  retired.rate_of_return=0.01/12;

  retirement (327, 21345, working, retired);

}
