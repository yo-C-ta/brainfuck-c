
#include "bf.h"

static int rangeCheck(signed short in_num, const signed short THRESHOLD);
static void loopCheck(signed short *count, const signed short ADDEND, const char CODE);

int bfProcessor(const char *CODE, const signed short CODE_LEN, char *output)
{
    unsigned char buffer[BUFFER_SIZE] = {0};
    signed short buffer_ptr = 0;
    signed short code_ptr = 0;
    signed short loop_count = 0;
    unsigned short output_ptr = 0;

    for (; code_ptr < CODE_LEN; code_ptr++)
    {
        switch (CODE[code_ptr])
        {
        case '>':
            if (rangeCheck(++buffer_ptr, BUFFER_SIZE) == EXIT_FAILURE)
                return EXIT_FAILURE;
            break;
        case '<':
            if (rangeCheck(--buffer_ptr, -1) == EXIT_FAILURE)
                return EXIT_FAILURE;
            break;
        case '+':
            if (rangeCheck(++buffer[buffer_ptr], 0) == EXIT_FAILURE)
                return EXIT_FAILURE;
            break;
        case '-':
            if (rangeCheck(--buffer[buffer_ptr], 255) == EXIT_FAILURE)
                return EXIT_FAILURE;
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
            output[output_ptr] = buffer[buffer_ptr];
            output_ptr++;
            break;
        case ',':
            getchar();
            break;
        default:
            break;
        }
    }

    return EXIT_SUCCESS;
}

static int rangeCheck(signed short in_num, const signed short THRESHOLD)
{
    return in_num == THRESHOLD ? EXIT_FAILURE : EXIT_SUCCESS;
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
