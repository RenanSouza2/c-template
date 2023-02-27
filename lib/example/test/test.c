#include <stdio.h>

#include "../debug.h"

void test_example_func()
{
    printf("\n\ttest example func\t\t");

    hello_example();
}

void test_example()
{
    printf("\ntest example library\t\t");

    test_example_func();
}


int main() {
    setbuf(stdout, NULL);
    test_example();
    printf("\n\n\tTest successful\n\n");
    return 0;
}
