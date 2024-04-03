#include "s21_string_test.h"

static char* memset_array[11][3] = {
    {"123", "3", "2"},       {"gwevwe", "g", "3"},  {"", "s", "2"},
    {"1230", "3", "1"},      {"qrqwr/0", "r", "2"}, {"qwqwrwq\0", "w", "3"},
    {"asdfg", "d", "4"},     {"asdfg", "e", "10"},  {"asdfg", "f", "10"},
    {"аб ъвггд", "й", "10"}, {NULL, NULL, NULL}};

START_TEST(test_memset) {
  char test_str[256];
  strcpy(test_str, memset_array[_i][0]);

  int test_int = memset_array[_i][1][0];
  size_t test_n = atoi(memset_array[_i][2]);

  void* real_func = memset(test_str, test_int, test_n);
  void* our_func = s21_memset(test_str, test_int, test_n);

  if (real_func != NULL) {
    ck_assert_msg(
        strcmp(real_func, our_func) == 0,
        "\nError with: test_str_1 == \"%s\",test_int == %d, test_n == %ld \n\
=>        : real_func == %s,   our_func == %s\n",
        (char*)test_str, test_int, test_n, (char*)real_func, (char*)our_func);
  } else {
    ck_assert_msg(our_func == NULL, "\n real_func == NULL, our_func == %s\n",
                  (char*)our_func);
  }
}
END_TEST

Suite* suite_memset(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("MEMSET");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (memset_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_memset, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
