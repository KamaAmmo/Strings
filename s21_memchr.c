#include "../s21_string.h"

void* s21_memchr(const void* str, int c, s21_size_t n) {
  const char* charStr = (const char*)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (charStr[i] == c) {
      return (void*)&charStr[i];
    }
  }
  return s21_NULL;
}