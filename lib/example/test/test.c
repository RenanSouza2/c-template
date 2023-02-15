#include <stdio.h>

#include "../code.c"

void test_example_func()
{
    printf("\n\ttest example func");

    hello_example();
}

void test_example()
{
    printf("\ntest example library");

    test_example_func();
}


int main() {
    setbuf(stdout, NULL);
    test_example();
    printf("\n\n\tTest successful\n\n");
    return 0;
}
