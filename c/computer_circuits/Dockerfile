FROM kaczmarskikevin/c

COPY . .

RUN gcc $(find src -name "*.c" -not -name "main.c") tests/test1.c -I./include -Wall -Wextra -o bin/test1 && \
    gcc $(find src -name "*.c") -I./include -Wall -Wextra -o bin/main_program
    

CMD ["./bin/test1", "&&", "./bin/main_program"]