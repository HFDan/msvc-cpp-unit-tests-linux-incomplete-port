#include <CppUnitTest.h>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(lmao) {
    TEST_METHOD(Equals1) {
        Assert::AreEqual(5, 5);
    }

    TEST_METHOD(Equals2) {
        Assert::AreEqual("aaa", "aAa", true);
    }

    TEST_METHOD(Equals3) {
        Assert::AreEqual(std::string("lmao").c_str(), std::string("aAa").c_str(), false, "Hey this is a test fail msg");
    }

    TEST_METHOD(Equals4) {
        Assert::AreEqual(std::tuple<int, int>(2, 2), std::tuple<int, int>(2, 2));
    }
};