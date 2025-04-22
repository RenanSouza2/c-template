
#include "../debug.h"

#include "../../../mods/macros/U64.h"
#include "../../../mods/macros/test.h"
#include "../../../mods/macros/assert.h"

#include "../../../mods/clu/header.h"



#define TEST_ASSERT_EMPTY assert(clu_mem_is_empty());

void test_example_hello(bool show)
{
    TEST_FN

    TEST_CASE_OPEN(1)
    {
        example_debug();
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(2)
    {
        example_hello();
    }
    TEST_CASE_CLOSE

    TEST_ASSERT_EMPTY
}

void test_example_malloc(bool show)
{
    TEST_FN

    TEST_CASE_OPEN(1)
    {
        handler_p h = example_malloc();

        /* Comment next line to see the clu assertion fail */
        free(h);
    }
    TEST_CASE_CLOSE


    TEST_CASE_OPEN(2)
    {
        handler_p h = example_malloc();

        printf("\n\nThis prints the current allocated pointers in short form\n");
        clu_mem_report("TAG");

        free(h);
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(3)
    {
        handler_p h = example_malloc();

        printf("\n\nThis prints the current allocated pointers in long form\n");
        clu_mem_report_full("TAG");

        free(h);
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(4)
    {
        handler_p h = example_malloc();

        printf("\n\nThis prints the current allocated pointers in long form\n");
        clu_mem_report_full("TAG");

        free(h);
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(5)
    {
        handler_p h = example_malloc();

        uint64_t i_max = clu_get_max_i();
        printf("\n\nThis is the number of different tags still allocated: " U64P() "\n", i_max);

        free(h);
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(6)
    {
        handler_p h = example_malloc();

        uint64_t j_max = clu_get_max_j(0);
        printf("\n\nThis is the number of pointers still allocated in the tag index 0: " U64P() "\n", j_max);

        free(h);
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(7)
    {
        handler_p h = example_malloc();

        handler_p h_leaked = clu_get_handler(0, 0);
        printf("\n\nThis is the handler still alocated in corrdinates (0, 0): %p", h_leaked);
        printf("\nand the content of the pointer: " U64PX "\n", *(uint64_t*)h);

        free(h);
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(8)
    {
        handler_p h = example_malloc();

        printf("\n\nThis tests if a given pointer safe to interact");
        printf("\nWhich means either NULL or curentrly allocated");
        CLU_HANDLER_IS_SAFE(h);
        printf("\nCan be used anywhere in the code");
        printf("\nOnly adds overhead if compiled in debug mode");
        printf("\n");

        free(h);

        /* Uncomment next line to see the assertion fail */
        // CLU_HANDLER_VALIDATE(h);
    }
    TEST_CASE_CLOSE

    TEST_ASSERT_EMPTY
}

void test_example_revert(bool show)
{
    TEST_FN

    TEST_CASE_OPEN(1)
    {
        example_revert(false);
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(2)
    {
        TEST_REVERT_OPEN
        {
            example_revert(true);
        }
        TEST_REVERT_CLOSE
    }
    TEST_CASE_CLOSE

    TEST_CASE_OPEN(3)
    {
        uint64_t *a = NULL;
        TEST_REVERT_OPEN
        {
            *a = 1;
        }
        TEST_REVERT_CLOSE
    }
    TEST_CASE_CLOSE

    TEST_ASSERT_EMPTY
}



void test_example()
{
    TEST_LIB

    bool show = false;

    test_example_hello(show);
    test_example_malloc(show);
    test_example_revert(show);

    TEST_ASSERT_EMPTY
}



int main()
{
    setbuf(stdout, NULL);
    TEST_TIMEOUT_OPEN(5)
    test_example();
    TEST_TIMEOUT_CLOSE
    printf("\n\n\tTest successful\n\n");
    return 0;
}
