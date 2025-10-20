#!/bin/sh

set -e # Exit early if any commands fail

(
  cd "$(dirname "$0")"
  cmake -B build -S .
  cmake --build ./cmake-build-debug
)

exec $(dirname $0)/cmake-build-debug/posix_shell "$@"
