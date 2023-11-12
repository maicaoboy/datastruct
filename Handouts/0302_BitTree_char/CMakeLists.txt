# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(BitTreeChar_M BitTree.cpp BitTree_main.cpp)

set_target_properties(BitTreeChar_M PROPERTIES LINKER_LANGUAGE CXX)

# 链接公共库
target_link_libraries(BitTreeChar_M Scanf_lib)
