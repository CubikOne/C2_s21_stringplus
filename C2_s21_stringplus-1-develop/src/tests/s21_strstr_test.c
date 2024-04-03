#include "s21_string_test.h"

static char* strstr_array[11][2] = {{"123", "23"},
                                    {"g99hnwdwqewevwe", "we"},
                                    {"", "asda"},
                                    {"1230", "30"},
                                    {"qrqwr/0", "qrq"},
                                    {"qwqwrwq\0", "assqwf"},
                                    {"asdfg", ""},
                                    {"татыпапвывр", "ыв"},
                                    {"sa42dv42weg", "42w"},
                                    {"таъты й й йъпапвывр", "йъв"},
                                    {NULL, NULL}};

START_TEST(test_strstr) {
  char* test_str_1 = strstr_array[_i][0];
  char* test_str_2 = strstr_array[_i][1];

  char* real_func = strstr(test_str_1, test_str_2);
  char* our_func = s21_strstr(test_str_1, test_str_2);

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

Suite* suite_strstr(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRSTR");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strstr_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strstr, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
