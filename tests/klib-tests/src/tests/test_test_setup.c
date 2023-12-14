#include <klibtest.h>


void test_test_setup() {
  reset();
  extern uint8_t data[N];
  char* init_str = "111112345666666";
  for (int i=0;i<15;i++){
    data[i] = init_str[i];
  }
  check_eq(0, 5, '1');
  check_seq(4, 10,'1');
  check_eq(9, 15, '6');
  check_seq(15, N, 16);
}