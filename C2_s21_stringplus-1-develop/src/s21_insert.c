#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *result = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t length_src = s21_strlen(src);

    if (length_src >= start_index) {
      s21_size_t length_str = s21_strlen(str);
      s21_size_t length = length_src + length_str;
      result = (void *)calloc(length + 1, sizeof(char));

      for (s21_size_t i = 0; i < length; i++) {
        if (i < start_index) {
          ((char *)result)[i] = src[i];
        } else if (i < start_index + length_str) {
          ((char *)result)[i] = str[i - start_index];
        } else {
          ((char *)result)[i] = src[i - length_str];
        }
      }
    }
  }

  return result;
}