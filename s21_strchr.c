#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  for (;; ++str) {
    if (*str == c) {
      return (char *)str;
    }
    if (*str == '\0') {
      return s21_NULL;
    }
  }
}