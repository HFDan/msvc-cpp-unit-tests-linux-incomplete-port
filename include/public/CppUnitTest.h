#pragma once
#include <memory>

#include <TestRegistry.h>
#include <CppUnitTestAssert.h>
#if !__has_include("cxxabi.h")
#error "Library cxxabi.h must be available"
#endif
#include <cxxabi.h>

static inline std::string demangle(const char* name) {
    int status = -1;
    const std::unique_ptr<char, void(*)(void*)> result {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };

    return (status == 0) ? std::string(result.get()) : name;
}

#define TEST_CLASS(CLASS_NAME)\
class CLASS_NAME##_impl;\
class CLASS_NAME { \
    protected:\
    using real_name = CLASS_NAME##_impl;\
};\
class CLASS_NAME##_impl: public CLASS_NAME

#define TEST_METHOD(METHOD_NAME)\
struct AutoRegister_##METHOD_NAME {\
    AutoRegister_##METHOD_NAME() {\
        std::string fullName = demangle(typeid(real_name).name());\
        fullName.erase(fullName.end() - 5, fullName.end());\
        fullName += ": ";\
        fullName += #METHOD_NAME;\
        auto& inst = Microsoft::VisualStudio::CppUnitTestFramework::TestRegistry::instance();\
        inst.Register(fullName,[]() -> void {\
            real_name instance;\
            instance.METHOD_NAME();\
        });\
    }\
};\
inline static AutoRegister_##METHOD_NAME _auto_##METHOD_NAME;\
void METHOD_NAME()