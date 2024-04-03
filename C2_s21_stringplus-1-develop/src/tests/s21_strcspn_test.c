#include "s21_string_test.h"

char* strcspn_array[12][2] = {
    {"123", "13"},           {"gwevwe", "ve"},        {"asda", ""},
    {"asda", "0"},           {"1230", "230"},         {"qrqwr/0", "qrq"},
    {"qwqwrwq\0", "assqwf"}, {"0123456789", "39"},    {"0123456789", "039"},
    {"0123456789", "6"},     {"ьфмлвфыойъумв", "ъы"}, {NULL, NULL}};

START_TEST(test_strcspn) {
  char* test_str_1 = strcspn_array[_i][0];
  char* test_str_2 = strcspn_array[_i][1];

  size_t real_func = strcspn(test_str_1, test_str_2);
  size_t our_func = s21_strcspn(test_str_1, test_str_2);

  ck_assert_msg(real_func == our_func,
                "\nError with: test_str_1 == \"%s\",  test_str_2 == \"%s\" "
                "\n=>        : real_func == %ld,   our_func == %ld\n",
                test_str_1, test_str_2, real_func, our_func);
}
END_TEST

Suite* suite_strcspn(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRCSPN");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strcspn_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strcspn, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
