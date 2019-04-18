#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "bf.h"

static int cu_init_bf_suite(void);
static int cu_clean_bf_suite(void);
static void tc001_hello(void);
static void tc002_bf_overflow(void);
static void tc003_bf_overflow(void);
static void tc004_bfsz_overflow(void);
static void tc005_bfsz_overflow(void);
static void tc006_skip_bracket(void);
static void tc007_skip_bracket_nest(void);
static void tc008_comment(void);

int main()
{
    CU_ErrorCode cu_bf_error;

    CU_TestInfo cu_bf_tarray[] = {
        {"Test001 Hello", tc001_hello},
        {"Test002 Buffer overflow plus", tc002_bf_overflow},
        {"Test003 Buffer overflow minus", tc003_bf_overflow},
        {"Test004 Buffer size overflow plus", tc004_bfsz_overflow},
        {"Test005 Buffer size overflow minus", tc005_bfsz_overflow},
        {"Test006 Skip bracket pair", tc006_skip_bracket},
        {"Test007 Skip nested bracket pair", tc007_skip_bracket_nest},
        {"Test008 Comment in code", tc008_comment},
        CU_TEST_INFO_NULL};

    CU_SuiteInfo cu_tsuites[] = {
        {"Brainfuck", cu_init_bf_suite, cu_clean_bf_suite, cu_bf_tarray},
        CU_SUITE_INFO_NULL};

    cu_bf_error = CU_initialize_registry();
    if (CUE_SUCCESS != cu_bf_error)
    {
        return CU_get_error();
    }

    cu_bf_error = CU_register_suites(cu_tsuites);
    if (CUE_SUCCESS != cu_bf_error)
    {
        return CU_get_error();
    }

    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

static int cu_init_bf_suite(void)
{
    return 0;
}

static int cu_clean_bf_suite(void)
{
    return 0;
}

static void tc001_hello(void)
{
    char code[129] = "++++++[->+++++>+++++++>+++++++++++>++++++++++++>+++++++++++++++++>++++++++++++++++++<<<<<<]>>>>.>-.>..+++.<<<<++.<++.>>.>--.<<<+.";
    char out[32] = {0};

    CU_ASSERT_EQUAL(bfProcessor(code, 129, out), EXIT_SUCCESS);
    CU_ASSERT_STRING_EQUAL(out, "Hello, BF!");
}

static void tc002_bf_overflow(void)
{
    char code[39] = "+++++++++++++++[->+++++++++++++++++<]>+";
    char out[32] = {0};

    CU_ASSERT_EQUAL(bfProcessor(code, 39, out), EXIT_FAILURE);
}

static void tc003_bf_overflow(void)
{
    char code[1] = "-";
    char out[32] = {0};

    CU_ASSERT_EQUAL(bfProcessor(code, 1, out), EXIT_FAILURE);
}

static void tc004_bfsz_overflow(void)
{
    char code[5] = "+[>+]";
    char out[32] = {0};

    CU_ASSERT_EQUAL(bfProcessor(code, 5, out), EXIT_FAILURE);
}

static void tc005_bfsz_overflow(void)
{
    char code[1] = "<";
    char out[32] = {0};

    CU_ASSERT_EQUAL(bfProcessor(code, 1, out), EXIT_FAILURE);
}

static void tc006_skip_bracket(void)
{
    char code[54] = "+-[+]++++++++++++++++++++++++++++++++++++++++++++++++.";
    char out[32] = {0};

    CU_ASSERT_EQUAL(bfProcessor(code, 54, out), EXIT_SUCCESS);
    CU_ASSERT_STRING_EQUAL(out, "0");
}

static void tc007_skip_bracket_nest(void)
{
    char code[57] = "+-[[+]+]++++++++++++++++++++++++++++++++++++++++++++++++.";
    char out[32] = {0};

    CU_ASSERT_EQUAL(bfProcessor(code, 57, out), EXIT_SUCCESS);
    CU_ASSERT_STRING_EQUAL(out, "0");
}

static void tc008_comment(void)
{
    char code[53] = "+++++++++++++++++++++++++TEST+++++++++++++++++++++++.";
    char out[32] = {0};

    CU_ASSERT_EQUAL(bfProcessor(code, 53, out), EXIT_SUCCESS);
    CU_ASSERT_STRING_EQUAL(out, "0");
}
