#include "../s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  flags flag = {0};
  va_list args;
  va_start(args, format);

  int written = 0;

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      s21_memset(&flag, 0, sizeof(flags));
      flag.width = -1;
      if (*format == '*') {
        format++;

        while (*format != '\0' && !is_valid_specifier(*format)) {
          format++;
        }

        if (*format != '\0') {
          format++;
        }
        if (*str != '\0' && *str != ' ') {
          str++;
        }

        if (*str != '\0') {
          str++;
        }

        continue;
        // flag.no_write = 1;
      }  // else flag.no_write = 0;
      if (is_digit(*format)) {
        flag.width = 0;
        while (is_digit(*format)) {
          flag.width = flag.width * 10 + (*format - '0');
          format++;
          // result = result * 10 + (str[i] - '0');
        }
      }
      while (s21_isSpace(*str)) {
        str++;
      }

      if (*str == '%') {
        str++;
      }

      if (is_length(*format)) {
        flag.length = *format;
        format++;
      }

      switch (*format) {
        case 'c': {
          char value;
          int chars_read = sscanf_spec_c(str, &value);
          // if (!flag.no_write)
          // {
          *va_arg(args, char *) = value;
          written++;
          // }
          str += chars_read;
          break;
        }

        case 'd': {
          int value;
          int chars_read;
          chars_read = sscanf_spec_d(str, &value, flag.width);
          if (flag.length == 'l') {
            *va_arg(args, long *) = value;
          }
          if (flag.length == 'h') {
            *va_arg(args, short int *) = value;
          } else if (!flag.length)
            *va_arg(args, int *) = value;
          written++;
          str += chars_read;
          break;
        }

        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G': {
          long double value;
          int chars_read;
          chars_read = sscanf_spec_gef(str, &value, flag.width);
          // if (!flag.no_write)
          // {
          if (flag.length == 'L')
            *va_arg(args, long double *) = value;
          else if (!flag.length)
            *va_arg(args, float *) = value;

          written++;
          str += chars_read;
          // }

          break;
        }

        case 'i': {
          int value;
          int chars_read = sscanf_spec_i(str, &value, flag.width);
          if (flag.length == 'l') {
            *va_arg(args, long *) = value;
          }
          if (flag.length == 'h') {
            *va_arg(args, short int *) = value;
          }
          *va_arg(args, int *) = value;
          written++;
          str += chars_read;
          break;
        }

        case 'o': {
          unsigned long value;
          int chars_read = sscanf_spec_o(str, &value, flag.width);
          if (flag.length == 'l')
            *va_arg(args, unsigned long *) = value;
          else if (flag.length == 'h')
            *va_arg(args, unsigned short *) = value;
          else
            *va_arg(args, unsigned *) = value;
          written++;
          str += chars_read;
          break;
        }
        case 's': {
          flag.specifier = *format;
          char *value = va_arg(args, char *);
          int chars_read = sscanf_spec_s(str, value, flag.width);
          written++;
          str += chars_read;
          break;
        }
        case 'u': {
          unsigned long value;
          int chars_read = sscanf_spec_u(str, &value, flag.width);
          if (flag.length == 'l')
            *va_arg(args, unsigned long *) = value;
          else if (flag.length == 'h')
            *va_arg(args, unsigned short *) = value;
          else if (!flag.length)
            *va_arg(args, unsigned *) = value;
          written++;
          str += chars_read;
          break;
        }

        case 'x':
        case 'X': {
          unsigned long value;
          int chars_read = sscanf_spec_xX(str, &value);
          if (flag.length == 'l')
            *va_arg(args, unsigned long *) = value;
          else if (flag.length == 'h')
            *va_arg(args, unsigned short *) = value;
          else if (!flag.length)
            *va_arg(args, unsigned *) = value;
          written++;
          str += chars_read;
          break;
        }
        case 'p': {
          void *value = NULL;
          int chars_read = sscanf_spec_p(str, &value);
          *va_arg(args, void **) = value;
          written++;
          str += chars_read;
          break;
        }
        case 'n': {
          int value;
          int chars_read = sscanf_spec_n(str, &value);
          *va_arg(args, int *) = value;
          written++;
          str += chars_read;
          break;
        }
        case '%': {
          written++;
          str++;
          break;
        }
      }
    }

    flag.specifier = *format;
    format++;
  }

  va_end(args);

  return written;
}

int sscanf_spec_c(const char *str, char *ch) {
  if (str[0] == '\0') {
    return 0;
  }

  *ch = str[0];
  return *ch ? 1 : 0;
}
int sscanf_spec_d(const char *str, int *value, int width) {
  if (*str == '\0') {
    return 0;
  }

  long result = 0;
  int sign = 1;
  int i = 0;
  int count = 0;

  if (str[i] == '-') {
    sign = -1;
    i++;
    count++;
  } else if (str[i] == '+') {
    i++;
    count++;
  }

  while (is_digit(str[i]) && ((width > 0 && count < width) || width == -1)) {
    result = result * 10 + (str[i] - '0');
    i++;
    count++;
  }
  *value = result * sign;

  return i;
}

int sscanf_spec_i(const char *str, int *value, int width) {
  if (*str == '\0') {
    return 0;
  }

  int result = 0;
  int sign = 1;
  int i = 0;
  if (str[i] == '-') {
    sign = -1;
    i++;
  } else {
    i++;
  }
  if (str[i] == '-') {
    sign = -1;
    i++;
  }
  if (str[i] == '0') {
    i++;
    if (str[i] == 'x' || str[i] == 'X') {
      i++;

      while ((str[i] >= '0' && str[i] <= '9') ||
             (str[i] >= 'a' && str[i] <= 'f') ||
             (str[i] >= 'A' && str[i] <= 'F')) {
        result = result * 16 + hex_to_decimal(str[i]);
        i++;
      }

    } else {
      while (str[i] >= '0' && str[i] <= '7') {
        result = result * 8 + (str[i] - '0');
        i++;
      }
    }
  } else {
    int count = 0;
    while (
        (is_digit(str[i]) && ((width > 0 && count < width) || width == -1))) {
      result = result * 10 + (str[i] - '0');
      i++;
      count++;
    }
  }

  *value = result * sign;
  return i;
}

int sscanf_spec_gef(const char *str, long double *value, int width) {
  if (*str == '\0') {
    return 0;
  }

  int interger_result = 0;
  double fraction_result = 0;
  int sign = 1;
  int i = 0;
  int magnitude = 0;
  int dot_check = 0;
  int exp_check = 0;
  int exp = 0;
  int exp_sign = 1;
  int count = 0;

  if (str[i] == '-') {
    sign = -1;
    i++;
    count++;
  } else if (str[i] == '+') {
    i++;
    count++;
  }

  if (is_digit(str[i]) || str[i] == '.') {
    while (is_gef_valid(str[i]) &&
           ((width > 0 && count < width) || width == -1)) {
      if (str[i] == '.' && !dot_check) {
        dot_check++;
        count++;
        i++;
      } else if (str[i] == '.' && dot_check) {
        break;
      }
      if ((str[i] == 'e' || str[i] == 'E') && !exp_check) {
        exp_check++;
        count++;
        i++;
        if (str[i] == '-') {
          exp_sign = -1;
          i++;
        } else if (str[i] == '+') {
          i++;
        }
      }
      if ((str[i] == 'e' || str[i] == 'E') && exp_check) break;

      if (count >= width && width != -1) {
        break;
      }

      if (!dot_check && !exp_check) {
        interger_result = interger_result * 10 + (str[i] - '0');
      } else if (dot_check && !exp_check) {
        fraction_result = fraction_result * 10 + (str[i] - '0');
        magnitude++;

      } else if (exp_check && (fraction_result || interger_result)) {
        exp = exp * 10 + (str[i] - '0');
      }

      i++;
      count++;
      if (i == 0) {
        return -1;
      }
    }
  }

  *value =
      (exp) ? (fraction_result / pow(10, magnitude) + interger_result) * sign *
                  pow(10, exp * exp_sign)
            : (fraction_result / pow(10, magnitude) + interger_result) * sign;
  return i;
}

int sscanf_spec_o(const char *str, unsigned long *value, int width) {
  if (*str == '\0') {
    return 0;
  }

  long result = 0;
  int sign = 1;
  int i = 0;

  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  }

  int count = 0;
  while ((str[i] >= '0' && str[i] <= '7') &&
         ((width > 0 && count < width) || width == -1)) {
    result = result * 8 + (str[i] - '0');
    i++;
    count++;
  }

  *value = result * sign;
  return i;
}

int sscanf_spec_s(const char *str, char *buffer, int width) {
  if (*str == '\0') {
    return 0;
  }

  int i = 0;
  int j = 0;

  while (s21_isSpace(str[i])) {
    i++;
  }

  int count = 0;

  while (str[i] != '\0' && !s21_isSpace(str[i]) &&
         (width == -1 || count < width)) {
    buffer[j] = str[i];
    i++;
    j++;
    count++;
  }

  buffer[j] = '\0';
  return j;
}

int sscanf_spec_u(const char *str, unsigned long *value, int width) {
  if (*str == '\0') {
    return 0;
  }

  int result = 0;
  int i = 0;
  if (str[i] == '-') {
    return -1;
  } else if (str[i] == '+') {
    i++;
  }
  int count = 0;
  while (is_digit(str[i]) && (width > 0 && count < width)) {
    result = result * 10 + (str[i] - '0');
    i++;
    count++;
    if (i == 0) {
      return -1;
    }
  }

  *value = result;
  return i;
}

int sscanf_spec_xX(const char *str, unsigned long *value) {
  if (*str == '\0') {
    return 0;
  }

  int result = 0;
  int sign = 1;
  int i = 0;
  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  }
  int is_hex = 1;
  if ((str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))) {
    i += 2;
  }
  while ((str[i] >= '0' && str[i] <= '9') ||
         (is_hex && ((str[i] >= 'a' && str[i] <= 'f') ||
                     (str[i] >= 'A' && str[i] <= 'F')))) {
    if (is_hex) {
      result = result * 16 + hex_to_decimal(str[i]);
    }
    i++;
  }

  *value = result * sign;
  return i;
}

int sscanf_spec_p(const char *str, void **value) {
  if (*str == '\0') {
    return 0;
  }
  int i = 0;
  while (s21_isSpace(str[i])) {
    i++;
  }
  int is_hex = 1;
  if ((str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))) {
    i += 2;
  }
  uintptr_t result = 0;
  while ((str[i] >= '0' && str[i] <= '9') ||
         (is_hex && ((str[i] >= 'a' && str[i] <= 'f') ||
                     (str[i] >= 'A' && str[i] <= 'F')))) {
    if (is_hex) {
      result = result * 16 + hex_to_decimal(str[i]);
    } else {
      result = result * 10 + (str[i] - '0');
    }
    i++;
  }

  *value = (void *)result;
  return i;
}

int sscanf_spec_n(const char *str, int *value) {
  if (*str == '\0') {
    return 0;
  }

  int i = 0;
  int count = 0;
  int space = 0;
  int character = 0;

  while (str[i] != '\0') {
    if (s21_isSpace(str[i])) {
      if (!character) {
        space++;
      } else {
        break;
      }
    } else {
      character = 1;
      count++;
    }

    i++;
  }

  if (!character) {
    count = 0;
  } else {
    count += space;
  }

  *value = count;
  return i;
}

int hex_to_decimal(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  }
  if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  }
  return 0;
}
int s21_isSpace(int c) {
  return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
                  c == ' '
              ? 1
              : 0);
}

int is_valid_specifier(char c) {
  return (c == 'c' || c == 'i' || c == 'o' || c == 's' || c == 'u' ||
          c == 'x' || c == 'X' || c == 'p' || c == 'n' || c == 'd');
}