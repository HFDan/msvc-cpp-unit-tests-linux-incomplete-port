add_executable(testingexec ${PROJECT_SOURCE_DIR}/testApp/testApp.cpp)
target_link_libraries(testingexec PRIVATE msvctest::msvctest)
