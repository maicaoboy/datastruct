# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(SqListH SqList.cpp SqList_main.cpp)

set_target_properties(SqListH PROPERTIES LINKER_LANGUAGE CXX)

# 链接公共库
target_link_libraries(SqListH Scanf_lib)
