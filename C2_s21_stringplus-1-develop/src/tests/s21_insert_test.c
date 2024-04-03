#include "s21_string_test.h"

static char *insert_array[15][5] = {
    {"", "123", "0", "123", ""},
    {"g", "G", "0", "Gg", ""},
    {"g", "G", "1", "gG", ""},
    {"g", "G", "2", NULL, ""},
    {"abc", "ABC", "1", "aABCbc", ""},
    {NULL, "ABC", "1", NULL, ""},
    {"abc", NULL, "1", NULL, ""},
    {"SOME-TEXT", "insert-", "5", "SOME-insert-TEXT", ""},
    {"SaMe-TeXt", "default", "9", "SaMe-TeXtdefault", ""},
    {"~QWERTY{}", "456", "5", "~QWER456TY{}", ""},
    {NULL, "456", "3", NULL, ""},
    {"@12341234/0", NULL, "0", NULL, ""},
    {"SADFASD123ASD12\0sdsds", "~{}[]", "10", "SADFASD123~{}[]ASD12", ""},
    {"asd", "dsa", "7", NULL, ""},
    {NULL, NULL, NULL, NULL, NULL}};

START_TEST(test_insert) {
  char *test_src = insert_array[_i][0];
  char *test_str = insert_array[_i][1];
  size_t start_index = (size_t)atoi(insert_array[_i][2]);

  void *real_func = (char *)insert_array[_i][3];

  void *our_func = s21_insert(test_src, test_str, start_index);
  if (real_func != NULL) {
    ck_assert_msg(
        strcmp(real_func, our_func) == 0,
        "\nError with: test_src == \"%s\", test_str == \"%s\", start_index == %ld\n\
=>        : real_func == %s,   our_func == %s\n",
        (char *)test_src, (char *)test_str, start_index, (char *)real_func,
        (char *)our_func);
    free(our_func);

  } else {
    ck_assert_msg(our_func == NULL, "\n real_func == NULL, our_func == %s\n",
                  (char *)our_func);
  }
}
END_TEST

Suite *suite_insert(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("INSERT");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (insert_array[len_array][4] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_insert, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
