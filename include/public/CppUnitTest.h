#pragma once
#include <TestRegistry.h>
#include <CppUnitTestAssert.h>

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
        std::string fullName = typeid(real_name).name();\
        fullName.erase(fullName.end()-5, fullName.end());\
        while (fullName[0] >= '0' && fullName[0] <= '9') {\
            fullName.erase(fullName.begin());\
        }\
        fullName += ": " #METHOD_NAME;\
        auto& inst = Microsoft::VisualStudio::CppUnitTestFramework::TestRegistry::instance();\
        inst.Register(fullName,[]() -> void {\
            real_name instance;\
            instance.METHOD_NAME();\
        });\
    }\
};\
inline static AutoRegister_##METHOD_NAME _auto_##METHOD_NAME;\
void METHOD_NAME()