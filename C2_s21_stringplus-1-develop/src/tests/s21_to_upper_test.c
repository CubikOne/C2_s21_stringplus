#include "s21_string_test.h"

static char* to_upper_array[8][3] = {
    {"some-text", "SOME-TEXT", ""},
    {"SaMe-TeXt", "SAME-TEXT", ""},
    {"~qwerty{}", "~QWERTY{}", ""},
    {"QWERTY", "QWERTY", ""},
    {"@12341234/0", "@12341234/0", ""},
    {"sadfASD123asd12\0sdsds", "SADFASD123ASD12\0sdsds", ""},
    {NULL, NULL, ""},
    {NULL, NULL, NULL}};

START_TEST(test_to_upper) {
  char* test_str_1 = to_upper_array[_i][0];
  char* test_str_2 = to_upper_array[_i][1];

  char* our_func = s21_to_upper(test_str_1);
  char* real_func = test_str_2;

  if (real_func != NULL) {
    ck_assert_msg(strcmp(real_func, our_func) == 0,
                  "\nError with:test_str_1 == \"%s\",\n\
=>        : real_func == %s,   our_func == %s \n",
                  test_str_1, real_func, our_func);
  } else {
    ck_assert_msg(our_func == NULL, "\n real_func == NULL, our_func == %s\n",
                  (char*)our_func);
  }
  free(our_func);
}
END_TEST

Suite* suite_to_upper(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("TO_UPPER");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (to_upper_array[len_array][2] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_to_upper, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}