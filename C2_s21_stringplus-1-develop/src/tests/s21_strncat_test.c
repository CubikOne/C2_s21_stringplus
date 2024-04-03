#include "s21_string_test.h"

static char* strncat_array[30][3] = {
    {"123", "4567", "2"},    {"123", "4567", "3"},
    {"123", "4567", "4"},    {"123", "4567", "5"},
    {"1234", "567", "2"},    {"1234", "567", "3"},
    {"1234", "567", "4"},    {"1234", "567", "5"},
    {"123", "123", "2"},     {"gwevwe", "gwe", "1"},
    {"", "asda", "2"},       {"1230", "230", "1"},
    {"qrqwr/0", "qrq", "2"}, {"qwqwrwq\0", "assqwf", "3"},
    {"asdfg", "asde", "4"},  {"asdfg", "asde", "10"},
    {"asdfg", "asdf", "10"}, {"Ъйьбя", "вывйЪ", "10"},
    {NULL, NULL, NULL}};

START_TEST(test_strncat) {
  char test_dest_real[256] = "";
  char test_dest_our[256] = "";
  strcpy(test_dest_real, strncat_array[_i][0]);
  strcpy(test_dest_our, strncat_array[_i][0]);

  char* test_str_1 = strncat_array[_i][1];
  size_t test_n = atoi(strncat_array[_i][2]);

  char* real_func = strncat(test_dest_real, test_str_1, test_n);
  char* our_func = s21_strncat(test_dest_our, test_str_1, test_n);

  ck_assert_msg(
      strcmp(real_func, our_func) == 0 &&
          strcmp(test_dest_real, test_dest_our) == 0,
      "\nError with:test_dest == \"%s\", test_str_1 == \"%s\", test_n == %ld \n\
=>        : real_func == %s,   our_func_1 == %s,   test_dest_our == %s\n",
      strncat_array[_i][0], test_str_1, test_n, real_func, our_func,
      test_dest_our);
}
END_TEST

Suite* suite_strncat(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRNCAT");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strncat_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strncat, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
