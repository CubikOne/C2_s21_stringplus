#include "s21_string_test.h"

static char* strlen_array[] = {"123",  "gwevwe",        "",
                               "1230", "qrqwr/0",       "qwqwrwq\0sdsds",
                               "ыв",   "выпв паып вфы", NULL};

START_TEST(test_strlen) {
  char* test_str = strlen_array[_i];

  size_t real_func = strlen(test_str);
  size_t our_func = s21_strlen(test_str);

  ck_assert_int_eq(real_func, our_func);
}
END_TEST

Suite* suite_strlen(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRLEN");
  tc_core = tcase_create("Core");

  int len_array = 0;
  char** tmp = strlen_array;
  while (*tmp != NULL) {
    len_array += 1;
    tmp += 1;
  }

  tcase_add_loop_test(tc_core, test_strlen, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
