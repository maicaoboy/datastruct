# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(Search_Binary_Sort_Tree  BiTree.c BiTree.h BSTree.h BSTree.c BSTree_main.c)
# 链接公共库
target_link_libraries(Search_Binary_Sort_Tree Scanf_lib)