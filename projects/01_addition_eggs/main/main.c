#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "MATH_PROJECTS";

void app_main(void)
{
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // =====================================
    // 🥚 โปรเจค 1: ไข่ไก่ของแม่
    // =====================================
    int eggs_already_have = 8;
    int eggs_new_today = 3;
    int total_eggs = eggs_already_have + eggs_new_today;

    int duck_eggs = 3;
    int total_all_eggs = total_eggs + duck_eggs;

    ESP_LOGI(TAG, "🥚 โปรเจค 1: ไข่ไก่ของแม่");
    ESP_LOGI(TAG, "แม่มีไข่ไก่แล้ว: %d ฟอง", eggs_already_have);
    ESP_LOGI(TAG, "ไก่ออกไข่เพิ่ม: %d ฟอง", eggs_new_today);
    ESP_LOGI(TAG, "รวมไข่ไก่ทั้งหมด: %d ฟอง", total_eggs);
    ESP_LOGI(TAG, "ไข่เป็ดที่แม่มี: %d ฟอง", duck_eggs);
    ESP_LOGI(TAG, "รวมไข่ทั้งหมด (ไก่ + เป็ด): %d ฟอง", total_all_eggs);
    ESP_LOGI(TAG, "");

    // ตัวอย่างเสริม
    ESP_LOGI(TAG, "🔁 ตัวอย่างเพิ่มเติม:");
    int ex1_old = 7, ex1_new = 2;
    int ex1_total = ex1_old + ex1_new;
    ESP_LOGI(TAG, "แม่มีไข่ %d ฟอง ไก่ออกเพิ่ม %d ฟอง รวม %d ฟอง", ex1_old, ex1_new, ex1_total);
    ESP_LOGI(TAG, "");

    // =====================================
    // 🍎 โปรเจค 2: แอปเปิ้ลในตะกร้า
    // =====================================
    int apples_in_basket = 5;
    int apples_bought = 4;
    int total_apples = apples_in_basket + apples_bought;

    ESP_LOGI(TAG, "🍎 โปรเจค 2: แอปเปิ้ลในตะกร้า");
    ESP_LOGI(TAG, "แอปเปิ้ลในตะกร้าเดิม: %d ผล", apples_in_basket);
    ESP_LOGI(TAG, "แม่ซื้อเพิ่มมาอีก: %d ผล", apples_bought);
    ESP_LOGI(TAG, "รวมแอปเปิ้ลทั้งหมด: %d ผล", total_apples);
    ESP_LOGI(TAG, "");

    // ตัวอย่างเสริม
    int ex2_old = 6, ex2_new = 5;
    int ex2_total = ex2_old + ex2_new;
    ESP_LOGI(TAG, "ถ้ามีแอปเปิ้ล %d ผล และซื้อเพิ่ม %d ผล จะรวมเป็น %d ผล", ex2_old, ex2_new, ex2_total);
    ESP_LOGI(TAG, "");

    // =====================================
    // 📚 สรุปสิ่งที่เรียนรู้
    // =====================================
    ESP_LOGI(TAG, "📚 สรุปสิ่งที่เรียนรู้วันนี้:");
    ESP_LOGI(TAG, "1. การบวกเลขด้วยตัวแปรในภาษา C");
    ESP_LOGI(TAG, "2. การแสดงผลด้วย ESP_LOGI");
    ESP_LOGI(TAG, "3. การต่อยอดโจทย์จากชีวิตจริง");

    ESP_LOGI(TAG, "🎉 จบโปรแกรม!");
    vTaskDelay(3000 / portTICK_PERIOD_MS);
}
