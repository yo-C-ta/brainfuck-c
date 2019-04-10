#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 30000
#define CODE_SIZE 1024

static void bfProcessor(const char *CODE, const signed short CODE_LEN);
static void rangeCheck(signed short in_num, const signed short THRESHOLD);
static void loopCheck(signed short *count, const signed short ADDEND, const char CODE);

int main(int argc, char *argv[])
{
    FILE *fp;
    char code[CODE_SIZE] = {0};
    signed short code_len = 0;

    if (argc == 2)
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
        {
            printf("file open error\n");
            return -1;
        }
        for (code_len = 0; (code[code_len] = fgetc(fp)) != EOF && code_len < CODE_SIZE; code_len++)
            ;
    }
    else if (argc == 1)
    {
        // for inline interpreter
        printf("[input]: ");
        fgets(code, CODE_SIZE, stdin);
        code_len = strlen(code);
    }
    else
    {
        printf("usage: %s [filename.bf]\n", argv[0]);
        return -1;
    }
    fclose(fp);

    bfProcessor(code, code_len);

    return 0;
}

static void bfProcessor(const char *CODE, const signed short CODE_LEN)
{
    unsigned char buffer[BUFFER_SIZE] = {0};
    signed short buffer_ptr = 0;
    signed short code_ptr = 0;
    signed short loop_count = 0;

    for (; code_ptr < CODE_LEN; code_ptr++)
    {
        switch (CODE[code_ptr])
        {
        case '>':
            rangeCheck(++buffer_ptr, BUFFER_SIZE);
            break;
        case '<':
            rangeCheck(--buffer_ptr, -1);
            break;
        case '+':
            rangeCheck(++buffer[buffer_ptr], 0);
            break;
        case '-':
            rangeCheck(--buffer[buffer_ptr], 255);
            break;
        case '[':
            if (buffer[buffer_ptr] == 0)
            {
                for (code_ptr++; CODE[code_ptr] != ']' || loop_count > 0; code_ptr++)
                {
                    loopCheck(&loop_count, 1, CODE[code_ptr]);
                }
            }
            break;
        case ']':
            if (buffer[buffer_ptr] != 0)
            {
                for (code_ptr--; CODE[code_ptr] != '[' || loop_count > 0; code_ptr--)
                {
                    loopCheck(&loop_count, -1, CODE[code_ptr]);
                }
            }
            break;
        case '.':
            putchar(buffer[buffer_ptr]);
            break;
        case ',':
            getchar();
            break;
        default:
            break;
        }
    }
    printf("\n");
}

static void rangeCheck(signed short in_num, const signed short THRESHOLD)
{
    if (in_num == THRESHOLD)
    {
        printf("syntax error\n");
        exit(1);
    }
    return;
}

static void loopCheck(signed short *count, const signed short ADDEND, const char CODE)
{
    if (CODE == '[')
    {
        (*count) += ADDEND;
    }
    else if (CODE == ']')
    {
        (*count) -= ADDEND;
    }
}
