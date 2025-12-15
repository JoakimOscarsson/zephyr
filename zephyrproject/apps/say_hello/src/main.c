#include <zephyr/kernel.h>

#ifdef CONFIG_SAY_HELLO
#include "say_hello.h"
#endif

//Settings
static const int32_t sleep_time_ms = 1000;

int main(void){
    while(1) {

        #ifdef CONFIG_SAY_HELLO
        say_hello();
        #endif
        k_sleep(K_MSEC(sleep_time_ms));
    }
    return 0;
}


