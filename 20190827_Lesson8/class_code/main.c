#include <stdio.h>
#include "mymath.h"

struct macro
{
    int N;
    char M;
};
struct macro macro_drv = {100,20};

#define PR(x,...) printf("Message" #x ":" __VA_ARGS__)
#define VA(x,y,...) printf(#x" "#y" "#__VA_ARGS__)

#define XNAME(n) x##n
#define Macro(x) x##_drv.N

#define PI 3.14
#define MAX(a,b) ((a)>(b)?(a):(b))

int main(void)
{
/*
    int Add1=10,Add2=20,Res=0;
    Res = sum(Add1,Add2);
    printf("%d + %d = %d\n",Add1,Add2,Res);


    char *XNAME(3) = "Hello,Macro(##)";
    printf("The string:%s\n",XNAME(3));
    printf("The struct:%d\n",Macro(macro));

    PR(1,"%s,%s\n","Hello","Macro");
    VA(I,am,Superman!);

    printf("The Source File Name:%s\n",__FILE__);
    printf("Current Code Line:%d\n",__LINE__);
    printf("Current Func Name:%s\n",__FUNCTION__);
*/
    printf("The PI:%f\n",PI);
    printf("The Bigger:%f\n",MAX(PI,2.34));
    return 0;
}
