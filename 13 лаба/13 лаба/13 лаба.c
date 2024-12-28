//13 лаба
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Функция для преобразования имени в верхний регистр
void to_uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Функция для разворачивания строки
void reverse_string(char* str, char* reversed) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';
}

// Функция для подсчёта знаков препинания во второй половине строки
int count_punctuation_in_second_half(char* str) {
    int length = strlen(str);
    int half = length / 2;
    int count = 0;

    for (int i = half; i < length; i++) {
        if (ispunct(str[i])) {
            count++;
        }
    }
    return count;
}

int main() {

    setlocale(LC_CTYPE, "RUS");
    char Snew[100];
    char Name[50];
    char ReversedName[50];
    char InputString[100];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. запрашивает имя пользователя и здоровается с ним, используя введённое имя. \n");
        printf("2. В верхнем регистре\n");
        printf("3. Восклицаьельными знаками(40 символов)\n");
        printf("4. Имя наоборот\n");
        printf("5. Посчитать знаки во 2 половине строки\n");
        printf("6. Выход\n");
        printf("Выберите опцию: ");
        scanf("%d", &choice);
        getchar(); // удаление символа новой строки после ввода

        switch (choice) {
        case 1:
            // Задание 1.1
            strcpy(Snew, "Hello, ");
            printf("Введите имя: ");
            scanf("%s", Name);
            strcat(Snew, Name);
            printf("%s!\n", Snew);
            break;

        case 2:
            // Задание 1.2
            strcpy(Snew, "HELLO, ");
            printf("Введите имя: ");
            scanf("%s", Name);
            to_uppercase(Name);
            strcat(Snew, Name);
            printf("%s!\n", Snew);
            break;

        case 3:
            // Задание 1.3
            strcpy(Snew, "Hello, ");
            printf("Введите имя: ");
            scanf("%s", Name);
            strcat(Snew, Name);
            int current_length = strlen(Snew);
            for (int i = current_length; i < 39; i++) {
                Snew[i] = '!';
            }
            Snew[39] = '\0';
            printf("%s\n", Snew);
            break;

        case 4:
            // Задание 2
            strcpy(Snew, "Hello, ");
            printf("введите имя: ");
            scanf("%s", Name);
            reverse_string(Name, ReversedName);
            strcat(Snew, ReversedName);
            printf("%s!\n", Snew);
            break;

        case 5:
            // Задание 3
            printf("Введите строку (до 99 символов): ");
            fgets(InputString, sizeof(InputString), stdin);
            int punctuation_count = count_punctuation_in_second_half(InputString);
            printf("Количество знаков препинания во второй половине: %d\n", punctuation_count);
            break;

        case 6:
            printf("ВЫход из программы\n");
            break;

        default:
            printf("Не правильный выбор.Введите снова\n");
            break;
        }
    } while (choice != 6);

    return 0;
}
