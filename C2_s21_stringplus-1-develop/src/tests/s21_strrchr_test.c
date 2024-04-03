#include "s21_string_test.h"

static char* strrchr_array[11][2] = {
    {"1232324", "2"}, {"16232324", "6"}, {"gwevwe", "e"},  {"asda", "q"},
    {"230", ""},      {"", ""},          {"qrqwr/0", "0"}, {"иаивафы", "ы"},
    {"иаивафы", "ф"}, {"иаивафы", "а"},  {NULL, NULL}};

START_TEST(test_strrchr) {
  char* test_str_1 = strrchr_array[_i][0];
  int test_int = (unsigned char)strrchr_array[_i][1][0];

  char* real_func = strrchr(test_str_1, test_int);
  char* our_func = s21_strrchr(test_str_1, test_int);
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

Suite* suite_strrchr(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRRCHR");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strrchr_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strrchr, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
