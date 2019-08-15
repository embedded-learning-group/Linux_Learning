#include <stdio.h>
#include "mymath.h"

int main(void)
{
    int Add1=10,Add2=20,Res=0;
    Res = sum(Add1,Add2);
    printf("%d + %d = %d\n",Add1,Add2,Res);
    return 0;
}
