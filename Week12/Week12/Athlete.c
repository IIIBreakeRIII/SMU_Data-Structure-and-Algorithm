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
    
    printf("After Trade : ");
    for(int i = 0; i < athlete; i++) {
        printf("%d ", HomeTeam[i]);
    }
    printf("\n");
}
