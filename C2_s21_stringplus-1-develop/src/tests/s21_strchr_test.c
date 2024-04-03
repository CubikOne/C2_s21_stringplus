#include "s21_string_test.h"

static char* strchr_array[11][2] = {
    {"123", "2"},     {"gwevwe", "g"},       {"asda", "q"},    {"230", ""},
    {"", ""},         {"qrqwr/0", "0"},      {"иаивафы", "ы"}, {"иаивафы", "ф"},
    {"иаивафы", "а"}, {"татыпапвывр", "ыв"}, {NULL, NULL}};

START_TEST(test_strchr) {
  char* test_str_1 = strchr_array[_i][0];
  int test_int = (unsigned char)strchr_array[_i][1][0];

  char* real_func = strchr(test_str_1, test_int);
  char* our_func = s21_strchr(test_str_1, test_int);
  if (real_func != NULL) {
    ck_assert_msg((real_func != our_func) == 0,
                  "\nError with: test_str_1 == \"%s\", test_int == %d \n\
=>        : real_func == %s,   our_func_1 == %s\n",
                  test_str_1, test_int, real_func, our_func);
  } else {
    ck_assert_msg(our_func == NULL,
                  "real_func == NULL, our_func != NULL,our_func = %s",
                  our_func);
  }
}
END_TEST

Suite* suite_strchr(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRCHR");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strchr_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strchr, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
