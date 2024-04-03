#include "s21_string_test.h"

static char* memcpy_array[8][2] = {
    {"123", "2"},           {"gwevwe", "3"},  {"asda", "2"},
    {"230", /*"5"*/ "2"},   {"qrqwr/0", "2"}, {"qwqwrwq\0trt", "10"},
    {"!№;%: впупц21", "7"}, {NULL, NULL}};

START_TEST(test_memcpy) {
  char real_func[256];
  char our_func[256];
  char* test_str_1 = memcpy_array[_i][0];
  size_t test_n = atoi(memcpy_array[_i][1]);

  memcpy(real_func, test_str_1, test_n);
  s21_memcpy(our_func, test_str_1, test_n);

  if (real_func != NULL) {
    ck_assert_msg(strcmp(real_func, our_func) == 0,
                  "\nError with: test_str_1 == \"%s\", test_n == %ld \n\
=>        : real_func == %s,   our_func == %sn",
                  (char*)test_str_1, test_n, (char*)real_func, (char*)our_func);
  } else {
    ck_assert_msg(our_func == NULL, "\n real_func == NULL, our_func == %s\n",
                  (char*)our_func);
  }
}
END_TEST

Suite* suite_memcpy(void) {
  Suite* s = suite_create("MEMCPY");
  ;
  TCase* tc_core = tcase_create("Core");
  ;

  int len_array = 0;
  while (memcpy_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_memcpy, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
