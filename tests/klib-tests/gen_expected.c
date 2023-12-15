#include<stdio.h>
#include<limits.h>
int intdata[] = {0, INT_MAX / 17, INT_MAX, INT_MIN, INT_MIN + 1,
              UINT_MAX / 17, INT_MAX / 17, UINT_MAX};

int main(){
    printf("%d;%d;%d;%d;%d;%d;%d;",(int) intdata[0],(int) intdata[1],(int) intdata[2],(int) intdata[3],(int) intdata[4],(int) intdata[5],(int) intdata[6]);

    
    return 0;
}