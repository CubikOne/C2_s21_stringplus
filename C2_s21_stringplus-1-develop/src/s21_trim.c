#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  void *res = S21_NULL;

  if (src == S21_NULL)
    res = S21_NULL;
  else {
    s21_size_t counter = s21_strlen(src);

    if (s21_strlen(src) == 0)
      res = (void *)calloc((1), sizeof(char));
    else {
      res = (void *)calloc((counter + 1), sizeof(char));

      if (trim_chars == S21_NULL || !s21_strlen(trim_chars))
        trim_chars = " 		";

      while (s21_strchr(trim_chars, *(unsigned char *)src) != S21_NULL) src++;

      counter = 0;

      while (*src != '\0') {
        ((char *)res)[counter] = *src;
        src++;
        counter++;
      }

      counter = s21_strlen((char *)res) - 1;

      while (s21_strrchr(trim_chars, ((unsigned char *)res)[counter]) !=
             S21_NULL) {
        ((char *)res)[counter] = '\0';
        counter--;
      }
    }
  }
  return res;
}