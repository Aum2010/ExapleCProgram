#include <stdio.h>
#include <stdlib.h>

extern int a;

int test(int n) {
    if(n == 1){
        return n;
    }else{
        return n + test(n-1);
    }
}

void test2(int *x,int *y){
    printf("*************InFuction********\n");
    printf("x = %d  | y = %d\n" , x , y);
    printf("*x = %d | *y = %d\n" , *x , *y);
    int temp ;
    temp = *y;
    printf("temp = %d  | *y = %d\n" , temp , *y);
    *y = *x;
    printf("*y = %d  | *x = %d\n" , *y , *x);
    *x = temp;
    printf("*x = %d  | temp = %d\n" , *x , temp);
    printf("***********After*************\n");
    printf("x = %d  | y = %d\n" , x , y);
    printf("*x = %d | *y = %d\n" , *x , *y);
    printf("*************InFuction********\n");

}

int main()
{
    int a = 10 , b = 1;
    printf("a = %d | b = %d\n" , a , b);
    printf("&a = %d | &b = %d\n" , &a , &b);
    test2(&a,&b);
    printf("&a = %d | &b = %d\n" , &a , &b);
    printf("a = %d | b = %d\n" , a , b);
    return 0;
}
