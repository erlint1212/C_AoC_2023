#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// const char input_str[] = "1abc2\npqr3stu8vwx\na1b2c3d4e5f\ntreb7uchet";
// const char example_str[4][20] = {"1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"};
// const int true_task_answer[4] = {12,38,15,77};
// Answer: 12, 38, 15, 77

bool is_digit(char c) {
    return (c >= '0' && c <= '9'); 
}

int sum(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return arr[0] + sum(arr + 1, n - 1);
    }
}

int main() {
    char *filename = "input_test.txt";
    FILE *fp = fopen(filename, "r")

    int task_answer[] = {};

    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    size_t sup_length = sizeof(example_str)/sizeof(example_str[0]);
    // size_t sup_length = *(&example_str + 1) - example_str;
    for (size_t i = 0; i < sup_length; i++) {
        size_t length = strlen(example_str[i]);
        for (size_t j = 0; j < length; j++){
            if (is_digit(example_str[i][j]) == true) {
                task_answer[i] = (example_str[i][j] - '0')*10;
                break;
            }
        }
        for (size_t j = length; j > 0; j--){
            if (is_digit(example_str[i][j]) == true) {
                task_answer[i] = task_answer[i] + (example_str[i][j] - '0');
                break;
            }
        }
    }
    printf("Answ sum: %d\n", sum(task_answer, sizeof(task_answer)/sizeof(task_answer[0])));

    fclose(fp);

    return 0;
}
