FROM kaczmarskikevin/c

COPY . .

RUN gcc $(find src -name "*.c") -I./include -Wall -Wextra -o bin/main_program

ENTRYPOINT ["./bin/main_program"]