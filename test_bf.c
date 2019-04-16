#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "bf.h"

static int cu_init_bf_suite(void);
static int cu_clean_bf_suite(void);
static void tc001_hello(void);
//static void cu_bf_002(void);
//static void cu_bf_003(void);
//static void cu_bf_004(void);
//static void cu_bf_005(void);

int main()
{
    CU_ErrorCode cu_bf_error;

    CU_TestInfo cu_bf_tarray[] = {
        {"Test_001", tc001_hello},
        //{"Test_002", cu_bf_002},
        //{"Test_003", cu_bf_003},
        //{"Test_004", cu_bf_004},
        //{"Test_005", cu_bf_005},
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
    int codelen = 129;
    char buffer[32];

    bfProcessor(code, codelen, buffer);
    CU_ASSERT_STRING_EQUAL(buffer, "Hello, BF!");
}
//static void cu_bf_002(void)
//static void cu_bf_003(void)
//static void cu_bf_004(void)
//static void cu_bf_005(void)
