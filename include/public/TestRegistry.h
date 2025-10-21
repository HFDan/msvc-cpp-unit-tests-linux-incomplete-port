#pragma once
#include <utility>
#include <vector>
#include <string>
#include <functional>
namespace Microsoft::VisualStudio::CppUnitTestFramework {
    class TestRegistry final {
    private:
        TestRegistry() = default;
        ~TestRegistry() = default;

        TestRegistry(const TestRegistry&) = delete;
        TestRegistry& operator=(const TestRegistry&) = delete;
        TestRegistry(TestRegistry&&) = delete;
        TestRegistry& operator=(TestRegistry&&) = delete;

        std::vector<std::pair<std::string, std::function<void()>>> tests;

    public:
        static TestRegistry& instance();

        void Register(const std::string& name, std::function<void()> test);

        bool RunAllTests();
    };
}