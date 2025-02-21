#include <Arduino.h>
#include <unity.h>
#include <key.h>

// �����Եĺ���
int add(int a, int b) {
    return a + b;
}

void test_add_function() {
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(-1, add(-2, 1));
    TEST_ASSERT_EQUAL(0, add(0, 0));
}

void setup() {
    // ��ʼ�� Unity ���Կ��
    UNITY_BEGIN();

    // ���в���
    RUN_TEST(test_add_function);

    // ��������
    UNITY_END();
}

void loop() {
    // ��ѭ��
}
