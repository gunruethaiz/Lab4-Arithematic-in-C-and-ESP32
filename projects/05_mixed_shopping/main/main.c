#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "SHOPPING_MIXED";

// โครงสร้างข้อมูลสินค้า
typedef struct {
    char name[20];
    int quantity;
    float price_per_unit;
    float total_price;
} product_t;

// ฟังก์ชันคำนวณราคาสินค้าแต่ละชนิด
void calculate_total(product_t *p) {
    p->total_price = p->quantity * p->price_per_unit;
}

void app_main(void) {
    ESP_LOGI(TAG, "=== ใบเสร็จซื้อของที่ตลาด ===");

    product_t products[] = {
        {"แอปเปิ้ล", 6, 15.0, 0},
        {"กล้วย", 12, 8.0, 0},
        {"ส้ม", 8, 12.0, 0},
    };
    int count = sizeof(products) / sizeof(products[0]);
    float discount = 20.0;  // ส่วนลดเป็นจำนวนเงิน
    int people = 3;         // จำนวนคนแบ่งจ่าย

    float total = 0;
    for (int i = 0; i < count; i++) {
        calculate_total(&products[i]);
        total += products[i].total_price;
        ESP_LOGI(TAG, "%s: %d × %.0f = %.0f บาท", products[i].name, products[i].quantity, products[i].price_per_unit, products[i].total_price);
    }

    ESP_LOGI(TAG, "----------------------");
    ESP_LOGI(TAG, "รวม: %.0f บาท", total);

    float after_discount = total - discount;
    ESP_LOGI(TAG, "ส่วนลด: -%.0f บาท", discount);

    ESP_LOGI(TAG, "ยอดสุทธิ: %.0f บาท", after_discount);

    float per_person = after_discount / people;
    ESP_LOGI(TAG, "แบ่งจ่าย %d คน: %.2f บาท/คน", people, per_person);

    ESP_LOGI(TAG, "=======================");

    vTaskDelay(2000 / portTICK_PERIOD_MS);
}
