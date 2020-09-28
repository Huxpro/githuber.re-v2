#!/usr/bin/env sh

SCRIPT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

SRC=$SCRIPT
GH_PAGES="$SCRIPT/gh-pages"

build() {
  mkdir $GH_PAGES && \
  cp -r "$SRC/bundleOutput" "$GH_PAGES/bundleOutput" && \
  cp "$SRC/indexProduction.html" "$GH_PAGES/index.html"
}

cleanup() {
  rm -rf $GH_PAGES
}

cleanup && build
