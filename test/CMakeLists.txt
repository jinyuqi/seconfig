find_package(GTest REQUIRED)

add_executable(ut_seconfig ut_seconfig.cpp)
target_link_libraries(ut_seconfig PRIVATE GTest::Main seconfig)
