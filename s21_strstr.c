#include "../s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
  const char *a, *b;
  b = needle;
  if (*b == 0) {
    return (char *)haystack;
  }
  for (; *haystack != 0; haystack++) {
    if (*haystack != *b) {
      continue;
    }
    a = haystack;
    while (1) {
      if (*b == 0) {
        return (char *)haystack;
      }
      if (*a++ != *b++) {
        break;
      }
    }
    b = needle;
  }
  return NULL;
}
