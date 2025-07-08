#include <gtest/gtest.h>
#include <iostream>
#include "stub.h"


int StubIncrease(int mum)
{
    std::cout << "StubIncrease excute !";
    return 1;
}


int Increase(int num)
{
    int tmp = ++num;
    std::cout << "Increased num = : " << tmp << std::endl;
    return tmp;
}


int OutNumber()
{
    int i = 1;
    i = Increase(1);
    std::cout << "out number = : " << i << std::endl;
    return i;
}



class TestClass
{
    public:
        int TestNum(int num)
        {
            return num + 2;
        }
};


int OutClassNum(int num)
{
    TestClass test;
    return test.TestNum(1);
}


// 一个简单的测试用例
TEST(SampleTest, Test1) {
    EXPECT_EQ(1, 1);
}


TEST(IncreaseTest, StubTest)
{
    Stub stub;
    typedef int (*fptr)(int);
    fptr ptr_Increase = (fptr)(&Increase);   //获取函数地址
    stub.set(ptr_Increase, StubIncrease);
    int i = OutNumber();
    EXPECT_EQ(i, 1);
    stub.reset(ptr_Increase);
}


TEST(IncreaseNumTest, ClassMethodTest)
{
    Stub stub; 
    stub.set(ADDR(TestClass, TestNum), StubIncrease);
    int j = OutClassNum(2);
    EXPECT_EQ(j, 1);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

