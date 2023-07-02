#ifndef S21_STRING_H_
#define S21_STRING_H_
#include <limits.h>  // for strerror test INT_MAX etc
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define s21_NULL (void *)0
typedef long unsigned s21_size_t;

#define BUFF_SIZE 512

// arithm
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str, const char *sym);
s21_size_t s21_strcspn(const char *str1, const char *str2);
// COPYs
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
// secondary
char *s21_strtok(char *str, const char *delim);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

// ed
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// sprintf
// /////////////////////////////////////////////////////////////////////////////////////
typedef struct flags {
  char specifier;
  char length;
  int precision;
  int left_justify;
  int show_sign;
  int show_plus;
  int space;
  int width;
  int point;
  int flag_zero;
  int flag_sharp;
  int no_write;
} flags;

#define is_flag(ch)                                                   \
  ((ch) == '-') || ((ch) == '+') || ((ch) == ' ') || ((ch) == '#') || \
      ((ch) == '0')

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')

#define is_length(ch) ((ch) == 'h' || (ch) == 'l' || (ch) == 'L')

#define is_specifier(ch)                                                      \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'e' || (ch) == 'E' || \
   (ch) == 'f' || (ch) == 'g' || (ch) == 'G' || (ch) == 'o' || (ch) == 's' || \
   (ch) == 'u' || (ch) == 'x' || (ch) == 'X' || (ch) == 'p' || (ch) == 'n' || \
   (ch) == '%')

int s21_sprintf(char *str, const char *format, ...);

// check
void parse_flags(flags *configs, const char *format);
char *parse_spec(char *str, s21_size_t *str_len, va_list *args, flags *configs);

// str
void make_str_flags(flags *configs, char *str);
void make_str_width(flags *configs, char *str);
void make_str_prec(flags *configs, char *str);
void move_str(char *str);
void reverse_writing(char *str);
int compare_round(flags *configs, long double number);
void make_mantissa(flags *configs, char *mantice, int notation);
void sharp_flag(flags *configs, char *str);
void delete_zero(flags *configs, char *str);

// specif
void format_char(char *str, va_list *args, flags *configs);
void format_di(char *str, va_list *args, flags *configs);
void format_s(char *str, va_list *args, flags *configs);
void format_u(char *str, va_list *args, flags *configs);
void format_f(char *str, va_list *args, flags *configs);
void format_gG(char *str, va_list *args, flags *configs);
void format_eE(char *str, va_list *args, flags *configs);
void format_n(s21_size_t const *str_len, va_list *args);
void format_p(char *str, va_list *args, flags *configs);
void format_xX(char *str, va_list *args, flags *configs);
void format_percentage(char *str, flags *configs);

void int_to_str(flags *configs, char *str, long double number);
char *str_to_int(int *number, const char *format, va_list *args);
void u_to_str(char *str, unsigned long long number, flags *configs);
void float_to_str(char *str, long double number, flags *configs);
void eE_to_str(char *str, long double number, flags *configs);
void gG_to_str(char *str, long double number, flags *configs);
void hlxX_to_str(char *str, unsigned long long number, flags *configs);
void ol_to_str(char *str, unsigned long long number, int pref);
void format_o(char *str, va_list *args, flags *configs);

void def_precision(flags *configs);

// sscanf
#define is_gef_valid(ch)                                                       \
  (is_digit(ch) || (ch) == '.' || (ch) == 'e' || (ch) == 'E' || (ch) == '+' || \
   (ch) == '-')

int s21_sscanf(const char *str, const char *format, ...);
int sscanf_spec_c(const char *str, char *ch);
int sscanf_spec_d(const char *str, int *value, int width);
int sscanf_spec_gef(const char *str, long double *value, int width);
int sscanf_spec_i(const char *str, int *value, int width);
int hex_to_decimal(char c);
int sscanf_spec_o(const char *str, unsigned long *value, int width);
int sscanf_spec_s(const char *str, char *buffer, int width);
int sscanf_spec_u(const char *str, unsigned long *value, int width);
int sscanf_spec_xX(const char *str, unsigned long *value);
int sscanf_spec_p(const char *str, void **value);
int sscanf_spec_n(const char *str, int *count);
int s21_isSpace(int c);
int is_valid_specifier(char c);

#endif