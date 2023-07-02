#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dest1 = (char *)dest;
  char *src1 = (char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    dest1[i] = src1[i];
  }
  return dest;
}
