#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calcFund(double initial, double rate_of_return, double contribution){
  initial=initial+(initial*rate_of_return);
  initial=initial+contribution;
  return initial;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired)
{
  int age=startAge/12;
  int month=startAge%12;
  int finalpoint;
  for (int ret=0; ret<2; ret++){
    if (ret==0) {
      finalpoint=working.months;
    }
    if (ret==1) {
      finalpoint=retired.months;
    }
    for (int i=0; i<finalpoint; i++){
  printf("Age %3d month %2d you have $%.2f\n", age, month, initial);
  if (ret==0){
  initial=calcFund(initial, working.rate_of_return, working.contribution);
  }
  if (ret==1){
    initial = calcFund(initial, retired.rate_of_return, retired.contribution);
  }
  month++;
    if (month==12) {
      month=0;
      age++;
  }  
  }
  }
  }

int main() {
retire_info working;
retire_info retired; 
working.months=489;
working.contribution=1000;
working.rate_of_return=(0.045/12);
retired.months=384;
retired.contribution=-4000;
retired.rate_of_return=(0.01/12);
retirement(327, 21345, working, retired) ;
 return EXIT_SUCCESS;
}
