#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "ERROR_HANDLING";

// กำหนด error codes
typedef enum {
    ERR_OK = 0,
    ERR_DIV_ZERO,
    ERR_INVALID_INPUT,
    ERR_OUT_OF_RANGE,
    ERR_NEGATIVE_VALUE,
    ERR_OVERFLOW,
} error_code_t;

// ฟังก์ชันตรวจสอบการหาร (ห้ามหารด้วยศูนย์)
error_code_t check_division(int numerator, int denominator) {
    if (denominator == 0) {
        return ERR_DIV_ZERO;
    }
    return ERR_OK;
}

// ฟังก์ชันตรวจสอบจำนวนลูกค้า (ห้ามติดลบ)
error_code_t check_customers(int customers) {
    if (customers < 0) {
        return ERR_NEGATIVE_VALUE;
    }
    return ERR_OK;
}

// ฟังก์ชันตรวจสอบราคาสินค้า (เป็นตัวเลขหรือไม่)
error_code_t check_price(const char *price_str) {
    for (int i = 0; i < (int)strlen(price_str); i++) {
        if (price_str[i] < '0' || price_str[i] > '9') {
            return ERR_INVALID_INPUT;
        }
    }
    return ERR_OK;
}

// ฟังก์ชันตรวจสอบเงินทอน (ไม่ติดลบ)
error_code_t check_change(int change) {
    if (change < 0) {
        return ERR_NEGATIVE_VALUE;
    }
    return ERR_OK;
}

// ฟังก์ชันตรวจสอบยอดเงินฝาก (ไม่เกินขีดจำกัด)
error_code_t check_deposit(unsigned long long deposit) {
    // สมมติขีดจำกัด 1,000,000,000,000
    unsigned long long limit = 1000000000000ULL;
    if (deposit > limit) {
        return ERR_OUT_OF_RANGE;
    }
    return ERR_OK;
}

// ฟังก์ชันตรวจสอบดอกเบี้ย (ไม่ติดลบ)
error_code_t check_interest(float interest) {
    if (interest < 0.0f) {
        return ERR_NEGATIVE_VALUE;
    }
    return ERR_OK;
}

// ฟังก์ชันแสดงข้อความ error friendly
void display_error(error_code_t err) {
    switch (err) {
        case ERR_DIV_ZERO:
            ESP_LOGE(TAG, "❌ ข้อผิดพลาด: ไม่สามารถหารด้วยศูนย์ได้");
            ESP_LOGI(TAG, "💡 แนะนำ: ตรวจสอบจำนวนก่อนทำการหาร");
            break;
        case ERR_INVALID_INPUT:
            ESP_LOGE(TAG, "❌ ข้อผิดพลาด: ข้อมูลที่ป้อนไม่ถูกต้อง");
            ESP_LOGI(TAG, "💡 แนะนำ: กรุณาป้อนตัวเลขเท่านั้น");
            break;
        case ERR_OUT_OF_RANGE:
            ESP_LOGE(TAG, "❌ ข้อผิดพลาด: ค่าที่ป้อนเกินขอบเขตที่กำหนด");
            ESP_LOGI(TAG, "💡 แนะนำ: ตรวจสอบข้อมูลและป้อนใหม่");
            break;
        case ERR_NEGATIVE_VALUE:
            ESP_LOGE(TAG, "❌ ข้อผิดพลาด: ค่าติดลบในที่ที่ไม่ควรเป็นลบ");
            ESP_LOGI(TAG, "💡 แนะนำ: ตรวจสอบข้อมูลและป้อนค่าที่ถูกต้อง");
            break;
        case ERR_OVERFLOW:
            ESP_LOGE(TAG, "❌ ข้อผิดพลาด: ข้อมูลล้นขอบเขตที่กำหนด");
            ESP_LOGI(TAG, "💡 แนะนำ: ลดค่าหรือใช้ชนิดข้อมูลที่ใหญ่ขึ้น");
            break;
        case ERR_OK:
        default:
            ESP_LOGI(TAG, "✅ ข้อมูลถูกต้อง: ดำเนินการต่อได้");
            break;
    }
}

void app_main(void) {
    // ตัวอย่าง 1: ร้านพิซซ่า
    int total_pizza = 12;
    int customers = 0; // ฝนตก ไม่มีลูกค้า

    ESP_LOGI(TAG, "🍕 ร้านพิซซ่า:");
    error_code_t err = check_division(total_pizza, customers);
    if (err != ERR_OK) {
        display_error(err);
    } else {
        ESP_LOGI(TAG, "🍕 ลูกค้า %d คน ได้พิซซ่าคนละ %d ชิ้น", customers, total_pizza / customers);
    }
    ESP_LOGI(TAG, "");

    // ตัวอย่าง 2: ร้านขายของ
    int change = -50;           // เงินทอนติดลบ
    const char *price_str = "ABC"; // ราคาสินค้าไม่ถูกต้อง

    ESP_LOGI(TAG, "💰 ร้านขายของ:");
    err = check_change(change);
    if (err != ERR_OK) {
        display_error(err);
    } else {
        ESP_LOGI(TAG, "เงินทอน: %d บาท", change);
    }

    err = check_price(price_str);
    if (err != ERR_OK) {
        display_error(err);
    } else {
        ESP_LOGI(TAG, "ราคาสินค้า: %s บาท", price_str);
    }
    ESP_LOGI(TAG, "");

    // ตัวอย่าง 3: ธนาคาร
    unsigned long long deposit = 9999999999999ULL;  // เกินขีดจำกัด
    float interest = -5.0f;                          // ดอกเบี้ยติดลบ

    ESP_LOGI(TAG, "🏦 ธนาคาร:");
    err = check_deposit(deposit);
    if (err != ERR_OK) {
        display_error(err);
    } else {
        ESP_LOGI(TAG, "ยอดเงินฝาก: %llu บาท", deposit);
    }

    err = check_interest(interest);
    if (err != ERR_OK) {
        display_error(err);
    } else {
        ESP_LOGI(TAG, "อัตราดอกเบี้ย: %.2f%%", interest);
    }
    ESP_LOGI(TAG, "");

    // ตัวอย่างที่สำเร็จ: หารปกติ
    total_pizza = 12;
    customers = 4;

    ESP_LOGI(TAG, "✅ ตัวอย่างที่สำเร็จ:");
    err = check_division(total_pizza, customers);
    if (err == ERR_OK) {
        ESP_LOGI(TAG, "📊 ผลลัพธ์: %d ÷ %d = %d ชิ้นต่อคน", total_pizza, customers, total_pizza / customers);
    } else {
        display_error(err);
    }

    vTaskDelay(2000 / portTICK_PERIOD_MS);
}
