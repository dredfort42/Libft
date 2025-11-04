#!/usr/bin/env bash
# scripts/test_example.sh
# Tiny test script to build libft, compile example.c and run it.
# By default this script will CLEANUP build artifacts after running the example.
# Pass --keep to preserve libft.a, object files, and the example binary.
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT_DIR"

# Default: do cleanup after the test. Set --keep to preserve artifacts.
KEEP=false
if [ "${1-}" = "--keep" ]; then
  KEEP=true
fi

echo "[test] Building libft (make)..."
make

EXAMPLE_SRC=examples/example.c
EXAMPLE_BIN=example

if [ ! -f "$EXAMPLE_SRC" ]; then
  echo "[test] example.c not found: $EXAMPLE_SRC"
  exit 1
fi

echo "[test] Compiling example..."
gcc -I. "$EXAMPLE_SRC" libft.a -o "$EXAMPLE_BIN"

echo "[test] Running example..."
./"$EXAMPLE_BIN"

echo "[test] Success."

if [ "$KEEP" = false ]; then
  echo "[test] Cleaning build artifacts (make fclean)..."
  # fclean removes libft.a and object files via Makefile
  make fclean >/dev/null 2>&1 || true
  rm -f "$EXAMPLE_BIN"
  echo "[test] Cleaned."
else
  echo "[test] Keeping build artifacts as requested (--keep)."
fi
