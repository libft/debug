#!/bin/sh

set +e

find . -maxdepth 1 -type d -name "case*" | sort | xargs -I {} -- "$MAKE" -C {} $1
