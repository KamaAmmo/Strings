#include "../s21_string.h"
void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL || *trim_chars == '\0') {
    return s21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  if (src_len == 0) {
    return s21_NULL;
  }

  s21_size_t start_index = 0;
  s21_size_t end_index = src_len - 1;

  while (start_index <= end_index &&
         s21_strchr(trim_chars, src[start_index]) != s21_NULL) {
    start_index++;
  }

  while (end_index > start_index &&
         s21_strchr(trim_chars, src[end_index]) != s21_NULL) {
    end_index--;
  }

  s21_size_t trim_len = end_index - start_index + 1;
  char *trimmed_str = (char *)malloc((trim_len + 1) * sizeof(char));

  if (trimmed_str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t i;
  for (i = 0; i < trim_len; i++) {
    trimmed_str[i] = src[start_index + i];
  }

  trimmed_str[trim_len] = '\0';

  return trimmed_str;
}
