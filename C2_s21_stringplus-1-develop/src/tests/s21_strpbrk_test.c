#include "s21_string_test.h"

static char* strpbrk_array[11][2] = {{"1239", "973"},
                                     {"1239", "397"},
                                     {"gwevwe", ""},
                                     {"", "asda"},
                                     {"1230", "-=0"},
                                     {"qrqwr/0", "qoii"},
                                     {"qwqwrwq\0", "assqwf"},
                                     {"аырврав", "в"},
                                     {"кьевныптыц в", "ыыв"},
                                     {"asdfg", "asdf"},
                                     {NULL, NULL}};

START_TEST(test_strpbrk) {
  char* test_str_1 = strpbrk_array[_i][0];
  char* test_str_2 = strpbrk_array[_i][1];

  char* real_func = strpbrk(test_str_1, test_str_2);
  char* our_func = s21_strpbrk(test_str_1, test_str_2);
  if (real_func != NULL) {
    ck_assert_msg(strcmp(real_func, our_func) == 0,
                  "\nError with:test_str_1 == \"%s\", test_str_2 == \"%s\" \n\
=>        : real_func == %s,   our_func == %s \n",
                  test_str_1, test_str_2, real_func, our_func);
  } else {
    ck_assert_msg(our_func == NULL,
                  "real_func == NULL, our_func != NULL,our_func = %s",
                  our_func);
  }
}
END_TEST

Suite* suite_strpbrk(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRPBRK");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strpbrk_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strpbrk, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
