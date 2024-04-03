
#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t i = 0;
  int stop = 0;

  while (str1[i] != '\0' && !stop) {
    s21_size_t y = 0;

    while (str2[y] != '\0' && !stop) {
      if (str1[i] == str2[y]) {
        stop = 1;
      }
      y++;
    }

    if (!stop) {
      result++;
    }
    i++;
  }

  return result;
}
