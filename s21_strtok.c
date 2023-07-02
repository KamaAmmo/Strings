#include "../s21_string.h"
// #include "s21_strspn.c"
// #include "s21_strcspn.c"

char *s21_strtok(char *str, const char *delim) {
  static char *lastToken = s21_NULL;

  if (str == s21_NULL) {
    str = lastToken;
  }

  str += s21_strspn(str, delim);

  if (*str == '\0') {
    lastToken = s21_NULL;
    return s21_NULL;
  }

  char *tokenEnd = str + s21_strcspn(str, delim);

  if (*tokenEnd == '\0') {
    lastToken = tokenEnd;
    return str;
  }

  *tokenEnd = '\0';
  lastToken = tokenEnd + 1;

  return str;
}
