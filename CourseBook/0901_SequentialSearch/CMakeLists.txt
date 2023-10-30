# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(Search_Seq Search_Seq.c Search_Seq.h SSTable.h SSTable-main.c)
# 链接公共库
target_link_libraries(Search_Seq Scanf_lib)