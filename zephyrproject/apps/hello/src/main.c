#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(hello, LOG_LEVEL_INF);

/* Bigger than needed, but comfy for demos */
#define STACK_SIZE 1024
#define PRIO_FAST  2   /* Higher priority (runs more readily) */
#define PRIO_SLOW  5   /* Lower priority */

K_THREAD_STACK_DEFINE(stack_fast, STACK_SIZE);
K_THREAD_STACK_DEFINE(stack_slow, STACK_SIZE);

static struct k_thread thread_fast;
static struct k_thread thread_slow;

static void fast_thread(void *a, void *b, void *c)
{
    ARG_UNUSED(a); ARG_UNUSED(b); ARG_UNUSED(c);

    uint32_t n = 0;
    while (1) {
        LOG_INF("FAST  (prio=%d) n=%u uptime=%lld", PRIO_FAST, n++, k_uptime_get());
        k_sleep(K_MSEC(250));
    }
}

static void slow_thread(void *a, void *b, void *c)
{
    ARG_UNUSED(a); ARG_UNUSED(b); ARG_UNUSED(c);

    uint32_t n = 0;
    while (1) {
        LOG_INF("SLOW  (prio=%d) n=%u uptime=%lld", PRIO_SLOW, n++, k_uptime_get());
        k_sleep(K_SECONDS(1));
    }
}

int main(void)
{
    printk("main(): starting threads...\n");

    k_thread_create(&thread_fast, stack_fast, STACK_SIZE,
                    fast_thread, NULL, NULL, NULL,
                    PRIO_FAST, 0, K_NO_WAIT);
    k_thread_name_set(&thread_fast, "fast");

    k_thread_create(&thread_slow, stack_slow, STACK_SIZE,
                    slow_thread, NULL, NULL, NULL,
                    PRIO_SLOW, 0, K_NO_WAIT);
    k_thread_name_set(&thread_slow, "slow");

    uint32_t n = 0;
    while (1) {
        LOG_INF("MAIN  (prio=%d) n=%u uptime=%lld", 0, n++, k_uptime_get());
        k_sleep(K_SECONDS(2));
    }

    return 0;
}
