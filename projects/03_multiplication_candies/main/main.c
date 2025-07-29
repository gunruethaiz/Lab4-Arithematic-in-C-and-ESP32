#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "CANDIES_MULTIPLY";

void app_main(void) {
    // แบบฝึกหัดที่ 1: เปลี่ยนจำนวนถุงลูกอม
    int candy_bags = 7;         // จำนวนถุง
    int candies_per_bag = 8;    // ลูกอมต่อถุง

    ESP_LOGI(TAG, "=== ลูกอมในถุง ===");
    ESP_LOGI(TAG, "จำนวนถุง: %d ถุง", candy_bags);
    ESP_LOGI(TAG, "ลูกอมต่อถุง: %d เม็ด", candies_per_bag);

    // แบบฝึกหัดที่ 2: เพิ่มลูกอมหลายรส
    int strawberry_bags = 3;    // ถุงรสสตรอเบอร์รี่
    int orange_bags = 2;        // ถุงรสส้ม
    int grape_bags = 4;         // ถุงรสองุ่น

    int total_bags = strawberry_bags + orange_bags + grape_bags;
    int total_candies = total_bags * candies_per_bag;

    ESP_LOGI(TAG, "🍓 สตรอเบอร์รี่: %d ถุง = %d เม็ด", 
             strawberry_bags, strawberry_bags * candies_per_bag);
    ESP_LOGI(TAG, "🍊 รสส้ม: %d ถุง = %d เม็ด", 
             orange_bags, orange_bags * candies_per_bag);
    ESP_LOGI(TAG, "🍇 รสองุ่น: %d ถุง = %d เม็ด", 
             grape_bags, grape_bags * candies_per_bag);

    ESP_LOGI(TAG, "ลูกอมทั้งหมด: %d × %d = %d เม็ด", total_bags, candies_per_bag, total_candies);

    // แบบฝึกหัดที่ 3: สร้างตารางสูตรคูณ
    ESP_LOGI(TAG, "📊 ตารางสูตรคูณของ %d:", candies_per_bag);
    for (int i = 1; i <= 10; i++) {
        ESP_LOGI(TAG, "   %d x %d = %d", i, candies_per_bag, i * candies_per_bag);
    }

    // แบบฝึกหัดที่ 4: แจกลูกอมให้เพื่อน
    int friends = 12;           // จำนวนเพื่อน
    int candies_per_friend = total_candies / friends;  // ลูกอมต่อคน
    int remaining_candies = total_candies % friends;   // ลูกอมที่เหลือ

    ESP_LOGI(TAG, "👥 แจกให้เพื่อน %d คน:", friends);
    ESP_LOGI(TAG, "   คนละ %d เม็ด", candies_per_friend);
    ESP_LOGI(TAG, "   เหลือ %d เม็ด", remaining_candies);

    // แสดงการบวกซ้ำๆ เทียบกับการคูณ
    ESP_LOGI(TAG, "การบวกซ้ำๆ: ");
    char sum_str[100] = "";
    for (int i = 0; i < candy_bags; i++) {
        char buffer[8];
        snprintf(buffer, sizeof(buffer), "%d", candies_per_bag);
        strcat(sum_str, buffer);
        if (i < candy_bags - 1) {
            strcat(sum_str, " + ");
        }
    }
    char result_str[120];
    snprintf(result_str, sizeof(result_str), "%s = %d", sum_str, candy_bags * candies_per_bag);
    ESP_LOGI(TAG, "%s", result_str);

    vTaskDelay(10000 / portTICK_PERIOD_MS);  // รอ 10 วินาทีให้เห็นผลลัพธ์ใน monitor
}
