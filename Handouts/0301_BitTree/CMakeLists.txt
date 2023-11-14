# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(BitTree_M BitTree.cpp BitTree_main.cpp
        ../0304_BitSortTree/BSTree.cpp
        ../0304_BitSortTree/BSTree_main.cpp
        ../0305_BalanceTree/BalanceTree.cpp
        ../0305_BalanceTree/BalanceTree_main.cpp
        ../0306_BiThrTree/BiThrTree.cpp
        ../0306_BiThrTree/BiThrTree_main.cpp
        ../0307_CSTree/CSTree.cpp)

set_target_properties(BitTree_M PROPERTIES LINKER_LANGUAGE CXX)

# 链接公共库
target_link_libraries(BitTree_M Scanf_lib)
