#include "s21_string_test.h"

static char* strerror_array[] = {"1",  "67",  "",    "133",
                                 "25", "-20", "140", NULL};

START_TEST(test_strerror) {
  int test_errnum = atoi(strerror_array[_i]);

  char* real_func = strerror(test_errnum);
  char* our_func = s21_strerror(test_errnum);
  if (real_func != NULL) {
    ck_assert_msg(strcmp(real_func, our_func) == 0,
                  "\nError with:test_errnum == %d, \n\
=>        : real_func == %s,   our_func_1 == %s\n",
                  test_errnum, real_func, our_func);
  } else {
    ck_assert_msg(our_func == NULL,
                  "real_func == NULL, our_func != NULL,our_func = %s",
                  our_func);
  }
}
END_TEST

Suite* suite_strerror(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRERROR");
  tc_core = tcase_create("Core");

  int len_array = 0;
  char** tmp = strerror_array;
  while (*tmp != NULL) {
    len_array += 1;
    tmp += 1;
  }

  tcase_add_loop_test(tc_core, test_strerror, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
