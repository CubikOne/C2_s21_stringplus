
CC = gcc
CCFLAGS = -Wall -Wextra -Wextra -std=c11
LDFLAGS = -lcheck -lc -lsubunit -lrt -lm -pthread
RM = rm -rf

#GCOVR = ~/.local/bin/gcovr
GCOVR = gcovr # pip install gcovr

# имя библиотеки
LIB_NAME = s21_string.a
# имя тестового файла
ТESTS_NAME = s21_string_test
# имя тестового файла c тестами покрытия кода gcovr
ТESTS_GCOV_NAME = s21_string_tests_gcov

# файлы и директории функций библиотек
DIR = 
HEADER_NAME = s21_string.h
SOURCES = $(wildcard $(addprefix $(DIR),*.c))
OBJECTS = $(SOURCES:.c=.o)
HEADER = $(addprefix $(DIR),$(HEADER_NAME))

# файлы и директории тестов
TEST_DIR = tests/
TEST_HEADER_NAME := s21_string_test.h
TEST_SRC = $(wildcard $(addprefix $(TEST_DIR),*.c))
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_HEADER = $(addprefix $(TEST_DIR),$(TEST_HEADER_NAME))



all:$(LIB_NAME)

$(LIB_NAME):$(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o:%.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(SOURCES):$(HEADER)
$(TEST_SRC): $(TEST_HEADER)

test:clean $(ТESTS_NAME)
	./$(ТESTS_NAME)

$(ТESTS_NAME):$(TEST_OBJ) $(LIB_NAME)
	$(CC) $(CCFLAGS) $^ -L. -L/usr/local/lib -L/usr/include -l:s21_string.a -o $@ $(LDFLAGS)

gcov_report:clean_gcov clean_report $(ТESTS_GCOV_NAME)
	./$(ТESTS_GCOV_NAME)
	mkdir report
	$(GCOVR) -r . --html --html-details -o report/coverage.html --exclude=$(TEST_DIR)
	make clean_gcov
	firefox report/coverage.html

$(ТESTS_GCOV_NAME):$(TEST_SRC) $(SOURCES)
	$(CC) $(CCFLAGS) -g -fprofile-arcs -ftest-coverage $^ -o $@ $(LDFLAGS)

clean:clean_gcov clean_report
	$(RM) $(ТESTS_NAME)
	$(RM) $(LIB_NAME)
	$(RM) $(OBJECTS)
	$(RM) $(TEST_OBJ)

clean_report:
	$(RM) report

clean_gcov:
	$(RM) $(ТESTS_GCOV_NAME)
	$(RM) *.gcda
	$(RM) *.gcno
