#include <stdio.h>
#include <stdlib.h>

#define IS_DIGIT(A) ((A >= '0') && (A <= '9'))

int main(int argc, char *argv[])
{
    if (argc <= 1 || argc > 3) {
        exit(1);
    } else {
        int level = 0;
        char clevel[6]={0};

        if (argv[2] == NULL) {
            exit(2);
        } else {
            char* c = argv[2];
            while (*c != '\0') {
                if (!IS_DIGIT(*c)) {
                    exit(2);
                }
                c++;
            }
            level = atoi(argv[2]);
            if (level < 1000 || level > 3000) {
                exit(3);
            }
            sprintf(clevel, "%d", level);
        }
        FILE* fp = fopen(argv[1], "w+");
        if (!fp) {
            exit(2);
        }
        fwrite(clevel, sizeof(clevel), sizeof(clevel), fp);
        fflush(fp);
        fclose(fp);
    }

    return 0;
}
