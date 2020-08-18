#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int a;

struct outint {
    int a1 , a2 ;
};



int test(int n) {
    if(n == 1){
        return n;
    }else{
        return n + test(n-1);
    }
}

void swapnopointer(int x,int y)
{
    //struct outint outinttest1;
    printf("*************InFuction********\n");
    printf("x = %p  | y = %p\n" , &x , &y);
    printf("x = %d  | y = %d\n" , x , y);

    int temp ;
    temp = y;

    y = x;

    x = temp;

    printf("***********After*************\n");
    printf("x = %d  | y = %d\n" , x , y);
    printf("x = %p  | y = %p\n" , &x , &y);
    printf("*************InFuction********\n");

}

struct outint swapwithstruc(int x,int y)
{
    struct outint outinttest1;
    printf("*************InFuction********\n");
    printf("x = %p  | y = %p\n" , &x , &y);
    printf("x = %d  | y = %d\n" , x , y);

    int temp ;
    temp = y;

    y = x;

    x = temp;

    printf("***********After*************\n");
    printf("x = %d  | y = %d\n" , x , y);
    printf("x = %p  | y = %p\n" , &x , &y);
    printf("*************InFuction********\n");

    outinttest1.a1 = x;
    outinttest1.a2 = y;

    return outinttest1;

}

void swapwithpointer(int *x,int *y){
    printf("*************InFuction********\n");
    printf("x = %p  | y = %p\n" , x , y);
    printf("*x = %d | *y = %d\n" , *x , *y);
    int temp ;
    temp = *y;
    printf("temp = %d  | *y = %d\n" , temp , *y);
    *y = *x;
    printf("*y = %d  | *x = %d\n" , *y , *x);
    *x = temp;
    printf("*x = %d  | temp = %d\n" , *x , temp);
    printf("***********After*************\n");
    printf("x = %p  | y = %p\n" , x , y);
    printf("*x = %d | *y = %d\n" , *x , *y);
    printf("*************InFuction********\n");

}

void pointofpointer(void) {
    int *p , **q ,a = 10;
    int***r ;
    p = &a;
    q = &p;
    r = &q;
    printf("&p  : %p\n" , &p);
    printf("p  : %p\n" , p);
    printf("*p : %d\n" , *p);
    printf("&q  : %p\n" , &q);
    printf("q  : %p\n" , q);
    printf("*q : %p\n" , *q);
    printf("**q : %d\n" , **q);
    printf("&r  : %p\n" , &r);
    printf("r : %p\n" , r);
    printf("*r : %p\n" , *r);
    printf("**r : %p\n" , **r);
    printf("***r : %d\n" , ***r);

}

void test11(void) {

    int b = 10;
    int *p , *q ;
    p = q = &b;

    printf("BEFORE CHANG VALUE\n");
    printf("p : %p | q : %p | &b : %p\n",p ,q ,&b);
    printf("*p : %d | *q : %d | b : %d\n",*p ,*q ,b);

    *q = 12;

    printf("\nAFTER CHANG VALUE BY *q = 12\n");
    printf("p : %p | q : %p | &b : %p\n",p ,q ,&b);
    printf("*p : %d | *q : %d | b : %d\n",*p ,*q ,b);

    *p = 11;
    printf("\nAFTER CHANG VALUE BY *p = 11\n");
    printf("p : %p | q : %p | &b : %p\n",p ,q ,&b);
    printf("*p : %d | *q : %d | b : %d\n",*p ,*q ,b);

    b = 16;
    printf("\nAFTER CHANG VALUE BY b = 16\n");
    printf("p : %p | q : %p | &b : %p\n",p ,q ,&b);
    printf("*p : %d | *q : %d | b : %d\n",*p ,*q ,b);

}



void test3(int *a ,int size){
    printf("SIZEOF (a)  %d\n",(int)sizeof(a));
    printf("A : %p\n",a);
    printf("SIZEOF a[0] %d\n",(int)sizeof(a[0]));
    for(int i = 0 ; i<size ; i++){  //--> 0 to 6 in array!!
        printf("INDEX : %d | %d\n",i,a[i]);
    }
}


void test4(void){
    int b[] = { 1 , 2 , 1 , 2 , 0 };

    printf("b    : %p | b+1  : %p | b+2  : %p | b+3  : %p | b+4  : %p\n\n",b,b+1,b+2,b+3,b+4);

    printf("*b   : %d |*(b+1):%d | *(b+2):%d | *(b+3):%d |*(b+4):%d\n\n",*b,*(b+1),*(b+2),*(b+3),*(b+4));

    printf("&b[0]: %p | &b[1]: %p | &b[2]: %p | &b[3]: %p | &b[4]: %p\n\n",&b[0],&b[1],&b[2],&b[3],&b[4]);

    printf("b[0] : %d | b[1] : %d | b[2] : %d | b[3] : %d | b[4] : %d\n\n",b[0],b[1],b[2],b[3],b[4]);
}

void testalloc(void) {

    int i , n ;
    printf("Enter the number : ");
    scanf("%d" , &n);
    int *ptr = (int *)malloc(n*sizeof(int));

    if(ptr == NULL) {
        printf("Memory not available");
        exit(1);
    }

    for(i = 0 ; i < n ; i++){
        printf("Enter an integer : ");
        scanf("%d" ,ptr + i);
    }
    for(i = 0 ; i < n ; i++){
        printf("Value[%d] %d | Add : %p\n" , i , *(ptr + i) , ptr + i);
    }

}

void testrealloc(void) {
    int i , n ;
    printf("Enter the number : ");
    scanf("%d" ,&n);
    int *ptr = (int*)malloc(n*sizeof(int));

    if(ptr == NULL){
        printf("Memory not available");
        exit(1);
    }

    for(i = 0 ; i < n ; i++){  //--> for Enter number amount n
        printf("Your Number : ");
        scanf("%d" , ptr + i);
    }

    printf("Enter more 2 number!!\n");
    ptr = (int*)realloc(ptr,(2+n)*sizeof(int));


    for( i = n ;  i < n + 2 ; i++){  //--> for Enter number amount 2
        printf("Your Number : ");
        scanf("%d" , ptr + i);
    }

    for(i = 0 ; i < n+2; i++){
        printf("Value[%d] : %d | Add : %p \n", i , *(ptr+i) , ptr + i );
    }


}

int * getRannd(int n) {
    printf("\n----------------FUNCTION--------------------\n\n");
    int i;
    //static int r[10];
    int *r = (int *)malloc(n*sizeof(int));

    srand(time(NULL));
    for(i = 0 ; i < n ; i++) {

        r[i] = rand();
        printf("IN FUNCTION : r[%d] VALUE : %d : Add %p \n",i , r[i] , (r+i) );
    }

    return r;
}

int Add(int a,int b){
    return a + b;
}

int main()
{
    #if (0)
    int a = 10 , b = 1;

    printf("a = %d | b = %d\n" , a , b);
    printf("&a = %p | &b = %p\n" , &a , &b);

    swapwithpointer(&a,&b);


    printf("&a = %p | &b = %p\n" , &a , &b);
    printf("a = %d | b = %d\n" , a , b);
    #endif

   // swapnopointer(a,b);
    //swapwithpointer((int *)1,(int *)2);
    #if (0)
    int a[] = {1,2,1,2};
    int size = sizeof(a) / sizeof(a[0]) ; //--> 4*7 / 4 = 7
    printf("Amount in Array : %d\n" ,size);
    printf("SIZEOF IN MAIN : %d\n",sizeof(a));
    printf("SIZEOF IN MAIN : %d\n",sizeof(a[0]));
    test3(a , size);
    #endif


    #if (0)
    test4();
    #endif


    #if (0)
    int a = 10 , b = 1;

    printf("a = %d | b = %d\n" , a , b);
    printf("&a = %d | &b = %d\n" , &a , &b);
    swapwithstruc(a,b);
    struct outint tempint = swapnopointer(a,b);
    printf("&a = %d | &b = %d\n" , &a , &b);
    printf("a = %d | b = %d\n" , a , b);
    printf("a = %d | b = %d\n" , tempint.a1 , tempint.a2);
    #endif

    #if(0)

    int* ptr;
    int i,n;
    printf("Enter Your Amount Random : ");
    scanf("%d" , &n);
    ptr = getRannd(n);
    printf("\n----------------MAIN--------------------\n\n");
    for(i = 0 ; i < n ; i++){

        printf("IN MAIN : r[%d] VALUE : %d : Add %p \n",i , ptr[i] , (ptr+i) );

    }
    free(ptr);
    #endif

    #if(1)
    int c;
    printf("Add var : C  %p\n" , &c);
    int (*p)(int,int) = Add;



    c = (*p)(5,3);
    printf("Add : %p\n" , p);
    printf("%d\n" , c);
    printf("Add var : C  %p" , &c);
    #endif

    //pointofpointer();
    //test11();
    //testalloc();
    //testrealloc();


    return 0;

}
