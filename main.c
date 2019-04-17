
#include "bf.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    char code[CODE_SIZE] = {0};
    signed short code_len = 0;
    char output[BUFFER_SIZE];

    if (argc == 2)
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
        {
            printf("file open error\n");
            return -1;
        }
        for (code_len = 0; (code[code_len] = fgetc(fp)) != EOF && code_len < CODE_SIZE; code_len++)
            ;
        fclose(fp);
        if (bfProcessor(code, code_len, output) == EXIT_FAILURE)
        {
            printf("syntax error.");
        }
        else
        {
            printf("%s\n", output);
        }
    }
    else if (argc == 1)
    {
        while (1)
        {
            // for inline interpreter
            printf("[input]: ");
            fgets(code, CODE_SIZE, stdin);
            code_len = strlen(code);
            if (bfProcessor(code, code_len, output) == EXIT_FAILURE)
            {
                printf("syntax error.");
            }
            else
            {
                printf("%s\n", output);
            }
        }
    }
    else
    {
        printf("usage: %s [filename.bf]\n", argv[0]);
        return -1;
    }

    return 0;
}
