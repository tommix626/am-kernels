#include <klibtest.h>
#include<limits.h>

void test_sprintf_min() {
    // char expected[1000] = "-2147483648";
    char buffer[1000];
    sprintf(buffer,"%d",INT_MIN);
    // printf("\n%s\n",expected);
    // printf("\n%s\n",buffer);
    assert(0 == strcmp(buffer,"-2147483648"));
}


//test suite
void test_printf_min() {
    test_sprintf_min();
    // TESTCASE(test_sprintf_min);
}
