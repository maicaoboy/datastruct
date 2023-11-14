# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(LinkListCircle_Char_M LinkList_char.cpp LinkList_main_char.cpp)

set_target_properties(LinkListCircle_Char_M PROPERTIES LINKER_LANGUAGE CXX)

# 链接公共库
target_link_libraries(LinkListCircle_Char_M Scanf_lib)
