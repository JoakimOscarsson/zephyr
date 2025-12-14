#!/usr/bin/env bash
set -euo pipefail

mkdir -p /workdir
cd /workdir

# If the workspace doesn't exist yet, initialize it.
if [[ ! -d "zephyrproject/.west" ]]; then
  echo "==> Initializing Zephyr workspace in /workdir/zephyrproject"
  west init zephyrproject
  cd zephyrproject
  west update
  west zephyr-export
else
  cd zephyrproject
fi

echo "==> Zephyr workspace ready at: /workdir/zephyrproject"
exec "$@"
