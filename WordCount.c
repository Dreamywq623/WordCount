#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数用于统计字符数
int countCharacters(FILE* file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {  // 每次读取一个字符，直到文件结束
        count++;
    }
    return count;  // 返回字符总数
}

// 函数用于统计单词数
int countWords(FILE* file) {
    int count = 0;
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {  // 使用fscanf读取单词，直到文件结束
        count++;
    }
    return count;  // 返回单词总数
}

int main(int argc, char* argv[]) {
    if (argc != 3) {  // 检查命令行参数数量是否正确
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }
    
    char* option = argv[1];
    char* filename = argv[2];
    
    FILE* file = fopen(filename, "r");  // 打开文件以进行读取
    if (file == NULL) {  // 检查文件是否成功打开
        printf("Error opening file.\n");
        return 1;
    }
    
    int result;
    if (strcmp(option, "-c") == 0) {  // 如果选项是-c，统计字符数
        result = countCharacters(file);
        printf("字符数：%d\n", result);
    } else if (strcmp(option, "-w") == 0) {  // 如果选项是-w，统计单词数
        result = countWords(file);
        printf("单词数：%d\n", result);
    } else {
        printf("Invalid option.\n");
        return 1;
    }
    
    fclose(file);  // 关闭文件
    return 0;
}

