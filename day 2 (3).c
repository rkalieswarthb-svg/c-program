#include <stdio.h>

int main() {
    int i;
    printf("enter the number:\t");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
        printf("tamil");
        break;
        case 2:
        printf("english");
        break;
        case 3:
        printf("hindi");
        break;
        default:
        printf("the number is not find");
    }
    return 0;
}