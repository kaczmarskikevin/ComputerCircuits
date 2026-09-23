FROM kaczmarskikevin/c

COPY . .

RUN gcc $(find src -name "*.c") -Wall -Wextra -o bin/main_program

ENTRYPOINT ["./bin/main"]