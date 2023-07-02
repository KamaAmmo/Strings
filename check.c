#include <check.h>
#include <string.h>

#include "s21_string.h"
// funcs
START_TEST(s21_strlen_test) {
  char test_1[] = "BigMak";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = " ";
  char test_5[] = "123\0456";
  char test_6[] = "rrr\\\0";
  char test_8[] = "";
  char test_10[] = "1";

  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
  ck_assert_int_eq(s21_strlen(test_8), strlen(test_8));
  ck_assert_int_eq(s21_strlen(test_10), strlen(test_10));
}
END_TEST

START_TEST(s21_strcat_test) {
  char test1[] = "Hi Salut I want this geer";
  char test3[] = "\0";
  ck_assert_uint_eq((unsigned long)s21_strcat(test1, test3),
                    (unsigned long)strcat(test1, test3));

  char test5[] = "1\0";
  char test4[] = "\0";
  ck_assert_uint_eq((unsigned long)s21_strcat(test5, test4),
                    (unsigned long)strcat(test5, test4));
  char test6[] = "";
  char test7[] = "";
  ck_assert_uint_eq((unsigned long)s21_strcat(test6, test7),
                    (unsigned long)strcat(test6, test7));
  char test8[5] = "1\0";
  char test9[5] = "1";
  ck_assert_uint_eq((unsigned long)s21_strcat(test8, test9),
                    (unsigned long)strcat(test8, test9));
  char test2[5] = "1";
  char test10[5] = "1";
  ck_assert_uint_eq((unsigned long)s21_strcat(test2, test10),
                    (unsigned long)strcat(test2, test10));
}
END_TEST

START_TEST(s21_strncat_test) {
  char src[] = "";
  char res[] = "";
  char expected[] = "";
  char cd[10] = "cd";
  char expcd[10] = "cd";
  char str[] = "asdcxz";
  char src1[10] = "";
  char res1[10] = "";
  char string[25] = "vorisa";
  char expected_string[25] = "vorisa";
  char SRC[] = "AZXCVBNMA";
  char RES[25] = "AZXCVBNMA";
  char EXP[25] = "AZXCVBNMA";
  char null[] = "\0";
  s21_size_t n_byte1 = 1;
  s21_size_t n_byte6 = 6;
  s21_size_t n_byte = 0;
  s21_size_t n_byte5 = 5;

  ck_assert_str_eq(strncat(expected, src, n_byte),
                   s21_strncat(res, src, n_byte));
  ck_assert_str_eq(strncat(expcd, src, n_byte), s21_strncat(cd, src, n_byte));
  ck_assert_str_eq(strncat(src1, str, n_byte), s21_strncat(res1, str, n_byte));
  ck_assert_str_eq(strncat(expcd, str, n_byte5), s21_strncat(cd, str, n_byte5));
  ck_assert_str_eq(strncat(expected_string, str, n_byte6),
                   s21_strncat(string, str, n_byte6));
  ck_assert_str_eq(strncat(EXP, SRC, n_byte5), s21_strncat(RES, SRC, n_byte5));
  ck_assert_str_eq(strncat(EXP, null, n_byte1),
                   s21_strncat(RES, null, n_byte1));
}
END_TEST

START_TEST(s21_strerror_test) {
  char *case1 = s21_strerror(0);
  char *case2 = strerror(0);
  ck_assert_uint_eq((unsigned long)*case1, (unsigned long)*case2);

  char *case9 = s21_strerror(1);
  char *case10 = strerror(1);
  ck_assert_uint_eq((unsigned long)*case9, (unsigned long)*case10);

  char *case0 = s21_strerror(106);
  char *case3 = strerror(106);
  ck_assert_uint_eq((unsigned long)*case0, (unsigned long)*case3);

  char *case7 = s21_strerror(200);
  char *case8 = strerror(200);
  ck_assert_uint_eq((unsigned long)*case7, (unsigned long)*case8);

  char *case5 = s21_strerror(INT_MAX);
  char *case6 = strerror(INT_MAX);
  ck_assert_uint_eq((unsigned long)*case5, (unsigned long)*case6);

  char *case11 = s21_strerror(-1);
  char *case12 = strerror(-1);
  ck_assert_uint_eq((unsigned long)*case11, (unsigned long)*case12);
}
END_TEST
START_TEST(s21_strchr_test) {
  char str1[] = "School";
  int symbol1 = 'o';
  char *ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "ool");

  char str2[] = "School";
  int symbol2 = 'o';
  char *ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strchr(str3, symbol3);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);

  char str5[] = "abcd";
  int symbol5 = 'a';
  char *ach5 = s21_strchr(str5, symbol5);
  char str6[] = "abcd";
  int symbol6 = 'a';
  char *ach6 = strchr(str6, symbol6);
  ck_assert_str_eq(ach5, ach6);
  ck_assert_str_eq(str5, str6);

  char str7[] = "abcd";
  int symbol7 = 'd';
  char *ach7 = s21_strchr(str7, symbol7);
  char str8[] = "abcd";
  int symbol8 = 'd';
  char *ach8 = strchr(str8, symbol8);
  ck_assert_str_eq(ach7, ach8);
  ck_assert_str_eq(str7, str8);
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[] = "Earth Spirit";
  char str2[] = "EarthShake";
  char str3[] = "EarthShake\0";
  char str4[] = "";
  char str5[] = "";

  ck_assert_int_eq(s21_strncmp(str1, str2, 5) == 0,
                   strncmp(str1, str2, 5) == 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) > 0, strncmp(str1, str2, 6) > 0);
  ck_assert_int_eq(s21_strncmp(str1, str3, 10) > 0,
                   strncmp(str1, str3, 10) > 0);
  ck_assert_int_eq(s21_strncmp(str4, str5, 1) == 0,
                   strncmp(str4, str5, 1) == 0);
}
END_TEST

START_TEST(s21_strcpy_test) {
  char test_1[] = "Axe and Primal Spirit";
  char test_2[] = "     ";
  char test_3[] = "Axe\0";
  char test_4[] = "Dire\0Radiant";
  char test_5[128] = "";
  char test_6[] = "School 21 and School 42";
  char test_7[] = "";
  char test_8[] = "1";
  ck_assert_str_eq(s21_strcpy(test_1, test_2), strcpy(test_1, test_2));
  ck_assert_str_eq(s21_strcpy(test_2, test_3), strcpy(test_2, test_3));
  ck_assert_str_eq(s21_strcpy(test_4, test_5), strcpy(test_4, test_5));
  ck_assert_str_eq(s21_strcpy(test_5, test_4), strcpy(test_5, test_4));
  ck_assert_str_eq(s21_strcpy(test_6, test_5), strcpy(test_6, test_5));
  ck_assert_str_eq(s21_strcpy(test_7, test_5), strcpy(test_7, test_5));
  ck_assert_str_eq(s21_strcpy(test_8, test_5), strcpy(test_8, test_5));
}
END_TEST

START_TEST(s21_strncpy_test) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  char src1[] = "123";
  char res1[] = "123";
  char exp1[] = "123";
  char empty[] = "";
  char src2[] = "Str1ng";
  char res2[7 + 7] = "Str1ng";
  char exp2[7 + 7] = "Str1ng";
  s21_size_t n_byte7 = 7;
  s21_size_t n_byte = 0;
  s21_size_t n_byte1 = 1;
  s21_size_t n_byte2 = 2;
  ck_assert_str_eq(s21_strncpy(res, src, n_byte), strncpy(exp, src, n_byte));
  ck_assert_str_eq(s21_strncpy(res1, src1, n_byte),
                   strncpy(exp1, src1, n_byte));
  ck_assert_str_eq(s21_strncpy(src1, empty, n_byte),
                   strncpy(exp1, empty, n_byte));
  ck_assert_str_eq(s21_strncpy(res1, src1, n_byte1),
                   strncpy(exp1, src1, n_byte1));
  ck_assert_str_eq(s21_strncpy(res1, src1, n_byte2),
                   strncpy(exp1, src1, n_byte2));
  ck_assert_str_eq(s21_strncpy(res2, src2, n_byte7),
                   strncpy(exp2, src2, n_byte7));
  //

  //
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test1[] = "Untildawn";
  char test2[] = "Until";
  char test3[] = "Brimal Sairzx";
  char test4[] = "spirit";
  char test5[] = "0/";
  char test6[] = "//#";
  char test7[] = " ";
  char test8[] = "0987654321";
  char test9[] = "0";
  char test10[] = "1";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
  ck_assert_uint_eq(s21_strcspn(test8, test9), strcspn(test8, test9));
  ck_assert_uint_eq(s21_strcspn(test8, test10), strcspn(test8, test10));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Tank Assasin";
  char str_oneof[] = "Ass";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "Assasin");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));
  char str_for_strpbrk2[] = "State Of New York";
  char str_oneof2[] = "Of";

  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk2, str_oneof2),
                   strpbrk(str_for_strpbrk2, str_oneof2));

  char *str = "This is the road to hell";
  char *empty = "";
  char *empty2 = "T";
  char *empty3 = "a";

  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty2),
                    (unsigned long)strpbrk(str, empty2));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty3),
                    (unsigned long)strpbrk(str, empty3));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "9876 54326 10";
  char test2[] = "a;b;c;d;e;f;g;h;i;j;h";
  char test3[] = " $ ! @ # $ ^ & * ( $ ) $ ";
  char test4[] = "$";

  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'h'),
                    (unsigned long)strrchr(test2, 'h'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, '$'),
                    (unsigned long)strrchr(test3, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test4, '$'),
                    (unsigned long)strrchr(test4, '$'));
}
END_TEST

START_TEST(s21_strspn_test) {
  char str1[] = "0987654321";
  char str2[] = "012";
  char str3[] = "abcdefg";
  char str4[] = "gda";
  char str5[] = "!@#$^&*()";
  char str6[] = ")(*";
  char str7[] = ")";
  char str8[] = "";

  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
  ck_assert_int_eq(s21_strspn(str3, str4), strspn(str3, str4));
  ck_assert_int_eq(s21_strspn(str5, str6), strspn(str5, str6));
  ck_assert_int_eq(s21_strspn(str5, str7), strspn(str5, str7));
  ck_assert_int_eq(s21_strspn(str5, str8), strspn(str5, str8));
}

START_TEST(s21_strstr_test) {
  char test_1[] = "Money lego";
  char test_2[] = "lego";
  char test_3[] = "jho1faQsdkjnSa3aefwf8hiuJafeHioj";
  char test_4[] = "Assassin";
  char test_5[] = "1234";
  char test_6[] = "";
  char test_7[] = "5123451234512345";
  char test_8[] = "1234";
  char test_9[] = "1";
  char test_10[] = "4";
  char test_11[] =
      "13625523478437263475984675342345sdghyftrg freshtsyASFWEt wEafe";
  char test_12[] = " ";
  char test_13[] = "-";
  char test_14[] = "1234567890qwertyuiopasdfghjk-";

  ck_assert_pstr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_pstr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_pstr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_pstr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_pstr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
  ck_assert_pstr_eq(s21_strstr(test_8, test_9), strstr(test_8, test_9));
  ck_assert_pstr_eq(s21_strstr(test_8, test_10), strstr(test_8, test_10));
  ck_assert_pstr_eq(s21_strstr(test_11, test_12), strstr(test_11, test_12));
  ck_assert_pstr_eq(s21_strstr(test_13, test_14), strstr(test_13, test_14));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "One-two/Three/Four(Fith)Five Six";
  char delim1[] = "/";

  char str_strtok2[] = "One-two/Three/Four(Fith)Five Six";
  char delim2[] = "/";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}

END_TEST

START_TEST(s21_to_upper_test) {
  char str1[] = "everything seems imposible until it's done";
  char str2[] = "school21forever";
  char str3[] = "";
  char str4[] = "f";

  char *str = s21_to_upper(str1);

  if (str) {
    ck_assert_str_eq(str, "EVERYTHING SEEMS IMPOSIBLE UNTIL IT'S DONE");
    free(str);
  }

  str = s21_to_upper(str2);

  if (str) {
    ck_assert_str_eq(str, "SCHOOL21FOREVER");
    free(str);
  }
  str = s21_to_upper(str3);

  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }

  str = s21_to_upper(str4);

  if (str) {
    ck_assert_str_eq(str, "F");
    free(str);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str1[] = "I'M JUST a REGULAR EVERY DAy";
  char str2[] = "SCHOOLFOREVER";
  char str3[] = "";
  char str4[] = "A";
  char *str = s21_to_lower(str1);

  if (str) {
    ck_assert_str_eq(str, "i'm just a regular every day");
    free(str);
  }

  str = s21_to_lower(str2);

  if (str) {
    ck_assert_str_eq(str, "schoolforever");
    free(str);
  }

  str = s21_to_lower(str3);

  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }

  str = s21_to_lower(str4);

  if (str) {
    ck_assert_str_eq(str, "a");
    free(str);
  }
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = "Regular!";
  char *str = ", asdfgzxcvbn";
  char *new_str = {0};
  new_str = s21_insert(src, str, 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, asdfgzxcvbn!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 9);
  ck_assert(new_str == s21_NULL);
  free(new_str);

  new_str = s21_insert("Regular!", ", asdfgzxcvbn!!", 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, asdfgzxcvbn!!!");
    free(new_str);
  }

  new_str = s21_insert("Regular!", ", asdfgzxcvbn!!", 35);
  ck_assert(new_str == s21_NULL);
  free(new_str);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }

  char *src1 = "1";
  char *str1 = "1";
  char *new_str2 = s21_insert(src1, str1, 1);
  if (new_str2) {
    ck_assert_str_eq(new_str2, "11");
    free(new_str2);
  }
}

END_TEST

START_TEST(s21_trim_test) {
  char *result;
  char *banner = " \n   !* * *'\' Much Ado About Nothing * * '\'*  !\n";
  result = s21_trim(banner, " *!\n '\'");
  if (result) {
    ck_assert_str_eq(result, "Much Ado About Nothing");
    free(result);
  }

  char *banner2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  result = s21_trim(banner2, format_str);
  if (result) {
    ck_assert_str_eq(result, "Hello, world!");
    free(result);
  }

  char *empty_str = "";
  result = s21_trim(empty_str, s21_NULL);
  if (result) {
    ck_assert_str_eq(result, "");
    free(result);
  }

  char *empty_format = "";
  result = s21_trim(s21_NULL, empty_format);
  ck_assert(result == s21_NULL);

  result = s21_trim(banner, empty_format);
  if (result) {
    ck_assert_str_eq(result, "!* * *'' Much Ado About Nothing * * ''*  !");
    free(result);
  }

  result = s21_trim("banner \n", "\n");
  if (result) {
    ck_assert_str_eq(result, "banner ");
    free(result);
  }

  result = s21_trim(empty_str, " \n\0");
  if (result) {
    ck_assert_str_eq(result, "");
    free(result);
  }
}
END_TEST

START_TEST(s21_memchr_test) {
  char test1[] = "BazwMrater";
  char test2 = 'M';
  char test3 = 'r';
  char test4[] = "8919/\0";
  char test5[] = "?";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  char test_8[] = "";
  char test_10[] = "1";
  char test_11 = '1';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 10),
                    (unsigned long)memchr(test1, test2, 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 10),
                    (unsigned long)memchr(test1, test3, 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 7),
                    (unsigned long)memchr(test4, test6, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 7),
                    (unsigned long)memchr(test4, test8, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 7),
                    (unsigned long)memchr(test4, test9, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test_8, test7, 1),
                    (unsigned long)memchr(test_8, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test_10, test_11, 1),
                    (unsigned long)memchr(test_10, test_11, 1));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test1[] = "It's hard to be good";
  char test2[] = "Code like good";
  char test3[] = "\0";
  char test4[] = "Wanna\0 sleep";
  char test5[] = "Wanna\0 sleep";
  char test_8[] = "";
  char test_9[] = "";
  char test_10[] = "1";
  char test_11[] = "1";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 14) == 0,
                    memcmp(test1, test2, 14) == 0);
  ck_assert_uint_eq(s21_memcmp(test1, test3, 2) > 0,
                    memcmp(test1, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0,
                    memcmp(test2, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9) > 0,
                    memcmp(test4, test1, 9) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7) == 0,
                    memcmp(test4, test5, 7) == 0);
  ck_assert_uint_eq(s21_memcmp(test_8, test_9, 1) == 0,
                    memcmp(test_8, test_9, 1) == 0);
  ck_assert_uint_eq(s21_memcmp(test_10, test_11, 1) == 0,
                    memcmp(test_10, test_11, 1) == 0);
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1[BUFF_SIZE] = "Azxcvbnm_Bratik";
  char test_2[BUFF_SIZE] = "  ";
  char test_3[BUFF_SIZE] = "///  ";
  char test_4[BUFF_SIZE] = "   & ///";
  char test_5[BUFF_SIZE] = "";
  char test_6[BUFF_SIZE] = "8922486";
  char test_7[BUFF_SIZE] = "5526\0123";
  char test_8[BUFF_SIZE] = "";
  char test_9[BUFF_SIZE] = "";
  char test_10[BUFF_SIZE] = "1";
  char test_11[BUFF_SIZE] = "1";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_6, test_7, 4), memcpy(test_6, test_7, 4));
  ck_assert_str_eq(s21_memcpy(test_8, test_9, 1), memcpy(test_8, test_9, 1));
  ck_assert_str_eq(s21_memcpy(test_10, test_11, 1),
                   memcpy(test_10, test_11, 1));
}
END_TEST

START_TEST(s21_memset_test) {
  unsigned char test1[10] = "Tommy CAT";
  unsigned char test2[10] = "Lochanta";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '-', 10),
                    (unsigned long)memset(test1, '-', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '6', 10),
                    (unsigned long)memchr(test1, '6', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '!', 6),
                    (unsigned long)memchr(test2, '!', 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '9', 0),
                    (unsigned long)memchr(test1, '9', 0));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, 'a', 5),
                    (unsigned long)memchr(test1, 'a', 5));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '>', 3),
                    (unsigned long)memchr(test2, '>', 3));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, ' ', 1),
                    (unsigned long)memchr(test2, ' ', 1));
}
END_TEST

//////////

////SPRINTF
START_TEST(simplE_int11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precisE_int11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val1_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val1_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_flags1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_flags1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many1_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many11_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE string1S AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string1_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE string1S AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "90 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG string1";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(ptr1_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr1_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(n_specifier1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision1_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision1_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision1_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision1_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.16Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision1_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision1_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_huge1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_many1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_dec1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_dec1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111onE_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_float1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_float1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f %f %f %f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f %f %f %f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(test_111one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(test_111one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(test_111one_hex_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(test_111one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(test_111one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(test_111one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_111sprintf9) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%li%ld%lu";

//   ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
//                    sprintf(str2, format, 666666666666, 777, 111));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_111sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.16Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_trailing_zero11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_large1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_small1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_many1_zeroes_in_front1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_one_zero1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_zero1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_mantiss1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_mantiss1_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_short_no_mantiss1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(LG1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_many1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_char1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

////ENDSPRINTF

// SSCANF
START_TEST(S21_SSCANF) {
  char a, b, c, d;  // chars
  char a1, b1, c1, d1;
  s21_sscanf("English", "%c %c %c %*c   ", &a, &b, &c);
  sscanf("English", "%c %c %c %*c   ", &a1, &b1, &c1);
  s21_sscanf("ab", "%c", &d);
  sscanf("ab", "%c", &d1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(d, d1);

  int x, y, z = 0;  // ints
  int x1, y1, z1 = 0;
  s21_sscanf("+12 -23 .54", "%3d %d %d", &x, &y, &z);
  sscanf("+12 -23 .54", "%3d %d %d", &x1, &y1, &z1);
  ck_assert_int_eq(x, x1);
  ck_assert_int_eq(y, y1);
  ck_assert_int_eq(z, z1);

  s21_sscanf("+0775 1-0x1324--123", " %i %*i %i-  %i", &x, &y, &z);
  sscanf("+0775 1-0x1324--123", " %i %*i %i- %i", &x1, &y1, &z1);
  ck_assert_int_eq(x, x1);
  ck_assert_int_eq(y, y1);
  ck_assert_int_eq(z, z1);

  unsigned short usx, usx1;
  unsigned int ux, ux1;
  unsigned long ulx, ulx1;
  unsigned long ullx, ullx1;
  s21_sscanf("0 +2112 -12324", "%o %lo %lo", &ux, &ulx, &ullx);
  sscanf("0 +2112 -12324", "%o %lo %lo", &ux1, &ulx1, &ullx1);
  ck_assert_int_eq(ux, ux1);
  ck_assert_int_eq(ulx, ulx1);
  ck_assert_int_eq(ullx, ullx1);

  s21_sscanf("0 0x211a 12324 0x1", "%x %lx %lx %hx", &ux, &ulx, &ullx, &usx);
  sscanf("0 0x211a 12324 0x1", "%x %lx %lx %hx", &ux1, &ulx1, &ullx1, &usx1);
  ck_assert_int_eq(usx, usx1);
  ck_assert_int_eq(ux, ux1);
  ck_assert_int_eq(ulx, ulx1);
  ck_assert_int_eq(ullx, ullx1);

  x = 0, x1 = 0;  // errors
  s21_sscanf("a21", "%d", &x);
  sscanf("a21", "%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("a21", "b%d", &x);
  sscanf("a21", "b%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("--a21", "%d", &x);
  sscanf("--a21", "%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("-21", "%1d", &x);
  sscanf("-21", "%1d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("-21", "%%%1d", &x);
  sscanf("-21", "%%%1d", &x1);
  // ck_assert_int_eq(x, x1);
  s21_sscanf("-21   ", "%d %d", &x, &y);
  sscanf("-21   ", "%d %d", &x1, &y1);
  ck_assert_int_eq(x, x1);

  float fx, fx1;  ////////////// floats
  long double lfx, lfx1;
  s21_sscanf("1 2 .995123 999.99.1", "%g %Le %*d", &fx, &lfx);
  sscanf("1 2 .995123 999.99.1", "%g %Le %*d", &fx1, &lfx1);
  ck_assert_float_eq(fx, fx1);
  ck_assert_ldouble_eq(lfx, lfx1);

  float af1 = 0, af2 = 0, bf1 = 0, bf2 = 0, cf1 = 0, cf2 = 0, df1 = 0, df2 = 0;

  const char strf[] = "1.2e10 -0.1111 20.2e-3 1e-10";
  const char fstr[] = "%f %f %f %f";

  int res1 = s21_sscanf(strf, fstr, &af1, &bf1, &cf1, &df1);
  int res2 = sscanf(strf, fstr, &af2, &bf2, &cf2, &df2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(af1, af2);
  ck_assert_float_eq(bf1, bf2);
  ck_assert_float_eq(cf1, cf2);
  ck_assert_float_eq(df1, df2);

  float al1 = 0, al2 = 0, bl1 = 0, bl2 = 0, cl1 = 0, cl2 = 0, dl1 = 0, dl2 = 0;
  const char strf3[] = "1.4441 1.31e3 3.31 4.44e2";

  res1 = s21_sscanf(strf3, "%f %f %f %f", &al1, &bl1, &cl1, &dl1);
  res2 = sscanf(strf3, "%f %f %f %f", &al2, &bl2, &cl2, &dl2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(bl1, bl2);
  ck_assert_float_eq(dl1, dl2);

  char str[100], str1[100];  // strings
  char p_str[100], p_str1[100];
  s21_sscanf("abc\n\r\t%%cba\faaa?.123", "%*s %%%s%s%n", str, str1, &x);
  sscanf("abc\n\r\t%%cba\faaa?.123", "%*s %%%s%s%n", p_str, p_str1, &x1);
  ck_assert_msg(strcmp(str, p_str) == 0, "str fail");
  ck_assert_msg(strcmp(str1, p_str1) == 0, "str1 fail");
  // ck_assert_int_eq(x, x1);

  void *addr1 = s21_NULL, *addr2 = s21_NULL, *addr3 = s21_NULL;
  void *paddr1 = NULL, *paddr2 = NULL, *paddr3 = NULL;
  s21_sscanf("0x1abcd -0xfffffffff +0xffffffffffffffffffaaa", "%p %n%p %p",
             &addr1, &x, &addr2, &addr3);
  sscanf("0x1abcd -0xfffffffff +0xffffffffffffffffffaaa", "%p %n%p %p", &paddr1,
         &x1, &paddr2, &paddr3);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_string");
  TCase *test_case_1 = tcase_create("s21_string");
  SRunner *sr = srunner_create(s1);
  int ERR;

  suite_add_tcase(s1, test_case_1);
  // FUNCS
  tcase_add_test(test_case_1, s21_strlen_test);
  tcase_add_test(test_case_1, s21_strerror_test);
  tcase_add_test(test_case_1, s21_strcat_test);
  tcase_add_test(test_case_1, s21_strncat_test);

  tcase_add_test(test_case_1, s21_memchr_test);
  tcase_add_test(test_case_1, s21_memcmp_test);
  tcase_add_test(test_case_1, s21_memcpy_test);

  tcase_add_test(test_case_1, s21_memset_test);

  tcase_add_test(test_case_1, s21_strchr_test);
  tcase_add_test(test_case_1, s21_strrchr_test);

  tcase_add_test(test_case_1, s21_strncmp_test);
  tcase_add_test(test_case_1, s21_strcpy_test);
  tcase_add_test(test_case_1, s21_strncpy_test);
  tcase_add_test(test_case_1, s21_strncpy_test);
  tcase_add_test(test_case_1, s21_strcspn_test);

  tcase_add_test(test_case_1, s21_strpbrk_test);

  tcase_add_test(test_case_1, s21_strspn_test);
  tcase_add_test(test_case_1, s21_strstr_test);
  tcase_add_test(test_case_1, s21_strtok_test);
  tcase_add_test(test_case_1, s21_to_upper_test);
  tcase_add_test(test_case_1, s21_to_lower_test);
  tcase_add_test(test_case_1, s21_insert_test);
  tcase_add_test(test_case_1, s21_trim_test);

  ///////////////////////////////////////////////////////
  // SPRINTF
  tcase_add_test(test_case_1, simplE_int11);
  tcase_add_test(test_case_1, precisE_int11);
  tcase_add_test(test_case_1, width_int1);
  tcase_add_test(test_case_1, minus_width_int1);
  tcase_add_test(test_case_1, plus_width_int1);
  tcase_add_test(test_case_1, star_precision_int1);
  tcase_add_test(test_case_1, flags_short_int1);
  tcase_add_test(test_case_1, flags_another_long_int1);
  tcase_add_test(test_case_1, zero_precision_zero_int1);
  tcase_add_test(test_case_1, space_flag_int1);
  tcase_add_test(test_case_1, unsigned_val1);
  tcase_add_test(test_case_1, unsigned_val1_width);
  tcase_add_test(test_case_1, unsigned_val1_flags);
  tcase_add_test(test_case_1, unsigned_val1_precision);
  tcase_add_test(test_case_1, unsigned_val1_many_flags);
  tcase_add_test(test_case_1, unsigned_val1_short);
  tcase_add_test(test_case_1, unsigned_val1_long);
  tcase_add_test(test_case_1, unsigned_val1_many);
  tcase_add_test(test_case_1, octal1);
  tcase_add_test(test_case_1, octal1_width1);
  tcase_add_test(test_case_1, octal1_flags1);
  tcase_add_test(test_case_1, octal1_precision1);
  tcase_add_test(test_case_1, octal1_many_flags);
  tcase_add_test(test_case_1, octal1_short);
  tcase_add_test(test_case_1, octal1_long);
  tcase_add_test(test_case_1, octal1_many);
  tcase_add_test(test_case_1, octal1_zero);
  tcase_add_test(test_case_1, octal1_hash);
  tcase_add_test(test_case_1, unsigned_zero1);
  tcase_add_test(test_case_1, hex_width1);
  tcase_add_test(test_case_1, hex_flags1);
  tcase_add_test(test_case_1, hex_precision1);
  tcase_add_test(test_case_1, hex_many1);
  tcase_add_test(test_case_1, hex_many1_flags);
  tcase_add_test(test_case_1, hex_zero1);
  tcase_add_test(test_case_1, hex_huge1);
  tcase_add_test(test_case_1, hex_short1);
  tcase_add_test(test_case_1, hex_long1);
  tcase_add_test(test_case_1, hex_one_longer_width1);
  tcase_add_test(test_case_1, hex_two_longer_width1);
  tcase_add_test(test_case_1, one_char1);
  tcase_add_test(test_case_1, one_precision11);
  tcase_add_test(test_case_1, one_flags11);
  tcase_add_test(test_case_1, one_width11);
  tcase_add_test(test_case_1, one_many11);
  tcase_add_test(test_case_1, one_many11_flags);
  tcase_add_test(test_case_1, string1);
  tcase_add_test(test_case_1, string1_precision);
  tcase_add_test(test_case_1, string1_long);
  tcase_add_test(test_case_1, ptr1_width);
  tcase_add_test(test_case_1, ptr1_precision);
  tcase_add_test(test_case_1, n_specifier1);
  tcase_add_test(test_case_1, string1_width_huge);
  tcase_add_test(test_case_1, float_width1);
  tcase_add_test(test_case_1, float_precision1_zero);
  tcase_add_test(test_case_1, float_precision1_empty);
  tcase_add_test(test_case_1, float_precision1_huge);
  tcase_add_test(test_case_1, float_precision1_huge_negative);
  tcase_add_test(test_case_1, float_huge1);
  tcase_add_test(test_case_1, float_flags1);
  tcase_add_test(test_case_1, float_many1);
  tcase_add_test(test_case_1, e_precision1);
  tcase_add_test(test_case_1, e_precision1_zero);
  tcase_add_test(test_case_1, e_precision1_empty);
  tcase_add_test(test_case_1, e_precision1_huge);
  tcase_add_test(test_case_1, e_precision1_huge_negative);
  tcase_add_test(test_case_1, e_huge1);
  tcase_add_test(test_case_1, e_many1);
  tcase_add_test(test_case_1, e_width1);
  tcase_add_test(test_case_1, all_empty1);
  tcase_add_test(test_case_1, empty_format_and_parameters1);
  tcase_add_test(test_case_1, test_111one_char1);
  tcase_add_test(test_case_1, test_111many_char);
  tcase_add_test(test_case_1, test_111one_string1);
  tcase_add_test(test_case_1, test_111many_string1);
  tcase_add_test(test_case_1, test_111one_dec1);
  tcase_add_test(test_case_1, test_111many_dec1);
  tcase_add_test(test_case_1, test_111onE_int1);
  tcase_add_test(test_case_1, test_111many_int);
  tcase_add_test(test_case_1, test_111one_float1);
  tcase_add_test(test_case_1, test_111many_float1);
  tcase_add_test(test_case_1, test_111one_unsigned_dec);
  tcase_add_test(test_case_1, test_111many_unsigned_dec);
  tcase_add_test(test_case_1, test_111one_char1_with_alignment_left);
  tcase_add_test(test_case_1, test_111one_char1_with_alignment_right);
  tcase_add_test(test_case_1, test_111many_char_with_alignment);
  tcase_add_test(test_case_1, test_111one_hex_lower);
  tcase_add_test(test_case_1, test_111one_hex_upper);
  tcase_add_test(test_case_1, test_111many_hex_lower);
  tcase_add_test(test_case_1, test_111many_hex_upper);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_alignment_left);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_alignment_right);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_alignment_left);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_alignment_right);
  tcase_add_test(test_case_1, test_111many_hex_lower_with_alignment);
  tcase_add_test(test_case_1, test_111many_hex_upper_with_alignment);
  tcase_add_test(test_case_1, test_111one_hex_with_hashtag);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_hashtag);
  tcase_add_test(test_case_1, test_111many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(test_case_1, test_111many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_width_star);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_width_star);
  tcase_add_test(test_case_1,
                 test_111many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(test_case_1, test_111many_hex_upper_with_width_star);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_precision);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_precision);
  tcase_add_test(test_case_1, test_111many_hex_lower_with_precision_and_other);
  tcase_add_test(test_case_1, test_111many_hex_upper_with_precision_and_other);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_length);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_length);
  tcase_add_test(test_case_1, test_111sprintf1);
  tcase_add_test(test_case_1, test_111sprintf2);
  tcase_add_test(test_case_1, test_111sprintf3);
  tcase_add_test(test_case_1, test_111sprintf4);
  tcase_add_test(test_case_1, test_111sprintf6);
  tcase_add_test(test_case_1, test_111sprintf8);
  // tcase_add_test(test_case_1, test_111sprintf9);
  tcase_add_test(test_case_1, test_111sprintf10);
  tcase_add_test(test_case_1, test_111sprintf11);
  tcase_add_test(test_case_1, test_111sprintf12);
  tcase_add_test(test_case_1, test_111sprintf14);
  tcase_add_test(test_case_1, test_111sprintf15);
  tcase_add_test(test_case_1, test_111sprintf16);
  tcase_add_test(test_case_1, test_111sprintf17);
  tcase_add_test(test_case_1, test_111sprintf18);
  tcase_add_test(test_case_1, test_111sprintf19);
  tcase_add_test(test_case_1, test_111sprintf20);
  tcase_add_test(test_case_1, test_111sprintf24);
  tcase_add_test(test_case_1, test_111sprintf25);
  tcase_add_test(test_case_1, test_111sprintf28);
  tcase_add_test(test_case_1, test_111sprintf29);
  tcase_add_test(test_case_1, test_111sprintf30);
  tcase_add_test(test_case_1, test_111sprintf31);
  tcase_add_test(test_case_1, test_111sprintf32);
  tcase_add_test(test_case_1, test_111sprintf33);
  tcase_add_test(test_case_1, test_111sprintf35);
  tcase_add_test(test_case_1, test_111sprintf36);
  tcase_add_test(test_case_1, test_111sprintf37);
  tcase_add_test(test_case_1, test_111sprintf38);
  tcase_add_test(test_case_1, test_111sprintf39);
  tcase_add_test(test_case_1, test_111sprintf40);
  tcase_add_test(test_case_1, test_111sprintf41);
  tcase_add_test(test_case_1, test_111sprintf42);
  tcase_add_test(test_case_1, test_111sprintf43);
  tcase_add_test(test_case_1, test_111sprintf44);
  tcase_add_test(test_case_1, g_trailing_zero11);
  tcase_add_test(test_case_1, g_large1);
  tcase_add_test(test_case_1, g_small1);
  tcase_add_test(test_case_1, g_precision1);
  tcase_add_test(test_case_1, g_precision1_zero);
  tcase_add_test(test_case_1, g_precision1_missing);
  tcase_add_test(test_case_1, g_many1_zeroes_in_front1);
  tcase_add_test(test_case_1, g_one_zero1);
  tcase_add_test(test_case_1, g_mantiss1);
  tcase_add_test(test_case_1, g_mantiss1_flags);
  tcase_add_test(test_case_1, g_short_no_mantiss1);
  tcase_add_test(test_case_1, LG1);
  tcase_add_test(test_case_1, g_many1);
  tcase_add_test(test_case_1, g_zero1);
  tcase_add_test(test_case_1, width_char1);
  //////////////////////////sscanf

  tcase_add_test(test_case_1, S21_SSCANF);

  srunner_run_all(sr, CK_ENV);
  ERR = srunner_ntests_failed(sr);

  srunner_free(sr);
  return ERR == 0 ? 0 : 1;
}