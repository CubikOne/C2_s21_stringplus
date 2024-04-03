#include "s21_string_test.h"

static char* strncpy_array[10][2] = {
    {"123", "2"},     {"gwevwe", "3"},        {"asda", "2"},
    {"asda", "10"},   {"asda", "20"},         {"230", "5"},
    {"qrqwr/0", "2"}, {"qwqwrwq\0trt", "13"}, {"йф сз  сыфым ы", "5"},
    {NULL, NULL}};

START_TEST(test_strncpy) {
  char test_dest_real[256] = "";
  char test_dest_our[256] = "";

  char* test_str_1 = strncpy_array[_i][0];
  size_t test_n = atoi(strncpy_array[_i][1]);

  char* real_func = strncpy(test_dest_real, test_str_1, test_n);
  char* our_func = s21_strncpy(test_dest_our, test_str_1, test_n);

  ck_assert_msg(strcmp(real_func, our_func) == 0 &&
                    strcmp(test_dest_real, test_dest_our) == 0,
                "\nError with: test_str_1 == \"%s\", test_n == %ld \n\
=>        : real_func == %s,   our_func_1 == %s,   test_dest_our == %s\n",
                test_str_1, test_n, real_func, our_func, test_dest_our);
}
END_TEST

Suite* suite_strncpy(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRNCPY");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strncpy_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strncpy, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
