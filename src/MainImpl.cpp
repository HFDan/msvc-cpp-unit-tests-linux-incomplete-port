#include <cstdlib>
#include <TestRegistry.h>

int main(int argc, char *argv[]) {
    auto& inst = Microsoft::VisualStudio::CppUnitTestFramework::TestRegistry::instance();

    if (!inst.RunAllTests()) return EXIT_SUCCESS;
    else return EXIT_FAILURE;
}