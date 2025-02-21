#include <Arduino.h>
#include <unity.h>
#include <key.h>

// 被测试的函数
int add(int a, int b) {
    return a + b;
}

void test_add_function() {
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(-1, add(-2, 1));
    TEST_ASSERT_EQUAL(0, add(0, 0));
}

void setup() {
    // 初始化 Unity 测试框架
    UNITY_BEGIN();

    // 运行测试
    RUN_TEST(test_add_function);

    // 结束测试
    UNITY_END();
}

void loop() {
    // 空循环
}
