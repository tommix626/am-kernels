#ifndef __AMUNIT_H__
#define __AMUNIT_H__

// #include <am.h>
#include <klib.h>
#include <klib-macros.h>

extern void (*entry)();

#define CASE(id, entry_, ...) \
  case id: { \
    void entry_(); \
    entry = entry_; \
    __VA_ARGS__; \
    entry_(); \
    break; \
  }

//test case wrapper
#define TESTCASE_PASS printf("test passed!\n\n")
#define TESTCASE_START(name) printf("Testing %s... \n",#name)
#define TESTCASE(func_) TESTCASE_START(func_);void func_(); func_(); TESTCASE_PASS;

//global test setup function

#define N 32

extern uint8_t data[N];

void reset();

void check_seq(int l, int r, int val);

void check_eq(int l, int r, int val);

void check_str_seq(int l, int r, int val);

void check_str_eq(int l, int r, int val);

#endif
