#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t len = s21_strlen(needle);
  char *res = S21_NULL;

  if (len != 0) {
    char *pointer = s21_strchr(haystack, *needle);

    while (pointer != S21_NULL) {
      if (s21_strncmp(pointer, needle, len) == 0) {
        res = pointer;
        break;
      } else {
        pointer++;
        pointer = s21_strchr(pointer, *needle);
      }
    }

  } else
    res = (char *)haystack;

  return res;
}