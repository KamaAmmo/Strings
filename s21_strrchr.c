#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  if ((char)c == '\0') {
    return "";
  }
  char *p = s21_NULL;
  while (*str != '\0') {
    if (*str == (char)c) {
      p = (char *)str;
    }
    str++;
  }
  return p;
}
