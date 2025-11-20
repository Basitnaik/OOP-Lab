#include<stdio.h>
int main(){
int n,rev=0,rem;
printf("enter the number");
scanf("%d",&n);
    while (n != 0) {
        rem = n % 10;        // Get last digit
        rev = rev * 10 + rem; // Add digit to reverse
        n /= 10;             // Remove last digit
    }
printf("reversed numbers are %d\n" ,rev);
return 0;
}