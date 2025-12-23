#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include <stdio.h>

#define LED_PIN 2

void blinkTask(void *parameter) {
  gpio_reset_pin(LED_PIN);
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

  while (1) {
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(1000));

    gpio_set_level(LED_PIN, 0);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void initLED(void) {
  xTaskCreate(blinkTask, "blink_task", 2048, NULL, 5, NULL);
}

void app_main(void) {
  printf("Starting LED blink\n");

  initLED();
}
