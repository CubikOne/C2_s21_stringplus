#include "s21_string_test.h"

static char* strncmp_array[12][3] = {{"123", "123", "2"},
                                     {"gwevwe", "gwe", "3"},
                                     {"", "asda", "2"},
                                     {"1230", "230", "1"},
                                     {"3076", "23", "2"},
                                     {"qrqwr/0", "qrq", "2"},
                                     {"qwqwrwq\0", "assqwf", "3"},
                                     {"asdfg", "asde", "4"},
                                     {"asdfg", "asde", "10"},
                                     {"asdfg", "asdf", "10"},
                                     {"вфвф урй", "вфвф урй", "10"},
                                     {NULL, NULL, NULL}};

START_TEST(test_strncmp) {
  char* test_str_1 = strncmp_array[_i][0];
  char* test_str_2 = strncmp_array[_i][1];
  size_t test_n = atoi(strncmp_array[_i][2]);

  int real_func = strncmp(test_str_1, test_str_2, test_n);
  int our_func = s21_strncmp(test_str_1, test_str_2, test_n);
  ck_assert_msg(
      real_func == our_func,
      "\nError with: test_str_1 == \"%s\",  test_str_2 == \"%s\", test_n == "
      "%ld \n=>        : real_func == %d,   our_func == %d\n",
      test_str_1, test_str_2, test_n, real_func, our_func);
}
END_TEST

Suite* suite_strncmp(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRNCMP");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strncmp_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strncmp, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
