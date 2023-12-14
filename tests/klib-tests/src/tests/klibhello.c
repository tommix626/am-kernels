#include <klibtest.h>

void test_klib_hello() {
  char hello_str[20] = "Hello, KLib";
  char dst_str[20] = "0123456789abcdefghij";
  char result[20] = "Hello, KLibcdefghij";
  strcpy(dst_str,hello_str);
  assert(0==strcmp(dst_str,result));

}
