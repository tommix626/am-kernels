#include <klibtest.h>

void (*entry)() = NULL; // mp entry

static const char *tests[256] = {
  ['h'] = "test_klib_hello",
  ['H'] = "display this help message",
  ['s'] = "test_suite_string",
  ['p'] = "test_suite_printf"
};

int main(const char *args) {
  switch (args[0]) {
    CASE('h', test_klib_hello);
    CASE('m', test_suite_memory);
    CASE('t', test_test_setup);
    CASE('s', test_suite_string);
    CASE('p', test_suite_printf);
    case 'H':
    default:
      printf("Usage: make run mainargs=*\n");
      for (int ch = 0; ch < 256; ch++) {
        if (tests[ch]) {
          printf("  %c: %s\n", ch, tests[ch]);
        }
      }
  }
  return 0;
}
