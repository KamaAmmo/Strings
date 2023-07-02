#include "../s21_string.h"
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  unsigned int dest_len = 0;
  unsigned int src_len = 0;
  while (dest[dest_len] != '\0') {
    dest_len++;
  }
  while (src[src_len] != '\0' && src_len < n) {
    dest[dest_len + src_len] = src[src_len];
    src_len++;
  }
  dest[dest_len + src_len] = '\0';
  return dest;
}