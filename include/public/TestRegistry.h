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

        std::vector<std::pair<std::string, std::function<void()>>> tests;

    public:
        TestRegistry(const TestRegistry&) = delete;
        TestRegistry& operator=(const TestRegistry&) = delete;
        TestRegistry(TestRegistry&&) = delete;
        TestRegistry& operator=(TestRegistry&&) = delete;

        static TestRegistry& instance();

        void Register(const std::string& name, const std::function<void()>& test);

        bool RunAllTests();
    };
}