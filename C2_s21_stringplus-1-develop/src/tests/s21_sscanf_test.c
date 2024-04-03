

#include "s21_string_test.h"
int len_array_func_3_sscanf(char* array[][3]);

static char* array_sscanf_d[120][3] = {
    {"123", "%d", ""},
    {"%123", "%%%d", ""},
    {" 123", "%d", ""},
    {" 123 4", "%d", ""},
    {"  123 4", "%d", ""},
    {"  123 4", "%d", ""},
    {"  123,4", "%d", ""},
    {"  123.4", "%d", ""},
    {" :  123 4", "%d", ""},
    {"123", "%2d", ""},
    {"123", "%5d", ""},
    {"123", "%.2d", ""},
    {"123", "%.5d", ""},
    {"123", "%5.2d", ""},
    {"123", "%7.4d", ""},
    {"123", "%2.4d", ""},
    {"+123", "%d", ""},
    {"+123", "%-010.5d", ""},
    {"00123", "%-010.5d", ""},
    {"0000123", "%d", ""},
    {"000123", "%4d", ""},
    {"000123", "%1d", ""},
    {"  0123", "%5d", ""},
    {"+123", "%2d", ""},
    {" 123", "%2d", ""},
    {" 123", "% 2d", ""},
    {" 123", "%02d", ""},
    {" 123", "%-2d", ""},
    {" 123", "%+2d", ""},
    {" 123", "%-2d", ""},
    {" 123", "%+-2d", ""},
    {" 123", "%+++2d", ""},
    {" 123", "%#2d", ""},
    {" 123", "%0d", ""},
    {"0123", "%02d", ""},
    {"0123", "%2d", ""},
    {"123e5", "%d", ""},
    {"123e5", "%%d", ""},
    {"123e5", "%0+02d", ""},
    {"123e5", "%002d", ""},
    {"123 5", "%*%d", ""},
    {"123 5", "%*d%d", ""},
    {"123 5", "%*d%d", ""},
    {"123 5", "%**d%d", ""},
    {"123", ":%d", ""},
    {":123", ":%d", ""},
    {": 123", ":%d", ""},
    {" : 123", ":%d", ""},
    {" :123", ":%d", ""},
    {"123", " %d", ""},
    {" +123", " %d", ""},
    {"+++123", "%d", ""},
    {"+123", "%2d", ""},
    {" . -0123", " . %d", ""},
    {"  . -0123", " . %d", ""},
    {"acb-", "acb%d", ""},
    {"acb-a", "acb%d", ""},
    {"acb-0", "acb%d", ""},
    {"acb-0a", "acb%d", ""},
    {"acb-01", "acb%d", ""},
    {"acb123456789012345678901234567890", "acb%d", ""},
    {"acb123456789012345678901234567890", "acb%ld", ""},
    {"acb123456789012345678901234567890", "acb%lu", ""},
    {"acb2147483647", "acb%d", ""},
    {"acb2147483648", "acb%d", ""},
    {"acb2147483649", "acb%d", ""},
    {"acb9223372036854775807", "acb%d", ""},
    {"acb9223372036854775807", "acb%hd", ""},
    {"acb9223372036854775808", "acb%d", ""},
    {"acb-9223372036854775800", "acb%d", ""},
    {"acb-9223372036854775807", "acb%d", ""},
    {"acb-9223372036854775808", "acb%d", ""},
    {"acb-9223372036854775809", "acb%d", ""},
    {"acb-9223372036854775810", "acb%d", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sscanf_d) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_d[_i][0];
  char* test_format = array_sscanf_d[_i][1];
  int our_func = -99;
  int real_func = -99;

  real_func_int = sscanf(test_src, test_format, &real_func);
  our_func_int = s21_sscanf(test_src, test_format, &our_func);

  ck_assert_msg(
      real_func == our_func && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%d\"\n\
  =>          our_func  == \"%d\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sscanf_d_xxl[120][3] = {
    {"123 321", "%d%d", ""},
    {" 123 321", "%d%d", ""},
    {"  123 321", "%d%d", ""},
    {"  123  321", "%d%d", ""},
    {"123:321", "%d:%d", ""},
    {"123: 321", "%d:%d", ""},
    {"123:  321", "%d:%d", ""},
    {"123 :321", "%d:%d", ""},
    {"123  :321", "%d:%d", ""},
    {"123 : 321", "%d:%d", ""},
    {"123  : 321", "%d:%d", ""},
    {"123  :  321", "%d:%d", ""},
    {"123  :  321", "%d :%d", ""},
    {"123  :  321", "%d: %d", ""},
    {"123  :  321", "%d : %d", ""},
    {"123::::321", "%d:%d", ""},
    {"123    :    321", "%d : 3%d", ""},
    {"123    :    321", "%d : 3 %d", ""},
    {"123    :    321", "%d : 3    %d", ""},
    {"123    :    321", "%d : 3.%d", ""},
    {"123    :    3.  21", "%d : 3.%d", ""},
    {"123    :    3 .  21", "%d : 3.%d", ""},
    {"123    :    3    21", "%d : 3%d", ""},
    {"123 321", "%+d%d", ""},
    {"123 321", "%d%+d", ""},
    {"123 321", "%d%*%d", ""},
    {"123 321", "%d%**%d", ""},
    {"123 321", "%d%**c%d", ""},
    {"123a 321", "%d%**c%d", ""},
    {"123 a321", "%d%**c%d", ""},
    {"123 a  321", "%d%**c%d", ""},
    {"123  321", "%d%%d", ""},
    {"123321", "%3d%d", ""},
    {"acb9223372036854775808123", "acb%d%d", ""},
    {"acb9223372036854775807123", "acb%d%d", ""},
    {"acb9223372036854775805123", "acb%d%d", ""},
    {"123   a 321", "%d%**c%d", ""},
    {"123", "%d%d", ""},
    {"123", "%*d%d", ""},
    {"123", "%*d:%d", ""},
    {"123", "%*d", ""},
    {"123", "%*d:", ""},
    {"123", "%d%d:", ""},
    {"123", "%d:%d", ""},
    {"123", "%d:%d:", ""},
    {"123", "%*d", ""},
    {"123", "%d:", ""},
    {"123", "%.d%d", ""},
    {NULL, NULL, NULL}};
START_TEST(test_sscanf_d_xxl) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_d_xxl[_i][0];
  char* test_format = array_sscanf_d_xxl[_i][1];
  int our_func_0 = -99;
  int real_func_0 = -99;
  int our_func_1 = -99;
  int real_func_1 = -99;
  int our_func_2 = -99;
  int real_func_2 = -99;
  int our_func_3 = -99;
  int real_func_3 = -99;

  real_func_int = sscanf(test_src, test_format, &real_func_0, &real_func_1,
                         &real_func_2, &real_func_3);
  our_func_int = s21_sscanf(test_src, test_format, &our_func_0, &our_func_1,
                            &our_func_2, &our_func_3);

  ck_assert_msg(
      real_func_0 == our_func_0 && real_func_1 == our_func_1 &&
          real_func_2 == our_func_2 && real_func_3 == our_func_3 &&
          real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func_0 == \"%d\"\n\
  =>          our_func_0  == \"%d\"\n\
  =>          real_func_1 == \"%d\"\n\
  =>          our_func_1  == \"%d\"\n\
  =>          real_func_2 == \"%d\"\n\
  =>          our_func_2  == \"%d\"\n\
  =>          real_func_3 == \"%d\"\n\
  =>          our_func_3  == \"%d\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func_0, our_func_0, real_func_1, our_func_1,
      real_func_2, our_func_2, real_func_3, our_func_3, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sscanf_c_xxl[120][3] = {{"ad", "%c%c", ""},
                                           {"a d", "%c%c", ""},
                                           {"a  d", "%c%c", ""},
                                           {" a  d", "%c%c", ""},
                                           {"a", "%c%c", ""},
                                           {"", "%c%c", ""},
                                           {"a b", "%c%c", ""},
                                           {"abcd", "%c%c%lc", ""},
                                           {"abcdefg", "%c%c%lc%lc", ""},
                                           {"dgs fas s", "%c%c%lc%lc", ""},
                                           {"abcdefg", "%c%c%lc%lc", ""},
                                           {"afas asf s", "%c%c%lc%lc", ""},
                                           {NULL, NULL, NULL}};
START_TEST(test_sscanf_c_xxl) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_c_xxl[_i][0];
  char* test_format = array_sscanf_c_xxl[_i][1];
  char our_func_0 = 100;
  char real_func_0 = 100;
  char our_func_1 = 100;
  char real_func_1 = 100;
  wchar_t our_func_2 = 10000;
  wchar_t real_func_2 = 10000;
  wchar_t our_func_3 = 10000;
  wchar_t real_func_3 = 10000;

  real_func_int = sscanf(test_src, test_format, &real_func_0, &real_func_1,
                         &real_func_2, &real_func_3);
  our_func_int = s21_sscanf(test_src, test_format, &our_func_0, &our_func_1,
                            &our_func_2, &our_func_3);

  ck_assert_msg(
      real_func_0 == our_func_0 && real_func_1 == our_func_1 &&
          real_func_2 == our_func_2 && real_func_3 == our_func_3 &&
          real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func_0 == \"%c\"\n\
  =>          our_func_0  == \"%c\"\n\
  =>          real_func_1 == \"%c\"\n\
  =>          our_func_1  == \"%c\"\n\
  =>          real_func_2 == \"%lc\"\n\
  =>          our_func_2  == \"%lc\"\n\
  =>          real_func_3 == \"%lc\"\n\
  =>          our_func_3  == \"%lc\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func_0, our_func_0, real_func_1, our_func_1,
      real_func_2, our_func_2, real_func_3, our_func_3, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sscanf_s_xxl[120][3] = {
    {"ad", "%s", ""},
    {"ad", "%s%s", ""},
    {"ad 12 2", "%s%s", ""},
    {"ad   12 2", "%s%s", ""},
    {"abcd", "%3c%c", ""},
    {"abcdef", "%0c%2c", ""},
    {"abcdef", "%3s%s", ""},
    {"abcdef", "%0s%2s", ""},
    {" a  d", "%2c%0c", ""},
    {" a  d", "%2s%0s", ""},
    {"  ab  cde rhn", "%3s%0s", ""},
    {"  ab  cde rhn", "%3s%4s", ""},
    {"  ab  cde rhn", "%1s%2s", ""},
    {"  ab  cde rhn", "%3s%2s", ""},
    {"  ab  cde", "%3s%5s", ""},
    {"  ab  cde rhn", "%3c%0c", ""},
    {"  ab  cde rhn", "%3c%4c", ""},
    {"  ab  cde rhn", "%1c%2c", ""},
    {"  ab  cde rhn", "%3c%2c", ""},
    {"  ab  cde", "%3c%5c", ""},

    {"йцуъяч", "%3c%c", ""},
    {"йцуъяч", "%0c%2c", ""},
    {"йцуъяч", "%3s%s", ""},
    {"йцуъяч", "%0s%2s", ""},
    {" й  ъ", "%2c%0c", ""},
    {" й  я", "%2s%0s", ""},
    {"  яй  ъэй йюя", "%3s%0s", ""},
    {"  яй  ъэй йюя", "%3s%4s", ""},
    {"  яй  ъэй йюя", "%1s%2s", ""},
    {"  яй  ъэй йюя", "%3s%2s", ""},
    {"  яй  ъэй йюя", "%3s%5s", ""},
    {"  яй  ъэй йюя", "%3c%0c", ""},
    {"  яй  ъэй йюя", "%3c%4c", ""},
    {"  яй  ъэй йюя", "%1c%2c", ""},
    {"  яй  ъэй йюя", "%3c%2c", ""},
    {"  яй  ъэй йюя", "%3c%5c", ""},

    {"sd dsd d", "%1s%1s%3lc%lc", ""},
    {"fd dsd d", "%1s%1s%0lc%2lc", ""},
    {"asgdasd", "%1s%1s%3ls%ls", ""},
    {"sagasdg", "%1s%1s%0ls%2ls", ""},
    {"123e)(1d", "%1s%1s%2lc%0lc", ""},
    {"!)#&$*!", "%1s%1s%2ls%0ls", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%3ls%0ls", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%3ls%4ls", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%1ls%2ls", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%3ls%2ls", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%3ls%5ls", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%3lc%0lc", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%3lc%4lc", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%1lc%2lc", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%3lc%2lc", ""},
    {"!)  #&  $*! 1eww", "%1s%1s%3lc%5lc", ""},
    {"!)  #&  $*! 1eww", "%1s%1s", ""},
    {NULL, NULL, NULL}};
START_TEST(test_sscanf_s_xxl) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_s_xxl[_i][0];
  char* test_format = array_sscanf_s_xxl[_i][1];
  char our_func_0[1024] = "-------------------------";
  char real_func_0[1024] = "-------------------------";
  char our_func_1[1024] = "-------------------------";
  char real_func_1[1024] = "-------------------------";
  wchar_t our_func_2[1024] = L"-------------------------";
  wchar_t real_func_2[1024] = L"-------------------------";
  wchar_t our_func_3[1024] = L"-------------------------";
  wchar_t real_func_3[1024] = L"-------------------------";

  real_func_int = sscanf(test_src, test_format, real_func_0, real_func_1,
                         real_func_2, real_func_3);
  our_func_int = s21_sscanf(test_src, test_format, our_func_0, our_func_1,
                            our_func_2, our_func_3);

  ck_assert_msg(
      !strcmp(real_func_0, our_func_0) && !strcmp(real_func_1, our_func_1) &&
          !strcmp((char*)real_func_2, (char*)our_func_2) &&
          !strcmp((char*)real_func_3, (char*)our_func_3) &&
          real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func_0 == \"%s\"\n\
  =>          our_func_0  == \"%s\"\n\
  =>          real_func_1 == \"%s\"\n\
  =>          our_func_1  == \"%s\"\n\
  =>          real_func_2 == \"%ls\"\n\
  =>          our_func_2  == \"%ls\"\n\
  =>          real_func_3 == \"%ls\"\n\
  =>          our_func_3  == \"%ls\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func_0, our_func_0, real_func_1, our_func_1,
      real_func_2, our_func_2, real_func_3, our_func_3, real_func_int,
      our_func_int);
}
END_TEST

static char* array_sscanf_u[140][3] = {
    {"123", "%u", ""},
    {" 123", "%u", ""},
    {" 123 4", "%u", ""},
    {"  123 4", "%u", ""},
    {"  123 4", "%u", ""},
    {"  123,4", "%u", ""},
    {"  123.4", "%u", ""},
    {" :  123 4", "%u", ""},
    {"123", "%2u", ""},
    {"123", "%5u", ""},
    {"123", "%.2u", ""},
    {"123", "%.5u", ""},
    {"123", "%5.2u", ""},
    {"123", "%7.4u", ""},
    {"123", "%2.4u", ""},
    {"+123", "%u", ""},
    {"+123", "%-010.5u", ""},
    {"00123", "%-010.5u", ""},
    {"0000123", "%u", ""},
    {"000123", "%4u", ""},
    {"000123", "%1u", ""},
    {"  0123", "%5u", ""},
    {"+123", "%2u", ""},
    {" 123", "%2u", ""},
    {" 123", "% 2u", ""},
    {" 123", "%02u", ""},
    {" 123", "%-2u", ""},
    {" 123", "%+2u", ""},
    {" 123", "%-2u", ""},
    {" 123", "%+-2u", ""},
    {" 123", "%+++2u", ""},
    {" 123", "%#2u", ""},
    {" 123", "%0u", ""},
    {"0123", "%02u", ""},
    {"0123", "%2u", ""},
    {"123e5", "%u", ""},
    {"123e5", "%%u", ""},
    {"123e5", "%0+02u", ""},
    {"123e5", "%002u", ""},
    {"123 5", "%*%u", ""},
    {"123 5", "%*u%u", ""},
    {"123 5", "%*u%u", ""},
    {"123 5", "%**u%u", ""},
    {"123", ":%u", ""},
    {":123", ":%u", ""},
    {": 123", ":%u", ""},
    {" : 123", ":%u", ""},
    {" :123", ":%u", ""},
    {"123", " %u", ""},
    {" +123", " %u", ""},
    {"+++123", "%u", ""},
    {"+123", "%2u", ""},
    {" . -0123", " . %u", ""},
    {"  . -0123", " . %u", ""},
    {"acb-", "acb%u", ""},
    {"acb-a", "acb%u", ""},
    {"acb-0", "acb%u", ""},
    {"acb-0a", "acb%u", ""},
    {"acb-01", "acb%u", ""},
    {"acb123456789012345678901234567890", "acb%u", ""},
    {"acb123456789012345678901234567890", "acb%lu", ""},
    {"acb123456789012345678901234567890", "acb%lu", ""},
    {"acb2147483647", "acb%u", ""},
    {"acb2147483648", "acb%u", ""},
    {"acb2147483649", "acb%u", ""},
    {"acb9223372036854775807", "acb%u", ""},
    {"acb9223372036854775807", "acb%hu", ""},
    {"acb9223372036854775808", "acb%u", ""},
    {"acb-9223372036854775800", "acb%u", ""},
    {"acb-9223372036854775807", "acb%u", ""},
    {"acb-9223372036854775808", "acb%u", ""},
    {"acb-9223372036854775809", "acb%u", ""},
    {"acb-9223372036854775811", "acb%u", ""},
    {"acb9223372036854775811", "acb%u", ""},
    {"acb-9223372036854775811", "acb%hu", ""},
    {"acb9223372036854775811", "acb%hu", ""},
    {"acb-9223372036854775811", "acb%lu", ""},
    {"acb9223372036854775811", "acb%lu", ""},
    {"acb18446744073709551614", "acb%lu", ""},
    {"acb18446744073709551615", "acb%lu", ""},
    {"acb18446744073709551616", "acb%lu", ""},
    {"acb-18446744073709551614", "acb%lu", ""},
    {"acb-18446744073709551615", "acb%lu", ""},
    {"acb-18446744073709551616", "acb%lu", ""},
    {"acb-18446744073709551618", "acb%lu", ""},
    {"acb-1", "acb%lu", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sscanf_u) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_u[_i][0];
  char* test_format = array_sscanf_u[_i][1];
  unsigned long int our_func = 99;
  unsigned long int real_func = 99;

  real_func_int = sscanf(test_src, test_format, &real_func);
  our_func_int = s21_sscanf(test_src, test_format, &our_func);

  ck_assert_msg(
      real_func == our_func && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%lu\"\n\
  =>          our_func  == \"%lu\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sscanf_hf[120][3] = {
    {"123", "%hf", ""},
    {"123,adhf", "%hf", ""},
    {"123.456edhf", "%hf", ""},
    {"123.456edhf", "%f", ""},
    {"0.0123edhf", "%f", ""},
    {"123.456edhf", "%4hf", ""},
    {"+123.456edhf", "%2hf", ""},
    {"1.2e10dhf", "%5hf", ""},
    {"1.2e10dhf", "%6hf", ""},
    {"123.456dhf", "%hf", ""},
    {"123.456e10dhf", "%hf", ""},
    {"123.456e+10dhf", "%hf", ""},
    {"123.456e-10dhf", "%hf", ""},
    {"12345678901234567890123456789012345678901234567890e-30dhf", "%hf", ""},
    {"12345678901234567890123456789012345678901234567890edhf", "%hf", ""},
    {"-inf", "%hf", ""},
    {"+inf", "%hf", ""},
    {"inf", "%hf", ""},
    {"-nan", "%hf", ""},
    {"+nan", "%hf", ""},
    {"nan", "%hf", ""},
    {"-123,456edhf", "%hf", ""},
    {"+123,456edhf", "%hf", ""},
    {"-inf", "%2hf", ""},
    {"-inf", "%0hf", ""},
    {"123", "%0hf", ""},
    {",123", "%hf", ""},
    {"-,123", "%hf", ""},
    {",abc", "%hf", ""},
    {",e10bc", "%hf", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sscanf_hf) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_hf[_i][0];
  char* test_format = array_sscanf_hf[_i][1];
  float our_func = -99;
  float real_func = -99;

  real_func_int = sscanf(test_src, test_format, &real_func);
  our_func_int = s21_sscanf(test_src, test_format, &our_func);

  if (isnan(real_func)) {
    char our_func_str[512] = "";
    char real_func_str[512] = "";
    sprintf(our_func_str, "%f", our_func);
    sprintf(real_func_str, "%f", real_func);
    if (strcmp(our_func_str, real_func_str) == 0) {
      real_func = -717;
      our_func = -717;
      // printf("%s\n",our_func_str);
      // printf("%s\n",real_func_str);
    }
  }

  ck_assert_msg(
      real_func == our_func && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%f\"\n\
  =>          our_func  == \"%f\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sscanf_hf_xxl[120][3] = {{"123 456", "%hf%hf", ""},
                                            {"123.f456", "%hf%*c%hf", ""},
                                            {"123.2ef456", "%hf%*c%hf", ""},
                                            {NULL, NULL, NULL}};
START_TEST(test_sscanf_hf_xxl) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_hf_xxl[_i][0];
  char* test_format = array_sscanf_hf_xxl[_i][1];
  float our_func_0 = -99;
  float real_func_0 = -99;
  float our_func_1 = -99;
  float real_func_1 = -99;
  float our_func_2 = -99;
  float real_func_2 = -99;
  float our_func_3 = -99;
  float real_func_3 = -99;

  real_func_int = sscanf(test_src, test_format, &real_func_0, &real_func_1,
                         &real_func_2, &real_func_3);
  our_func_int = s21_sscanf(test_src, test_format, &our_func_0, &our_func_1,
                            &our_func_2, &our_func_3);

  ck_assert_msg(
      real_func_0 == our_func_0 && real_func_1 == our_func_1 &&
          real_func_2 == our_func_2 && real_func_3 == our_func_3 &&
          real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func_0 == \"%f\"\n\
  =>          our_func_0  == \"%f\"\n\
  =>          real_func_1 == \"%f\"\n\
  =>          our_func_1  == \"%f\"\n\
  =>          real_func_2 == \"%f\"\n\
  =>          our_func_2  == \"%f\"\n\
  =>          real_func_3 == \"%f\"\n\
  =>          our_func_3  == \"%f\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func_0, our_func_0, real_func_1, our_func_1,
      real_func_2, our_func_2, real_func_3, our_func_3, real_func_int,
      our_func_int);
}

static char* array_sscanf_lf[120][3] = {
    {"123", "%lf", ""},
    {"123,adlf", "%lf", ""},
    {"123.456edlf", "%lf", ""},
    {"123.456edlf", "%4lf", ""},
    {"+123.456edlf", "%2lf", ""},
    {"1.2e10dlf", "%5lf", ""},
    {"1.2e10dlf", "%6lf", ""},
    {"123.456dlf", "%lf", ""},
    {"123.456e10dlf", "%lf", ""},
    {"123.456e+10dlf", "%lf", ""},
    {"123.456e-10dlf", "%lf", ""},
    {"12345678901234567890123456789012345678901234567890e-45dlf", "%lf", ""},
    {"12345678901234567890123456789012345678901234567890edlf", "%lf", ""},
    {"-inf", "%lf", ""},
    {"+inf", "%lf", ""},
    {"inf", "%lf", ""},
    {"-nan", "%lf", ""},
    {"+nan", "%lf", ""},
    {"nan", "%lf", ""},
    {"-123,456edlf", "%lf", ""},
    {"+123,456edlf", "%lf", ""},
    {"-inf", "%2lf", ""},
    {"-inf", "%0lf", ""},
    {"123", "%0lf", ""},
    {",123", "%lf", ""},
    {"-,123", "%lf", ""},
    {",abc", "%lf", ""},
    {",e10bc", "%lf", ""},
    {"123.456edlf", "%le", ""},
    {"123.456edlf", "%lE", ""},
    {"123.456edlf", "%lg", ""},
    {"123.456edlf", "%lG", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sscanf_lf) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_lf[_i][0];
  char* test_format = array_sscanf_lf[_i][1];
  double our_func = -99;
  double real_func = -99;

  real_func_int = sscanf(test_src, test_format, &real_func);
  our_func_int = s21_sscanf(test_src, test_format, &our_func);

  if (isnan(real_func)) {
    char our_func_str[512] = "";
    char real_func_str[512] = "";
    sprintf(our_func_str, "%f", our_func);
    sprintf(real_func_str, "%f", real_func);
    if (strcmp(our_func_str, real_func_str) == 0) {
      real_func = -717;
      our_func = -717;
      // printf("%s\n",our_func_str);
      // printf("%s\n",real_func_str);
    }
  } else {
    our_func = round((10000000 * our_func)) / 10000000;
    real_func = round((10000000 * real_func)) / 10000000;
  }

  ck_assert_msg(
      real_func == our_func && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%f\"\n\
  =>          our_func  == \"%f\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sscanf_Lf[120][3] = {
    {"123", "%Lf", ""},
    {"123,adLf", "%Lf", ""},
    {"123.456edLf", "%Lf", ""},
    {"123.456edLf", "%4Lf", ""},
    {"+123.456edLf", "%2Lf", ""},
    {"1.2e10dLf", "%5Lf", ""},
    {"1.2e10dLf", "%6Lf", ""},
    {"123.456dLf", "%Lf", ""},
    {"123.456e10dLf", "%Lf", ""},
    {"123.456e+10dLf", "%Lf", ""},
    {"123.456e-10dLf", "%Lf", ""},
    {"12345678901234567890123456789012345678901234567890e-45dLf", "%Lf", ""},
    {"12345678901234567890123456789012345678901234567890edLf", "%Lf", ""},
    {"-inf", "%Lf", ""},
    {"+inf", "%Lf", ""},
    {"inf", "%Lf", ""},
    {"-nan", "%Lf", ""},
    {"+nan", "%Lf", ""},
    {"nan", "%Lf", ""},
    {"-123,456edLf", "%Lf", ""},
    {"+123,456edLf", "%Lf", ""},
    {"-inf", "%2Lf", ""},
    {"-inf", "%0Lf", ""},
    {"123", "%0Lf", ""},
    {",123", "%Lf", ""},
    {"-,123", "%Lf", ""},
    {",abc", "%Lf", ""},
    {",e10bc", "%Lf", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sscanf_Lf) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_Lf[_i][0];
  char* test_format = array_sscanf_Lf[_i][1];
  long double our_func = -99;
  long double real_func = -99;

  real_func_int = sscanf(test_src, test_format, &real_func);
  our_func_int = s21_sscanf(test_src, test_format, &our_func);

  if (isnan(real_func)) {
    char our_func_str[512] = "";
    char real_func_str[512] = "";
    sprintf(our_func_str, "%Lf", our_func);
    sprintf(real_func_str, "%Lf", real_func);
    if (strcmp(our_func_str, real_func_str) == 0) {
      real_func = -717;
      our_func = -717;
      // printf("%s\n",our_func_str);
      // printf("%s\n",real_func_str);
    }
  } else {
    our_func = roundl((10000000 * our_func)) / 10000000;
    real_func = roundl((10000000 * real_func)) / 10000000;
  }

  ck_assert_msg(
      real_func == our_func && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%.15Lf\"\n\
  =>          our_func  == \"%.15Lf\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sscanf_n_xxl[120][3] = {
    {"123   4562  ew322", "%hf%lf%2s%d%n", ""},
    {"123   4562  ew322", "%hf%lf%2s%d%hn", ""},
    {"1234   4562  ew322", "%hf%lf%2s%d%20n", ""},
    {"123   4562  ew322", "%hf%lf%2s%d:%n", ""},
    {"123   4562  ew322", "%hf%lf%2s%d%*n%n", ""},
    {"123   4562  ew322", "%hf%lf%2s%d%*c%n", ""},
    {"123   4562  ew322", "%hf%lf%2s%d%*s%n", ""},
    {"123,f456  ewe 5, ", "%hf%*c%lf%s%d%n", ""},
    {"123,2f456  ewe 5, ", "%hf%*c%lf%s%d%n", ""},
    {"123.f456  ewe 5, ", "%hf%*c%lf%s%d%n", ""},
    {"123.2ef456sa 35 ", "%hf%*c%lf%s%d%n", ""},
    {"123. 2ef45 6sa  ", "%hf%*c%lf%s%d%n", ""},
    {"%123. 2ef45 7sa  ", "%%%hf%*c%lf%s%d%n", ""},
    {"%123. 2ef45 7sa  ", "%%%hf%*c%lf%s%d%5n", ""},
    {NULL, NULL, NULL}};
START_TEST(test_sscanf_n_xxl) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_n_xxl[_i][0];
  char* test_format = array_sscanf_n_xxl[_i][1];
  float our_func_0 = -991;
  float real_func_0 = -991;
  double our_func_1 = -992;
  double real_func_1 = -992;
  char our_func_2[1024] = "---------------";
  char real_func_2[1024] = "---------------";
  int our_func_3 = -993;
  int real_func_3 = -993;
  int our_func_4 = -999;
  int real_func_4 = -999;

  real_func_int = sscanf(test_src, test_format, &real_func_0, &real_func_1,
                         real_func_2, &real_func_3, &real_func_4);
  our_func_int = s21_sscanf(test_src, test_format, &our_func_0, &our_func_1,
                            our_func_2, &our_func_3, &our_func_4);

  ck_assert_msg(
      real_func_0 == our_func_0 && real_func_1 == our_func_1 &&
          !strcmp(real_func_2, our_func_2) && real_func_3 == our_func_3 &&
          real_func_4 == our_func_4 && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func_0 == \"%f\"\n\
  =>          our_func_0  == \"%f\"\n\
  =>          real_func_1 == \"%f\"\n\
  =>          our_func_1  == \"%f\"\n\
  =>          real_func_2 == \"%s\"\n\
  =>          our_func_2  == \"%s\"\n\
  =>          real_func_3 == \"%d\"\n\
  =>          our_func_3  == \"%d\"\n\
  =>          real_func_4 == \"%d\"\n\
  =>          our_func_4  == \"%d\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func_0, our_func_0, real_func_1, our_func_1,
      real_func_2, our_func_2, real_func_3, our_func_3, real_func_4, our_func_4,
      real_func_int, our_func_int);
}

static char* array_sscanf_o[140][3] = {
    {"123", "%o", ""},
    {" 123", "%o", ""},
    {" 123 4", "%o", ""},
    {"  123 4", "%o", ""},
    {"  123 4", "%o", ""},
    {"  123,4", "%o", ""},
    {"  123.4", "%o", ""},
    {" :  123 4", "%o", ""},
    {"123", "%2o", ""},
    {"123", "%5o", ""},
    {"123", "%.2o", ""},
    {"123", "%.5o", ""},
    {"123", "%5.2o", ""},
    {"123", "%7.4o", ""},
    {"123", "%2.4o", ""},
    {"+123", "%o", ""},
    {"+123", "%-010.5o", ""},
    {"00123", "%-010.5o", ""},
    {"0000123", "%o", ""},
    {"000123", "%4o", ""},
    {"000123", "%1o", ""},
    {"  0123", "%5o", ""},
    {"+123", "%2o", ""},
    {" 123", "%2o", ""},
    {" 123", "% 2o", ""},
    {" 123", "%02o", ""},
    {" 123", "%-2o", ""},
    {" 123", "%+2o", ""},
    {" 123", "%-2o", ""},
    {" 123", "%+-2o", ""},
    {" 123", "%+++2o", ""},
    {" 123", "%#2o", ""},
    {" 123", "%0o", ""},
    {"0123", "%02o", ""},
    {"0123", "%2o", ""},
    {"123e5", "%o", ""},
    {"123e5", "%%o", ""},
    {"123e5", "%0+02o", ""},
    {"123e5", "%002o", ""},
    {"123 5", "%*%o", ""},
    {"123 5", "%*o%o", ""},
    {"123 5", "%*o%o", ""},
    {"123 5", "%**o%o", ""},
    {"123", ":%o", ""},
    {":123", ":%o", ""},
    {": 123", ":%o", ""},
    {" : 123", ":%o", ""},
    {" :123", ":%o", ""},
    {"123", " %o", ""},
    {" +123", " %o", ""},
    {"+++123", "%o", ""},
    {"+123", "%2o", ""},
    {" . -0123", " . %o", ""},
    {"  . -0123", " . %o", ""},
    {"acb-", "acb%o", ""},
    {"acb-a", "acb%o", ""},
    {"acb-0", "acb%o", ""},
    {"acb-0a", "acb%o", ""},
    {"acb-01", "acb%o", ""},
    {"acb123456789012345678901234567890", "acb%o", ""},
    {"acb7777777777777777777777", "acb%o", ""},
    {"acb123456789012345678901234567890", "acb%lo", ""},
    {"acb123456789012345678901234567890", "acb%lo", ""},
    {"acb2147483647", "acb%o", ""},
    {"acb2147483648", "acb%o", ""},
    {"acb2147483649", "acb%o", ""},
    {"acb9223372036854775807", "acb%o", ""},
    {"acb9223372036854775807", "acb%ho", ""},
    {"acb9223372036854775808", "acb%o", ""},
    {"acb-9223372036854775800", "acb%o", ""},
    {"acb-9223372036854775807", "acb%o", ""},
    {"acb-9223372036854775808", "acb%o", ""},
    {"acb-9223372036854775809", "acb%o", ""},
    {"acb-9223372036854775811", "acb%o", ""},
    {"acb9223372036854775811", "acb%o", ""},
    {"acb-9223372036854775811", "acb%ho", ""},
    {"acb9223372036854775811", "acb%ho", ""},
    {"acb-9223372036854775811", "acb%lo", ""},
    {"acb9223372036854775811", "acb%lo", ""},
    {"acb18446744073709551614", "acb%lo", ""},
    {"acb18446744073709551615", "acb%lo", ""},
    {"acb18446744073709551616", "acb%lo", ""},
    {"acb-18446744073709551614", "acb%lo", ""},
    {"acb-18446744073709551615", "acb%lo", ""},
    {"acb-18446744073709551616", "acb%lo", ""},
    {"acb-18446744073709551618", "acb%lo", ""},
    {"acb-1", "acb%lo", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sscanf_o) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_o[_i][0];
  char* test_format = array_sscanf_o[_i][1];
  unsigned long int our_func = 99;
  unsigned long int real_func = 99;

  real_func_int = sscanf(test_src, test_format, &real_func);
  our_func_int = s21_sscanf(test_src, test_format, &our_func);

  ck_assert_msg(
      real_func == our_func && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%lu\"\n\
  =>          our_func  == \"%lu\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sscanf_x[140][3] = {
    {"123", "%x", ""},
    {" 123", "%x", ""},
    {" 123 4", "%x", ""},
    {"  123 4", "%x", ""},
    {"  123 4", "%x", ""},
    {"  123,4", "%x", ""},
    {"  123.4", "%x", ""},
    {" :  123 4", "%x", ""},
    {"123", "%2x", ""},
    {"123", "%5x", ""},
    {"123", "%.2x", ""},
    {"123", "%.5x", ""},
    {"123", "%5.2x", ""},
    {"123", "%7.4x", ""},
    {"123", "%2.4x", ""},
    {"+123", "%x", ""},
    {"+123", "%-010.5x", ""},
    {"00123", "%-010.5x", ""},
    {"0000123", "%x", ""},
    {"000123", "%4x", ""},
    {"000123", "%1x", ""},
    {"  0123", "%5x", ""},
    {"+123", "%2x", ""},
    {" 123", "%2x", ""},
    {" 123", "% 2x", ""},
    {" 123", "%02x", ""},
    {" 123", "%-2x", ""},
    {" 123", "%+2x", ""},
    {" 123", "%-2x", ""},
    {" 123", "%+-2x", ""},
    {" 123", "%+++2x", ""},
    {" 123", "%#2x", ""},
    {" 123", "%0x", ""},
    {"0123", "%02x", ""},
    {"0123", "%2x", ""},
    {"123e5", "%x", ""},
    {"123e5", "%%x", ""},
    {"123e5", "%0+02x", ""},
    {"123e5", "%002x", ""},
    {"123 5", "%*%x", ""},
    {"123 5", "%*x%x", ""},
    {"123 5", "%*x%x", ""},
    {"123 5", "%**x%x", ""},
    {"123", ":%x", ""},
    {":123", ":%x", ""},
    {": 123", ":%x", ""},
    {" : 123", ":%x", ""},
    {" :123", ":%x", ""},
    {"123", " %x", ""},
    {" +123", " %x", ""},
    {"+++123", "%x", ""},
    {"+123", "%2x", ""},
    {" . -0123", " . %x", ""},
    {"  . -0123", " . %x", ""},
    {"acb-", "acb%x", ""},
    {"acb-a", "acb%x", ""},
    {"acb-0", "acb%x", ""},
    {"acb-0a", "acb%x", ""},
    {"acb-01", "acb%x", ""},
    {"acb123456789012345678901234567890", "acb%x", ""},
    {"acb123456789012345678901234567890", "acb%lx", ""},
    {"acb123456789012345678901234567890", "acb%lx", ""},
    {"acb2147483647", "acb%x", ""},
    {"acb2147483648", "acb%x", ""},
    {"acb2147483649", "acb%x", ""},
    {"acb9223372036854775807", "acb%x", ""},
    {"acb9223372036854775807", "acb%hx", ""},
    {"acb9223372036854775808", "acb%x", ""},
    {"acb-9223372036854775800", "acb%x", ""},
    {"acb-9223372036854775807", "acb%x", ""},
    {"acb-9223372036854775808", "acb%x", ""},
    {"acb-9223372036854775809", "acb%x", ""},
    {"acb-9223372036854775811", "acb%x", ""},
    {"acb9223372036854775811", "acb%x", ""},
    {"acb-9223372036854775811", "acb%hx", ""},
    {"acb9223372036854775811", "acb%hx", ""},
    {"acb-9223372036854775811", "acb%lx", ""},
    {"acb9223372036854775811", "acb%lx", ""},
    {"acb18446744073709551614", "acb%lx", ""},
    {"acb18446744073709551615", "acb%lx", ""},
    {"acb18446744073709551616", "acb%lx", ""},
    {"acb-18446744073709551614", "acb%lx", ""},
    {"acb-18446744073709551615", "acb%lx", ""},
    {"acb-18446744073709551616", "acb%lx", ""},
    {"acb-18446744073709551618", "acb%lx", ""},
    {"acb-1", "acb%lx", ""},
    {"0000xaB123", "%x", ""},
    {"0000XaB123", "%x", ""},
    {"0000XxaB123", "%x", ""},
    {"0000XaB123", "%6x", ""},
    {"  0000aB123", "%6x", ""},
    {"acd4h  0000aB123", "%6x", ""},
    {"XxaB123", "%x", ""},
    {"XaB123", "%x", ""},
    {"0X4123", "%x", ""},
    {"0xa4123", "%x", ""},
    {"0xbAb4123", "%x", ""},
    {"00xbAb4123", "%x", ""},
    {"0xbAb4123", "%5x", ""},
    {"0xbAb4123", "%1x", ""},
    {"0xbAb4123", "%2x", ""},
    {"0xbAb4123", "%0x", ""},
    {"xbAb4123", "%x", ""},
    {"gbAb4123", "%x", ""},
    {"fff1", "%x", ""},
    {"fff1", "%X", ""},
    {NULL, NULL, NULL}};

START_TEST(test_sscanf_x) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_x[_i][0];
  char* test_format = array_sscanf_x[_i][1];
  unsigned long int our_func = 99;
  unsigned long int real_func = 99;

  real_func_int = sscanf(test_src, test_format, &real_func);
  our_func_int = s21_sscanf(test_src, test_format, &our_func);

  ck_assert_msg(
      real_func == our_func && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%lu\"\n\
  =>          our_func  == \"%lu\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sscanf_i[140][3] = {
    {"123", "%i", ""},    {"-123", "%i", ""},   {"0123", "%i", ""},
    {"000123", "%i", ""}, {"000a23", "%i", ""}, {"0a23", "%i", ""},
    {"a23", "%i", ""},    {"fff1", "%i", ""},   {"0x123", "%i", ""},
    {"00x123", "%i", ""}, {NULL, NULL, NULL}};

START_TEST(test_sscanf_i) {
  int real_func_int;
  int our_func_int;

  char* test_src = array_sscanf_i[_i][0];
  char* test_format = array_sscanf_i[_i][1];
  long int our_func = 99;
  long int real_func = 99;

  real_func_int = sscanf(test_src, test_format, &real_func);
  our_func_int = s21_sscanf(test_src, test_format, &our_func);

  ck_assert_msg(
      real_func == our_func && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%ld\"\n\
  =>          our_func  == \"%ld\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func, our_func, real_func_int, our_func_int);
}
END_TEST

static char* array_sscanf_p[140][3] = {
    {"%p", "%p", ""},      {"   %p", "%p", ""},    {":   %p", ":%p", ""},
    {"0123%p", "%p", ""},  {"000123%p", "%p", ""}, {"000a23%p", "%p", ""},
    {"0a23%p", "%p", ""},  {"a23%p", "%p", ""},    {"fff1%p", "%p", ""},
    {"0x123%p", "%p", ""}, {"00x123%p", "%p", ""}, {NULL, NULL, NULL}};

START_TEST(test_sscanf_p) {
  int real_func_int;
  int our_func_int;

  int test_pointer = 111111;
  char test_src[1024] = "";
  char* test_src_format = array_sscanf_p[_i][0];
  sprintf(test_src, test_src_format, &test_pointer);
  // printf("test_src=%s\n",test_src);

  char* test_format = array_sscanf_p[_i][1];
  int our_func_tmp = 99;
  int real_func_tmp = 99;
  int* our_func_p = &our_func_tmp;
  int* real_func_p = &real_func_tmp;

  // printf("real_func=%p\n",real_func_p);
  // printf("our_func=%p\n",our_func_p);

  // printf("real_func=%p\n",real_func);
  real_func_int = sscanf(test_src, test_format, (&real_func_p));
  // printf("   real_func=%p\n",real_func_p);
  our_func_int = s21_sscanf(test_src, test_format, (&our_func_p));
  // printf("   our_func=%p\n",our_func_p);
  ck_assert_msg(
      real_func_p == our_func_p && real_func_int == our_func_int,
      "\nError with: test_format == \"%s\"        , test_src == \"%s\"\n\
  =>          real_func == \"%p\"\n\
  =>          our_func  == \"%p\"\n\
  =>          real_func_int == \"%d\"\n\
  =>          our_func_int  == \"%d\"\n",
      test_format, test_src, real_func_p, our_func_p, real_func_int,
      our_func_int);
}
END_TEST

Suite* suite_sscanf(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("SSCANF");
  tc_core = tcase_create("Core");

  tcase_add_loop_test(tc_core, test_sscanf_d, 0,
                      len_array_func_3_sscanf(array_sscanf_d));
  tcase_add_loop_test(tc_core, test_sscanf_d_xxl, 0,
                      len_array_func_3_sscanf(array_sscanf_d_xxl));
  tcase_add_loop_test(tc_core, test_sscanf_c_xxl, 0,
                      len_array_func_3_sscanf(array_sscanf_c_xxl));
  tcase_add_loop_test(tc_core, test_sscanf_u, 0,
                      len_array_func_3_sscanf(array_sscanf_u));
  tcase_add_loop_test(tc_core, test_sscanf_s_xxl, 0,
                      len_array_func_3_sscanf(array_sscanf_s_xxl));
  tcase_add_loop_test(tc_core, test_sscanf_hf, 0,
                      len_array_func_3_sscanf(array_sscanf_hf));
  tcase_add_loop_test(tc_core, test_sscanf_hf_xxl, 0,
                      len_array_func_3_sscanf(array_sscanf_hf_xxl));
  tcase_add_loop_test(tc_core, test_sscanf_lf, 0,
                      len_array_func_3_sscanf(array_sscanf_lf));
  tcase_add_loop_test(tc_core, test_sscanf_Lf, 0,
                      len_array_func_3_sscanf(array_sscanf_Lf));
  tcase_add_loop_test(tc_core, test_sscanf_n_xxl, 0,
                      len_array_func_3_sscanf(array_sscanf_n_xxl));

  tcase_add_loop_test(tc_core, test_sscanf_o, 0,
                      len_array_func_3_sscanf(array_sscanf_o));
  tcase_add_loop_test(tc_core, test_sscanf_x, 0,
                      len_array_func_3_sscanf(array_sscanf_x));
  tcase_add_loop_test(tc_core, test_sscanf_i, 0,
                      len_array_func_3_sscanf(array_sscanf_i));
  tcase_add_loop_test(tc_core, test_sscanf_p, 0,
                      len_array_func_3_sscanf(array_sscanf_p));
  tcase_add_loop_test(tc_core, test_sscanf_n_xxl, 0,
                      len_array_func_3_sscanf(array_sscanf_n_xxl));

  suite_add_tcase(s, tc_core);
  return s;
}

//Функции расчета длины массива
int len_array_func_3_sscanf(char* array[][3]) {
  int len = 0;
  while (array[len][2] != NULL) {
    // printf("array[len][0]=%s\n",array[len][0]);
    len += 1;
  }
  return len;
}
