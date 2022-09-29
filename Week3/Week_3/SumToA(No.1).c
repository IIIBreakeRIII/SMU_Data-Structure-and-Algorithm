//
//  SumToA(No.1).c
//  Week_3
//
//  Created by 현소류 on 2022/09/20.
//

#include <stdio.h>

int main() {
  int num;
  int sum = 0;
  scanf("%d", &num);
  
  for(int i = 0; i <= num; i++) {
    sum += i;
  }
  printf("%d", sum);
}
