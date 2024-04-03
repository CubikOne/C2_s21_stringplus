#include "s21_string_test.h"

static char* memchr_array[21][3] = {{"123\0 y56", "y", "10"},
                                    {"123", "", "10"},
                                    {"123", "3", "10"},
                                    {"123", "3", "1"},
                                    {"123", "3", "2"},
                                    {"123", "3", "3"},
                                    {"gwevwe", "g", "3"},
                                    {"", "s", "2"},
                                    {"1", "s", "2"},
                                    {"1230", "3", "1"},
                                    {"qrqwr/0", "r", "2"},
                                    {"qwqwrwq\0", "w", "3"},
                                    {"asdfg", "d", "4"},
                                    {"asdfg", "e", "10"},
                                    {"asdfg", "f", "10"},
                                    {"абвггд", "в", "10"},
                                    {"абвггдфииафывиывво", "о", "10"},
                                    {"абвггды", "ы", "10"},
                                    {"абвг!гд", "!", "3"},
                                    {"абвг!гд", "!", "6"},
                                    {NULL, NULL, NULL}};

START_TEST(test_memchr) {
  void* test_str = memchr_array[_i][0];
  int test_c = (unsigned char)memchr_array[_i][1][0];
  size_t test_n = atoi(memchr_array[_i][2]);
  void* real_func = memchr(test_str, test_c, test_n);
  void* our_func = s21_memchr(test_str, test_c, test_n);

  if (real_func != NULL) {
    ck_assert_msg(
        (real_func != our_func) == 0,
        "\nError with: test_str == \"%s\",test_c == %d, test_n == %ld \n\
=>        : real_func == %s,   our_func == %s\n",
        (char*)test_str, test_c, test_n, (char*)real_func, (char*)our_func);
  } else {
    ck_assert_msg(our_func == NULL, "\n real_func == NULL, our_func == %s\n",
                  (char*)our_func);
  }
}
END_TEST

Suite* suite_memchr(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("MEMCHR");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (memchr_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_memchr, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
