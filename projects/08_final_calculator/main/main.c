#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "FINAL_CALC";

// สถานะเมนูหลัก
typedef enum {
    MENU_MAIN = 0,
    MENU_BASIC,
    MENU_ADVANCED,
    MENU_SHOP,
    MENU_HISTORY,
    MENU_EXIT
} menu_state_t;

// ฟังก์ชันแสดงเมนูหลัก
void show_main_menu() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║        🧮 เครื่องคิดเลขครบครัน        ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ [1] โหมดพื้นฐาน - Basic Calculator  ║\n");
    printf("║ [2] โหมดขั้นสูง - Advanced Math     ║\n");
    printf("║ [3] โหมดร้านค้า - Shop POS System   ║\n");
    printf("║ [4] โหมดประวัติ - History & Stats   ║\n");
    printf("║ [0] ออกจากโปรแกรม                   ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("เลือกเมนู: ");
}

// ฟังก์ชันโหมดพื้นฐาน (ตัวอย่าง: บวก ลบ คูณ หาร)
void mode_basic_calculator() {
    int choice;
    double a, b, result;

    printf("\n-- โหมดพื้นฐาน --\n");
    printf("[1] บวก [2] ลบ [3] คูณ [4] หาร [0] กลับ\n");
    printf("เลือก: ");
    scanf("%d", &choice);

    if(choice == 0) return;

    printf("ป้อนตัวเลขตัวที่ 1: ");
    scanf("%lf", &a);
    printf("ป้อนตัวเลขตัวที่ 2: ");
    scanf("%lf", &b);

    switch(choice) {
        case 1: result = a + b; break;
        case 2: result = a - b; break;
        case 3: result = a * b; break;
        case 4:
            if(b == 0) {
                printf("❌ ข้อผิดพลาด: ไม่สามารถหารด้วยศูนย์ได้\n");
                return;
            }
            result = a / b;
            break;
        default:
            printf("❌ ตัวเลือกไม่ถูกต้อง\n");
            return;
    }
    printf("ผลลัพธ์: %.6f\n", result);
}

// ฟังก์ชันโหมดขั้นสูง (ตัวอย่างยกกำลัง รากที่สอง แฟกทอเรียล)
unsigned long long factorial(int n) {
    if(n < 0) return 0;  // กำหนดว่าแฟกทอเรียลไม่รับค่าติดลบ
    if(n == 0) return 1;
    unsigned long long f = 1;
    for(int i=1; i<=n; i++) f *= i;
    return f;
}

void mode_advanced_math() {
    int choice;
    printf("\n-- โหมดขั้นสูง --\n");
    printf("[1] ยกกำลัง [2] รากที่สอง [3] แฟกทอเรียล [0] กลับ\n");
    printf("เลือก: ");
    scanf("%d", &choice);

    if(choice == 0) return;

    if(choice == 1) {
        double base, exponent, result;
        printf("ฐาน: "); scanf("%lf", &base);
        printf("ยกกำลัง: "); scanf("%lf", &exponent);
        result = pow(base, exponent);
        printf("ผลลัพธ์: %.6f\n", result);
    } else if(choice == 2) {
        double x, result;
        printf("ป้อนจำนวน: "); scanf("%lf", &x);
        if(x < 0) {
            printf("❌ ข้อผิดพลาด: ไม่สามารถหาค่ารากที่สองของจำนวนลบได้\n");
            return;
        }
        result = sqrt(x);
        printf("ผลลัพธ์: %.6f\n", result);
    } else if(choice == 3) {
        int n;
        printf("ป้อนจำนวนเต็มบวก: "); scanf("%d", &n);
        if(n < 0) {
            printf("❌ ข้อผิดพลาด: จำนวนต้องเป็นบวก\n");
            return;
        }
        printf("แฟกทอเรียลของ %d คือ %llu\n", n, factorial(n));
    } else {
        printf("❌ ตัวเลือกไม่ถูกต้อง\n");
    }
}

// ฟังก์ชันโหมดร้านค้า (POS) ตัวอย่างแค่เมนู
void mode_shop_pos() {
    printf("\n-- โหมดร้านค้า POS --\n");
    printf("[1] เพิ่มสินค้า [2] คำนวณรวม [3] ส่วนลด [4] ภาษี [5] เงินทอน [6] ใบเสร็จ [0] กลับ\n");
    printf("ฟีเจอร์ยังไม่พร้อมใช้งาน\n");
}

// ฟังก์ชันโหมดประวัติ (ตัวอย่าง)
void mode_history() {
    printf("\n-- โหมดประวัติ --\n");
    printf("[1] ดูประวัติ [2] ลบประวัติ [3] สถิติการใช้งาน [0] กลับ\n");
    printf("ฟีเจอร์ยังไม่พร้อมใช้งาน\n");
}

void app_main(void) {
    menu_state_t state = MENU_MAIN;
    int choice;

    while(state != MENU_EXIT) {
        switch(state) {
            case MENU_MAIN:
                show_main_menu();
                scanf("%d", &choice);
                switch(choice) {
                    case 0: state = MENU_EXIT; break;
                    case 1: state = MENU_BASIC; break;
                    case 2: state = MENU_ADVANCED; break;
                    case 3: state = MENU_SHOP; break;
                    case 4: state = MENU_HISTORY; break;
                    default:
                        printf("❌ ตัวเลือกไม่ถูกต้อง\n");
                        break;
                }
                break;

            case MENU_BASIC:
                mode_basic_calculator();
                state = MENU_MAIN;
                break;

            case MENU_ADVANCED:
                mode_advanced_math();
                state = MENU_MAIN;
                break;

            case MENU_SHOP:
                mode_shop_pos();
                state = MENU_MAIN;
                break;

            case MENU_HISTORY:
                mode_history();
                state = MENU_MAIN;
                break;

            default:
                state = MENU_MAIN;
                break;
        }
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }

    printf("ขอบคุณที่ใช้เครื่องคิดเลขครบครัน! ลาก่อน!\n");
}
