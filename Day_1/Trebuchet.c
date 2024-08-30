#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_digit(char c) {
    return (c >= '0' && c <= '9'); 
}

int main() {
    char *filename = "input.txt";
    FILE *fp = fopen(filename, "r");
    char input_str[30000]; // Have to allocate memory, why?

    int total = 0;
    int i = 0;
    while (fgets(input_str, sizeof(input_str), fp)) {
        int temp_num = 0;

        size_t length = strlen(input_str);
        for (size_t j = 0; j < length; j++){
            if (is_digit(input_str[j]) == true) {
                temp_num += (input_str[j] - '0')*10;
                break;
            }
        }
        for (size_t j = length - 1; j >= 0; j--){
            if (is_digit(input_str[j]) == true) {
                temp_num += (input_str[j] - '0');
                break;
            }
        }
        total = total + temp_num;
        i++;
    }
    printf("Answ sum: %d\n", total);

    fclose(fp);

    return 0;
}
