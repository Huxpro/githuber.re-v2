#!/usr/bin/env sh

SCRIPT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

SRC=$SCRIPT
PROD="$SCRIPT/docs" # used by github pages

build() {
  mkdir $PROD && \
  cp -r "$SRC/bundleOutput" "$PROD/bundleOutput" && \
  cp "$SRC/indexProduction.html" "$PROD/index.html"
}

cleanup() {
  rm -rf $PROD
}

cleanup && build
