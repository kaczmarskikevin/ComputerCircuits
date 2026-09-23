FROM kaczmarskikevin/c

COPY . .

RUN gcc $(find src -name "*.c") -I./include -Wall -Wextra -o bin/main_program && \
    gcc $(find src -name "*.c" -not -name "main.c") tests/test1.c -I./include -Wall -Wextra -o test_bin/test1

CMD ["./test_bin/test1", "&&", "./bin/main_program"]