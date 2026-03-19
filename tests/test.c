/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-16 00:28
 */

#include "greatest.h"
#include "fileio/lib.h"

/* A test runs various assertions, then calls PASS(), FAIL(), or SKIP(). */
TEST test_read_file(void) {
    char *filename = "./files/foo.txt";
    if (read_file(filename) != EXIT_SUCCESS) {
        FAIL();
    }

    PASS();
}

TEST test_write_file(void)  {
    char *filename = "./files/baz.txt";
    char *body = "hello, world\n";
    write_file(filename, body);
    // 만약 파일이 존재하지 않는다 -> 실패 케이스.
    if (read_file(filename) != EXIT_SUCCESS) {
        FAIL();
    }

    // 존재하는 경우.
    delete_file(filename);
    PASS();
}

/* Suites can group multiple tests with common setup. */
// fileio -> suite name
// suite (group of unit tests) -> unit test
SUITE(fileio) {
    RUN_TEST(test_read_file);
    RUN_TEST(test_write_file);
}

TEST linked_list(void) {
    // printf("linked_list\n");
    PASS();
}

SUITE(ds) {
    RUN_TEST(linked_list);
}

/* Add definitions that need to be in the test runner's main file. */
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();      /* command-line options, initialization. */

    /* Tests can also be gathered into test suites. */
    // RUN_SUITE(fileio);

    GREATEST_MAIN_END();        /* display results */
}
