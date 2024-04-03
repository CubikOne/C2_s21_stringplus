#include "s21_string_test.h"

int main(void) {
  // setlocale(LC_ALL, "");

  Suite *list_cases[] = {suite_strlen(),
                         suite_strcspn(),
                         suite_strncmp(),
                         suite_strncpy(),
                         suite_memchr(),
                         suite_memcmp(),
                         suite_memcpy(),
                         suite_memset(),
                         suite_strncat(),
                         suite_strchr(),
                         suite_strerror(),
                         suite_strpbrk(),
                         suite_strrchr(),
                         suite_strstr(),
                         suite_strtok(),

                         suite_to_upper(),
                         suite_to_lower(),
                         suite_insert(),
                         suite_trim(),

                         suite_sprintf(),
                         suite_sscanf(),

                         NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    fprintf(stderr,
            "------------------------------------------------------------------"
            "------------\n");
    SRunner *runner = srunner_create(list_cases[i]);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}
