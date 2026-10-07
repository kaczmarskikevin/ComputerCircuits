#!/bin/bash

gcc $(find src -name "*.c" -not -name "main.c") tests/test_elements.c -I./include -Wall -Wextra -o test_bin/test_elements && \
gcc $(find src -name "*.c") -I./include -Wall -Wextra -o bin/main_program