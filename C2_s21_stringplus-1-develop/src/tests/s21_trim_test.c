#include "s21_string_test.h"

static char *trim_array[8][4] = {{NULL, " ", NULL, ""},
                                 {" qwerty ", NULL, "qwerty", ""},
                                 {"", "123", "", ""},
                                 {" . 123. .", ". ", "123", ""},
                                 {"  1 2.3..", ". ", "1 2.3", ""},
                                 {"  123  ", "", "123", ""},
                                 {"qwe123rty", "zxc", "qwe123rty", ""},
                                 {NULL, NULL, NULL, NULL}};

START_TEST(test_trim) {
  char *test_src = trim_array[_i][0];
  char *test_trim_chars = trim_array[_i][1];

  void *real_func = (char *)trim_array[_i][2];

  void *our_func = s21_trim(test_src, test_trim_chars);
  if (real_func != NULL) {
    ck_assert_msg(
        strcmp(real_func, our_func) == 0,
        "\nError with: test_src == \"%s\", test_trim_chars == \"%s\"\n\
=>        : real_func == %s,   our_func == %s\n",
        (char *)test_src, (char *)test_trim_chars, (char *)real_func,
        (char *)our_func);
  } else {
    ck_assert_msg(our_func == NULL, "\n real_func == NULL, our_func == %s\n",
                  (char *)our_func);
  }

  free(our_func);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("TRIM");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (trim_array[len_array][3] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_trim, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
