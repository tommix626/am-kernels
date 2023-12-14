#include <klibtest.h>


void test_strlen() {
    extern char strdata[N];
    for (int l = 0; l < N; l ++) {
        reset();
        strdata[l] = 0;
        assert(l == strlen(strdata));
    }
}

void test_strncpy() {
    char source[2*N];
    extern char strdata[N];
    int l, r;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r < N; r ++) {
        reset();
        uint8_t val = (l + r) / 2;
        memset(source,val,sizeof(source));
        strncpy(strdata + l, source + l, r - l);
        check_str_seq(0, l, 1);
        check_str_eq(l, r, val);
        check_str_seq(r, N-1, r + 1);
        assert(strdata[N-1] == '\0');
        }
    }
}


void test_strncpy_capped() {
    char source[2*N];
    memset(source,49,sizeof(source));

    extern char strdata[N];
    strncpy(strdata, source, N); //strdata not ended with '\0'
    check_str_eq(0, N, 49); //especially the position [N-1]
}


//test suite
void test_suite_string() {
    TESTCASE(test_strlen);
    TESTCASE(test_strncpy);
    TESTCASE(test_strncpy_capped);
}
