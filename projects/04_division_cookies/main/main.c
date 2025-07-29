#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "COOKIES_DIVIDE";

void app_main(void) {
    // แบบฝึกหัดที่ 1: เปลี่ยนจำนวนคุกกี้และเพื่อน
    int total_cookies = 24;    // คุกกี้ทั้งหมด
    int friends = 6;           // จำนวนเพื่อน

    ESP_LOGI(TAG, "=== คุกกี้แบ่งกัน ===");
    ESP_LOGI(TAG, "คุกกี้ทั้งหมด: %d ชิ้น", total_cookies);
    ESP_LOGI(TAG, "จำนวนเพื่อน: %d คน", friends);

    // แบบฝึกหัดที่ 2: ตรวจสอบหารด้วยศูนย์ และหารลงตัวไหม
    if (friends == 0) {
        ESP_LOGI(TAG, "❌ ไม่สามารถหารด้วยศูนย์ได้!");
        return;
    }

    int cookies_per_person = total_cookies / friends;
    int remaining_cookies = total_cookies % friends;

    ESP_LOGI(TAG, "แต่ละคนได้: %d ÷ %d = %d ชิ้น", total_cookies, friends, cookies_per_person);
    ESP_LOGI(TAG, "เศษที่เหลือ: %d ชิ้น", remaining_cookies);

    if (remaining_cookies == 0) {
        ESP_LOGI(TAG, "✅ หารลงตัว! ทุกคนได้เท่ากัน");
    } else {
        ESP_LOGI(TAG, "⚠️ หารไม่ลงตัว! เหลือ %d ชิ้น", remaining_cookies);
    }

    // แบบฝึกหัดที่ 3: หาจำนวนเพื่อนที่เหมาะสม (หารลงตัว)
    int cookies = 30;
    ESP_LOGI(TAG, "🔍 คุกกี้ %d ชิ้น หารลงตัวกับ:", cookies);
    for (int people = 1; people <= 10; people++) {
        if (cookies % people == 0) {
            ESP_LOGI(TAG, "   ✅ %d คน → คนละ %d ชิ้น", people, cookies / people);
        }
    }

    vTaskDelay(10000 / portTICK_PERIOD_MS);  // รอ 10 วิ ให้เห็นผลใน monitor
}
