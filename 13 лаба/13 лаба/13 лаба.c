//13 ����
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// ������� ��� �������������� ����� � ������� �������
void to_uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// ������� ��� �������������� ������
void reverse_string(char* str, char* reversed) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';
}

// ������� ��� �������� ������ ���������� �� ������ �������� ������
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
        printf("1. ����������� ��� ������������ � ����������� � ���, ��������� �������� ���. \n");
        printf("2. � ������� ��������\n");
        printf("3. ���������������� �������(40 ��������)\n");
        printf("4. ��� ��������\n");
        printf("5. ��������� ����� �� 2 �������� ������\n");
        printf("6. �����\n");
        printf("�������� �����: ");
        scanf("%d", &choice);
        getchar(); // �������� ������� ����� ������ ����� �����

        switch (choice) {
        case 1:
            // ������� 1.1
            strcpy(Snew, "Hello, ");
            printf("������� ���: ");
            scanf("%s", Name);
            strcat(Snew, Name);
            printf("%s!\n", Snew);
            break;

        case 2:
            // ������� 1.2
            strcpy(Snew, "HELLO, ");
            printf("������� ���: ");
            scanf("%s", Name);
            to_uppercase(Name);
            strcat(Snew, Name);
            printf("%s!\n", Snew);
            break;

        case 3:
            // ������� 1.3
            strcpy(Snew, "Hello, ");
            printf("������� ���: ");
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
            // ������� 2
            strcpy(Snew, "Hello, ");
            printf("������� ���: ");
            scanf("%s", Name);
            reverse_string(Name, ReversedName);
            strcat(Snew, ReversedName);
            printf("%s!\n", Snew);
            break;

        case 5:
            // ������� 3
            printf("������� ������ (�� 99 ��������): ");
            fgets(InputString, sizeof(InputString), stdin);
            int punctuation_count = count_punctuation_in_second_half(InputString);
            printf("���������� ������ ���������� �� ������ ��������: %d\n", punctuation_count);
            break;

        case 6:
            printf("����� �� ���������\n");
            break;

        default:
            printf("�� ���������� �����.������� �����\n");
            break;
        }
    } while (choice != 6);

    return 0;
}
