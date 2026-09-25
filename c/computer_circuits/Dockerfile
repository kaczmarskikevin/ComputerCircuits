FROM debian:bookworm-slim

WORKDIR /usr/src/myapp

RUN apt-get update && \
    apt-get install -y gcc

COPY . .

RUN mkdir test_bin bin && \
    gcc $(find src -name "*.c" -not -name "main.c") tests/tests.c -I./include/tests -Wall -Wextra -o test_bin/tests && \
    gcc $(find src -name "*.c") -I./include -Wall -Wextra -o bin/main_program
    

CMD ["/bin/bash", "-c", "./test_bin/tests && ./bin/main_program"]