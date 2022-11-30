// strman = string manipulation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SplitResult {
    int len;
    char *storage;
    char **p;
};


// TODO: proper error handling
struct SplitResult split(char *s, char char_) {
    // Store all resulting words (from the split action) next to each
    // other in memory.
    int n = strlen(s) + 1;  // + 1 for null byte
    char *dest = malloc(n);
    if (dest == NULL) {
        printf("ERROR");
    }

    int num_words = 1;
    for (int i = 0; i < n; i++){
        if (s[i] == char_) {
            dest[i] = '\0';
            num_words++;
        } else {
            dest[i] = s[i];
        }
    }

    // *res -> res is a pointer
    // char * -> of type char *
    char **res = calloc(num_words, sizeof(char *));
    if (res == NULL) {
        printf("ERROR");
    }

    struct SplitResult result = {.len=num_words, .storage=dest};
    int i = 0;
    do {
        res[i] = dest;
        num_words--;
        i++;
        while (*dest != '\0') {
            dest++;
        }
        dest++;
    } while (num_words > 0);

    result.p = res;
    return result;
}


// Wrapper so that it can be used by Python.
void free_split_result(struct SplitResult res) {
    free(res.storage);
    free(res.p);
}

int main(void){
    struct SplitResult res;
    res = split("hello world", ' ');

    printf("Length: %i\n", res.len);
    for (int i = 0; i < res.len; i++) {
        printf("%s\n", res.p[i]);
    }

    free_split_result(res);
}
