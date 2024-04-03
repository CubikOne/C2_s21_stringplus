#include "s21_string_test.h"

static char* to_lower_array[8][3] = {
    {"SOME-TEXT", "some-text", ""},
    {"SaMe-TeXt", "same-text", ""},
    {"~QWERTY{}", "~qwerty{}", ""},
    {"QWERTY", "qwerty", ""},
    {"@12341234/0", "@12341234/0", ""},
    {"SADFASD123ASD12\0sdsds", "sadfasd123asd12\0sdsds", ""},
    {NULL, NULL, ""},
    {NULL, NULL, NULL}};

START_TEST(test_to_lower) {
  char* test_str_1 = to_lower_array[_i][0];
  char* test_str_2 = to_lower_array[_i][1];

  char* our_func = s21_to_lower(test_str_1);
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

Suite* suite_to_lower(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("TO_LOWER");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (to_lower_array[len_array][2] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_to_lower, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}