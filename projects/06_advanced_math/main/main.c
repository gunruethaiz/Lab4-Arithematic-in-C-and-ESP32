#include <stdio.h>
#include <math.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define TAG "ADV_MATH"

// กำหนดค่า π
#define PI 3.14159265358979323846

// ฟังก์ชันคำนวณพื้นที่สี่เหลี่ยมผืนผ้า
float rectangle_area(float length, float width) {
    return length * width;
}

// ฟังก์ชันคำนวณปริเมตรสี่เหลี่ยมผืนผ้า (รั้วรอบสนาม)
float rectangle_perimeter(float length, float width) {
    return 2 * (length + width);
}

// ฟังก์ชันคำนวณพื้นที่วงกลม
float circle_area(float radius) {
    return PI * radius * radius;
}

// ฟังก์ชันคำนวณปริมาตรทรงกระบอก (สระน้ำกลม)
float cylinder_volume(float radius, float height) {
    return PI * radius * radius * height;
}

// ฟังก์ชันคำนวณปริมาตรกล่อง
float box_volume(float length, float width, float height) {
    return length * width * height;
}

// ฟังก์ชันคำนวณพื้นที่ผิวกล่อง
float box_surface_area(float length, float width, float height) {
    return 2 * (length*width + width*height + height*length);
}

void app_main(void) {
    // สนามฟุตบอล
    float football_length = 100.0;  // เมตร
    float football_width = 60.0;    // เมตร

    float football_area = rectangle_area(football_length, football_width);
    float football_perimeter = rectangle_perimeter(football_length, football_width);

    ESP_LOGI(TAG, "=== สนามฟุตบอล ===");
    ESP_LOGI(TAG, "พื้นที่: %.0f × %.0f = %.0f ตร.ม.", football_length, football_width, football_area);
    ESP_LOGI(TAG, "ปริเมตร: 2×(%.0f + %.0f) = %.0f ม.", football_length, football_width, football_perimeter);
    ESP_LOGI(TAG, "");

    // สระน้ำกลม
    float pool_radius = 5.0;    // เมตร
    float pool_depth = 2.0;     // เมตร

    float pool_surface_area = circle_area(pool_radius);
    float pool_volume = cylinder_volume(pool_radius, pool_depth);

    ESP_LOGI(TAG, "=== สระน้ำกลม ===");
    ESP_LOGI(TAG, "พื้นที่ผิวน้ำ: π × %.0f² = %.2f ตร.ม.", pool_radius, pool_surface_area);
    ESP_LOGI(TAG, "ปริมาตรน้ำ: π × %.0f² × %.0f = %.2f ลบ.ม.", pool_radius, pool_depth, pool_volume);
    ESP_LOGI(TAG, "");

    // กล่องของขวัญ
    float box_length = 20.0;  // ซม.
    float box_width = 15.0;   // ซม.
    float box_height = 10.0;  // ซม.

    float box_vol = box_volume(box_length, box_width, box_height);
    float box_surf_area = box_surface_area(box_length, box_width, box_height);

    ESP_LOGI(TAG, "=== กล่องของขวัญ ===");
    ESP_LOGI(TAG, "ปริมาตร: %.0f × %.0f × %.0f = %.0f ลบ.ซม.", box_length, box_width, box_height, box_vol);
    ESP_LOGI(TAG, "พื้นที่ผิว: 2×(%.0f×%.0f + %.0f×%.0f + %.0f×%.0f) = %.0f ตร.ซม.", 
             box_length, box_width, box_width, box_height, box_height, box_length, box_surf_area);
    ESP_LOGI(TAG, "");

    vTaskDelay(2000 / portTICK_PERIOD_MS);
}
