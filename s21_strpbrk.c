#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  if (str1 == s21_NULL || str2 == s21_NULL) {
    return s21_NULL;
  }
  const char *temp;
  while (*str1 != '\0') {
    temp = str2;

    while (*temp != '\0') {
      if (*str1 == *temp) {
        return (char *)str1;
      }
      temp++;
    }
    str1++;
  }
  return s21_NULL;
}