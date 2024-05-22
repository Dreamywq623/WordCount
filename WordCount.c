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
    int inWord = 0; // 标记是否在单词中

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
        printf("参数错误！\n");
        printf("用法：%s [parameter] [input_file_name]\n", argv[0]);
        printf("[parameter] 取 \"-c\" 或 \"-w\"\n");
        printf("[input_file_name] 要被处理的文本文件名，默认存放在执行文件目录下\n");
        return 1;
    }

    char *parameter = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return 1;
    }

    int count = 0;
    if (strcmp(parameter, "-c") == 0) {
        count = countCharacters(file);
        printf("字符数：%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = countWords(file);
        printf("单词数：%d\n", count);
    } else {
        printf("参数错误！\n");
        printf("用法：%s [parameter] [input_file_name]\n", argv[0]);
        printf("[parameter] 取 \"-c\" 或 \"-w\"\n");
        printf("[input_file_name] 要被处理的文本文件名，默认存放在执行文件目录下\n");
        return 1;
    }

    fclose(file);

    return 0;
}
