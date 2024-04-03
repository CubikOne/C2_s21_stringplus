#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *res = S21_NULL;

  while (*str1 != 0) {
    if (s21_strchr(str2, *(unsigned char *)str1) != S21_NULL) {
      res = str1;
      break;
    } else
      str1++;
  }
  return (char *)res;
}