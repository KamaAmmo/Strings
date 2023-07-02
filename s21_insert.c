#include "../s21_string.h"
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || s21_strlen(src) == 0 || *str == '\0' ||
      str == s21_NULL || start_index > s21_strlen(src)) {
    return s21_NULL;
  }
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  s21_size_t new_len = src_len + str_len;
  char *res = (char *)malloc((new_len + 1) * sizeof(char));

  if (res == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t i, j;
  for (i = 0; i < start_index; i++) {
    res[i] = src[i];
  }

  for (j = 0; j < str_len; j++) {
    res[i++] = str[j];
  }

  s21_size_t k = start_index;
  for (; k < src_len; k++) {
    res[i++] = src[k];
  }
  res[new_len] = '\0';
  return res;
  free(res);
}