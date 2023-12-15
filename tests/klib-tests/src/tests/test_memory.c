#include <klibtest.h>


void test_memset() {
  int l, r;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      uint8_t val = (l + r) / 2;
      memset(data + l, val, r - l);
      check_seq(0, l, 1);
      check_eq(l, r, val);
      check_seq(r, N, r + 1);
    }
  }
}

// data[l,r) =?= val, val + 1, val + 2...
static void check_buffer_seq(char* buf, int l, int   r, int val) {
  int i;
  for (i = l; i < r; i ++) { 
    // putch(data[i]);putch(val+i-l);putch('\n'); //debug
    assert(buf[i] == val + i - l);
  }
}

// data[l,r) =?= val,val,val...
static void check_buffer_eq(char* buf, int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(buf[i] == val);
  }
}


void test_memcpy() {
  int l, r;
  char buffer[2 * N];
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      uint8_t val = (l + r) / 2;
      memset(data + l, val, r - l);
      memcpy(buffer,data,N);
      check_buffer_seq(buffer,0, l, 1);
      check_buffer_eq(buffer,l, r, val);
      check_buffer_seq(buffer,r, N, r + 1);
    }
  }

}


//test suite
void test_suite_memory() {
    TESTCASE(test_memset);
    TESTCASE(test_memcpy);
}

