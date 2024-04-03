#include "s21_string.h"

//Основная функция
int s21_sscanf(const char *str, const char *format, ...) {
  //количество записанных аргументов
  int stchetchik = 0;
  //количество прочитаных символов или байт
  int count_character = 0;
  short int stop = 0;
  va_list param;
  va_start(param, format);
  short int read_error = 0;

  if (str == S21_NULL || format == NULL || *str == 0) {
    stop = 1;
    stchetchik = -1;
  }

  while (!stop) {
    //обнуляем
    //обработка символов
    count_character += go_by_src_and_format(&str, &format, &stop);
    int error_options = 0;

    if (!stop) {
      //обнуляем
      struct Spec_Format spec_format = {0, 0, 0, 0, 0, -1, -1, 0, 0, 0};
      error_options = get_options_scanf(&format, &spec_format);
      if (!error_options) {
        count_character +=
            set_value_from_str(&str, &param, spec_format, &read_error,
                               &stchetchik, count_character);
        stop = read_error;
      } else {
        stop = 1;
      }
    } else {
    }
  }

  //Некий костыль, когда str прочитан полностью, format не полностью прочитан, и
  //ни одного аргумента не записали, значит оишибка -1
  if (*str == 0 && *format != 0 && stchetchik == 0) {
    stchetchik = -1;
  }

  //Костыль отлавливающий спецификацию n когда str закончился, а в формате
  //остался %n или %n%n, но не %s%n
  if (*format == '%') {
    int error_options = 0;
    while (!error_options && !read_error) {
      struct Spec_Format spec_format = {0, 0, 0, 0, 0, -1, -1, 0, 0, 0};
      error_options = get_options_scanf(&format, &spec_format);
      if (spec_format.specifecator == 'n' && !error_options) {
        set_value_from_str(&str, &param, spec_format, &stop, &stchetchik,
                           count_character);
      } else {
        error_options = 1;
      }
    }
  }

  va_end(param);
  return stchetchik;
}

int go_by_src_and_format(const char **str, const char **format,
                         short int *stop) {
  int stop_in = 0;
  int count_character = 0;

  while (**format != 0 && **str != 0 && !stop_in && **format != '%') {
    if (!is_not_white_space(format)) {
      count_character += reduce_space(str);
      *format += 1;
    } else if (**format != **str) {
      stop_in = 1;
      *stop = 1;
    } else {
      *format += 1;
      *str += 1;
      count_character += 1;
    }
  }

  if (**format == 0 || **str == 0) {
    *stop = 1;
  }

  if (**format == '%' && *(*format + 1) == '%' && **str == '%') {
    *str += 1;
    count_character += 1;
    *format += 2;
  }

  return count_character;
}

int get_options_scanf(const char **format, struct Spec_Format *spec_format) {
  short int error_options = 0;
  short int stop = 0;
  short int search_flag = 1;
  short int search_width = 1;
  short int search_length = 1;
  short int search_specifacators = 1;
  if (**format == '%') {
    *format += 1;
    while (!stop) {
      short int result_search = 0;

      if (search_flag && !result_search) {
        result_search = is_it_the_flag_in_format_scanf(format, spec_format);
        if (result_search) {
          *format += 1;
        }
      }

      if (search_width && !result_search) {
        result_search = is_it_the_width_in_format_scanf(format, spec_format);
        if (result_search) {
          search_flag = 0;
          search_width = 0;
        }
      }

      if (search_length && !result_search) {
        result_search = is_it_the_length_in_format_scanf(format, spec_format);
        if (result_search) {
          *format += 1;
          search_flag = 0;
          search_width = 0;
          search_length = 0;
        }
      }
      if (search_specifacators && !result_search) {
        result_search =
            is_it_the_specifacators_in_format_scanf(format, spec_format);
        if (result_search) {
          *format += 1;
          search_flag = 0;
          search_width = 0;
          search_length = 0;
          search_specifacators = 0;
          stop = 1;
        }
      }
      if (!result_search) {
        //некорректный формат ввода
        stop = 1;
        error_options = 1;
      }
    }
  } else {
    error_options = 1;
  }

  return error_options;
}

//---------------------------------Функции для считывания модификаторов
//форматирования----------------------------- Спецификаторы
short int is_it_the_specifacators_in_format_scanf(
    const char **format, struct Spec_Format *spec_format) {
  short int result_search = 0;
  if (**format == 'd') {
    spec_format->specifecator = 'd';
    result_search = 1;
  }
  if (**format == 'u') {
    spec_format->specifecator = 'u';
    result_search = 1;
  }
  if (**format == 'i') {
    // i
    spec_format->specifecator = 'i';
    result_search = 1;
  }
  if (**format == 'c') {
    // printf("spec_format->specifecator = 'c'\n");
    spec_format->specifecator = 'c';
    result_search = 1;
  }
  if (**format == 's') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 's';
    result_search = 1;
  }
  if (**format == 'f') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'f';
    result_search = 1;
  }
  if (**format == 'e') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'e';
    result_search = 1;
  }
  if (**format == 'E') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'E';
    result_search = 1;
  }
  if (**format == 'g') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'g';
    result_search = 1;
  }
  if (**format == 'G') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'G';
    result_search = 1;
  }
  if (**format == 'x') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'x';
    result_search = 1;
  }
  if (**format == 'X') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'X';
    result_search = 1;
  }
  if (**format == 'o') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'o';
    result_search = 1;
  }
  if (**format == 'n') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'n';
    result_search = 1;
  }
  if (**format == 'p') {
    // printf("spec_format->specifecator = 's'\n");
    spec_format->specifecator = 'p';
    result_search = 1;
  }
  return result_search;
}

//Длина
short int is_it_the_length_in_format_scanf(const char **format,
                                           struct Spec_Format *spec_format) {
  short int result_search = 0;
  if (**format == 'l') {
    spec_format->length = 'l';
    result_search = 1;
  }
  if (**format == 'h') {
    spec_format->length = 'h';
    result_search = 1;
  }
  if (**format == 'L') {
    spec_format->length = 'L';
    result_search = 1;
  }
  return result_search;
}

//Ширина
short int is_it_the_width_in_format_scanf(const char **format,
                                          struct Spec_Format *spec_format) {
  short int result_search = 0;

  if (**format >= '0' && **format <= '9') {
    spec_format->width = 0;
    while (**format >= '0' && **format <= '9') {
      spec_format->width = (spec_format->width) * 10 + **format - '0';
      *format += 1;
    }
    result_search = 1;
  }

  return result_search;
}
//Флаги
short int is_it_the_flag_in_format_scanf(const char **format,
                                         struct Spec_Format *spec_format) {
  short int result_search = 0;
  if (**format == '*') {
    spec_format->propusk = 1;
    result_search = 1;
  }

  return result_search;
}

//-------------------------------------------------------------Обработка
//Модификаторов

int set_value_from_str(const char **str, va_list *param,
                       struct Spec_Format spec_format, short int *stop,
                       int *stchetchik_common, int ready_count) {
  //количество прочитаных символов или байт
  int count_character = 0;
  int stchetchik = 0;
  if (spec_format.specifecator == 'd') {
    count_character += get_value_from_str_and_format_for_d(
        param, spec_format, str, stop, &stchetchik);
  }
  if (spec_format.specifecator == 'c' && spec_format.width < 0) {
    count_character += get_value_from_str_and_format_for_c(param, spec_format,
                                                           str, &stchetchik);
  }
  if (spec_format.specifecator == 's' ||
      (spec_format.specifecator == 'c' && spec_format.width >= 0)) {
    count_character += get_value_from_str_and_format_for_s(param, spec_format,
                                                           str, &stchetchik);
  }
  if (spec_format.specifecator == 'f' || spec_format.specifecator == 'e' ||
      spec_format.specifecator == 'E' || spec_format.specifecator == 'g' ||
      spec_format.specifecator == 'G') {
    count_character += get_value_from_str_and_format_for_f(
        param, spec_format, str, stop, &stchetchik);
  }
  if (spec_format.specifecator == 'n') {
    get_value_from_str_and_format_for_n(param, spec_format, &stchetchik,
                                        ready_count);
  }
  if (spec_format.specifecator == 'u' || spec_format.specifecator == 'o' ||
      spec_format.specifecator == 'x' || spec_format.specifecator == 'X' ||
      spec_format.specifecator == 'i') {
    count_character += get_value_from_str_and_format_for_u(
        param, spec_format, str, stop, &stchetchik);
  }
  if (spec_format.specifecator == 'p') {
    count_character += get_value_from_str_and_format_for_p(
        param, spec_format, str, stop, &stchetchik);
  }

  if (stchetchik) {
    *stchetchik_common += 1;
  }

  return count_character;
}

int read_cifri_o_from_str(unsigned long long int *result, const char **str,
                          short int *stop, int width, int *sign_minus,
                          int *find) {
  int count_character = 0;

  if (**str == '-') {
    *sign_minus = 1;
    *str += 1;
    width -= 1;
    count_character += 1;
  } else if (**str == '+') {
    *str += 1;
    width -= 1;
    count_character += 1;
  }

  if (**str >= '0' && **str <= '7') {
    *result = 0;
    while (**str >= '0' && **str <= '7' && width != 0) {
      if (((*result) > (*result) * 8 + (**str - '0'))) {
        //переполнение
        *result = -1;
        width = 1;
        *stop = 1;
        *sign_minus = 0;

      } else {
        *result = (*result) * 8 + (**str - '0');
      }
      *str += 1;
      width -= 1;
      count_character += 1;
    }
  } else {
    *find = 0;
    *stop = 1;
  }
  return count_character;
}

int is_it_a_hex(char ch) {
  int result = 0;
  if (ch >= '0' && ch <= '9') {
    result = 1;
  }
  if (ch >= 'a' && ch <= 'f') {
    result = 1;
  }
  if (ch >= 'A' && ch <= 'F') {
    result = 1;
  }
  return result;
}

int convert_cfr_hex_in_int(char ch) {
  int result = 0;
  if (ch >= '0' && ch <= '9') {
    result = ch - '0';
  }
  if (ch >= 'a' && ch <= 'f') {
    result = ch - 'a' + 10;
  }
  if (ch >= 'A' && ch <= 'F') {
    result = ch - 'A' + 10;
  }
  return result;
}

int read_cifri_x_from_str(unsigned long long int *result, const char **str,
                          short int *stop, int width, int *sign_minus,
                          int *find) {
  int count_character = 0;
  if (**str == '-') {
    *sign_minus = 1;
    *str += 1;
    width -= 1;
    count_character += 1;
  } else if (**str == '+') {
    *str += 1;
    width -= 1;
    count_character += 1;
  }

  if (is_it_a_hex(**str)) {
    *result = 0;
    //обработка 0x если есть
    if ((**str == '0') && width != 0) {
      *str += 1;
      width -= 1;
      count_character += 1;
      if ((**str == 'x' || **str == 'X') && width != 0) {
        *str += 1;
        width -= 1;
        count_character += 1;
      }
    }
    // printf(" *str=%s\n",*str);
    while (is_it_a_hex(**str) && width != 0) {
      if (((*result) > (*result) * 16 + convert_cfr_hex_in_int(**str))) {
        //переполнение
        *result = -1;
        width = 1;
        *stop = 1;
        *sign_minus = 0;

      } else {
        *result = (*result) * 16 + convert_cfr_hex_in_int(**str);
      }
      *str += 1;
      width -= 1;
      count_character += 1;
    }
  } else {
    *find = 0;
    *stop = 1;
  }
  return count_character;
}

//-------------------------Спецификация n
//----------------------------------------

int get_value_from_str_and_format_for_n(va_list *param,
                                        struct Spec_Format spec_format,
                                        int *stchetchik, int ready_count) {
  int count_character = 0;

  if (!(spec_format.propusk)) {
    void *value_p = NULL;

    if (spec_format.length == 'h') {
      value_p = (void *)va_arg(*param, unsigned short int *);
      *(unsigned short int *)value_p = (unsigned short int)ready_count;
    } else if (spec_format.length == 'l') {
      value_p = (void *)va_arg(*param, unsigned long int *);
      *(unsigned long int *)value_p = (unsigned long int)ready_count;
    } else {
      value_p = (void *)va_arg(*param, unsigned int *);
      *(unsigned int *)value_p = (unsigned int)ready_count;
    }
    *stchetchik = 0;
  }

  return count_character;
}

//-------------------------Спецификация s
//----------------------------------------
int get_value_from_str_and_format_for_s(va_list *param,
                                        struct Spec_Format spec_format,
                                        const char **str, int *stchetchik) {
  void *value_p = NULL;
  int count_character = 0;

  if (!(spec_format.propusk)) {
    value_p = (void *)va_arg(*param, int *);
  }

  if (spec_format.specifecator == 'c') {
    count_character += read_cs_from_str(spec_format, str, value_p, stchetchik);
  } else {
    count_character += read_s_from_str(spec_format, str, value_p, stchetchik);
  }

  return count_character;
}

int read_s_from_str(struct Spec_Format spec_format, const char **str,
                    void *value_p, int *stchetchik) {
  int count_character = 0;
  int width = 0;
  wchar_t *value_ls = NULL;
  char *value_p_s = NULL;
  if (spec_format.width <= 0) {
    width = -1;
  } else {
    width = spec_format.width;
  }

  if (spec_format.length == 'l') {
    value_ls = (wchar_t *)value_p;
  } else {
    value_p_s = (char *)value_p;
  }
  count_character += reduce_space(str);

  while (is_not_white_space(str) && **str != 0 && width != 0) {
    wchar_t w_ch;
    int count_wb = 1;
    if (spec_format.length == 'l') {
      count_wb = mbtowc(&w_ch, *str, MB_CUR_MAX);
    }
    if (!(spec_format.propusk)) {
      if (spec_format.length == 'l') {
        *value_ls = w_ch;
        value_ls += 1;
      } else {
        *value_p_s = **str;
        value_p_s += 1;
      }
      *stchetchik = 1;
    }
    *str += count_wb;
    count_character += count_wb;
    width -= 1;
  }

  if (spec_format.length == 'l') {
    *value_ls = 0;
  } else {
    *value_p_s = 0;
  }

  return count_character;
}

int read_cs_from_str(struct Spec_Format spec_format, const char **str,
                     void *value_p, int *stchetchik) {
  int count_character = 0;
  int width = 0;
  wchar_t *value_ls = NULL;
  char *value_p_s = NULL;
  if (spec_format.width == 0) {
    width = 1;
  } else {
    width = spec_format.width;
  }

  if (spec_format.length == 'l') {
    value_ls = (wchar_t *)value_p;
  } else {
    value_p_s = (char *)value_p;
  }

  while (**str != 0 && width != 0) {
    wchar_t w_ch;
    int count_wb = 1;
    if (spec_format.length == 'l') {
      count_wb = mbtowc(&w_ch, *str, MB_CUR_MAX);
    }
    if (!(spec_format.propusk)) {
      if (spec_format.length == 'l') {
        *value_ls = w_ch;
        value_ls += 1;
      } else {
        *value_p_s = **str;
        value_p_s += 1;
      }
      *stchetchik = 1;
    }
    *str += count_wb;
    count_character += count_wb;
    width -= 1;
  }

  return count_character;
}

int is_not_white_space(const char **str) {
  int result = 1;
  if (**str == ' ' || **str == '\t' || **str == '\n') {
    result = 0;
  }
  return result;
}

//-------------------------Спецификация с
//----------------------------------------
int get_value_from_str_and_format_for_c(va_list *param,
                                        struct Spec_Format spec_format,
                                        const char **str, int *stchetchik) {
  int count_character = 0;
  char ch;
  wchar_t w_ch;

  if (spec_format.length == 'l') {
    int count_wb = mbtowc(&w_ch, *str, MB_CUR_MAX);
    if (count_wb > 0) {
      *str += count_wb;
      count_character = count_wb;
    }
  } else {
    ch = **str;
    *str += 1;
    count_character = 1;
  }

  if (!(spec_format.propusk)) {
    void *value_p = NULL;

    if (spec_format.length == 'l' && count_character > 0) {
      value_p = (void *)va_arg(*param, int *);
      *(wchar_t *)value_p = w_ch;
      *stchetchik = 1;
    } else {
      value_p = (void *)va_arg(*param, int *);
      *(char *)value_p = (char)ch;
      *stchetchik = 1;
    }
  }

  return count_character;
}

//-------------------------Спецификация f
//----------------------------------------
int get_value_from_str_and_format_for_f(va_list *param,
                                        struct Spec_Format spec_format,
                                        const char **str, short int *stop,
                                        int *stchetchik) {
  int count_character = 0;
  int find = 0;
  int width = 0;
  long double result = 0;

  if (spec_format.width <= 0) {
    width = -1;
  } else {
    width = spec_format.width;
  }
  count_character += reduce_space(str);
  count_character +=
      read_double_cifri_from_str(&result, str, width, &find, stop);

  if (!(spec_format.propusk) && find) {
    void *value_p = NULL;

    if (spec_format.length == 'h') {
      value_p = (void *)va_arg(*param, float *);
      *(float *)value_p = (float)result;

    } else if (spec_format.length == 'l') {
      value_p = (void *)va_arg(*param, double *);
      *(double *)value_p = (double)result;

    } else if (spec_format.length == 'L') {
      value_p = (void *)va_arg(*param, long double *);
      *(long double *)value_p = result;

    } else {
      value_p = (void *)va_arg(*param, float *);
      *(float *)value_p = (float)result;
    }

    *stchetchik = 1;
  }

  return count_character;
}

int read_double_cifri_from_str(long double *result, const char **str, int width,
                               int *find, short int *stop) {
  char number_One[5120] = "";
  char number_Two[5120] = "";
  int sign_minus = 0;
  int count_character = 0;
  int exp = 0;
  int find_inf = 0;

  if (**str == '-') {
    sign_minus = 1;
    *str += 1;
    width -= 1;
    count_character += 1;
  } else if (**str == '+') {
    *str += 1;
    width -= 1;
    count_character += 1;
  }

  if (s21_strncmp(*str, "nan", 3) == 0 && (width >= 3 || width < 0)) {
    count_character += 3;
    *str += 3;
    find_inf = 1;
    *result = (0.0 / 0.0);
    *result = -(*result);
    *find = 1;

  } else if ((s21_strncmp(*str, "inf", 3) == 0 && (width >= 3 || width < 0))) {
    count_character += 3;
    *str += 3;
    find_inf = 1;
    *result = 1.0 / 0.0;
    *find = 1;
  }

  int stop_in = 0;
  int stop_convert = 0;
  if (find_inf) {
    stop_in = 1;
    stop_convert = 1;
  }

  //число до точки
  if (!stop_in) {
    count_character += read_str_One_cifri_from_str(str, &width, number_One);
  }

  if (**str == '.') {
    *str += 1;
    width -= 1;
    count_character += 1;
  }

  //число после точки
  if (!stop_in) {
    count_character += read_str_Two_cifri_from_str(str, &width, number_Two);
  }
  if (!stop_in) {
    if (s21_strlen(number_One) == 0 && s21_strlen(number_Two) == 0) {
      stop_in = 1;
      stop_convert = 1;
      *stop = 1;
    }
  }

  if (!stop_in) {
    if (**str == 'e' || **str == 'E') {
      *str += 1;
      width -= 1;
      count_character += 1;
    } else {
      stop_in = 1;
    }
  }

  //Определяем экспоненту
  if (!stop_in) {
    int sign_minus_e = 0;
    if (**str == '-') {
      sign_minus_e = 1;
      *str += 1;
      width -= 1;
      count_character += 1;
    } else if (**str == '+') {
      *str += 1;
      width -= 1;
      count_character += 1;
    }

    if (**str >= '0' && **str <= '9') {
      while (**str >= '0' && **str <= '9' && width != 0) {
        exp = exp * 10 + (**str - '0');
        *str += 1;
        width -= 1;
        count_character += 1;
      }
    }
    if (sign_minus_e) {
      exp = -exp;
    }
  }

  if (!(stop_convert)) {
    convert_final_double(result, number_One, number_Two, exp);
    *find = 1;
  }

  if (sign_minus) {
    *result = -(*result);
  }

  return count_character;
}

int read_str_One_cifri_from_str(const char **str, int *width,
                                char *number_One) {
  int count_character = 0;
  int zero_first_end = 0;
  while (**str >= '0' && **str <= '9' && *width != 0) {
    if (**str != '0') {
      zero_first_end = 1;
    }
    if (zero_first_end) {
      *number_One = **str;
      number_One += 1;
    }
    *str += 1;
    *width -= 1;
    count_character += 1;
  }

  *number_One = 0;

  return count_character;
}

int read_str_Two_cifri_from_str(const char **str, int *width,
                                char *number_One) {
  int count_character = 0;

  while (**str >= '0' && **str <= '9' && *width != 0) {
    *number_One = **str;
    number_One += 1;
    *str += 1;
    *width -= 1;
    count_character += 1;
  }

  *number_One = 0;

  return count_character;
}

void convert_final_double(long double *result, char *number_One,
                          char *number_Two, int exp) {
  int significant_number = 19;
  int len = (int)s21_strlen(number_One);
  if (len >= significant_number) {
    number_One[significant_number] = 0;
    exp += (len - significant_number);
  } else if (len > 0) {
    exp -= (significant_number - len);
    s21_strncpy(number_One + len, number_Two, significant_number - len);
    len = (int)s21_strlen(number_One);
    if (len < significant_number) {
      s21_memset(number_One + len, '0', significant_number - len);
      number_One[significant_number] = 0;
    }

  } else {
    while (*number_Two == '0') {
      number_Two += 1;
      exp -= 1;
    }
    exp -= significant_number;
    s21_strncpy(number_One, number_Two, significant_number);
    len = (int)s21_strlen(number_One);
    if (len < significant_number) {
      s21_memset(number_One + len, '0', significant_number - len);
      number_One[significant_number] = 0;
    }
  }

  *result = 0;
  while (*number_One >= '0' && *number_One <= '9') {
    *result = (*result) * 10 + (*number_One - '0');
    ;
    number_One += 1;
  }

  *result = change_double_for_int_sscanf(*result, exp);
}

long double change_double_for_int_sscanf(long double long_number,
                                         int multiply_ont_ten) {
  long double double_for_int_operation = long_number;

  while (multiply_ont_ten > 0) {
    double_for_int_operation = double_for_int_operation * 10.0;
    multiply_ont_ten -= 1;
  }
  while (multiply_ont_ten < 0) {
    double_for_int_operation = double_for_int_operation / 10.0;
    multiply_ont_ten += 1;
  }
  return double_for_int_operation;
}

//-------------------------Спецификация d
//----------------------------------------
int get_value_from_str_and_format_for_d(va_list *param,
                                        struct Spec_Format spec_format,
                                        const char **str, short int *stop,
                                        int *stchetchik) {
  int count_character = 0;

  int find = 1;
  int width = 0;
  long int result = 0;
  int sign_minus = 0;
  if (spec_format.width <= 0) {
    width = -1;
  } else {
    width = spec_format.width;
  }
  count_character += reduce_space(str);
  count_character +=
      read_cifri_from_str(&result, str, stop, width, &sign_minus, &find);

  if (!(spec_format.propusk) && find) {
    void *value_p = NULL;
    if (spec_format.length == 'h') {
      value_p = (void *)va_arg(*param, short int *);
      *(short int *)value_p = (short int)result;
    } else if (spec_format.length == 'l') {
      value_p = (void *)va_arg(*param, long int *);
      *(long int *)value_p = (long int)result;
    } else {
      value_p = (void *)va_arg(*param, int *);
      *(int *)value_p = (int)result;
      /*
      if (sign_minus){
          *(int*)value_p = (int) result;
      }else{
          *(int*)value_p = (int) result;
      }
      */
    }

    *stchetchik = 1;
  }

  return count_character;
}

int read_cifri_from_str(long int *result, const char **str, short int *stop,
                        int width, int *sign_minus, int *find) {
  int count_character = 0;
  int sign_m = 1;

  if (**str == '-') {
    sign_m = -1;
    *sign_minus = 1;
    *str += 1;
    width -= 1;
    count_character += 1;
  } else if (**str == '+') {
    *str += 1;
    width -= 1;
    count_character += 1;
  }

  if (**str >= '0' && **str <= '9') {
    *result = 0;
    while (**str >= '0' && **str <= '9' && width != 0) {
      if (((*result) > (*result) * 10 + sign_m * (**str - '0')) &&
          !(*sign_minus)) {
        //переполнение
        *result = -1;
        width = 1;
        *stop = 1;
      } else if (((*result) < (*result) * 10 + sign_m * (**str - '0')) &&
                 (*sign_minus)) {
        *result = 0;
        width = 1;
        *stop = 1;
      } else {
        *result = (*result) * 10 + sign_m * (**str - '0');
      }
      count_character += 1;
      *str += 1;
      width -= 1;
    }
  } else {
    *find = 0;
    *stop = 1;
  }
  return count_character;
}

int reduce_space(const char **str) {
  int count_character = 0;
  while (!is_not_white_space(str)) {
    *str += 1;
    count_character += 1;
  }
  return count_character;
}
//-------------------------Спецификация p
//----------------------------------------
int get_value_from_str_and_format_for_p(va_list *param,
                                        struct Spec_Format spec_format,
                                        const char **str, short int *stop,
                                        int *stchetchik) {
  int count_character = 0;
  int find = 1;
  int width = 0;
  unsigned long long int result = 0;
  int sign_minus = 0;
  if (spec_format.width <= 0) {
    width = -1;
  } else {
    width = spec_format.width;
  }
  count_character += reduce_space(str);
  count_character +=
      read_cifri_x_from_str(&result, str, stop, width, &sign_minus, &find);

  if (!(spec_format.propusk) && find) {
    if (sign_minus) {
      result = result * (-1);
    }

    unsigned long int **value_p = va_arg(*param, unsigned long int **);
    *value_p = (unsigned long int *)result;
    *stchetchik = 1;
  }

  return count_character;
}

//-------------------------Спецификация u
//----------------------------------------
int get_value_from_str_and_format_for_u(va_list *param,
                                        struct Spec_Format spec_format,
                                        const char **str, short int *stop,
                                        int *stchetchik) {
  int count_character = 0;
  int find = 1;
  int width = 0;
  unsigned long long int result = 0;
  int sign_minus = 0;
  if (spec_format.width <= 0) {
    width = -1;
  } else {
    width = spec_format.width;
  }
  count_character += reduce_space(str);

  if (spec_format.specifecator == 'o') {
    count_character +=
        read_cifri_o_from_str(&result, str, stop, width, &sign_minus, &find);
  }
  if (spec_format.specifecator == 'x' || spec_format.specifecator == 'X') {
    count_character +=
        read_cifri_x_from_str(&result, str, stop, width, &sign_minus, &find);
  }
  if (spec_format.specifecator == 'u') {
    count_character +=
        read_cifri_u_from_str(&result, str, stop, width, &sign_minus, &find);
  }
  if (spec_format.specifecator == 'i') {
    if (**str == '0') {
      if (*(*str + 1) == 'x') {
        count_character += read_cifri_x_from_str(&result, str, stop, width,
                                                 &sign_minus, &find);
      } else {
        count_character += read_cifri_o_from_str(&result, str, stop, width,
                                                 &sign_minus, &find);
      }
    } else {
      count_character +=
          read_cifri_u_from_str(&result, str, stop, width, &sign_minus, &find);
    }
  }

  if (!(spec_format.propusk) && find) {
    void *value_p = NULL;

    if (sign_minus) {
      result = result * (-1);
    }

    if (spec_format.length == 'h') {
      value_p = (void *)va_arg(*param, unsigned short int *);
      *(unsigned short int *)value_p = (unsigned short int)result;

    } else if (spec_format.length == 'l') {
      value_p = (void *)va_arg(*param, unsigned long int *);
      *(unsigned long int *)value_p = (unsigned long int)result;

    } else {
      value_p = (void *)va_arg(*param, unsigned int *);
      *(unsigned int *)value_p = (unsigned int)result;
    }

    *stchetchik = 1;
  }

  return count_character;
}

int read_cifri_u_from_str(unsigned long long int *result, const char **str,
                          short int *stop, int width, int *sign_minus,
                          int *find) {
  int count_character = 0;
  if (**str == '-') {
    *sign_minus = 1;
    *str += 1;
    width -= 1;
    count_character += 1;
  } else if (**str == '+') {
    *str += 1;
    width -= 1;
    count_character += 1;
  }

  if (**str >= '0' && **str <= '9') {
    *result = 0;
    while (**str >= '0' && **str <= '9' && width != 0) {
      if (((*result) > (*result) * 10 + (**str - '0'))) {
        //переполнение
        *result = -1;
        width = 1;
        *stop = 1;
        *sign_minus = 0;

      } else {
        *result = (*result) * 10 + (**str - '0');
      }
      *str += 1;
      width -= 1;
      count_character += 1;
    }
  } else {
    *find = 0;
    *stop = 1;
  }
  return count_character;
}
