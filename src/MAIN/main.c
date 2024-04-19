/**
 * @file main.c
 * @brief Application entry point
 * @copyright 
 * @license Apache-2.0
 * @author Mohd Ramza <mohdramza@yahoo.com>
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(MAIN, LOG_LEVEL_INF);

/* A conditional variable to suspend main thread post initialization */
K_CONDVAR_DEFINE(main_thread_suspend_resume);
K_MUTEX_DEFINE(main_thread_mutex);

/**
 * @brief Entry point of application
 */
int main(void)
{
	LOG_INF("Hello. This is Stm32f4 Series Project");

	while (1) {
		/*Lets suspend the thread as it has done its job*/
		LOG_WRN("Init done. Suspending myself!");
		k_condvar_wait(&main_thread_suspend_resume, &main_thread_mutex, K_FOREVER);
	}
}