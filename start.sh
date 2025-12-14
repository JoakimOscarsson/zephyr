#!/usr/bin/env bash
set -e

IMAGE=zephyr-dev
WORKDIR="$(pwd)"

docker run --rm -it \
  -v "${WORKDIR}:/workdir" \
  ${IMAGE}
