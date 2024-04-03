#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *buffer = S21_NULL;
  char *res = S21_NULL;

  str != S21_NULL ? (buffer = str) : (str = buffer);

  if (buffer == S21_NULL)
    res = S21_NULL;
  else {
    while (s21_strchr(delim, *(unsigned char *)str) != S21_NULL && *str != '\0')
      str++;

    if (*str != 0) {
      res = str;
      str = s21_strpbrk(str, delim);

      if (str == S21_NULL) {
        buffer = S21_NULL;
      } else {
        *str = '\0';
        buffer = str + 1;
      }

    } else
      res = S21_NULL;
  }
  return res;
}