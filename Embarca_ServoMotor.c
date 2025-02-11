#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12
#define PWM_WRAP 25000

// =================== Função para controle do Servo Motor ===================
void setServoAngle(uint16_t pulse_width) {
    uint16_t pulse_scaled = (pulse_width * PWM_WRAP) / 20000;
    pwm_set_gpio_level(SERVO_PIN, pulse_scaled);
}

// =================== Interrupção do PWM para LED (Fade) ===================
void wrapHandler() { 
    static int fade = 0;
    static bool rise = true;
    pwm_clear_irq(pwm_gpio_to_slice_num(LED_PIN));

    if (rise) {
        fade++;
        if (fade > 255) {
            fade = 255;
            rise = false;
        }
    } else {
        fade--;
        if (fade < 0) {
            fade = 0;
            rise = true;
        }
    }
    pwm_set_gpio_level(LED_PIN, fade * fade);
}

// =================== Configuração do PWM com interrupção ===================
uint pwm_setup_irq() {
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint sliceNum = pwm_gpio_to_slice_num(LED_PIN);

    pwm_clear_irq(sliceNum);
    pwm_set_irq_enabled(sliceNum, true);
    irq_set_exclusive_handler(PWM_IRQ_WRAP, wrapHandler);
    irq_set_enabled(PWM_IRQ_WRAP, true);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    pwm_init(sliceNum, &config, true);

    return sliceNum;
}

// =================== Código principal ===================
int main() {
    // Configuração do Servo Motor
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_wrap(slice_num, 12500);
    pwm_set_clkdiv(slice_num, 100.0);
    pwm_set_enabled(slice_num, true);

    // Configuração do LED PWM com interrupção
    uint sliceNumLED = pwm_setup_irq();

    while (1) {
        printf("Movendo o servo para 180° e aumentando brilho do LED...\n");
        setServoAngle(2400);
        pwm_set_irq_enabled(sliceNumLED, true);
        sleep_ms(5000);

        printf("Movendo o servo para 90° e desligando o LED...\n");
        setServoAngle(1470);
        pwm_set_irq_enabled(sliceNumLED, false);
        sleep_ms(5000);

        printf("Movendo o servo para 0° e reduzindo brilho do LED...\n");
        setServoAngle(500);
        pwm_set_irq_enabled(sliceNumLED, true);
        sleep_ms(5000);

        printf("Movendo o servo suavemente entre 0° e 180°...\n");
        for (uint16_t pulse = 500; pulse <= 2400; pulse += 5) {
            setServoAngle(pulse);
            sleep_ms(10);
        }
        for (uint16_t pulse = 2400; pulse >= 500; pulse -= 5) {
            setServoAngle(pulse);
            sleep_ms(10);
        }
    }
}
