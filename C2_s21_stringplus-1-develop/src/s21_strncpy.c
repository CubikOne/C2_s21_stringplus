
#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i_dest = 0;
  s21_size_t i_src = 0;

  while ((i_dest != n)) {
    if (src[i_src] != '\0') {
      dest[i_dest] = src[i_src];
      i_src += 1;
      i_dest += 1;
    } else {
      dest[i_dest] = 0;
      i_dest += 1;
    }
  }

  return dest;
}
