//
//  Athlete.c
//  Week12
//
//  Created by 현소류 on 2022/11/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand((unsigned)time(NULL));
    
    int athlete = 0;
    int trade = 0;
    int SumBefore = 0;
    int SumAfter = 0;
    double AverageBefore = 0;
    double AverageAfter = 0;
    
    //Enter amount of athlete, trade num
    scanf("%d %d", &athlete, &trade);
    
    int HomeTeam[athlete];
    int AwayTeam[athlete];
    int RandomNum[trade];
    
    // Enter Team Score
    for(int i = 0; i < athlete; i++) {
        scanf("%d", &HomeTeam[i]);
    }
    for(int i = 0; i < athlete; i++) {
        scanf("%d", &AwayTeam[i]);
    }
    
    //Average Score
    for(int i = 0; i < athlete; i++) {
        SumBefore += HomeTeam[i];
    }
    AverageBefore = (double)SumBefore / athlete;
    
    //Random Num
    for(int i = 0; i < trade; i++) {
        RandomNum[i] = rand() % athlete;
        for(int j = 0; j < i; j++) {
            if(RandomNum[i] == RandomNum[j]) {
                i--;
            }
        }
    }
    
    //Trade
    for(int i = 0; i < trade; i++) {
        HomeTeam[RandomNum[i]] = AwayTeam[RandomNum[i]];
    }
    
    //Average Score after trade
    for(int i = 0; i < athlete; i++) {
        SumAfter += HomeTeam[i];
    }
    AverageAfter = (double)SumAfter / athlete;
    
    printf("After Trade : ");
    for(int i = 0; i < athlete; i++) {
        printf("%d ", HomeTeam[i]);
    }
    printf("\n");
    printf("Average Score Change : %.1f -> %.1f \n", AverageBefore, AverageAfter);
}
