//
//  ReverseString(No.6).c
//  Week_3
//
//  Created by 현소류 on 2022/09/22.
//

#include <stdio.h>
 
void reverse(char *str, int k) {
    if (*(str + k) == '\0') {
        return;
    }
    reverse(str, k + 1);
    printf("%c", str[k]);
}

int main() {
    char str[] = "flower";
    reverse(str, 0);
    printf("\n");
    return 0;
}
