#!/bin/bash

docker build -t kaczmarskikevin/$1-$2 ./$1/$2/

LANG="$1"
PROG="$2"

shift 2

mkdir -p /tmp/kkaczmarski-container

docker run --cap-add=SYS_PTRACE -v /tmp/kkaczmarski-container:/tmp kaczmarskikevin/$LANG-$PROG $@ > stdout.log 2> stderr.log