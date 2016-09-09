#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char key[] = {"0123456789~`!@#$%^&*()_-+=\"[]'{}|\\;:/?><., "};
    while(gets(input) != NULL){
        int words = 0;
        char *ptr;
        ptr = strtok(input , key);
        while(ptr != NULL){
            words++;
            ptr = strtok(NULL , key);
        }
        printf("%d\n",words);
    }
    return 0;
}
