# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(Search_Binary Search_Bin.c Search_Bin.h Search_Bin_main.c SSTable.h)
# 链接公共库
target_link_libraries(Search_Binary Scanf_lib)