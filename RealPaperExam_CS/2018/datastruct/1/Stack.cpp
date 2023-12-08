//
// Created by maicaoboy on 2023/12/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define Status int
/**
 * 使用num记录栈中的元素个数,num初始值未0, 遍历字符串,遇到A则num-1,D则num+1,zai遇到A时若num==0则为非法,否则遍历完数组即为合法
 * @param s
 */

Status isOk(const char *s) {
    int num = 0;
    for (const char *p = s; *p != '\0'; p++) {
        if(*p == 'D') {
            num++;
        }else {
            if(num == 0) {
                return false;
            }
            num--;
        }
        p++;
    }
    return true;
}
