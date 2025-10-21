#include <TestRegistry.h>

int main(int argc, char *argv[]) {
    auto& inst = Microsoft::VisualStudio::CppUnitTestFramework::TestRegistry::instance();

    inst.RunAllTests();
}