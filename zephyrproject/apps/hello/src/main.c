#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(hello, LOG_LEVEL_INF);

int main(void)
{
    printk("printk: hello from Zephyr!!\n");
    LOG_INF("log: hello from Zephyr (uptime=%lld ms)", k_uptime_get());

    while (1) {
        LOG_INF("tick");
        k_sleep(K_SECONDS(1));
    }
    return 0;
}
