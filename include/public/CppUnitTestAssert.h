#pragma once
#include <algorithm>
#include <stdexcept>

namespace Microsoft::VisualStudio::CppUnitTestFramework {
    namespace Assert {
        // Equality
        template<typename T>
        static void AreEqual(const T& expected, const T& actual, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed AreEqual assert" : message;
            if (expected != actual) throw std::runtime_error(final_msg);
        }

        template<>
        void AreEqual(const double&, const double&, const char*) = delete;
        template<>
        void AreEqual(const float&, const float&, const char*) = delete;

        template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
        static void AreEqual(T expected, T actual, T tolerance, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed AreEqual assert" : message;
            const T diff = expected - actual;
            if (diff > tolerance) throw std::runtime_error(final_msg);
        }

        static void AreEqual(const char* expected, const char* actual, const bool ignoreCase = false, const char* message = nullptr) {
            std::string s1 = expected;
            std::string s2 = actual;
            if (ignoreCase) {
                std::ranges::transform(s1, s1.begin(), tolower);
                std::ranges::transform(s2, s2.begin(), tolower);
            }

            const char* final_msg = message == nullptr ? "Failed AreEqual assert" : message;
            if (s1 != s2) throw std::runtime_error(final_msg);

        }

        // Inequality
        template <typename T>
        static void AreNotEqual(const T& notExpected, const T& actual, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed AreNotEqual assert" : message;
            if (notExpected == actual) throw std::runtime_error(final_msg);
        }

        template<>
        void AreNotEqual(const double&, const double&, const char*) = delete;
        template<>
        void AreNotEqual(const float&, const float&, const char*) = delete;

        template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
        static void AreNotEqual(T notExpected, T actual, T tolerance, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed AreNotEqual assert" : message;
            const T diff = notExpected - actual;
            if (diff < tolerance) throw std::runtime_error(final_msg);
        }

        static void AreNotEqual(const char* notExpected, const char* actual, const bool ignoreCase = false, const char* message = nullptr) {
            std::string s1 = notExpected;
            std::string s2 = actual;
            if (ignoreCase) {
                std::ranges::transform(s1, s1.begin(), tolower);
                std::ranges::transform(s2, s2.begin(), tolower);
            }

            const char* final_msg = message == nullptr ? "Failed AreNotEqual assert" : message;
            if (s1 == s2) throw std::runtime_error(final_msg);
        }

        // Same
        template <typename T>
        static void AreSame(const T& expected, const T& actual, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed AreSame assert" : message;
            if (std::addressof(expected) != std::addressof(actual)) throw std::runtime_error(final_msg);
        }

        // Not same
        template <typename T>
        static void AreNotSame(const T& notExpected, const T& actual, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed AreNotSame assert" : message;
            if (std::addressof(notExpected) == std::addressof(actual)) throw std::runtime_error(final_msg);
        }

        // Is null
        static void IsNull(const auto* actual, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed IsNull assert" : message;
            if (actual != nullptr) throw std::runtime_error(final_msg);
        }

        // Is not null
        static void IsNotNull(const auto* actual, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed IsNotNull assert" : message;
            if (actual == nullptr) throw std::runtime_error(final_msg);
        }

        // Is true
        static void IsTrue(bool cond, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed IsTrue assert" : message;
            if (!cond) throw std::runtime_error(final_msg);
        }

        // Is false
        static void IsFalse(bool cond, const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed IsFalse assert" : message;
            if (cond) throw std::runtime_error(final_msg);
        }

        // Fail
        static void Fail(const char* message = nullptr) {
            const char* final_msg = message == nullptr ? "Failed" : message;
            throw std::runtime_error(final_msg);
        }
    }
}