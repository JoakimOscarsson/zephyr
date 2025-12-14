ARG ZEPHYR_BASE_IMAGE=ghcr.io/zephyrproject-rtos/zephyr-build:main
FROM ${ZEPHYR_BASE_IMAGE}

WORKDIR /workdir
COPY --chmod=755 entrypoint.sh /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD ["bash", "-l"]
