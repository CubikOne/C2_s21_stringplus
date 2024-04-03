#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *result = S21_NULL;

  while (*str != 0) {
    if (*(unsigned char *)str == (unsigned char)c) {
      result = str;
    }
    str += 1;
  }

  if (c == 0) {
    result = str;
  }

  return (char *)result;
}
