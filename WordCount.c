#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��������ͳ���ַ���
int countCharacters(FILE* file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {  // ÿ�ζ�ȡһ���ַ���ֱ���ļ�����
        count++;
    }
    return count;  // �����ַ�����
}

// ��������ͳ�Ƶ�����
int countWords(FILE* file) {
    int count = 0;
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {  // ʹ��fscanf��ȡ���ʣ�ֱ���ļ�����
        count++;
    }
    return count;  // ���ص�������
}

int main(int argc, char* argv[]) {
    if (argc != 3) {  // ��������в��������Ƿ���ȷ
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }
    
    char* option = argv[1];
    char* filename = argv[2];
    
    FILE* file = fopen(filename, "r");  // ���ļ��Խ��ж�ȡ
    if (file == NULL) {  // ����ļ��Ƿ�ɹ���
        printf("Error opening file.\n");
        return 1;
    }
    
    int result;
    if (strcmp(option, "-c") == 0) {  // ���ѡ����-c��ͳ���ַ���
        result = countCharacters(file);
        printf("�ַ�����%d\n", result);
    } else if (strcmp(option, "-w") == 0) {  // ���ѡ����-w��ͳ�Ƶ�����
        result = countWords(file);
        printf("��������%d\n", result);
    } else {
        printf("Invalid option.\n");
        return 1;
    }
    
    fclose(file);  // �ر��ļ�
    return 0;
}

