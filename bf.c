
#include "bf.h"

static void rangeCheck(signed short in_num, const signed short THRESHOLD);
static void loopCheck(signed short *count, const signed short ADDEND, const char CODE);

void bfProcessor(const char *CODE, const signed short CODE_LEN)
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
