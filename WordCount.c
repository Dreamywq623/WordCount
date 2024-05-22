#include <stdio.h>
#include <stdlib.h>

int countCharacters(FILE *file) {
    int count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        count++;
    }

    return count;
}

int countWords(FILE *file) {
    int count = 0;
    char c;
    int inWord = 0; // ����Ƿ��ڵ�����

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            inWord = 1;
        } else if (inWord) {
            inWord = 0;
            count++;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("��������\n");
        printf("�÷���%s [parameter] [input_file_name]\n", argv[0]);
        printf("[parameter] ȡ \"-c\" �� \"-w\"\n");
        printf("[input_file_name] Ҫ��������ı��ļ�����Ĭ�ϴ����ִ���ļ�Ŀ¼��\n");
        return 1;
    }

    char *parameter = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("�޷����ļ� %s\n", filename);
        return 1;
    }

    int count = 0;
    if (strcmp(parameter, "-c") == 0) {
        count = countCharacters(file);
        printf("�ַ�����%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = countWords(file);
        printf("��������%d\n", count);
    } else {
        printf("��������\n");
        printf("�÷���%s [parameter] [input_file_name]\n", argv[0]);
        printf("[parameter] ȡ \"-c\" �� \"-w\"\n");
        printf("[input_file_name] Ҫ��������ı��ļ�����Ĭ�ϴ����ִ���ļ�Ŀ¼��\n");
        return 1;
    }

    fclose(file);

    return 0;
}
