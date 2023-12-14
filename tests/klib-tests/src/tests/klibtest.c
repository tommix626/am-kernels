#include <klibtest.h>

uint8_t data[N];
char strdata[N];

void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    data[i] = i + 1;
    strdata[i] = i + 1;
  }
  strdata[N-1] = '\0';
}

// data[l,r) =?= val, val + 1, val + 2...
void check_seq(int l, int   r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    // putch(data[i]);putch(val+i-l);putch('\n'); //debug
    assert(data[i] == val + i - l);
  }
}

// data[l,r) =?= val,val,val...
void check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(data[i] == val);
  }
}


// strdata[l,r) =?= val, val + 1, val + 2...
void check_str_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    // putch(data[i]);putch(val+i-l);putch('\n'); //debug
    assert(strdata[i] == val + i - l);
  }
}

// strdata[l,r) =?= val,val,val...
void check_str_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(strdata[i] == val);
  }
}
