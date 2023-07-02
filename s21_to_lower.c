#include "../s21_string.h"
void *s21_to_lower(const char *str) {
  s21_size_t lenght = s21_strlen(str);
  char *res = malloc(lenght + 1);
  if (res == s21_NULL) {
    return s21_NULL;
  }
  for (s21_size_t i = 0; i < lenght; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      res[i] = str[i] + 32;
    } else {
      res[i] = str[i];
    }
  }
  res[lenght] = '\0';
  return (char *)res;
}
