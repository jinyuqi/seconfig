#
# Author: Jin Yuqi (Ricky)
# Email: 179386223@qq.com
# Date: 2018.08.02
#

find_package(GTest REQUIRED)

add_executable(ut_seconfig ut_seconfig.cpp)
target_link_libraries(ut_seconfig PRIVATE GTest::Main seconfig)
