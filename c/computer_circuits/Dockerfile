FROM kaczmarskikevin/c

COPY . .

RUN gcc $(find . -name "src/*.c") -Wall -Wextra -o bin/main_program

ENTRYPOINT ["./bin/main"]