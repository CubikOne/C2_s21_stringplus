#include "s21_string_test.h"

static char *memcmp_array[32][3] = {{"\0\0", "1", "2"},
                                    {"\0\0", "1\0", "3"},
                                    {"1\0", "11\0", "3"},
                                    {"11\0", "111\0", "3"},
                                    {"11\0\0", "111\0", "4"},
                                    {"111\0\0", "1111\0", "4"},
                                    {"\0\0", "11", "2"},
                                    {"1\0", "11", "2"},
                                    {"11", "111", "3"},
                                    {"123", "123", "2"},
                                    {"gwevwe", "gwe", "3"},
                                    {"", "asda", "1"},
                                    {"", "bsda", "1"},
                                    {"", "asda", "2"},
                                    {"", "bsda", "2"},
                                    {"asda", "", "2"},
                                    {"bsda", "", "2"},
                                    {"", "asda", "3"},
                                    {"1230", "230", "1"},
                                    {"qrqwr/0", "qrq", "2"},
                                    {"qwqwrwq\0", "assqwf", "3"},
                                    {"asdfg", "asde", "4"},
                                    {"asdfg", "asdd", "4"},
                                    {"asdfg", "asde", "10"},
                                    {"asdfg", "asdf", "10"},
                                    {"asdfg", "asdy", "10"},
                                    {"asdfg", "asdo", "10"},
                                    {"asdfg", "asdo", "5"},
                                    {"фмфы ыф", "фмфы ыф", "11"},
                                    {"фмфйы ыф", "фмфы ыф", "11"},
                                    {NULL, NULL, NULL}};

START_TEST(test_memcmp) {
  void *test_str_1 = memcmp_array[_i][0];
  void *test_str_2 = memcmp_array[_i][1];
  size_t test_n = atoi(memcmp_array[_i][2]);

  int real_func = memcmp(test_str_1, test_str_2, test_n);
  int our_func = s21_memcmp(test_str_1, test_str_2, test_n);
  ck_assert_msg(
      (real_func < 0 && our_func < 0) || (real_func == 0 && our_func == 0) ||
          (real_func > 0 && our_func > 0),
      "\nError with: test_str_1 == \"%s\",  test_str_2 == \"%s\", test_n == "
      "%ld \n=>        : real_func == %d,   our_func == %d\n",
      (char *)test_str_1, (char *)test_str_2, test_n, real_func, our_func);
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MEMCMP");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (memcmp_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_memcmp, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
