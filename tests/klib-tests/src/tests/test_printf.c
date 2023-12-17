#include <klibtest.h>
#include<limits.h>

void test_sprintf() {
    int intdata[] = {0, INT_MAX / 17, INT_MAX, INT_MIN, INT_MIN + 1, UINT_MAX / 17, INT_MAX / 17, UINT_MAX};
    char expected[1000] = "0;126322567;2147483647;-2147483648;-2147483647;252645135;126322567;";
    char buffer[1000];
    sprintf(buffer,"%d;%d;%d;%d;%d;%d;%d;",(int) intdata[0],(int) intdata[1],(int) intdata[2],(int) intdata[3],(int) intdata[4],(int) intdata[5],(int) intdata[6]);
    printf("\n%s\n",expected);
    printf("\n%s\n",buffer);
    assert(0 == strcmp(buffer,expected));
}


//test suite
void test_suite_printf() {
    
    TESTCASE(test_sprintf);
}
