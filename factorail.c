#include <stdio.h>
int main(){
    int numb;
    long long factorail=1;
    printf("enter the number=  ");
    scanf("%d", &numb);
    for(int i=1;i<=numb;i++){
        factorail*=i;
    }printf("factorail of number of %d= %lld\n",numb,factorail);
    return 0;

}