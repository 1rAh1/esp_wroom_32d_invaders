#include "sleep_mode.h"
#include "Arduino.h"
#include "gpio_def.h"

uint16_t g_goto_sleep_counter = 0;


//no se puede implementar el modo de apagado automático por que no se puede apagar la pantalla...
void goto_sleep(void){
  const uint32_t GOTO_SLEEP_PERIOD_MS = 500;
  const uint32_t GOTO_SLEEP_TIME_MS = 1500;
  uint32_t current_time = 0;
  static uint32_t last_execution_time = 0;

  current_time = millis();

  if (last_execution_time <= (current_time + GOTO_SLEEP_PERIOD_MS)){
    last_execution_time = current_time;

    g_goto_sleep_counter = g_goto_sleep_counter + GOTO_SLEEP_PERIOD_MS;

    if(g_goto_sleep_counter >= GOTO_SLEEP_TIME_MS){
      esp_sleep_enable_ext0_wakeup(((gpio_num_t) DI_A_BUTTON), 1);
      esp_deep_sleep_start();
    }

  }

}


void sleep_delay(uint32_t time_ms){
  esp_sleep_enable_timer_wakeup((1000 * time_ms));
  esp_light_sleep_start();
}