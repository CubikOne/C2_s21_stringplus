#include "s21_string.h"

#define LEN_STR 5024
#define LEN_STR_TYPE 1024
#define LEN_STR_FOR_LU 1024
#define LEN_STR_FOR_LD 5120

//Основная функция
int s21_sprintf(char *str, const char *format, ...) {
  long int stchetchik = 0;
  long int len_of_part = 0;
  short int stop = 0;
  va_list param;
  va_start(param, format);

  if (str == S21_NULL || format == NULL) {
    stop = 1;
    stchetchik = -1;
  }
  while (!stop) {
    //обнуляем
    struct Spec_Format spec_format = {0, 0, 0, 0, 0, -1, -1, 0, 0, 0};
    //копируем, обрабатываем, находим  %,%%,\0
    copy_while_not_find_mark_format_start_or_end(&str, &format, &stchetchik,
                                                 &stop);
    if (!stop) {
      char *str_to_add_from_param = (char *)calloc(LEN_STR, sizeof(char));

      //собираем флаги проверяем на корректность, если * меняем, считываем
      short int error_options =
          get_options(&format, str_to_add_from_param, &param, &spec_format);
      if (!error_options) {
        //Если флаги и спеки считаны нормально, начинаем считывать и
        //обрабатывать значение из переменной
        len_of_part = get_str_from_value_global(
            &param, spec_format, str_to_add_from_param, stchetchik);
      }
      if (error_options && stchetchik == 0 && *format == 0) {
        //один из случаев ошибки
        stop = 1;
        stchetchik = -1;
      } else if (len_of_part < 0) {
        stop = 1;
        stchetchik = -1;

      } else {
        //Добавляем то что получили в финальную строку
        s21_size_t len_str = s21_strlen(str_to_add_from_param);
        if (spec_format.specifecator == 'c') {
          len_str = len_of_part;
        }
        str = s21_strncpy(str, str_to_add_from_param, len_str);
        str += len_str;
        stchetchik += len_str;
      }

      free(str_to_add_from_param);
    }
  }
  *str = 0;
  va_end(param);
  return stchetchik;
}

//идем по строке
//считываем----------------------------------------------------------
void copy_while_not_find_mark_format_start_or_end(char **str,
                                                  const char **format,
                                                  long int *stchetchik,
                                                  short int *stop_out) {
  int stop_in = 0;

  while (**format != 0 && !stop_in) {
    if (**format == '%') {
      if (*(*format + 1) == '%') {
        *stchetchik += 1;
        **str = **format;
        *str += 1;
        *format += 2;
      } else {
        stop_in = 1;
      }
    } else {
      *stchetchik += 1;
      **str = **format;
      *str += 1;
      *format += 1;
    }
  }
  if (**format == 0) {
    *stop_out = 1;
  }
  **str = 0;
}

//-----------------------------------------------------------------

//-------------------------------------Сборщик модификаторов, флагов и
//спцификаций-------------------------------------------------
short int get_options(const char **format, char *str_to_add_from_param,
                      va_list *param, struct Spec_Format *spec_format) {
  short int error_options = 0;
  short int stop = 0;
  short int search_flag = 1;
  short int search_width = 1;
  short int search_accuracy = 1;
  short int search_length = 1;
  short int search_specifacators = 1;

  *str_to_add_from_param = **format;
  str_to_add_from_param += 1;
  *format += 1;

  // нужен для перетасовки флагов при неправильном наборе
  char *str_to_add_from_param_start = str_to_add_from_param;

  while (!stop) {
    short int result_search = 0;

    if (search_flag && !result_search) {
      result_search = is_it_the_flag_in_format(format, spec_format);
      if (result_search) {
        str_to_add_from_param =
            add_flag_spec(str_to_add_from_param_start, spec_format);
        *format += 1;
      }
    }

    if (search_width && !result_search) {
      result_search = is_it_the_width_in_format(format, &str_to_add_from_param,
                                                param, spec_format);
      if (result_search) {
        search_flag = 0;
        search_width = 0;
      }
    }
    if (search_accuracy && !result_search) {
      result_search = is_it_the_accuracy_in_format(
          format, &str_to_add_from_param, param, spec_format);
      if (result_search) {
        search_flag = 0;
        search_width = 0;
        search_accuracy = 0;
      }
    }
    if (search_length && !result_search) {
      result_search = is_it_the_length_in_format(format, spec_format);
      if (result_search) {
        *format += 1;
        search_flag = 0;
        search_width = 0;
        search_accuracy = 0;
        search_length = 0;
      }
    }
    if (search_specifacators && !result_search) {
      result_search = is_it_the_specifacators_in_format(format, spec_format);
      if (result_search) {
        *str_to_add_from_param = **format;
        str_to_add_from_param += 1;
        *format += 1;
        search_flag = 0;
        search_width = 0;
        search_accuracy = 0;
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
  *str_to_add_from_param = 0;
  return error_options;
}

//строка заполняется на случай некорректного ввода формата
char *add_flag_spec(char *str_to_add_from_param_start,
                    struct Spec_Format *spec_format) {
  if (spec_format->flag_reshetka) {
    *str_to_add_from_param_start = '#';
    str_to_add_from_param_start += 1;
  }
  if (spec_format->flag_plus) {
    *str_to_add_from_param_start = '+';
    str_to_add_from_param_start += 1;

  } else if (spec_format->flag_space) {
    *str_to_add_from_param_start = ' ';
    str_to_add_from_param_start += 1;
  }
  if (spec_format->flag_left) {
    *str_to_add_from_param_start = '-';
    str_to_add_from_param_start += 1;

  } else if (spec_format->flag_zero) {
    *str_to_add_from_param_start = '0';
    str_to_add_from_param_start += 1;
  }

  return str_to_add_from_param_start;
}

//---------------------------------Функции для считывания модификаторов
//форматирования----------------------------- Спецификаторы
short int is_it_the_specifacators_in_format(const char **format,
                                            struct Spec_Format *spec_format) {
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
    // i и d идентичны
    spec_format->specifecator = 'd';
    result_search = 1;
  }
  if (**format == 'c') {
    spec_format->specifecator = 'c';
    result_search = 1;
  }
  if (**format == 's') {
    spec_format->specifecator = 's';
    result_search = 1;
  }
  if (**format == 'f') {
    spec_format->specifecator = 'f';
    result_search = 1;
  }
  if (**format == 'e') {
    spec_format->specifecator = 'e';
    result_search = 1;
  }
  if (**format == 'E') {
    spec_format->specifecator = 'E';
    result_search = 1;
  }
  if (**format == 'g') {
    spec_format->specifecator = 'g';
    result_search = 1;
  }
  if (**format == 'G') {
    spec_format->specifecator = 'G';
    result_search = 1;
  }
  if (**format == 'x') {
    spec_format->specifecator = 'x';
    result_search = 1;
  }
  if (**format == 'X') {
    spec_format->specifecator = 'X';
    result_search = 1;
  }
  if (**format == 'o') {
    spec_format->specifecator = 'o';
    result_search = 1;
  }
  if (**format == 'n') {
    spec_format->specifecator = 'n';
    result_search = 1;
  }
  if (**format == 'p') {
    spec_format->specifecator = 'p';
    result_search = 1;
  }
  return result_search;
}

//Длина
short int is_it_the_length_in_format(const char **format,
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
//Точность
short int is_it_the_accuracy_in_format(const char **format,
                                       char **str_to_add_from_param,
                                       va_list *param,
                                       struct Spec_Format *spec_format) {
  short int result_search = 0;
  if (**format == '.') {
    //запись точки
    **str_to_add_from_param = **format;
    *str_to_add_from_param += 1;
    *format += 1;
    if (**format == '*') {
      long long int value_from_arg = va_arg(*param, long long int);
      char str_from_arg[LEN_STR_FOR_LU] = "";
      int_to_str_simple(str_from_arg, value_from_arg);
      if (value_from_arg >= 0) {
        s21_strncpy(*str_to_add_from_param, str_from_arg,
                    s21_strlen(str_from_arg));
        *str_to_add_from_param += s21_strlen(str_from_arg);

        spec_format->accuracy = value_from_arg;
        result_search = 1;

      } else {
        //удаляем записанную точку
        *str_to_add_from_param -= 1;
        **str_to_add_from_param = 0;
      }
      *format += 1;
    } else if (**format >= '0' && **format <= '9') {
      spec_format->accuracy = 0;
      while (**format >= '0' && **format <= '9') {
        **str_to_add_from_param = **format;
        *str_to_add_from_param += 1;
        spec_format->accuracy = (spec_format->accuracy) * 10 + **format - '0';
        *format += 1;
      }
      result_search = 1;
    } else {
      // случай когда только одна точка
      **str_to_add_from_param = '0';
      *str_to_add_from_param += 1;
      spec_format->accuracy = 0;
      result_search = 1;
    }
  }

  return result_search;
}
//Ширина
short int is_it_the_width_in_format(const char **format,
                                    char **str_to_add_from_param,
                                    va_list *param,
                                    struct Spec_Format *spec_format) {
  short int result_search = 0;
  if (**format == '*') {
    long long int value_from_arg = va_arg(*param, long long int);
    char str_from_arg[LEN_STR_FOR_LU] = "";
    int_to_str_simple(str_from_arg, value_from_arg);
    if (value_from_arg < 0) {
      //запись числа
      s21_strncpy(*str_to_add_from_param, str_from_arg,
                  s21_strlen(str_from_arg));
      *str_to_add_from_param += s21_strlen(str_from_arg);
      spec_format->width = -value_from_arg;
      spec_format->flag_left = 1;
      result_search = 1;
    } else if (value_from_arg > 0) {
      s21_strncpy(*str_to_add_from_param, str_from_arg,
                  s21_strlen(str_from_arg));
      *str_to_add_from_param += s21_strlen(str_from_arg);

      spec_format->width = value_from_arg;
      result_search = 1;
    } else {
      result_search = 1;
    }
    *format += 1;
    result_search = 1;
  } else if (**format > '0' && **format <= '9') {
    spec_format->width = 0;
    while (**format >= '0' && **format <= '9') {
      **str_to_add_from_param = **format;
      *str_to_add_from_param += 1;
      spec_format->width = (spec_format->width) * 10 + **format - '0';
      *format += 1;
    }
    result_search = 1;
  }

  return result_search;
}
//Флаги
short int is_it_the_flag_in_format(const char **format,
                                   struct Spec_Format *spec_format) {
  short int result_search = 0;
  if (**format == ' ') {
    spec_format->flag_space = 1;
    result_search = 1;
  }
  if (**format == '-') {
    spec_format->flag_left = 1;
    result_search = 1;
  }
  if (**format == '+') {
    spec_format->flag_plus = 1;
    result_search = 1;
  }
  if (**format == '0') {
    spec_format->flag_zero = 1;
    result_search = 1;
  }
  if (**format == '#') {
    spec_format->flag_reshetka = 1;
    result_search = 1;
  }
  return result_search;
}
//---------------------------------------------------------------------------------------------

//-----------------------------------------Обрабатываем
//спецификаторы----------------------------------------------
long int get_str_from_value_global(va_list *param,
                                   struct Spec_Format spec_format,
                                   char *str_to_add_from_param,
                                   long int schetchik_otvet) {
  long int schetchik = 0;

  if (spec_format.specifecator == 'd' || spec_format.specifecator == 'i') {
    get_value_from_arg_and_format_for_d(param, spec_format,
                                        str_to_add_from_param);
  }
  if (spec_format.specifecator == 'u') {
    get_value_from_arg_and_format_for_u(param, spec_format,
                                        str_to_add_from_param);
  }
  if (spec_format.specifecator == 'c') {
    schetchik = get_value_from_arg_and_format_for_c(param, spec_format,
                                                    str_to_add_from_param);
  }
  if (spec_format.specifecator == 's') {
    schetchik = get_value_from_arg_and_format_for_s(param, spec_format,
                                                    str_to_add_from_param);
  }
  if (spec_format.specifecator == 'f') {
    get_value_from_arg_and_format_for_f(param, spec_format,
                                        str_to_add_from_param);
  }
  if (spec_format.specifecator == 'e' || spec_format.specifecator == 'E') {
    get_value_from_arg_and_format_for_f(param, spec_format,
                                        str_to_add_from_param);
  }
  if (spec_format.specifecator == 'g' || spec_format.specifecator == 'G') {
    get_value_from_arg_and_format_for_f(param, spec_format,
                                        str_to_add_from_param);
  }
  if (spec_format.specifecator == 'x' || spec_format.specifecator == 'X') {
    get_value_from_arg_and_format_for_u(param, spec_format,
                                        str_to_add_from_param);
  }
  if (spec_format.specifecator == 'o' || spec_format.specifecator == 'p') {
    get_value_from_arg_and_format_for_u(param, spec_format,
                                        str_to_add_from_param);
  }
  if (spec_format.specifecator == 'n') {
    get_value_from_arg_and_format_for_n(param, str_to_add_from_param,
                                        schetchik_otvet);
  }
  return schetchik;
}

//------------------------------------------------------Обработка n
//------------------------------
short int get_value_from_arg_and_format_for_n(va_list *param,
                                              char *str_to_add_from_param,
                                              long int schetchik_otvet) {
  int *value_u_p = va_arg(*param, int *);
  *value_u_p = (int)schetchik_otvet;
  *str_to_add_from_param = 0;

  return 0;
}

//------------------------------------------------------Обработка x
//------------------------------ принимает unsigned long long int  возвращает
//строку ,перевод чисел в строку в перевернутом виде
short int represent_int_to_x(char *str_to_add_from_param,
                             unsigned long long int value_d, int flag_x) {
  int dop = 0;
  int ch = 0;
  int i = 0;
  int del = 16;
  if (flag_x == 1) {
    dop = 32;
  } else if (flag_x == 2) {
    del = 8;
  }

  while ((value_d / del) != 0) {
    if (value_d % del >= 10) {
      ch = 'a' + (value_d % del - 10) - dop;
    } else {
      ch = '0' + (value_d % del);
    }
    str_to_add_from_param[i] = ch;
    value_d = value_d / del;
    i += 1;
  }

  if (value_d != 0) {
    if (value_d % del >= 10) {
      ch = 'a' + (value_d % del - 10) - dop;
    } else {
      ch = '0' + (value_d % del);
    }
    str_to_add_from_param[i] = ch;
    value_d = value_d / del;
    i += 1;
  }

  str_to_add_from_param[i] = 0;

  return 0;
}
//------------------------------------------------------Обработка e
//------------------------------

// преобразует строки так чтобы 1 цифра была в number_One и возвращает на какую
// степень произошло смещение
int rebalnced_double_number(char *number_One, char *number_Two) {
  int exp = 0;
  char number_Tmp[LEN_STR_FOR_LD] = "";

  if (s21_strlen(number_One) > 1) {
    s21_strncpy(number_Tmp, number_Two, s21_strlen(number_Two));
    exp = s21_strlen(number_One) - 1;
    s21_strncpy(number_Two, number_One + 1, s21_strlen(number_One));
    number_One[1] = 0;
    s21_strncat(number_Two, number_Tmp, s21_strlen(number_Tmp));
  } else if (s21_strlen(number_One) == 1 && number_One[0] == '0') {
    s21_strncpy(number_Tmp, number_Two, s21_strlen(number_Two));
    int k = 0;
    while (number_Tmp[k] == '0') {
      k += 1;
    }
    if (number_Tmp[k] != 0) {
      exp = k + 1;
      number_One[0] = number_Tmp[k];
      number_One[1] = 0;
      s21_strncpy(number_Two, number_Tmp + exp, s21_strlen(number_Tmp + exp));
      exp = -exp;
    }
  }
  return exp;
}
//------------------------------------------------------Обработка f
//------------------------------

//этот код нужен для определенния знака у числа long double!!!!!
union VizionFloat {
  long double asLDouble;
  int asInt[4];
};

int get_sign_of_long_double(long double src) {
  int result = 0;
  union VizionFloat vid;
  vid.asLDouble = src;

  int integer_float = vid.asInt[2];
  result = (int)(integer_float >> 15) & 1;
  return result;
}

long int get_value_from_arg_and_format_for_f(va_list *param,
                                             struct Spec_Format spec_format,
                                             char *str_to_add_from_param) {
  long int schetchik = 0;
  char number_One[LEN_STR_FOR_LD] = "";
  char number_Two[LEN_STR_FOR_LD] = "";
  long double long_number = 0;
  double not_long_number = 0;
  int exp = 0;
  if (spec_format.length == 'L') {
    long_number = va_arg(*param, long double);
  } else {
    not_long_number = va_arg(*param, double);
    long_number = (long double)not_long_number;
  }

  short int sign_minus = 0;

  //Определяем знак long double по значению бита
  if (!isinf(long_number)) {
    if (get_sign_of_long_double(long_number)) {
      long_number = -long_number;
      sign_minus = 1;
    }
  }

  char *number_One_s = number_One;

  if (isnan(long_number)) {
    if (sign_minus) {
      s21_strncpy(number_One, "-", 2);
      number_One_s += 1;
    } else if (spec_format.flag_plus) {
      s21_strncpy(number_One, "+", 2);
      number_One_s += 1;
    } else if (spec_format.flag_space) {
      s21_strncpy(number_One, " ", 2);
      number_One_s += 1;
    }
    if (spec_format.specifecator == 'E' || spec_format.specifecator == 'G') {
      s21_strncpy(number_One_s, "NAN", 4);

    } else {
      s21_strncpy(number_One_s, "nan", 4);
    }
    spec_format.flag_zero = 0;
    spec_format.flag_space = 0;
    spec_format.flag_reshetka = 0;
    spec_format.accuracy = 0;
    spec_format.specifecator = 'f';
    spec_format.accuracy = -1;
    schetchik = formating_string_by_format_for_s(str_to_add_from_param,
                                                 number_One, spec_format);

  } else if (isinf(long_number) || isinf(not_long_number)) {
    if (long_number < 0 || not_long_number < 0) {
      s21_strncpy(number_One, "-", 2);
      number_One_s += 1;
    } else if (spec_format.flag_plus) {
      s21_strncpy(number_One, "+", 2);
      number_One_s += 1;
    } else if (spec_format.flag_space) {
      s21_strncpy(number_One, " ", 2);
      number_One_s += 1;
    }
    if (spec_format.specifecator == 'E' || spec_format.specifecator == 'G') {
      s21_strncpy(number_One_s, "INF", 4);
    } else {
      s21_strncpy(number_One_s, "inf", 4);
    }
    spec_format.specifecator = 'f';
    spec_format.flag_zero = 0;
    spec_format.flag_space = 0;
    spec_format.flag_reshetka = 0;
    spec_format.accuracy = 0;
    spec_format.accuracy = -1;

    schetchik = formating_string_by_format_for_s(str_to_add_from_param,
                                                 number_One, spec_format);
  } else {
    get_two_string_from_double(number_One, number_Two, long_number);
    schetchik =
        formating_two_string_for_f(str_to_add_from_param, spec_format,
                                   number_One, number_Two, sign_minus, exp);
  }
  return schetchik;
}

// обрбатывает только положительный long_number!
void get_two_string_from_double(char *number_One, char *number_Two,
                                long double long_number) {
  /*
   *
   * double
   * min 2.225073858507201e-308         16 цифр
   * max 1.797693134862316e+308
   *
   * long double
   * min 3.3621031431120935063e-4932     20 цифр
   * max 1.189731495357231765e+4932      19 цифр
   *
   * long long
   * min -9223372036854775808            19 цифр
   * max  9223372036854775807
   *
   * unsigned long long
   * max 18446744073709551615           20 цифр
   */
  int significant_number = 19;

  int count_of_ciphra = get_c_of_ciphra_in_number_before_dot(long_number);

  int multiply_ont_ten = significant_number - count_of_ciphra;
  long double double_for_int_operation =
      change_double_for_int(long_number, multiply_ont_ten);
  unsigned long long int int_toconvert =
      (unsigned long long int)double_for_int_operation;

  represent_int_to_str(number_Two, int_toconvert);
  revers_string(number_One, number_Two);

  if (count_of_ciphra >= significant_number) {
    s21_memset(number_One + significant_number, '0',
               (count_of_ciphra - significant_number));
    number_One[count_of_ciphra] = 0;
    number_Two[0] = 0;
  } else if (count_of_ciphra <= 0) {
    s21_memset(number_Two, '0', (-count_of_ciphra));
    s21_strncpy(number_Two + (-count_of_ciphra), number_One,
                significant_number);
    number_Two[-count_of_ciphra + significant_number] = 0;
    number_One[0] = '0';
    number_One[1] = 0;
  } else {
    s21_strncpy(number_Two, number_One + count_of_ciphra,
                significant_number - count_of_ciphra);

    number_Two[significant_number - count_of_ciphra] = 0;
    number_One[count_of_ciphra] = 0;
  }
}

long double change_double_for_int(long double long_number,
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

long int formating_two_string_for_f(char *str_to_add_from_param,
                                    struct Spec_Format spec_format,
                                    char *number_One, char *number_Two,
                                    short int sign_minus, int exp) {
  long int schetchik = 0;
  long int sign = 0;
  long int accuracy = 0;
  int reduce_last_zero = 0;

  //При указание точности flag_zero обнуляется
  if (spec_format.flag_left) {
    spec_format.flag_zero = 0;
  }
  //разбираемся с
  //точностью------------------------------------------------------
  if (spec_format.accuracy <= -1) {
    accuracy = 6;
  } else {
    accuracy = spec_format.accuracy;
  }
  // Переопределения на случай G
  if (spec_format.specifecator == 'g' || spec_format.specifecator == 'G') {
    if (!(spec_format.flag_reshetka)) {
      reduce_last_zero = 1;
    }
    if (accuracy == 0) {
      accuracy = 1;
    }
    if (s21_strlen(number_One) > 1 ||
        (s21_strlen(number_One) == 1 && number_One[0] != '0')) {
      if ((long int)s21_strlen(number_One) > accuracy) {
        accuracy -= 1;
        if (spec_format.specifecator == 'g') {
          spec_format.specifecator = 'e';
        }
        if (spec_format.specifecator == 'G') {
          spec_format.specifecator = 'E';
        }
      } else {
        accuracy = accuracy - s21_strlen(number_One);
      }
    } else {
      int k = 0;
      while (number_Two[k] == '0') {
        k += 1;
      }
      if (number_Two[k] != 0) {
        accuracy += k;
      } else {
        accuracy -= 1;
      }
    }
  }

  if (spec_format.specifecator == 'e' || spec_format.specifecator == 'E') {
    exp = rebalnced_double_number(number_One, number_Two);
  }
  //форматирование по точности
  format_double_by_accuracy(number_One, number_Two, accuracy);
  //ребалансировка при E
  if (spec_format.specifecator == 'e' || spec_format.specifecator == 'E') {
    int exp_dop = rebalnced_double_number(number_One, number_Two);
    exp += exp_dop;
    //форматирование по точности второй раз
    format_double_by_accuracy(number_One, number_Two, accuracy);
  }
  //удаление незначащих последних нулей при спеке G
  if (reduce_last_zero) {
    reduce_zero(number_Two);
  }
  //соединяем
  concat_two_str(number_One, number_Two, spec_format, exp);
  //переворачиваем
  revers_string(number_Two, number_One);

  //добавляем нули для ширины если нужно---------------------------------------
  if (sign_minus || spec_format.flag_space || spec_format.flag_plus) {
    sign = 1;
  }
  if (spec_format.flag_zero) {
    long int len_str = (long int)s21_strlen(number_Two);
    if (spec_format.width > (len_str + sign)) {
      s21_memset(number_Two + len_str, '0',
                 (spec_format.width - (len_str + sign)));
      number_Two[len_str + (spec_format.width - (len_str + sign))] = 0;
    }
  }
  //Добавляем знак--------------------------------------------------------
  add_sign(spec_format, number_Two, sign_minus);
  //переворачиваем
  revers_string(number_One, number_Two);
  //обрбатываем по ширине и выравнивание по нужному краю-----------------
  format_by_width(str_to_add_from_param, spec_format, number_One);

  return schetchik;
}

void reduce_zero(char *number_Two) {
  long int len = (long int)s21_strlen(number_Two) - 1;

  while (len >= 0 && number_Two[len] == '0') {
    number_Two[len] = 0;
    len -= 1;
  }
}

void concat_two_str(char *number_One, char *number_Two,
                    struct Spec_Format spec_format, int exp) {
  if (s21_strlen(number_Two) == 0) {
    if (spec_format.flag_reshetka) {
      number_One[(s21_strlen(number_One) + 1)] = 0;
      number_One[s21_strlen(number_One)] = '.';
    }
  } else {
    number_One[(s21_strlen(number_One) + 1)] = 0;
    number_One[s21_strlen(number_One)] = '.';
    s21_strncat(number_One, number_Two, s21_strlen(number_Two));
  }
  if (spec_format.specifecator == 'e') {
    s21_strncat(number_One, "e", 1);
  }
  if (spec_format.specifecator == 'E') {
    s21_strncat(number_One, "E", 1);
  }
  if (spec_format.specifecator == 'e' || spec_format.specifecator == 'E') {
    if (exp < 0) {
      s21_strncat(number_One, "-", 1);
      exp = -exp;
    } else {
      s21_strncat(number_One, "+", 1);
    }
    if (exp < 10) {
      s21_strncat(number_One, "0", 1);
    }
    int_to_str_simple(number_Two, (long long int)exp);
    s21_strncat(number_One, number_Two, s21_strlen(number_Two));
  }
}

short int add_perenos_to_str(char *number_Two, short int perenos) {
  long int len_str = (long int)s21_strlen(number_Two);
  while (len_str > 0 && perenos) {
    if (number_Two[len_str - 1] == '9') {
      number_Two[len_str - 1] = '0';
      perenos = 1;
    } else {
      number_Two[len_str - 1] += 1;
      perenos = 0;
    }
    len_str -= 1;
  }

  return perenos;
}
//Добавляем новый разряд в первую половину числа
short int add_inter_perenos_to_str(char *number_One, short int perenos) {
  if (perenos) {
    char number_Tmp[LEN_STR_FOR_LD] = "";
    s21_strncpy(number_Tmp, number_One, s21_strlen(number_One) + 1);
    number_One[0] = '1';
    number_One += 1;
    s21_strncpy(number_One, number_Tmp, s21_strlen(number_Tmp) + 1);
  }
  return 0;
}

short int is_chetnoe(char ch) {
  short int result = 0;
  if (ch == '0' || ch == '2' || ch == '4' || ch == '6' || ch == '8') {
    result = 1;
  }

  return result;
}

// форматируем два числа спецификацмм f по точности
void format_double_by_accuracy(char *number_One, char *number_Two,
                               long int accuracy) {
  short int perenos = 0;
  long int len_str = (long int)s21_strlen(number_Two);
  if (accuracy >= len_str) {
    s21_memset(number_Two + len_str, '0', accuracy - len_str);
    number_Two[accuracy] = 0;
  } else {
    //Первая часть
    if (number_Two[len_str - 1] < '5') {
      perenos = 0;
    } else if (number_Two[len_str - 1] > '5') {
      perenos = 1;
    } else {
      if ((len_str - 1) == 0) {
        //берем данные из number_One
        if (is_chetnoe(number_One[s21_strlen(number_One) - 1])) {
          perenos = 0;
        } else {
          perenos = 1;
        }
      } else {
        if (is_chetnoe(number_Two[len_str - 2])) {
          perenos = 0;
        } else {
          perenos = 1;
        }
      }
    }

    number_Two[len_str - 1] = 0;
    len_str -= 1;
    if (perenos) {
      perenos = add_perenos_to_str(number_Two, perenos);
      perenos = add_perenos_to_str(number_One, perenos);
      add_inter_perenos_to_str(number_One, perenos);
    }
    //Вторая часть
    perenos = 0;
    if (number_Two[accuracy] < '5') {
      perenos = 0;
    } else if (number_Two[accuracy] > '5') {
      perenos = 1;
    } else {
      short int stop = 0;
      long int accuracy_tmp = accuracy;
      while (!stop && accuracy_tmp != len_str) {
        if (number_Two[accuracy_tmp] > '0') {
          perenos = 1;
          stop = 1;
        } else {
          accuracy_tmp += 1;
        }
      }
      if (!stop) {
        if ((accuracy) == 0) {
          //берем данные из number_One
          if (is_chetnoe(number_One[s21_strlen(number_One) - 1])) {
            perenos = 0;
          } else {
            perenos = 1;
          }
        } else {
          if (is_chetnoe(number_Two[accuracy - 1])) {
            perenos = 0;
          } else {
            perenos = 1;
          }
        }
      }
    }
    number_Two[accuracy] = 0;
    if (perenos) {
      perenos = add_perenos_to_str(number_Two, perenos);
      perenos = add_perenos_to_str(number_One, perenos);
      add_inter_perenos_to_str(number_One, perenos);
    }
  }
}

//количество цифр до или после точки
int get_c_of_ciphra_in_number_before_dot(long double x) {
  int res = 0;

  if (isfinite(x)) {
    if (fabsl(x) >= 1.0) {
      while (fabsl(x) >= 1.0) {
        res += 1;
        x = x / 10.0;
      }
    } else if (x == 0.0) {
      res = 0;

    } else if (fabsl(x) < 0.1)

      while (fabsl(x) < 0.1) {
        res -= 1;
        x = x * 10.0;
      }
  }
  return res;
}

//------------------------------------------------------Обработка s
//------------------------------

long int get_value_from_arg_and_format_for_s(va_list *param,
                                             struct Spec_Format spec_format,
                                             char *str_to_add_from_param) {
  long int schetchik = 0;
  //решить проблему с объемом под строку для добавления
  wchar_t *array_wchar_t = NULL;
  char *array_char = "";
  //обрабатываем длину
  if (spec_format.length == 'l') {
    array_wchar_t = (wchar_t *)va_arg(*param, int *);
    //обрабатываем строку согласно формату
    schetchik = formating_string_by_format_for_ls(str_to_add_from_param,
                                                  array_wchar_t, spec_format);
  } else {
    array_char = (char *)va_arg(*param, int *);
    //обрабатываем строку согласно формату
    schetchik = formating_string_by_format_for_s(str_to_add_from_param,
                                                 array_char, spec_format);
  }

  return schetchik;
}

long int formating_string_by_format_for_s(char *str_to_add_from_param,
                                          char *array_char,
                                          struct Spec_Format spec_format) {
  long int schetchik = 0;
  s21_size_t len_array = s21_strlen(array_char);

  char *tmp_char_array = (char *)calloc(len_array + 1, sizeof(char));
  s21_strncpy(tmp_char_array, array_char, len_array);
  if (spec_format.accuracy >= 0) {
    if ((s21_size_t)spec_format.accuracy <= len_array) {
      *(tmp_char_array + ((s21_size_t)spec_format.accuracy)) = 0;
    }
  }
  schetchik =
      format_by_width(str_to_add_from_param, spec_format, tmp_char_array);

  free(tmp_char_array);

  return schetchik;
}

long int formating_string_by_format_for_ls(char *str_to_add_from_param,
                                           wchar_t *array_wchar_t,
                                           struct Spec_Format spec_format) {
  long int schetchik = 0;
  char *tmp_char_array =
      (char *)calloc(s21_strlen((char *)array_wchar_t) * 4 + 4, sizeof(char));

  schetchik = convert_wchar_to_char(tmp_char_array, array_wchar_t, spec_format);
  s21_size_t len_array = s21_strlen(tmp_char_array);

  if (spec_format.accuracy >= 0) {
    if ((s21_size_t)spec_format.accuracy <= len_array) {
      *(tmp_char_array + ((s21_size_t)spec_format.accuracy)) = 0;
    }
  }

  schetchik =
      format_by_width(str_to_add_from_param, spec_format, tmp_char_array);

  free(tmp_char_array);
  return schetchik;
}

long int convert_wchar_to_char(char *tmp_char_array, wchar_t *array_wchar_t,
                               struct Spec_Format spec_format) {
  long int schetchik = 0;
  long int len_of_wchar_t = 0;
  //  преобразуем wchar_t в char*

  if (spec_format.length == 'l') {
    while (*array_wchar_t != 0 && schetchik >= 0) {
      char new_char[5] = "";
      len_of_wchar_t = wctomb(new_char, *array_wchar_t);
      if (len_of_wchar_t < 0) {
        schetchik = -1;
      } else {
        s21_strncpy(tmp_char_array, new_char, len_of_wchar_t);
        tmp_char_array += len_of_wchar_t;
        schetchik += len_of_wchar_t;
      }
      array_wchar_t += 1;
    }
  }
  *tmp_char_array = 0;

  return schetchik;
}

//------------------------------------------------------Обработка c
//------------------------------

long int get_value_from_arg_and_format_for_c(va_list *param,
                                             struct Spec_Format spec_format,
                                             char *str_to_add_from_param) {
  long int schetchik = 0;
  wchar_t value_wchar_t = 0;
  //обрабатываем длину
  if (spec_format.specifecator == 'c') {
    if (spec_format.length == 'l') {
      value_wchar_t = (wchar_t)va_arg(*param, int);
    } else {
      value_wchar_t = (unsigned char)va_arg(*param, int);
    }
  }
  //обрабатываем строку согласно формату
  schetchik = formating_string_by_format_for_c(str_to_add_from_param,
                                               value_wchar_t, spec_format);

  return schetchik;
}

long int formating_string_by_format_for_c(char *str_to_add_from_param,
                                          wchar_t wchar_t_from,
                                          struct Spec_Format spec_format) {
  long int schetchik = 0;
  //обрбатываем по ширине и выравнивание по нужному краю-----------------
  schetchik =
      format_by_width_c(str_to_add_from_param, spec_format, wchar_t_from);
  return schetchik;
}

//форматируем по ширине wchar_t входящий
long int format_by_width_c(char *str_to_add_from_param,
                           struct Spec_Format spec_format,
                           wchar_t wchar_t_from) {
  long int schetchik = 0;
  char new_char[4] = "";
  long int len_str = 0;
  // преобразуем wchar_t в char*
  if (spec_format.length == 'l') {
    len_str = wctomb(new_char, wchar_t_from);
  } else {
    new_char[0] = (char)wchar_t_from;
    new_char[1] = 0;
    len_str = 1;
  }
  if (len_str > 0) {
    if (spec_format.flag_left) {
      s21_strncpy(str_to_add_from_param, new_char, len_str);
      str_to_add_from_param += len_str;
      schetchik += len_str;
      if (spec_format.width > len_str) {
        s21_memset(str_to_add_from_param, ' ', (spec_format.width - (len_str)));
        str_to_add_from_param += (spec_format.width - (len_str));
        schetchik += (spec_format.width - len_str);
      }
    } else {
      if (spec_format.width > len_str) {
        s21_memset(str_to_add_from_param, ' ', (spec_format.width - (len_str)));
        str_to_add_from_param += (spec_format.width - (len_str));
        schetchik += (spec_format.width - (len_str));
      }
      s21_strncpy(str_to_add_from_param, new_char, len_str);
      str_to_add_from_param += len_str;
      schetchik += len_str;
    }
  } else {
    schetchik = -1;
  }
  *str_to_add_from_param = 0;
  return schetchik;
}

//------------------------------------------------------Обработка u
//------------------------------

short int get_value_from_arg_and_format_for_u(va_list *param,
                                              struct Spec_Format spec_format,
                                              char *str_to_add_from_param) {
  // Возможно нужно через calloc это делать, но как узнать длину
  char str_from_int[1024] = "";
  unsigned long long int value_u = 0;
  short int sign_minus = 0;

  //обрабатываем длину
  if (spec_format.specifecator == 'u' || spec_format.specifecator == 'x' ||
      spec_format.specifecator == 'X' || spec_format.specifecator == 'o') {
    if (spec_format.length == 'h') {
      value_u = (unsigned short int)va_arg(*param, long long int);
    } else if (spec_format.length == 'l') {
      value_u = (unsigned long long int)va_arg(*param, unsigned long long int);
    } else {
      value_u = (unsigned int)va_arg(*param, long long int);
    }
  } else {
    value_u = (unsigned long int)va_arg(*param, long long int);
  }

  //получаем представление числа в строковой форме(реверсивное)
  if (spec_format.specifecator == 'x') {
    represent_int_to_x(str_from_int, value_u, 0);

  } else if (spec_format.specifecator == 'X') {
    represent_int_to_x(str_from_int, value_u, 1);

  } else if (spec_format.specifecator == 'o') {
    represent_int_to_x(str_from_int, value_u, 2);
    // printf("A str_from_int=%s\n",str_from_int);
  } else if (spec_format.specifecator == 'p') {
    if (value_u == 0.0) {
      s21_strncpy(str_from_int, ")lin(", 6);
      spec_format.flag_reshetka = 0;
      spec_format.flag_space = 0;
      spec_format.flag_plus = 0;
      spec_format.accuracy = 0;
      spec_format.flag_zero = 0;

    } else {
      spec_format.flag_reshetka = 1;

      represent_int_to_x(str_from_int, value_u, 0);
    }

  } else {
    represent_int_to_str(str_from_int, value_u);
  }
  //обрабатываем строку согласно формату
  formating_string_by_format_for_d(str_to_add_from_param, str_from_int,
                                   spec_format, sign_minus);

  return 0;
}

//------------------------------------------------------Обработка d
//------------------------------

short int get_value_from_arg_and_format_for_d(va_list *param,
                                              struct Spec_Format spec_format,
                                              char *str_to_add_from_param) {
  // Возможно нужно через calloc это делать, но как узнать длину
  char str_from_int[1024] = "";
  unsigned long long int value_u = 0;
  long long int value_d = va_arg(*param, long long int);
  short int sign_minus = 0;

  //обрабатываем длину
  if (spec_format.specifecator == 'd') {
    if (spec_format.length == 'h') {
      value_d = (short int)value_d;
    } else if (spec_format.length == 'l') {
      value_d = (long int)value_d;
    } else {
      value_d = (int)value_d;
    }
  }
  if (value_d < 0) {
    value_u = (unsigned long long int)-value_d;
    sign_minus = 1;
  } else {
    value_u = (unsigned long long int)value_d;
  }

  //получаем представление числа в строковой форме(реверсивное)
  represent_int_to_str(str_from_int, value_u);
  //обрабатываем строку согласно формату
  formating_string_by_format_for_d(str_to_add_from_param, str_from_int,
                                   spec_format, sign_minus);

  return 0;
}

short int formating_string_by_format_for_d(char *str_to_add_from_param,
                                           char *str_from_int,
                                           struct Spec_Format spec_format,
                                           short int sign_minus) {
  long int accuracy = 0;
  //если нули при точности добавили то не добавляем префикс 0 при восьмеричной
  //системе
  int nul_add_in_accuracy = 0;
  long int len_str = (long int)s21_strlen(str_from_int);

  char *str_from_int_tmp = str_from_int;

  if (len_str == 0) {
    if (spec_format.specifecator == 'X' || spec_format.specifecator == 'x') {
      spec_format.flag_reshetka = 0;
    }
  }

  if (spec_format.accuracy > -1 || spec_format.flag_left) {
    //При указание точности flag_zero обнуляется
    spec_format.flag_zero = 0;
  }

  //разбираемся с
  //точностью----------------------------------------------------------------
  if (spec_format.accuracy <= -1) {
    accuracy = 1;
  } else {
    accuracy = spec_format.accuracy;
  }
  if (accuracy > len_str) {
    nul_add_in_accuracy = 1;
    str_from_int_tmp = str_from_int_tmp + len_str;
    s21_memset(str_from_int_tmp, '0', (accuracy - len_str));
    str_from_int_tmp = str_from_int_tmp + (accuracy - len_str);
  } else {
    str_from_int_tmp = str_from_int_tmp + len_str;
  }
  *str_from_int_tmp = 0;

  //разбираемся с нулем-флагом--------------------------------------------------
  //есть ли символ знака
  long int sign = 0;
  //количество символов префикса у 16 и 8 ричных системах счисления
  int sign_oX = 0;
  //Преподготовка для нуля-флага в случае со знак-флагом
  //-------------------------------------------------------
  if (spec_format.specifecator != 'u' && spec_format.specifecator != 'x' &&
      spec_format.specifecator != 'X' && spec_format.specifecator != 'o') {
    //при u не печатается знак
    if (sign_minus || spec_format.flag_space || spec_format.flag_plus) {
      sign = 1;
    }
  }
  //Преподготовка для нуля-флага в случае с решеткой
  //-------------------------------------------------------
  if (spec_format.flag_reshetka) {
    if (spec_format.specifecator == 'X' || spec_format.specifecator == 'p') {
      sign_oX = 2;
    } else if (spec_format.specifecator == 'x') {
      sign_oX = 2;
    } else if (spec_format.specifecator == 'o' && !nul_add_in_accuracy) {
      sign_oX = 1;
    }
  }
  //Добавление нулей с
  //нулем-флагом--------------------------------------------------
  if (spec_format.flag_zero) {
    len_str = (long int)s21_strlen(str_from_int);
    if (spec_format.width > (len_str + sign + sign_oX)) {
      s21_memset(str_from_int_tmp, '0',
                 (spec_format.width - (len_str + sign + sign_oX)));
      str_from_int_tmp =
          str_from_int_tmp + (spec_format.width - (len_str + sign + sign_oX));
    }
    *str_from_int_tmp = 0;
  }

  //Случай с решеткой-------------------------------------------------------
  if (spec_format.flag_reshetka) {
    if (spec_format.specifecator == 'X') {
      str_from_int_tmp[0] = 'X';
      str_from_int_tmp[1] = '0';
      str_from_int_tmp += 2;
    } else if (spec_format.specifecator == 'x' ||
               spec_format.specifecator == 'p') {
      str_from_int_tmp[0] = 'x';
      str_from_int_tmp[1] = '0';
      str_from_int_tmp += 2;
    } else if (spec_format.specifecator == 'o' && !nul_add_in_accuracy) {
      str_from_int_tmp[0] = '0';
      str_from_int_tmp += 1;
    }
    *str_from_int_tmp = 0;
  }

  //Добавляем знак--------------------------------------------------------
  if (spec_format.specifecator != 'u' && spec_format.specifecator != 'x' &&
      spec_format.specifecator != 'X' && spec_format.specifecator != 'o') {
    //при u не печатается знак
    str_from_int_tmp = add_sign(spec_format, str_from_int, sign_minus);
  }
  //Переворачиваем
  revers_string(str_to_add_from_param, str_from_int);
  s21_strncpy(str_from_int, str_to_add_from_param,
              s21_strlen(str_to_add_from_param));
  //обрбатываем по ширине и выравнивание по нужному
  //краю-------------------------------------------
  format_by_width(str_to_add_from_param, spec_format, str_from_int);

  return 0;
}

//Модификатор ширины, принимает строку и двигает ее по ширине
long int format_by_width(char *str_to_add_from_param,
                         struct Spec_Format spec_format, char *str_from_int) {
  long int schetchik = 0;
  long int len_str = 0;

  if (spec_format.flag_left) {
    len_str = (long int)s21_strlen(str_from_int);
    s21_strncpy(str_to_add_from_param, str_from_int, len_str);
    str_to_add_from_param += len_str;
    schetchik += len_str;
    if (spec_format.width > len_str) {
      s21_memset(str_to_add_from_param, ' ', (spec_format.width - (len_str)));
      str_to_add_from_param += (spec_format.width - (len_str));
      schetchik += (spec_format.width - (len_str));
    }
  } else {
    len_str = (long int)s21_strlen(str_from_int);

    if (spec_format.width > len_str) {
      s21_memset(str_to_add_from_param, ' ', (spec_format.width - (len_str)));
      str_to_add_from_param += (spec_format.width - (len_str));
      schetchik += (spec_format.width - (len_str));
    }
    s21_strncpy(str_to_add_from_param, str_from_int, len_str);
    str_to_add_from_param += len_str;
    schetchik += len_str;
  }
  *str_to_add_from_param = 0;
  return schetchik;
}

//принимает unsigned long long int  возвращает строку ,перевод чисел в строку в
//перевернутом виде возвращает перевернутую строку
short int represent_int_to_str(char *str_to_add_from_param,
                               unsigned long long int value_d) {
  int ch = 0;
  int i = 0;

  while ((value_d / 10) != 0) {
    ch = '0' + (value_d % 10);
    str_to_add_from_param[i] = ch;
    value_d = value_d / 10;
    i += 1;
  }

  if (value_d != 0) {
    ch = '0' + (value_d % 10);
    str_to_add_from_param[i] = ch;
    value_d = value_d / 10;
    i += 1;
  }
  str_to_add_from_param[i] = 0;

  return 0;
}

//переворачивает строку
char *revers_string(char *dst, char *revers) {
  char *start = dst;

  for (int i = s21_strlen(revers); i != 0; i--) {
    *dst = revers[i - 1];
    dst += 1;
  }
  *dst = 0;

  return start;
}

char *int_to_str_simple(char *str_from_arg, long long int value_from_arg) {
  /*
  простой перевод со знаком минус
  число->строка минус добавляется
  нужно в некоторых местах
  */
  unsigned long long int value_from_arg_u = 0;
  short int sign_minus = 0;
  char tmp_str[LEN_STR_FOR_LU] = "";
  char *start = str_from_arg;
  if (value_from_arg < 0) {
    sign_minus = 1;
    value_from_arg_u = (unsigned long long int)-value_from_arg;
  } else {
    value_from_arg_u = (unsigned long long int)value_from_arg;
  }
  represent_int_to_str(tmp_str, value_from_arg_u);

  if (sign_minus) {
    *(tmp_str + s21_strlen(tmp_str)) = '-';
  }
  *(tmp_str + s21_strlen(tmp_str)) = 0;

  revers_string(str_from_arg, tmp_str);
  if (s21_strlen(str_from_arg) == 0) {
    *str_from_arg = '0';
    str_from_arg[1] = 0;
  }
  return start;
}

//для реверсной строки добавление знака
char *add_sign(struct Spec_Format spec_format, char *str_from_int,
               short int sign_minus) {
  char *str_from_int_tmp = str_from_int + s21_strlen(str_from_int);
  if (sign_minus) {
    *str_from_int_tmp = '-';
    str_from_int_tmp += 1;
  } else if (spec_format.flag_plus) {
    *str_from_int_tmp = '+';
    str_from_int_tmp += 1;
  } else if (spec_format.flag_space) {
    *str_from_int_tmp = ' ';
    str_from_int_tmp += 1;
  }
  *str_from_int_tmp = 0;
  return str_from_int_tmp;
}
