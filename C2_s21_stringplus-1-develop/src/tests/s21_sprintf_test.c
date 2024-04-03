

#include "s21_string_test.h"
int len_array_func_3(char* array[][3]);
int len_array_func_4(char* array[][4]);
int len_array_func_6(char* array[][6]);

static char* array_sprintf_d[130][3] = {{"123 AbC=%100dyee", "123", ""},
                                        {"%l 0++   0 05dd", "123", ""},
                                        {"%.2 0++   0 05 dd", "123", ""},
                                        {"%.2h 0++   0 05dd", "123", ""},
                                        {"%.2hl 0++   0 05dd", "123", ""},
                                        {"%.2l 0++   0 05dd", "123", ""},
                                        {"%.2ld 0++   0 05dd", "123", ""},
                                        {"% .2d y", "123", ""},
                                        {"%  .2d y", "123", ""},
                                        {"%  0.2d y", "123", ""},
                                        {"%0  0.2d y", "123", ""},
                                        {"%06  0.2d y", "123", ""},
                                        {"% 06 .3d 0++", "123", ""},
                                        {"% 06.3d 0++", "123", ""},
                                        {"% 06 d 0++", "123", ""},
                                        {"% 06d 0++", "123", ""},
                                        {"% 06l d 0++", "123", ""},
                                        {"% 06ld 0++", "123", ""},
                                        {"%+7.10d", "12345", ""},
                                        {"%+10.7d", "12345", ""},
                                        {"%0+7.10d", "12345", ""},
                                        {"%0+10.7d", "12345", ""},
                                        {"%10d", "12345", ""},
                                        {"%+10d", "12345", ""},
                                        {"%010d", "12345", ""},
                                        {"%+010d", "12345", ""},
                                        {"%10.7d", "12345", ""},
                                        {"%010.7d", "12345", ""},
                                        {"%+010.7d", "12345", ""},
                                        {"%-010.7d", "12345", ""},
                                        {"%- 010.7d", "12345", ""},
                                        {"%%- 010.7d", "12345", ""},
                                        {"%.- 010.7d", "12345", ""},
                                        {"%.0- 010.7d", "12345", ""},
                                        {"%.9- 010.7d", "12345", ""},
                                        {"%+10.3d", "12345", ""},
                                        {"%+010.3d", "12345", ""},
                                        {"%+010d", "12345", ""},
                                        {"%+010.0d", "12345", ""},
                                        {"%+010.07d", "12345", ""},
                                        {"%+ 010.0d", "0", ""},
                                        {"%+010.7d", "0", ""},
                                        {"%+010d", "0", ""},
                                        {"%+10.7d", "0", ""},
                                        {"%+10d", "0", ""},
                                        {"%+10.1d", "0", ""},
                                        {"%+10.0d", "0", ""},
                                        {"%+010d", "0", ""},
                                        {"%+010.1d", "0", ""},
                                        {"%+010.0d", "0", ""},
                                        {"%+010.=d", "0", ""},
                                        {"%+010.d", "0", ""},
                                        {"%+020hd", "2147483646", ""},
                                        {"%+020hd", "2147483649", ""},
                                        {"%+020d", "2147483649", ""},
                                        {"%+020d", "21474836490", ""},
                                        {"%+020hd", "21474836490", ""},
                                        {"%+020hd", "4147483649012", ""},
                                        {"%+020d", "4147483649012", ""},
                                        {"%+020ld", "4147483649012", ""},
                                        {"%+#020ld", "4147483649012", ""},
                                        {"%+#10.7d", "12345", ""},
                                        {"%+020hu", "-2147483646", ""},
                                        {"%+020hu", "-2147483649", ""},
                                        {"%+020u", "-2147483649", ""},
                                        {"%+020u", "-21474836490", ""},
                                        {"%+020hu", "-21474836490", ""},
                                        {"%+020hu", "-4147483649012", ""},
                                        {"%+ 020hu", "-4147483649012", ""},
                                        {"%+ 020.15hu", "-4147483649012", ""},
                                        {"%+020u", "-4147483649012", ""},
                                        {"%+025lu", "-4294967290", ""},
                                        {"%+#025lu", "-4294967290", ""},
                                        {"%+#10.7u", "-12345", ""},
                                        {"%+- 020.15hu", "-2147483646", ""},
                                        {"%+- 020.15hu", "-2147483649", ""},
                                        {"%+- 020.16u", "-2147483649", ""},
                                        {"%+- 020.15u", "-21474836490", ""},
                                        {"%+64", "64", ""},
                                        {"aaa%+64 bbb", "64", ""},
                                        {"%+64 bbb", "64", ""},
                                        {"%++# 06 d 0++", "123", ""},
                                        {"%-+-# ++# 06 d 0++", "123", ""},
                                        {"%-  +-# ++# 06 d 0++", "123", ""},
                                        {"%-  +- ++ 06 d 0++", "123", ""},
                                        {"% +06 d 0++", "123", ""},
                                        {"% -06 d 0++", "123", ""},
                                        {"% #06 d 0++", "123", ""},
                                        {"% ###06 d 0++", "123", ""},
                                        {"%# 06l d 0++", "123", ""},
                                        {"%## 06 d 0++", "123", ""},
                                        {"%++ 06 d 0++", "123", ""},
                                        {"%+ 06 d 0++", "123", ""},
                                        {"% +06 d 0++", "123", ""},
                                        {"% ++06 d 0++", "123", ""},
                                        {"% --06 d 0++", "123", ""},
                                        {"%-- 06 d 0++", "123", ""},
                                        {"%- 06 d 0++", "123", ""},
                                        {"% - 06 d 0++", "123", ""},
                                        {"%## 6 d 0++", "123", ""},
                                        {"%++ 6 d 0++", "123", ""},
                                        {"%+ 6 d 0++", "123", ""},
                                        {"% +6 d 0++", "123", ""},
                                        {"% ++6 d 0++", "123", ""},
                                        {"% 0---#-6 d 0++", "123", ""},
                                        {"%-- 6 d 0++", "123", ""},
                                        {"%- 6 d 0++", "123", ""},
                                        {"% - 6 d 0++", "123", ""},
                                        {"%+ 6 d 0++", "123", ""},
                                        {"%#-# 6 d 0++", "123", ""},
                                        {"%-++ 6 d 0++", "123", ""},
                                        {"%+- 6 d 0++", "123", ""},
                                        {"% -+6 d 0++", "123", ""},
                                        {"% +-+6 d 0++", "123", ""},
                                        {"% 0---#-6 d 0++", "123", ""},
                                        {"%-0+- 6 d 0++", "123", ""},
                                        {"%0- 6 d 0++", "123", ""},
                                        {"% -0 6 d 0++", "123", ""},
                                        {"%0+ 6 d 0++", "123", ""},
                                        {"%0+", "123", ""},
                                        {NULL, NULL, NULL}};

START_TEST(test_sprintf_d) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_d[_i][0];
  int real_func_int;
  int our_func_int;

  long int argument_d = atol(array_sprintf_d[_i][1]);
  real_func_int = sprintf(real_func, test_format, argument_d);
  our_func_int = s21_sprintf(our_func, test_format, argument_d);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%ld\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_d, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_i[90][3] = {{"123 AbC=%iyee", "123", ""},
                                       {"%l 0++   0 05ii", "123", ""},
                                       {"%.2 0++   0 05ii", "123", ""},
                                       {"%.2h 0++   0 05ii", "123", ""},
                                       {"%.2hl 0++   0 05ii", "123", ""},
                                       {"%.2l 0++   0 05ii", "123", ""},
                                       {"%.2li 0++   0 05ii", "123", ""},
                                       {"% .2i y", "123", ""},
                                       {"%  .2i y", "123", ""},
                                       {"%  0.2i y", "123", ""},
                                       {"%0  0.2i y", "123", ""},
                                       {"%06  0.2i y", "123", ""},
                                       {"% 06 .3i 0++", "123", ""},
                                       {"% 06.3i 0++", "123", ""},
                                       {"% 06 i 0++", "123", ""},
                                       {"% 06i 0++", "123", ""},
                                       {"% 06l i 0++", "123", ""},
                                       {"% 06li 0++", "123", ""},
                                       {"%+7.10i", "12345", ""},
                                       {"%+10.7i", "12345", ""},
                                       {"%0+7.10i", "12345", ""},
                                       {"%0+10.7i", "12345", ""},
                                       {"%10i", "12345", ""},
                                       {"%+10i", "12345", ""},
                                       {"%010i", "12345", ""},
                                       {"%+010i", "12345", ""},
                                       {"%10.7i", "12345", ""},
                                       {"%010.7i", "12345", ""},
                                       {"%+010.7i", "12345", ""},
                                       {"%-010.7i", "12345", ""},
                                       {"%- 010.7i", "12345", ""},
                                       {"%%- 010.7i", "12345", ""},
                                       {"%.- 010.7i", "12345", ""},
                                       {"%.0- 010.7i", "12345", ""},
                                       {"%.9- 010.7i", "12345", ""},
                                       {"%+10.3i", "12345", ""},
                                       {"%+010.3i", "12345", ""},
                                       {"%+010i", "12345", ""},
                                       {"%+010.0i", "12345", ""},
                                       {"%+010.07i", "12345", ""},
                                       {"%+ 010.0i", "0", ""},
                                       {"%+010.7i", "0", ""},
                                       {"%+010i", "0", ""},
                                       {"%+10.7i", "0", ""},
                                       {"%+10i", "0", ""},
                                       {"%+10.1i", "0", ""},
                                       {"%+10.0i", "0", ""},
                                       {"%+010i", "0", ""},
                                       {"%+010.1i", "0", ""},
                                       {"%+010.0i", "0", ""},
                                       {"%+010.=i", "0", ""},
                                       {"%+010.i", "0", ""},
                                       {"%+020hi", "2147483646", ""},
                                       {"%+020hi", "2147483649", ""},
                                       {"%+020i", "2147483649", ""},
                                       {"%+020i", "21474836490", ""},
                                       {"%+020hi", "21474836490", ""},
                                       {"%+020hi", "4147483649012", ""},
                                       {"%+020i", "4147483649012", ""},
                                       {"%+020li", "4147483649012", ""},
                                       {"%+#020li", "4147483649012", ""},
                                       {"%+#10.7i", "12345", ""},
                                       {"%+020hu", "-2147483646", ""},
                                       {"%+020hu", "-2147483649", ""},
                                       {"%+020u", "-2147483649", ""},
                                       {"%+020u", "-21474836490", ""},
                                       {"%+020hu", "-21474836490", ""},
                                       {"%+020hu", "-4147483649012", ""},
                                       {"%+ 020hu", "-4147483649012", ""},
                                       {"%+ 020.15hu", "-4147483649012", ""},
                                       {"%+020u", "-4147483649012", ""},
                                       {"%+025lu", "-4294967290", ""},
                                       {"%+#025lu", "-4294967290", ""},
                                       {"%+#10.7u", "-12345", ""},
                                       {"%+- 020.15hu", "-2147483646", ""},
                                       {"%+- 020.15hu", "-2147483649", ""},
                                       {"%+- 020.16u", "-2147483649", ""},
                                       {"%+- 020.15u", "-21474836490", ""},
                                       {"%+64", "64", ""},
                                       {"aaa%+64 bbb", "64", ""},
                                       {"%+64 bbb", "64", ""},
                                       {NULL, NULL, NULL}};

START_TEST(test_sprintf_i) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_i[_i][0];
  int real_func_int;
  int our_func_int;

  long int argument_d = atol(array_sprintf_i[_i][1]);
  real_func_int = sprintf(real_func, test_format, argument_d);
  our_func_int = s21_sprintf(our_func, test_format, argument_d);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%ld\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_d, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_d_xxl[50][6] = {
    {"%+0*.*7 d%*d", "11", "9", "7", "12345", ""},
    {"%+0*.*7 d%*d", "0", "0", "7", "12345", ""},
    {"%+0-*.*7 d%*d", "0", "0", "7", "12345", ""},
    {"%+-0*.*7 d%*d", "0", "0", "7", "12345", ""},
    {"%+*.*7 d%*d", "0", "0", "7", "12345", ""},
    {"%+0*.*d%* d", "11", "9", "12345", "7", ""},
    {"%+0* .*d%* d", "11", "9", "7", "12345", ""},
    {"%+0* .*d%*d", "11", "9", "12345", "7", ""},
    {"%%+0* .*d%*d", "11", "9", "12345", "7", ""},
    {"%+*.*d", "-11", "-7", "12345", "7", ""},
    {"%+*.* d", "-11", "-7", "12345", "7", ""},
    {"%+*.* d", "11", "-7", "12345", "7", ""},
    {"%+*.* d", "11", "7", "12345", "7", ""},
    {"%+*.*d", "11", "-7", "12345", "7", ""},
    {"%+0*.*d", "11", "-7", "12345", "7", ""},
    {"%+0*.*d", "11", "7", "12345", "7", ""},
    {"%+0d  %-10.7d oo %00 12.8d ii %-+ 015.9d", "113", "42117", "12345",
     "20027", ""},
    {NULL, NULL, NULL, NULL, NULL, NULL}};
START_TEST(test_sprintf_d_xxl) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_d_xxl[_i][0];
  int real_func_int;
  int our_func_int;

  long int argument_d_1 = atol(array_sprintf_d_xxl[_i][1]);
  long int argument_d_2 = atol(array_sprintf_d_xxl[_i][2]);
  long int argument_d_3 = atol(array_sprintf_d_xxl[_i][3]);
  long int argument_d_4 = atol(array_sprintf_d_xxl[_i][4]);
  real_func_int = sprintf(real_func, test_format, argument_d_1, argument_d_2,
                          argument_d_3, argument_d_4);
  our_func_int = s21_sprintf(our_func, test_format, argument_d_1, argument_d_2,
                             argument_d_3, argument_d_4);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\", argument == \"%ld\",\"%ld\",\"%ld\",\"%ld\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_d_1, argument_d_2, argument_d_3, argument_d_4,
      real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sprintf_c[100][3] = {{"64 AbC=%cyee", "64", ""},
                                        {"%l 0++   0 05cc", "64", ""},
                                        {"%.2 0++   0 05cc", "64", ""},
                                        {"%.2h 0++   0 05cc", "64", ""},
                                        {"%.2hl 0++   0 05cc", "64", ""},
                                        {"%.2l 0++   0 05cc", "64", ""},
                                        {"%.2c 0++   0 05cc", "64", ""},
                                        {"% .2c y", "64", ""},
                                        {"%  .2c y", "64", ""},
                                        {"%  0.2c y", "64", ""},
                                        {"%0  0.2c y", "64", ""},
                                        {"%06  0.2c y", "64", ""},
                                        {"% 06 .3c 0++", "64", ""},
                                        {"% 06.3c 0++", "64", ""},
                                        {"% 06 c 0++", "64", ""},
                                        {"% 06c 0++", "64", ""},
                                        {"% 06l c 0++", "64", ""},
                                        {"% 06c 0++", "64", ""},
                                        {"%+7.10c", "64", ""},
                                        {"%+10.7c", "64", ""},
                                        {"%0+7.10c", "64", ""},
                                        {"%0+10.7c", "64", ""},
                                        {"%10c", "64", ""},
                                        {"%+10c", "64", ""},
                                        {"%010c", "64", ""},
                                        {"%+010c", "64", ""},
                                        {"%10.7c", "64", ""},
                                        {"%010.7c", "64", ""},
                                        {"%+010.7c", "64", ""},
                                        {"%-010.7c", "64", ""},
                                        {"%- 010.7c", "64", ""},
                                        {"%%- 010.7c", "64", ""},
                                        {"%.- 010.7c", "64", ""},
                                        {"%.0- 010.7c", "64", ""},
                                        {"%.9- 010.7c", "64", ""},
                                        {"%+10.3c", "64", ""},
                                        {"%+010.3c", "64", ""},
                                        {"%+010c", "64", ""},
                                        {"%+010.0c", "64", ""},
                                        {"%+010.07c", "64", ""},
                                        {"%+ 010.0c", "64", ""},
                                        {"%+010.7c", "64", ""},
                                        {"%+010c", "64", ""},
                                        {"%+10.7c", "64", ""},
                                        {"%+10c", "64", ""},
                                        {"%+10.1c", "64", ""},
                                        {"%+10.0c", "64", ""},
                                        {"%+010c", "64", ""},
                                        {"%+010.1c", "64", ""},
                                        {"%+010.0c", "64", ""},
                                        {"%+010.=c", "64", ""},
                                        {"%+010.c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+#020c", "64", ""},
                                        {"%+#10.7c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+64", "64", ""},
                                        {"%+ 020c", "64", ""},
                                        {"%+ 020.15c", "64", ""},
                                        {"%+020c", "64", ""},
                                        {"%+025c", "64", ""},
                                        {"%+#025c", "64", ""},
                                        {"%+#10.7c", "64", ""},
                                        {"%+- 020.15c", "64", ""},
                                        {"%+- 020.15c", "64", ""},
                                        {"%+- 020.16c", "64", ""},
                                        {"%+- 020.15c", "64", ""},
                                        {"%+010.c", "0", ""},
                                        {"aaaa%- #020.10c bbb", "0", ""},
                                        {"aaa%+64 bbb", "64", ""},
                                        {"%+64 bbb", "64", ""},
                                        {"%10c", "1024", ""},
                                        {"%10lc", "1024", ""},
                                        {"%10c", "1095", ""},
                                        {"%10lc", "1095", ""},
                                        {"%10c", "68", ""},
                                        {"%10lc", "68", ""},
                                        {"%10c", "10095", ""},
                                        {"%10lc", "10095", ""},
                                        {"aaa%10c", "10095", ""},
                                        {"aaa%10lc", "10095", ""},
                                        {"aaa%10c", "0", ""},
                                        {"aaa%10lc", "0", ""},
                                        {"aaa%10c", "52095", ""},
                                        {"aaa%10lc", "52095", ""},
                                        {"%+2.0c", "-64", ""},
                                        {"%+2.0lc", "-64", ""},
                                        {NULL, NULL, NULL}};

START_TEST(test_sprintf_c) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_c[_i][0];
  int real_func_int;
  int our_func_int;

  int argument_c = atoi(array_sprintf_c[_i][1]);
  real_func_int = sprintf(real_func, test_format, argument_c);
  our_func_int = s21_sprintf(our_func, test_format, argument_c);
  // printf("real_func=%s\n",real_func);
  // printf("our_func=%s\n",our_func);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%c\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_c, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_s[100][3] = {
    {"=%s sa", "abcde", ""},      {"=%10s sa", "abcde", ""},
    {"=%10.6s sa", "abcde", ""},  {"=%10.3s sa", "abcde", ""},
    {"=%7.10s sa", "abcde", ""},  {"=%3.10s sa", "abcde", ""},
    {"=%3.4s sa", "abcde", ""},   {"=%4.3s sa", "abcde", ""},
    {"=%04.3s sa", "abcde", ""},  {"=%03.4s sa", "abcde", ""},
    {"=%07.10s sa", "abcde", ""}, {"=%07.5s sa", "abcde", ""},
    {"=%07.5s sa", "", ""},       {"=%07.5s sa", "", ""},
    {"=%10.6s sa", "цуйъы", ""},  {"=%10.4s sa", "цуйъы", ""},
    {"=%3.4s sa", "цуйъы", ""},   {"=%3.7s sa", "цуйъы", ""},
    {"=%07.s sa", "abcde", ""},   {"=%-10s sa", "abcde", ""},
    {"=%-10.6s sa", "abcde", ""}, {NULL, NULL, NULL}};

START_TEST(test_sprintf_s) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_s[_i][0];
  int real_func_int;
  int our_func_int;

  char* argument_s = array_sprintf_s[_i][1];
  real_func_int = sprintf(real_func, test_format, argument_s);
  our_func_int = s21_sprintf(our_func, test_format, argument_s);
  // printf("real_func=%s\n",real_func);
  // printf("our_func=%s\n",our_func);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%s\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_s, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_ls[100][3] = {{"=%ls sa", "abcde", ""},
                                         {"=%10ls sa", "abcde", ""},
                                         {"=%10.6ls sa", "abcde", ""},
                                         {"=%10.3ls sa", "abcde", ""},
                                         {"=%7.10ls sa", "abcde", ""},
                                         {"=%3.10ls sa", "abcde", ""},
                                         {"=%3.4ls sa", "abcde", ""},
                                         {"=%4.3ls sa", "abcde", ""},
                                         {"=%04.3ls sa", "abcde", ""},
                                         {"=%03.4ls sa", "abcde", ""},
                                         {"=%07.10ls sa", "abcde", ""},
                                         {"=%07.5ls sa", "abcde", ""},
                                         {"=%07.5ls sa", "", ""},
                                         {"=%07.5ls sa", "", ""},
                                         {"=%10.6ls sa", "цуйъы", ""},
                                         {"=%10.4ls sa", "цуйъы", ""},
                                         {"=%3.4ls sa", "цуйъы", ""},
                                         {"=%3.7ls sa", "цуйъы", ""},
                                         {"=%-10ls sa", "abcde", ""},
                                         {"=%-10.6ls sa", "abcde", ""},
                                         {NULL, NULL, NULL}};

START_TEST(test_sprintf_ls) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_ls[_i][0];
  int real_func_int;
  int our_func_int;

  // wchar_t * argument_ls = array_sprintf_ls[_i][1];
  // wchar_t* argument_ls = L"цуйъы";
  wchar_t* argument_ls = L"fast";
  // wchar_t * argument_ls = "abcde";
  real_func_int = sprintf(real_func, test_format, argument_ls);
  our_func_int = s21_sprintf(our_func, test_format, argument_ls);
  // printf("real_func=%s\n",real_func);
  // printf("our_func=%s\n",our_func);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%ls\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_ls, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_f[150][3] = {
    {"AbC=%fyee", "123.45678901234567890123", ""},
    {"AbC=%fyee", "123.45678901234567890123", ""},
    {"AbC=%fyee", "123.45678901234567890123", ""},
    {"AbC=%fyee", "123.9999999999", ""},
    {"AbC=%fyee", "12.3456", ""},
    {"AbC=%.fyee", "123.456789012345", ""},
    {"AbC=%.fyee", "123.456789912345", ""},
    {"AbC=%.fyee", "123.456789512345", ""},
    {"AbC=%.fyee", "123.9999999999", ""},
    {"AbC=% .fyee", "123.456789012345", ""},
    {"AbC=% .fyee", "123.456789912345", ""},
    {"AbC=% .fyee", "123.456789512345", ""},
    {"AbC=% .fyee", "123.9999999999", ""},
    {"AbC=% 20.fyee", "123.456789012345", ""},
    {"AbC=% 20.fyee", "123.456789912345", ""},
    {"AbC=% 20.fyee", "123.456789512345", ""},
    {"AbC=% 20.fyee", "123.9999999999", ""},
    {"AbC=% -+20.fyee", "123.456789012345", ""},
    {"AbC=%-+ 20.fyee", "123.456789912345", ""},
    {"AbC=%-+ 20.fyee", "123.456789512345", ""},
    {"AbC=%-+ 20.fyee", "123.9999999999", ""},
    {"AbC=%# -+20.fyee", "123.456789012345", ""},
    {"AbC=%#-+ 20.fyee", "123.456789912345", ""},
    {"AbC=%#-+ 20.fyee", "123.456789512345", ""},
    {"AbC=%#-+ 20.fyee", "123.9999999999", ""},
    {"AbC=%-+ 20.fyee", "123.9999999999", ""},
    {"AbC=%-+ 20.fyee", "123.999999", ""},
    {"AbC=%-+ 20.fyee", "123.49999999999", ""},
    {"AbC=%-+ 20.fyee", "123.49", ""},
    {"AbC=%0+ 20.fyee", "123.6", ""},
    {"AbC=%0+ 20.fyee", "123.59", ""},
    {"AbC=%0+ 20.fyee", "123.5", ""},
    {"AbC=%0+ 23.fyee", "123456789012345", ""},
    {"AbC=%0.1fyee", "123.456789912345", ""},
    {"AbC=%0.3fyee", "0.456789912345", ""},
    {"AbC=%0.3fyee", "0.00456789912345", ""},
    {"AbC=%0.3fyee", "0.0035000000000", ""},
    {"AbC=%0.3fyee", "0.0035000000001", ""},
    {"AbC=%0.3fyee", "1.9999900000001", ""},
    {"AbC=%0.3fyee", "1.99900000001", ""},
    {"AbC=%0.3fyee", "1.99950000001", ""},
    {"AbC=%0.3fyee", "1.99950000", ""},
    {"AbC=%0.3fyee", "5.5", ""},
    {"AbC=%-+ 20.fyee", "123e15", ""},
    {"AbC=%-+ 20eyee", "123e15", ""},
    {"AbC=%-+ 20eyee", "1.234567890123e15", ""},
    {"AbC=%-+ 20eyee", "123.4567890123e15", ""},
    {"AbC=% 020e!", "123.4567890123e15", ""},
    {"AbC=%# 020.e!", "123.4567890123e15", ""},
    {"AbC=%# 020.e!", "123.4567890123e3", ""},
    {"AbC=%# 020.e!", "123.4567890123e-3", ""},
    {"AbC=%# 020.e!", "123.4567890123e-6", ""},
    {"AbC=%# 020e!", "123.4567890123e3", ""},
    {"AbC=%# 020e!", "123.4567890123e-3", ""},
    {"AbC=%# 020e!", "123.4567890123e-6", ""},
    {"AbC=%# 020.e!", "123.4567890123e-6", ""},
    {"AbC=%# 020.2E!", "-123.4567890123e-6", ""},
    {"AbC=%# 020f!", "0", ""},
    {"AbC=% 020f!", "0", ""},
    {"AbC=%# 020e!", "0", ""},
    {"AbC=% 020e!", "0", ""},
    {"AbC=%-+ 20gygg", "123g15", ""},
    {"AbC=%-+ 20gygg", "1.234567890123g15", ""},
    {"AbC=%-+ 20gygg", "123.4567890123g15", ""},
    {"AbC=% 020g!", "123.4567890123g15", ""},
    {"AbC=%# 020.g!", "123.4567890123g15", ""},
    {"AbC=%# 020.g!", "123.4567890123g3", ""},
    {"AbC=%# 020.g!", "123.4567890123g-3", ""},
    {"AbC=%# 020.g!", "123.4567890123g-6", ""},
    {"AbC=%# 020g!", "123.4567890123g3", ""},
    {"AbC=%# 020g!", "123.4567890123g-3", ""},
    {"AbC=%# 020g!", "123.4567890123g-6", ""},
    {"AbC=%# 020.0g!", "123.4567890123g-6", ""},
    {"AbC=%# 020.g!", "123.4567890123g-6", ""},
    {"AbC=%# 020.1g!", "123.4567890123g-6", ""},
    {"AbC=%# 020.2G!", "-123.4567890123g-6", ""},
    {"AbC=%# 020.3G!", "-123.4567890123g-6", ""},
    {"AbC=%# 020.4G!", "-123.4567890123g-6", ""},
    {"AbC=%# 020.5G!", "-123.4567890123g-6", ""},
    {"AbC=%# 020.6G!", "-123.4567890123g-6", ""},
    {"AbC=%# 020.7G!", "-123.4567890123", ""},
    {"AbC=%# 020.g!", "123.4567890123e-6", ""},
    {"AbC=%# 020.2G!", "-123.4567890123e-6", ""},
    {"AbC=%# 020.4G!", "-123.4567890123e-6", ""},
    {"AbC=%# 020.5G!", "-123.4567890123e-6", ""},
    {"AbC=%# 020.6G!", "-123.4567890123e-6", ""},
    {"AbC=%# 020.7G!", "-123.4567890123e-6", ""},
    {"AbC=%# 020.7G!", "-123.4567890123", ""},
    {"AbC=%# 020G!", "-1234567890", ""},
    {"AbC=%# 020G!", "-123456", ""},
    {"AbC=%# 020G!", "-1234567", ""},
    {"AbC=%# 020G!", "-12345678", ""},
    {"AbC=%# 020.3G!", "123.55678", ""},
    {"AbC=%# 020.3G!", "-123.55678", ""},
    {"AbC=%# 020.G!", "0", ""},
    {"AbC=%# 020G!", "0", ""},
    {"AbC=% 020G!", "0", ""},
    {"AbC=% 020G!", "1.23", ""},
    {"AbC=%# 020G!", "1.23", ""},
    {"AbC=% 020f!", "1.23", ""},
    {"AbC=%# 020f!", "1.23", ""},
    {"AbC=% 020e!", "1.23", ""},
    {"AbC=%# 020e!", "1.23", ""},
    {"AbC=%# 020e!", "1.2300000001", ""},
    {"AbC=%# 020G!", "12300000001", ""},
    {"AbC=% 020g!", "12300000001", ""},
    {"AbC=% 010.3e!", "9.999999", ""},
    {"AbC=%.3f!", "1.55555", ""},
    {"AbC=%.3f!", "4.55555", ""},
    {"AbC=%.3f!", "5.55555", ""},
    {"AbC=%.3f!", "5.66666", ""},
    {"AbC=%.3f!", "5.66666", ""},
    {"AbC=%.f!", "5.5", ""},
    {"AbC=%.f!", "5.6", ""},
    {"AbC=%.f!", "5.4", ""},
    {"AbC=%.1f!", "5.5", ""},
    {"AbC=%.f!", "5.0005", ""},
    {"AbC=%.2f!", "5.0005", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sprintf_f) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_f[_i][0];
  int real_func_int;
  int our_func_int;
  // printf("_i=%d\n",_i);
  // printf("test_format=%s\n",test_format);
  double argument_f = atof(array_sprintf_f[_i][1]);
  // printf("argument_f=%f\n",argument_f);
  real_func_int = sprintf(real_func, test_format, argument_f);
  our_func_int = s21_sprintf(our_func, test_format, argument_f);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%.25f\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_f, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

START_TEST(test_sprintf_f_nan) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_f[_i][0];
  int real_func_int;
  int our_func_int;

  double argument_f = 0.0 / 0.0;
  // printf("argument_f=%f\n",argument_f);
  real_func_int = sprintf(real_func, test_format, argument_f);
  our_func_int = s21_sprintf(our_func, test_format, argument_f);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%.25f\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_f, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

START_TEST(test_sprintf_f_inf) {
  char our_func[5024] = "";
  char real_func[5024] = "";
  char* test_format = array_sprintf_f[_i][0];
  int real_func_int;
  int our_func_int;

  double argument_f = -1.0 / 0.0;
  real_func_int = sprintf(real_func, test_format, argument_f);
  our_func_int = s21_sprintf(our_func, test_format, argument_f);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%.25f\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_f, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_Lf[90][3] = {
    {"AbC=%Lfyee", "123.45678901234567890123", ""},
    {"AbC=%Lfyee", "123.45678901234567890123", ""},
    {"AbC=%Lfyee", "123.45678901234567890123", ""},
    {"AbC=%Lfyee", "123.9999999999", ""},
    {"AbC=%Lfyee", "12.3456", ""},
    {"AbC=%.Lfyee", "123.456789012345", ""},
    {"AbC=%.Lfyee", "123.456789912345", ""},
    {"AbC=%.Lfyee", "123.456789512345", ""},
    {"AbC=%.Lfyee", "123.9999999999", ""},
    {"AbC=% .Lfyee", "123.456789012345", ""},
    {"AbC=% .Lfyee", "123.456789912345", ""},
    {"AbC=% .Lfyee", "123.456789512345", ""},
    {"AbC=% .Lfyee", "123.9999999999999999999999999", ""},
    {"AbC=% 20.Lfyee", "123.456789012345", ""},
    {"AbC=% 20.Lfyee", "123.456789912345", ""},
    {"AbC=% 20.Lfyee", "123.456789512345", ""},
    {"AbC=% 20.Lfyee", "123.9999999999", ""},
    {"AbC=% -+20.Lfyee", "123.456789012345", ""},
    {"AbC=%-+ 20.Lfyee", "123.456789912345", ""},
    {"AbC=%-+ 20.Lfyee", "123.456789512345", ""},
    {"AbC=%-+ 20.Lfyee", "123.9999999999", ""},
    {"AbC=%# -+20.Lfyee", "123.456789012345", ""},
    {"AbC=%#-+ 20.Lfyee", "123.456789912345", ""},
    {"AbC=%#-+ 20.Lfyee", "123.456789512345", ""},
    {"AbC=%#-+ 20.Lfyee", "123.9999999999", ""},
    {"AbC=%-+ 20.Lfyee", "123.9999999999", ""},
    {"AbC=%-+ 20.Lfyee", "123.999999", ""},
    {"AbC=%-+ 20.Lfyee", "123.49999999999", ""},
    {"AbC=%-+ 20.Lfyee", "123.49", ""},
    {"AbC=%0+ 20.Lfyee", "123.6", ""},
    {"AbC=%0+ 20.Lfyee", "123.59", ""},
    {"AbC=%0+ 20.Lfyee", "123.5", ""},
    {"AbC=%0+ 25.Lfyee", "1234567890123456", ""},
    {"AbC=%0.1Lfyee", "123.456789912345", ""},
    {"AbC=%0.3Lfyee", "0.456789912345", ""},
    {"AbC=%0.3Lfyee", "0.00456789912345", ""},
    {"AbC=%0.3Lfyee", "0.0035000000000", ""},
    {"AbC=%0.3Lfyee", "0.003500", ""},
    {"AbC=%0.3Lfyee", "0.0035000000001", ""},
    {"AbC=%0.3Lfyee", "0.0035", ""},
    {"AbC=%Lfyee", "0.0035", ""},
    {"AbC=%Lfyee", "0.0035000000000001", ""},
    {"AbC=%Lfyee", "0.003500000000001", ""},
    {"AbC=%Lfyee", "0.00350000000001", ""},
    {"AbC=%Lfyee", "0.0035000000001", ""},
    {"AbC=%Lfyee", "0.003500000001", ""},
    {"AbC=%Lfyee", "0.00350000001", ""},
    {"AbC=%Lfyee", "0.0035000001", ""},
    {"AbC=%0.3Lfyee", "5.5", ""},
    {"1AbC=%-+ 20.Lfyee", "123.499999999999999999999999", ""},
    {"2AbC=%-+ 20.Lfyee", "123.4999", ""},
    {"3AbC=%-+ 20.Lfyee", "123.5", ""},
    {"AbC=%-+ 20.Lfyee", "123e15", ""},
    {"AbC=%-+ 20.Lfyee", "123e15", ""},
    {"AbC=%-+ 20.Lfyee", "123e15", ""},
    {"AbC=%#-+ 20.3Lfyee", "123.456789912345", ""},
    {"AbC=%#-+ 20.3Lfyee", "123e10", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sprintf_Lf) {
  char our_func[5024] = "";
  char real_func[5024] = "";
  char* test_format = array_sprintf_Lf[_i][0];
  int real_func_int;
  int our_func_int;

  long double argument_f;
  sscanf(array_sprintf_Lf[_i][1], "%Lf", &argument_f);

  // printf("argument_f=%f\n",argument_f);
  real_func_int = sprintf(real_func, test_format, argument_f);
  our_func_int = s21_sprintf(our_func, test_format, argument_f);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%.25Lf\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_f, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

START_TEST(test_sprintf_Lf_nan) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_Lf[_i][0];
  int real_func_int;
  int our_func_int;

  long double argument_f = 0.0 / 0.0;

  // printf("argument_f=%f\n",argument_f);
  real_func_int = sprintf(real_func, test_format, argument_f);
  our_func_int = s21_sprintf(our_func, test_format, argument_f);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%Lf\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_f, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

START_TEST(test_sprintf_Lf_inf) {
  // printf("До 0");
  char our_func[5024] = "";
  char real_func[5024] = "";
  char* test_format = array_sprintf_Lf[_i][0];
  int real_func_int;
  int our_func_int;

  char* argument_f_inf = "inf";
  long double argument_f;
  sscanf(argument_f_inf, "%Lf", &argument_f);
  if (isfinite(argument_f)) {
    argument_f = 999;
  }
  real_func_int = sprintf(real_func, test_format, argument_f);
  our_func_int = s21_sprintf(our_func, test_format, argument_f);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%Lf\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_f, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_x[130][3] = {{"123 AbC=%xyee", "123", ""},
                                        {"%l 0++   0 05xx", "123", ""},
                                        {"%.2 0++   0 05 xx", "123", ""},
                                        {"%.2h 0++   0 05xx", "123", ""},
                                        {"%.2hl 0++   0 05xx", "123", ""},
                                        {"%.2l 0++   0 05xx", "123", ""},
                                        {"%.2lx 0++   0 05xx", "123", ""},
                                        {"% .2x y", "123", ""},
                                        {"%  .2x y", "123", ""},
                                        {"%  0.2x y", "123", ""},
                                        {"%0  0.2x y", "123", ""},
                                        {"%06  0.2x y", "123", ""},
                                        {"% 06 .3x 0++", "123", ""},
                                        {"% 06.3x 0++", "123", ""},
                                        {"% 06 x 0++", "123", ""},
                                        {"% 06x 0++", "123", ""},
                                        {"% 06l x 0++", "123", ""},
                                        {"% 06lx 0++", "123", ""},
                                        {"%+7.10x", "12345", ""},
                                        {"%+10.7x", "12345", ""},
                                        {"%0+7.10x", "12345", ""},
                                        {"%0+10.7x", "12345", ""},
                                        {"%10x", "12345", ""},
                                        {"%+10x", "12345", ""},
                                        {"%010x", "12345", ""},
                                        {"%+010x", "12345", ""},
                                        {"%10.7x", "12345", ""},
                                        {"%010.7x", "12345", ""},
                                        {"%+010.7x", "12345", ""},
                                        {"%-010.7x", "12345", ""},
                                        {"%- 010.7x", "12345", ""},
                                        {"%%- 010.7x", "12345", ""},
                                        {"%.- 010.7x", "12345", ""},
                                        {"%.0- 010.7x", "12345", ""},
                                        {"%.9- 010.7x", "12345", ""},
                                        {"%+10.3x", "12345", ""},
                                        {"%+010.3x", "12345", ""},
                                        {"%+010x", "12345", ""},
                                        {"%+010.0x", "12345", ""},
                                        {"%+010.07x", "12345", ""},
                                        {"%+ 010.0x", "0", ""},
                                        {"%+010.7x", "0", ""},
                                        {"%+010x", "0", ""},
                                        {"%+10.7x", "0", ""},
                                        {"%+10x", "0", ""},
                                        {"%+10.1x", "0", ""},
                                        {"%+10.0x", "0", ""},
                                        {"%+010x", "0", ""},
                                        {"%+010.1x", "0", ""},
                                        {"%+010.0x", "0", ""},
                                        {"%+010.=x", "0", ""},
                                        {"%+010.x", "0", ""},
                                        {"%+020hx", "2147483646", ""},
                                        {"%+020hx", "2147483649", ""},
                                        {"%+020x", "2147483649", ""},
                                        {"%+020x", "21474836490", ""},
                                        {"%+020hx", "21474836490", ""},
                                        {"%+020hx", "4147483649012", ""},
                                        {"%+020x", "4147483649012", ""},
                                        {"%+020lx", "4147483649012", ""},
                                        {"%+#020lx", "4147483649012", ""},
                                        {"%+#10.7x", "12345", ""},
                                        {"%+020hx", "-2147483646", ""},
                                        {"%+020hx", "-2147483649", ""},
                                        {"%+020x", "-2147483649", ""},
                                        {"%+020x", "-21474836490", ""},
                                        {"%+020hx", "-21474836490", ""},
                                        {"%+020hx", "-4147483649012", ""},
                                        {"%+ 020hx", "-4147483649012", ""},
                                        {"%+ 020.15hx", "-4147483649012", ""},
                                        {"%+020x", "-4147483649012", ""},
                                        {"%+025lx", "-4294967290", ""},
                                        {"%+#025lx", "-4294967290", ""},
                                        {"%+#10.7x", "-12345", ""},
                                        {"%+- 020.15hx", "-2147483646", ""},
                                        {"%+- 020.15hx", "-2147483649", ""},
                                        {"%+- 020.16x", "-2147483649", ""},
                                        {"%+- 020.15x", "-21474836490", ""},
                                        {"%+64", "64", ""},
                                        {"aaa%+64 bbb", "64", ""},
                                        {"%+64 bbb", "64", ""},
                                        {"%++# 06 x 0++", "123", ""},
                                        {"%-+-# ++# 06 x 0++", "123", ""},
                                        {"%-  +-# ++# 06 x 0++", "123", ""},
                                        {"%-  +- ++ 06 x 0++", "123", ""},
                                        {"% +06 x 0++", "123", ""},
                                        {"% -06 x 0++", "123", ""},
                                        {"% #06 x 0++", "123", ""},
                                        {"% ###06 x 0++", "123", ""},
                                        {"%# 06l x 0++", "123", ""},
                                        {"%## 06 x 0++", "123", ""},
                                        {"%++ 06 x 0++", "123", ""},
                                        {"%+ 06 x 0++", "123", ""},
                                        {"% +06 x 0++", "123", ""},
                                        {"% ++06 x 0++", "123", ""},
                                        {"% --06 x 0++", "123", ""},
                                        {"%-- 06 x 0++", "123", ""},
                                        {"%- 06 x 0++", "123", ""},
                                        {"% - 06 x 0++", "123", ""},
                                        {"%## 6 x 0++", "123", ""},
                                        {"%++ 6 x 0++", "123", ""},
                                        {"%+ 6 x 0++", "123", ""},
                                        {"% +6 x 0++", "123", ""},
                                        {"% ++6 x 0++", "123", ""},
                                        {"% 0---#-6 x 0++", "123", ""},
                                        {"%-- 6 x 0++", "123", ""},
                                        {"%- 6 x 0++", "123", ""},
                                        {"% - 6 x 0++", "123", ""},
                                        {"%+ 6 x 0++", "123", ""},
                                        {"%#-# 6 x 0++", "123", ""},
                                        {"%-++ 6 x 0++", "123", ""},
                                        {"%+- 6 x 0++", "123", ""},
                                        {"% -+6 x 0++", "123", ""},
                                        {"% +-+6 x 0++", "123", ""},
                                        {"% 0---#-6 x 0++", "123", ""},
                                        {"%-0+- 6 x 0++", "123", ""},
                                        {"%0- 6 x 0++", "123", ""},
                                        {"% -0 6 x 0++", "123", ""},
                                        {"%0+ 6 x 0++", "123", ""},
                                        {"%#+0 10.7x 0++", "123", ""},
                                        {"%#14.7X!", "17", ""},
                                        {"%#14.7X!", "17", ""},
                                        {"%#014.7X!", "17", ""},
                                        {"%#014.7X!", "17", ""},
                                        {"%#014X!", "17", ""},
                                        {"%#014X!", "0", ""},
                                        {"%#014.X!", "0", ""},
                                        {"%#014.1X!", "0", ""},
                                        {NULL, NULL, NULL}};

START_TEST(test_sprintf_x) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_x[_i][0];
  int real_func_int;
  int our_func_int;

  long int argument_d = atol(array_sprintf_x[_i][1]);
  real_func_int = sprintf(real_func, test_format, argument_d);
  our_func_int = s21_sprintf(our_func, test_format, argument_d);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%ld\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_d, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_o[130][3] = {{"123 AbC=%oyee", "123", ""},
                                        {"%l 0++   0 05oo", "123", ""},
                                        {"%.2 0++   0 05 oo", "123", ""},
                                        {"%.2h 0++   0 05oo", "123", ""},
                                        {"%.2hl 0++   0 05oo", "123", ""},
                                        {"%.2l 0++   0 05oo", "123", ""},
                                        {"%.2lo 0++   0 05oo", "123", ""},
                                        {"% .2o y", "123", ""},
                                        {"%  .2o y", "123", ""},
                                        {"%  0.2o y", "123", ""},
                                        {"%0  0.2o y", "123", ""},
                                        {"%06  0.2o y", "123", ""},
                                        {"% 06 .3o 0++", "123", ""},
                                        {"% 06.3o 0++", "123", ""},
                                        {"% 06 o 0++", "123", ""},
                                        {"% 06o 0++", "123", ""},
                                        {"% 06l o 0++", "123", ""},
                                        {"% 06lo 0++", "123", ""},
                                        {"%+7.10o", "12345", ""},
                                        {"%+10.7o", "12345", ""},
                                        {"%0+7.10o", "12345", ""},
                                        {"%0+10.7o", "12345", ""},
                                        {"%10o", "12345", ""},
                                        {"%+10o", "12345", ""},
                                        {"%010o", "12345", ""},
                                        {"%+010o", "12345", ""},
                                        {"%10.7o", "12345", ""},
                                        {"%010.7o", "12345", ""},
                                        {"%+010.7o", "12345", ""},
                                        {"%-010.7o", "12345", ""},
                                        {"%- 010.7o", "12345", ""},
                                        {"%%- 010.7o", "12345", ""},
                                        {"%.- 010.7o", "12345", ""},
                                        {"%.0- 010.7o", "12345", ""},
                                        {"%.9- 010.7o", "12345", ""},
                                        {"%+10.3o", "12345", ""},
                                        {"%+010.3o", "12345", ""},
                                        {"%+010o", "12345", ""},
                                        {"%+010.0o", "12345", ""},
                                        {"%+010.07o", "12345", ""},
                                        {"%+ 010.0o", "0", ""},
                                        {"%+010.7o", "0", ""},
                                        {"%+010o", "0", ""},
                                        {"%+10.7o", "0", ""},
                                        {"%+10o", "0", ""},
                                        {"%+10.1o", "0", ""},
                                        {"%+10.0o", "0", ""},
                                        {"%+010o", "0", ""},
                                        {"%+010.1o", "0", ""},
                                        {"%+010.0o", "0", ""},
                                        {"%+010.=o", "0", ""},
                                        {"%+010.o", "0", ""},
                                        {"%+020ho", "2147483646", ""},
                                        {"%+020ho", "2147483649", ""},
                                        {"%+020o", "2147483649", ""},
                                        {"%+020o", "21474836490", ""},
                                        {"%+020ho", "21474836490", ""},
                                        {"%+020ho", "4147483649012", ""},
                                        {"%+020o", "4147483649012", ""},
                                        {"%+020lo", "4147483649012", ""},
                                        {"%+#020lo", "4147483649012", ""},
                                        {"%+#10.7o", "12345", ""},
                                        {"%+020ho", "-2147483646", ""},
                                        {"%+020ho", "-2147483649", ""},
                                        {"%+020o", "-2147483649", ""},
                                        {"%+020o", "-21474836490", ""},
                                        {"%+020ho", "-21474836490", ""},
                                        {"%+020ho", "-4147483649012", ""},
                                        {"%+ 020ho", "-4147483649012", ""},
                                        {"%+ 020.15ho", "-4147483649012", ""},
                                        {"%+020o", "-4147483649012", ""},
                                        {"%+025lo", "-4294967290", ""},
                                        {"%+#025lo", "-4294967290", ""},
                                        {"%+#10.7o", "-12345", ""},
                                        {"%+- 020.15ho", "-2147483646", ""},
                                        {"%+- 020.15ho", "-2147483649", ""},
                                        {"%+- 020.16o", "-2147483649", ""},
                                        {"%+- 020.15o", "-21474836490", ""},
                                        {"%+64", "64", ""},
                                        {"aaa%+64 bbb", "64", ""},
                                        {"%+64 bbb", "64", ""},
                                        {"%++# 06 o 0++", "123", ""},
                                        {"%-+-# ++# 06 o 0++", "123", ""},
                                        {"%-  +-# ++# 06 o 0++", "123", ""},
                                        {"%-  +- ++ 06 o 0++", "123", ""},
                                        {"% +06 o 0++", "123", ""},
                                        {"% -06 o 0++", "123", ""},
                                        {"% #06 o 0++", "123", ""},
                                        {"% ###06 o 0++", "123", ""},
                                        {"%# 06l o 0++", "123", ""},
                                        {"%## 06 o 0++", "123", ""},
                                        {"%++ 06 o 0++", "123", ""},
                                        {"%+ 06 o 0++", "123", ""},
                                        {"% +06 o 0++", "123", ""},
                                        {"% ++06 o 0++", "123", ""},
                                        {"% --06 o 0++", "123", ""},
                                        {"%-- 06 o 0++", "123", ""},
                                        {"%- 06 o 0++", "123", ""},
                                        {"% - 06 o 0++", "123", ""},
                                        {"%## 6 o 0++", "123", ""},
                                        {"%++ 6 o 0++", "123", ""},
                                        {"%+ 6 o 0++", "123", ""},
                                        {"% +6 o 0++", "123", ""},
                                        {"% ++6 o 0++", "123", ""},
                                        {"% 0---#-6 o 0++", "123", ""},
                                        {"%-- 6 o 0++", "123", ""},
                                        {"%- 6 o 0++", "123", ""},
                                        {"% - 6 o 0++", "123", ""},
                                        {"%+ 6 o 0++", "123", ""},
                                        {"%#-# 6 o 0++", "123", ""},
                                        {"%-++ 6 o 0++", "123", ""},
                                        {"%+- 6 o 0++", "123", ""},
                                        {"% -+6 o 0++", "123", ""},
                                        {"% +-+6 o 0++", "123", ""},
                                        {"% 0---#-6 o 0++", "123", ""},
                                        {"%-0+- 6 o 0++", "123", ""},
                                        {"%0- 6 o 0++", "123", ""},
                                        {"% -0 6 o 0++", "123", ""},
                                        {"%0+ 6 o 0++", "123", ""},
                                        {"%#+0 10.7o 0++", "123", ""},
                                        {"%10.7o!", "123", ""},
                                        {"%#10.7o!", "123", ""},
                                        {"%#010o!", "123", ""},
                                        {"%#010o!", "0", ""},
                                        {"%#010.o!", "0", ""},
                                        {"%#010.1o!", "0", ""},
                                        {NULL, NULL, NULL}};

START_TEST(test_sprintf_o) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_o[_i][0];
  int real_func_int;
  int our_func_int;

  long int argument_d = atol(array_sprintf_o[_i][1]);
  real_func_int = sprintf(real_func, test_format, argument_d);
  our_func_int = s21_sprintf(our_func, test_format, argument_d);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%ld\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_d, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_p[130][3] = {{"123 AbC=%pyee", "123", ""},
                                        {"%l 0++   0 05pp", "123", ""},
                                        {"%.2 0++   0 05 pp", "123", ""},
                                        {"%.2h 0++   0 05pp", "123", ""},
                                        {"%.2hl 0++   0 05pp", "123", ""},
                                        {"%.2l 0++   0 05pp", "123", ""},
                                        {"%.2lp 0++   0 05pp", "123", ""},
                                        {"% .2p y", "123", ""},
                                        {"%  .2p y", "123", ""},
                                        {"%  0.2p y", "123", ""},
                                        {"%0  0.2p y", "123", ""},
                                        {"%06  0.2p y", "123", ""},
                                        {"% 06 .3p 0++", "123", ""},
                                        {"% 06.3p 0++", "123", ""},
                                        {"% 06 p 0++", "123", ""},
                                        {"% 06p 0++", "123", ""},
                                        {"% 06l p 0++", "123", ""},
                                        {"% 06lp 0++", "123", ""},
                                        {"%+7.10p", "12345", ""},
                                        {"%+10.7p", "12345", ""},
                                        {"%0+7.10p", "12345", ""},
                                        {"%0+10.7p", "12345", ""},
                                        {"%10p", "12345", ""},
                                        {"%+10p", "12345", ""},
                                        {"%010p", "12345", ""},
                                        {"%+010p", "12345", ""},
                                        {"%10.7p", "12345", ""},
                                        {"%010.7p", "12345", ""},
                                        {"%+010.7p", "12345", ""},
                                        {"%-010.7p", "12345", ""},
                                        {"%- 010.7p", "12345", ""},
                                        {"%%- 010.7p", "12345", ""},
                                        {"%.- 010.7p", "12345", ""},
                                        {"%.0- 010.7p", "12345", ""},
                                        {"%.9- 010.7p", "12345", ""},
                                        {"%+10.3p", "12345", ""},
                                        {"%+010.3p", "12345", ""},
                                        {"%+010p", "12345", ""},
                                        {"%+010.0p", "12345", ""},
                                        {"%+010.07p", "12345", ""},
                                        {"%+ 010.0p", "0", ""},
                                        {"%+010.7p", "0", ""},
                                        {"%+010p", "0", ""},
                                        {"%+10.7p", "0", ""},
                                        {"%+10p", "0", ""},
                                        {"%+10.1p", "0", ""},
                                        {"%+10.0p", "0", ""},
                                        {"%+010p", "0", ""},
                                        {"%+010.1p", "0", ""},
                                        {"%+010.0p", "0", ""},
                                        {"%+010.=p", "0", ""},
                                        {"%+010.p", "0", ""},
                                        {"%+020hp", "2147483646", ""},
                                        {"%+020hp", "2147483649", ""},
                                        {"%+020p", "2147483649", ""},
                                        {"%+020p", "21474836490", ""},
                                        {"%+020hp", "21474836490", ""},
                                        {"%+020hp", "4147483649012", ""},
                                        {"%+020p", "4147483649012", ""},
                                        {"%+020lp", "4147483649012", ""},
                                        {"%+#020lp", "4147483649012", ""},
                                        {"%+#10.7p", "12345", ""},
                                        {"%+020hp", "-2147483646", ""},
                                        {"%+020hp", "-2147483649", ""},
                                        {"%+020p", "-2147483649", ""},
                                        {"%+020p", "-21474836490", ""},
                                        {"%+020hp", "-21474836490", ""},
                                        {"%+020hp", "-4147483649012", ""},
                                        {"%+ 020hp", "-4147483649012", ""},
                                        {"%+ 020.15hp", "-4147483649012", ""},
                                        {"%+020p", "-4147483649012", ""},
                                        {"%+025lp", "-4294967290", ""},
                                        {"%+#025lp", "-4294967290", ""},
                                        {"%+#10.7p", "-12345", ""},
                                        {"%+- 020.15hp", "-2147483646", ""},
                                        {"%+- 020.15hp", "-2147483649", ""},
                                        {"%+- 020.16p", "-2147483649", ""},
                                        {"%+- 020.15p", "-21474836490", ""},
                                        {"%+64", "64", ""},
                                        {"aaa%+64 bbb", "64", ""},
                                        {"%+64 bbb", "64", ""},
                                        {"%++# 06 p 0++", "123", ""},
                                        {"%-+-# ++# 06 p 0++", "123", ""},
                                        {"%-  +-# ++# 06 p 0++", "123", ""},
                                        {"%-  +- ++ 06 p 0++", "123", ""},
                                        {"% +06 p 0++", "123", ""},
                                        {"% -06 p 0++", "123", ""},
                                        {"% #06 p 0++", "123", ""},
                                        {"% ###06 p 0++", "123", ""},
                                        {"%# 06l p 0++", "123", ""},
                                        {"%## 06 p 0++", "123", ""},
                                        {"%++ 06 p 0++", "123", ""},
                                        {"%+ 06 p 0++", "123", ""},
                                        {"% +06 p 0++", "123", ""},
                                        {"% ++06 p 0++", "123", ""},
                                        {"% --06 p 0++", "123", ""},
                                        {"%-- 06 p 0++", "123", ""},
                                        {"%- 06 p 0++", "123", ""},
                                        {"% - 06 p 0++", "123", ""},
                                        {"%## 6 p 0++", "123", ""},
                                        {"%++ 6 p 0++", "123", ""},
                                        {"%+ 6 p 0++", "123", ""},
                                        {"% +6 p 0++", "123", ""},
                                        {"% ++6 p 0++", "123", ""},
                                        {"% 0---#-6 p 0++", "123", ""},
                                        {"%-- 6 p 0++", "123", ""},
                                        {"%- 6 p 0++", "123", ""},
                                        {"% - 6 p 0++", "123", ""},
                                        {"%+ 6 p 0++", "123", ""},
                                        {"%#-# 6 p 0++", "123", ""},
                                        {"%-++ 6 p 0++", "123", ""},
                                        {"%+- 6 p 0++", "123", ""},
                                        {"% -+6 p 0++", "123", ""},
                                        {"% +-+6 p 0++", "123", ""},
                                        {"% 0---#-6 p 0++", "123", ""},
                                        {"%-0+- 6 p 0++", "123", ""},
                                        {"%0- 6 p 0++", "123", ""},
                                        {"% -0 6 p 0++", "123", ""},
                                        {"%0+ 6 p 0++", "123", ""},
                                        {"%0+ 6 p 0++", "-123", ""},
                                        {"%-10p0++", "0", ""},
                                        {"%10p0++", "0", ""},
                                        {"%-10.p0++", "0", ""},
                                        {"%10.p0++", "0", ""},
                                        {NULL, NULL, NULL}};

START_TEST(test_sprintf_p) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_p[_i][0];
  int real_func_int;
  int our_func_int;

  long int argument_d = atol(array_sprintf_p[_i][1]);

  real_func_int = sprintf(real_func, test_format, argument_d);
  our_func_int = s21_sprintf(our_func, test_format, argument_d);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , argument == \"%ld\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_d, real_func, our_func, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sprintf_n[130][3] = {{"123 AbC=%nyee", "123", ""},
                                        {"%l 0++   0 05nn", "123", ""},
                                        {"%.2 0++   0 05 nn", "123", ""},
                                        {"%.2h 0++   0 05nn", "123", ""},
                                        {"%.2hl 0++   0 05nn", "123", ""},
                                        {"%.2l 0++   0 05nn", "123", ""},
                                        {"%.2ln 0++   0 05nn", "123", ""},
                                        {"% .2n y", "123", ""},
                                        {"sadg %% sg%  .2n y", "123", ""},
                                        {"%  0.2n y", "123", ""},
                                        {"%%%0  0.2n y", "123", ""},
                                        {"gs% #--- 5 %06  0.2n y", "123", ""},
                                        {"% 06 .3n 0++", "123", ""},
                                        {"% 06.3n 0++", "123", ""},
                                        {"% 06 n 0++", "123", ""},
                                        {"% 06n 0++", "123", ""},
                                        {"% 06l n 0++", "123", ""},
                                        {"% 06ln 0++", "123", ""},
                                        {"  %+7.10n", "12345", ""},
                                        {"%+10.7n", "12345", ""},
                                        {"%0+7.10n", "12345", ""},
                                        {"%0+10.7n", "12345", ""},
                                        {"%10n", "12345", ""},
                                        {"%+10n", "12345", ""},
                                        {"%010n", "12345", ""},
                                        {"%+010n", "12345", ""},
                                        {"%10.7n", "12345", ""},
                                        {"%010.7n", "12345", ""},
                                        {"%+010.7n", "12345", ""},
                                        {"%-010.7n", "12345", ""},
                                        {"%- 010.7n", "12345", ""},
                                        {"%%- 010.7n", "12345", ""},
                                        {"%.- 010.7n", "12345", ""},
                                        {"%.0- 010.7n", "12345", ""},
                                        {"%.9- 010.7n", "12345", ""},
                                        {"%+10.3n", "12345", ""},
                                        {"%+010.3n", "12345", ""},
                                        {"qw%+010n", "12345", ""},
                                        {"%+010.0n", "12345", ""},
                                        {"%+010.07n", "12345", ""},
                                        {"%+ 010.0n", "0", ""},
                                        {"%+010.7n", "0", ""},
                                        {"%+010n", "0", ""},
                                        {"%+10.7n", "0", ""},
                                        {"%+10n", "0", ""},
                                        {"%+10.1n", "0", ""},
                                        {"%+10.0n", "0", ""},
                                        {"%+010n", "0", ""},
                                        {"%+010.1n", "0", ""},
                                        {"%+010.0n", "0", ""},
                                        {"%+010.=n", "0", ""},
                                        {"%+010.n", "0", ""},
                                        {"%+020hn", "2147483646", ""},
                                        {"%+020hn", "2147483649", ""},
                                        {"%+020n", "2147483649", ""},
                                        {"%+020n", "21474836490", ""},
                                        {"%+020hn", "21474836490", ""},
                                        {"%+020hn", "4147483649012", ""},
                                        {"a%+020n", "4147483649012", ""},
                                        {"%+020ln", "4147483649012", ""},
                                        {"%+#020ln", "4147483649012", ""},
                                        {"%+#10.7n", "12345", ""},
                                        {"%+020hn", "-2147483646", ""},
                                        {"%+020hn", "-2147483649", ""},
                                        {"%+020n", "-2147483649", ""},
                                        {"%+020n", "-21474836490", ""},
                                        {"%+020hn", "-21474836490", ""},
                                        {"dd%+020hn", "-4147483649012", ""},
                                        {"%+ 020hn", "-4147483649012", ""},
                                        {"%+ 020.15hn", "-4147483649012", ""},
                                        {"%+020n", "-4147483649012", ""},
                                        {"%+025ln", "-4294967290", ""},
                                        {"%+#025ln", "-4294967290", ""},
                                        {"%+#10.7n", "-12345", ""},
                                        {"weg%+- 020.15hn", "-2147483646", ""},
                                        {"gewg%+- 020.15hn", "-2147483649", ""},
                                        {"%+- 020.16n", "-2147483649", ""},
                                        {"%+- 020.15n", "-21474836490", ""},
                                        {"%+64", "64", ""},
                                        {"aaa%+64 bbb", "64", ""},
                                        {"%+64 bbb", "64", ""},
                                        {"%++# 06 n 0++", "123", ""},
                                        {"%-+-# ++# 06 n 0++", "123", ""},
                                        {"%-  +-# ++# 06 n 0++", "123", ""},
                                        {"%-  +- ++ 06 n 0++", "123", ""},
                                        {"% +06 n 0++", "123", ""},
                                        {"% -06 n 0++", "123", ""},
                                        {"% #06 n 0++", "123", ""},
                                        {"% ###06 n 0++", "123", ""},
                                        {"%# 06l n 0++", "123", ""},
                                        {"%## 06 n 0++", "123", ""},
                                        {"%++ 06 n 0++", "123", ""},
                                        {"%+ 06 n 0++", "123", ""},
                                        {"% +06 n 0++", "123", ""},
                                        {"% ++06 n 0++", "123", ""},
                                        {"% --06 n 0++", "123", ""},
                                        {"%-- 06 n 0++", "123", ""},
                                        {"%- 06 n 0++", "123", ""},
                                        {"% - 06 n 0++", "123", ""},
                                        {"%## 6 n 0++", "123", ""},
                                        {"%++ 6 n 0++", "123", ""},
                                        {"%+ 6 n 0++", "123", ""},
                                        {"% +6 n 0++", "123", ""},
                                        {"% ++6 n 0++", "123", ""},
                                        {"% 0---#-6 n 0++", "123", ""},
                                        {"%-- 6 n 0++", "123", ""},
                                        {"%- 6 n 0++", "123", ""},
                                        {"% - 6 n 0++", "123", ""},
                                        {"%+ 6 n 0++", "123", ""},
                                        {"%#-# 6 n 0++", "123", ""},
                                        {"%-++ 6 n 0++", "123", ""},
                                        {"%+- 6 n 0++", "123", ""},
                                        {"% -+6 n 0++", "123", ""},
                                        {"% +-+6 n 0++", "123", ""},
                                        {"% 0---#-6 n 0++", "123", ""},
                                        {"%-0+- 6 n 0++", "123", ""},
                                        {"%0- 6 n 0++", "123", ""},
                                        {"% -0 6 n 0++", "123", ""},
                                        {"%0+ 6 n 0++", "123", ""},
                                        {"%0+ 6 n 0++", "-123", ""},
                                        {"%-10n0++", "0", ""},
                                        {"%10n0++", "0", ""},
                                        {"weew%-10.n0++", "0", ""},
                                        {"gweg%10.n0++", "0", ""},
                                        {NULL, NULL, NULL}};

START_TEST(test_sprintf_n) {
  char our_func[1024] = "";
  char real_func[1024] = "";
  char* test_format = array_sprintf_n[_i][0];
  int real_func_int;
  int our_func_int;

  int argument_n_real = 0;
  int argument_n_our = 0;
  real_func_int = sprintf(real_func, test_format, &argument_n_real);
  our_func_int = s21_sprintf(our_func, test_format, &argument_n_our);
  ck_assert_msg(
      strcmp(real_func, our_func) == 0 && real_func_int == our_func_int &&
          argument_n_real == argument_n_our,
      "\nError with: test_format == \"%s\"        , argument_n_real == \"%d\", argument_n_our == \"%d\"\n\
  =>          real_func == \"%s\"\n\
  =>          our_func  == \"%s\"\n\
  =>         real_func_int == \"%d\"\n\
  =>         our_func_int  == \"%d\"\n",
      test_format, argument_n_real, argument_n_our, real_func, our_func,
      real_func_int, our_func_int);
}
END_TEST

Suite* suite_sprintf(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("SPRINTF");
  tc_core = tcase_create("Core");

  tcase_add_loop_test(tc_core, test_sprintf_d, 0,
                      len_array_func_3(array_sprintf_d));
  tcase_add_loop_test(tc_core, test_sprintf_i, 0,
                      len_array_func_3(array_sprintf_i));
  tcase_add_loop_test(tc_core, test_sprintf_d_xxl, 0,
                      len_array_func_6(array_sprintf_d_xxl));
  tcase_add_loop_test(tc_core, test_sprintf_c, 0,
                      len_array_func_3(array_sprintf_c));
  tcase_add_loop_test(tc_core, test_sprintf_s, 0,
                      len_array_func_3(array_sprintf_s));
  tcase_add_loop_test(tc_core, test_sprintf_ls, 0,
                      len_array_func_3(array_sprintf_ls));
  tcase_add_loop_test(tc_core, test_sprintf_f, 0,
                      len_array_func_3(array_sprintf_f));
  tcase_add_loop_test(tc_core, test_sprintf_Lf, 0,
                      len_array_func_3(array_sprintf_Lf));
  tcase_add_loop_test(tc_core, test_sprintf_x, 0,
                      len_array_func_3(array_sprintf_x));
  tcase_add_loop_test(tc_core, test_sprintf_o, 0,
                      len_array_func_3(array_sprintf_o));
  tcase_add_loop_test(tc_core, test_sprintf_p, 0,
                      len_array_func_3(array_sprintf_p));
  tcase_add_loop_test(tc_core, test_sprintf_n, 0,
                      len_array_func_3(array_sprintf_n));
  tcase_add_loop_test(tc_core, test_sprintf_Lf_nan, 0,
                      len_array_func_3(array_sprintf_Lf));
  tcase_add_loop_test(tc_core, test_sprintf_f_nan, 0,
                      len_array_func_3(array_sprintf_f));
  tcase_add_loop_test(tc_core, test_sprintf_Lf_inf, 0,
                      len_array_func_3(array_sprintf_Lf));
  tcase_add_loop_test(tc_core, test_sprintf_f_inf, 0,
                      len_array_func_3(array_sprintf_f));

  suite_add_tcase(s, tc_core);
  return s;
}

//Функции расчета длины массива
int len_array_func_3(char* array[][3]) {
  int len = 0;
  while (array[len][2] != NULL) {
    // printf("array[len][0]=%s\n",array[len][0]);
    len += 1;
  }
  return len;
}
int len_array_func_4(char* array[][4]) {
  int len = 0;
  while (array[len][3] != NULL) {
    // printf("array[len][0]=%s\n",array[len][0]);
    len += 1;
  }
  return len;
}
int len_array_func_6(char* array[][6]) {
  int len = 0;
  while (array[len][3] != NULL) {
    // printf("array[len][0]=%s\n",array[len][0]);
    len += 1;
  }
  return len;
}
