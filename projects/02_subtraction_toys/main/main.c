#include <stdio.h>

void app_main(void) {
    // แบบฝึกหัดที่ 1: เปลี่ยนจำนวนของเล่น
    int toys_at_home = 15;     // ของเล่นที่บ้าน
    int toys_give_away = 7;    // แจกไป

    printf("=== ของเล่นของน้อง ===\n");
    printf("น้องมีของเล่นอยู่: %d ชิ้น\n", toys_at_home);
    printf("แจกให้เพื่อน: %d ชิ้น\n", toys_give_away);

    // แบบฝึกหัดที่ 2: ตรวจสอบของเล่นพอแจกไหม
    if (toys_at_home >= toys_give_away) {
        printf("✅ ของเล่นพอแจก\n");
    } else {
        printf("❌ ของเล่นไม่พอ! ขาดไป %d ชิ้น\n", toys_give_away - toys_at_home);
    }

    // คำนวณของเล่นที่เหลือ
    int toys_remaining = toys_at_home - toys_give_away;
    printf("ของเล่นที่เหลือ: %d ชิ้น\n", toys_remaining);

    // แบบฝึกหัดที่ 3: เพิ่มของเล่นประเภทอื่น
    int dolls = 5;        // ตุ๊กตา
    int robots = 2;       // หุ่นยนต์
    int total_toys = toys_remaining + dolls + robots;

    printf("🪆 ตุ๊กตา: %d ตัว\n", dolls);
    printf("🤖 หุ่นยนต์: %d ตัว\n", robots);
    printf("🎯 ของเล่นทั้งหมด: %d ชิ้น\n", total_toys);

    // แบบฝึกหัดที่ 4: แจกของเล่นให้ 10 คน คนละ 2 ชิ้น
    int friends = 10;
    int toys_per_friend = 2;
    int total_needed = friends * toys_per_friend;

    printf("👦👧 เพื่อนทั้งหมด: %d คน, ต้องใช้ของเล่น: %d ชิ้น\n", friends, total_needed);

    if (total_toys >= total_needed) {
        printf("✅ ของเล่นเพียงพอสำหรับแจกเพื่อน\n");
    } else {
        printf("❌ ของเล่นไม่พอ! ขาดอีก %d ชิ้น\n", total_needed - total_toys);
    }
}
