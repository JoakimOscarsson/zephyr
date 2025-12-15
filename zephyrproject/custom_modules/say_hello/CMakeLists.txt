#Check if SAY_HELLO is set in Kconfig
if(CONFIG_SAY_HELLO)
    # Add source file dir
    zephyr_include_directories(.)

    # Add source file
    zephyr_library_sources(say_hello.c)

endif()
