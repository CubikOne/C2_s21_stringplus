#include "s21_string.h"

void *s21_to_upper(const char *str) {
  void *res = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t length = s21_strlen(str) + 1;
    res = (void *)calloc(length, sizeof(char));

    for (s21_size_t i = 0; *str != '\0'; i++, str++) {
      if (*str <= 'z' && *str >= 'a') {
        ((char *)res)[i] = *str - 32;
      } else {
        ((char *)res)[i] = *str;
      }
    }
  }
  return res;
}