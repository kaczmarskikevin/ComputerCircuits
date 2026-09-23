FROM debian:bookworm-slim

WORKDIR /usr/src/myapp

RUN apt-get update && \
    apt-get install -y gcc

COPY . .

RUN mkdir test_bin bin && \
    gcc $(find src -name "*.c" -not -name "main.c") tests/test1.c -I./include -Wall -Wextra -o test_bin/test1 && \
    gcc $(find src -name "*.c") -I./include -Wall -Wextra -o bin/main_program
    

CMD ["./test_bin/test1", "&&", "./test_bin/main_program"]