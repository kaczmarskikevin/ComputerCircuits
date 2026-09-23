FROM kaczmarskikevin/c

COPY . .

RUN gcc $(find src -name "*.c") $(find include -name "*.h") -Wall -Wextra -o bin/main_program

ENTRYPOINT ["./bin/main"]