cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加 include 目录
include_directories(include)

# 查找 src 目录下的所有源文件，并将列表存储在 SRC_FILES 变量中
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# 将 main.cpp 添加到源文件列表
list(APPEND SRC_FILES main.cpp)

# 添加库文件夹，如果有静态库或动态库可以在这里指定
# link_directories(lib)

# 将所有源文件编译成一个可执行文件
add_executable(MyProject ${SRC_FILES}
        include/mystl.h
        src/mystl.cpp
        test/test_string.cpp
        test/test_vector.cpp
        test/test_list.cpp
        include/test.h
        test/test_queue_stack.cpp
        test/test_priority_queue.cpp
)