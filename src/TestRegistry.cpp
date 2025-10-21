#include <TestRegistry.h>
#include <print>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TestRegistry& TestRegistry::instance() {
    static TestRegistry instance;
    return instance;
}

void TestRegistry::Register(const std::string& name, std::function<void()> test) {
    tests.emplace_back(name, test);
}

void TestRegistry::RunAllTests() {
    for (const auto& [name, func] : tests) {
#if !defined(_WIN32)
        std::print("[ {:^4} ] {}", "Run", name);
        try {
            func();
            std::println("\033[2K\r[ \033[32m{:^4}\033[0m ] {}", "Ok", name);
        } catch (const std::exception& e) {
            std::println("\033[2K\r[ \033[31m{:^4}\033[0m ] {}: {}", "Fail", name, e.what());
        }
#else
        std::println("[ {:^4} ] {}", "Run", name);
        try {
            func();
            std::println("[ {:^4} ] {}", "Ok", name);
        } catch (const std::exception& e) {
            std::println("[ {:^4} ] {}: {}", "Fail", name, e.what());
        }
#endif
    }
}