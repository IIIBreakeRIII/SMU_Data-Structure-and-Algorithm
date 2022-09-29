//
//  ReverseString(No.3).c
//  Week4
//
//  Created by 현소류 on 2022/09/28.
//

#include <stdio.h>
#include <string.h>

int main() {
    char* str = "apple";
    char len = 0;
    
    len = strlen(str);
    
    printf("Input : ");
    for (int i = 0; i <= len; i++) {
        printf("%c", str[i]);
    }

    printf("\n");
    
    printf("Ouput : ");
    for (int i = len - 1; i >= 0; --i) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
