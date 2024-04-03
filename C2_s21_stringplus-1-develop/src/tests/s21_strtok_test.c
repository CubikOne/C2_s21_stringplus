#include "s21_string_test.h"

static char* strtok_array[16][3] = {{"123 4646 rwrgw 4", " ", "1"},
                                    {" 123 4646 rwrgw 4", " ", "2"},
                                    {"123 4646 rwrgw 4", " ", "4"},
                                    {"123 4646 rwrgw 4", " 4", "4"},
                                    {"1re/yyf/yf/yyy/230", "/", "3"},
                                    {"ee1re/yyf/yf/yyy/230", "ye/", "7"},
                                    {"qrqwr/0", "qrq", "1"},
                                    {"", "assqwf", "1"},
                                    {"asdfg", "", "1"},
                                    {"asdfg", "", "2"},
                                    {"asdfg", "", "3"},
                                    {"asdfg", "653", "1"},
                                    {"ыф йыймы фв ыфуе", "й ", "1"},
                                    {"ыф йыймы фв ыфуе", "й ", "2"},
                                    {"ыф йыймы фв ыфуе", "й ", "3"},
                                    {NULL, NULL, NULL}};

START_TEST(test_strtok) {
  char test_str_1[256];
  char test_str_2[256];
  strcpy(test_str_1, strtok_array[_i][0]);
  strcpy(test_str_2, strtok_array[_i][0]);

  char* test_delim = strtok_array[_i][1];
  int test_num = atoi(strtok_array[_i][2]);

  char* real_func = strtok(test_str_1, test_delim);
  char* our_func = s21_strtok(test_str_2, test_delim);
  for (int i = 1; i < test_num; i++) {
    real_func = strtok(NULL, test_delim);
    our_func = s21_strtok(NULL, test_delim);
  }

  if (real_func != NULL) {
    ck_assert_msg(
        strcmp(real_func, our_func) == 0,
        "\nError with:test_str_1 == \"%s\", test_delim == \"%s\" test_num = %d\n\
=>        : real_func == %s,   our_func == %s \n",
        test_str_1, test_delim, test_num, real_func, our_func);
  } else {
    ck_assert_msg(our_func == NULL,
                  "real_func == NULL, our_func != NULL,our_func = %s",
                  our_func);
  }
}
END_TEST

Suite* suite_strtok(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("STRTOK");
  tc_core = tcase_create("Core");

  int len_array = 0;
  while (strtok_array[len_array][0] != NULL) {
    len_array += 1;
  }

  tcase_add_loop_test(tc_core, test_strtok, 0, len_array);
  suite_add_tcase(s, tc_core);
  return s;
}
