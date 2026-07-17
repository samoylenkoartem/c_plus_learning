#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 32

int main() {
    // Открываем файлы
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    if (!input_file || !output_file) {
        printf("Ошибка открытия файлов!\n");
        return 1;
    }

    char line[BUFFER_SIZE];

    // Читаем файл построчно
    while (fgets(line, sizeof(line), input_file)) {
        // Убираем символ новой строки
        line[strcspn(line, "\n\r")] = '\0';

        // Если строка пустая - пропускаем
        if (strlen(line) == 0) {
            fputs("\n", output_file);
            continue;
        }

        // Убираем пробелы в начале
        int start = 0;
        while (line[start] == ' ' || line[start] == '\t') {
            start++;
        }

        // Убираем пробелы в конце
        int end = strlen(line) - 1;
        while (end >= start && (line[end] == ' ' || line[end] == '\t')) {
            end--;
        }

        // Если строка состоит только из пробелов
        if (start > end) {
            fputs("\n", output_file);
            continue;
        }

        // Копируем очищенную строку
        char nickname[BUFFER_SIZE];
        int nickname_len = 0;
        for (int i = start; i <= end; i++) {
            nickname[nickname_len++] = line[i];
        }
        nickname[nickname_len] = '\0';


        // Проверяем первую букву
        if (strlen(nickname) == 0 || !islower((unsigned char)nickname[0])) {
            // если первая буква не маленькая или строка пустая - *error*
            fputs("*error*\n", output_file);
            continue;
        }


        int has_underscore = 0;
        int has_uppercase_inside = 0;
        int has_error = 0;
        

        // Проходим по всем символам строки 
        for (size_t i = 0; i < strlen(nickname); i++) {
            unsigned char c = (unsigned char)nickname[i];

            // Проверяем на подчеркивание
            if (c == '_') {
                has_underscore = 1;

                // Проверяем двойные подчеркивания
                if (i > 0 && nickname[i - 1] == '_') {
                    has_error = 1;
                }

                // Проверяем подчеркивание в конце строки
                if (i == strlen(nickname) - 1) {
                    fputs("*error*\n", output_file);
                    has_error = 1;
                    break;
                }

                // Если после подчеркивания идет цифра 
                if (i < strlen(nickname) - 1 && isdigit((unsigned char)nickname[i + 1])) {
                    has_error = 1;
                }
            }

            // Проверяем на заглавные буквы
            else if (isupper(c)) {
                has_uppercase_inside = 1;
            }
            // Проверяем на цифры 
            else if (isdigit(c)) {
                continue;
            }
            // Проверяем на строчные буквы 
            else if (islower(c)) {
                continue;
            }
            // Остальные символы 
            else {
                has_error = 1;
                break;
            }
        }

        // Если найден дефис или другой спецсимвол или двойные подчеркивания 
        // или подчеркивания вместе с заглавными или цифра после подчеркивания
        if (has_error ||
            (has_underscore && has_uppercase_inside) ) {  
            fputs("*error*\n", output_file);
            continue;
        }

        // Если строка начинается или заканчивается подчеркиванием
        if (nickname[0] == '_' || nickname[strlen(nickname) - 1] == '_') {
            fputs("*error*\n", output_file);
            continue;
        }


        char result[BUFFER_SIZE * 2] = {0}; // Удвоенный размер на случай добавления '_'

        // camelCase (snake_case → camelCase)
        if (has_underscore) {
            int result_index = 0;
            int next_upper = 0;

            for (size_t i = 0; i < strlen(nickname); i++) {
                if (nickname[i] == '_') {
                    next_upper = 1;
                }
                else {
                    if (next_upper) {
                        result[result_index++] = toupper((unsigned char)nickname[i]);
                        next_upper = 0;
                    }
                    else {
                        result[result_index++] = nickname[i];
                    }
                }
            }
            result[result_index] = '\0';

            fputs(result, output_file);
            fputs("\n", output_file);
        }
        // snake_case (camelCase → snake_case)
        else if (has_uppercase_inside) {
            int result_index = 0;

            for (size_t i = 0; i < strlen(nickname); i++) {
                if (i > 0 && isupper((unsigned char)nickname[i])) {
                    result[result_index++] = '_';
                    result[result_index++] = tolower((unsigned char)nickname[i]);
                }
                else {
                    result[result_index++] = nickname[i];
                }
            }
            result[result_index] = '\0';

            fputs(result, output_file);
            fputs("\n", output_file);
        }
        // нижний регистр (без изменений)
        else {
            fputs(nickname, output_file);
            fputs("\n", output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
