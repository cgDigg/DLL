#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define def __declspec(dllexport)

// 辅助宏：检查指针是否由 malloc 分配（通过是否含空格判断）
// 但我们其实不需要加引号，所以根本不需要 malloc！

// 所有函数直接使用原始路径，不加引号！
def int free_sth(void* ptr) {
    if (!ptr) return -1;
    free(ptr) ;
    return 0;
}
def int cmd(char* command) {
    if (!command) return -1;
    int ret = system(command);
    return (ret == 0) ? 0 : -1;
}

def int copy(const char* src, const char* des) {
    if (!src || !des) return -1;
    return CopyFileA(src, des, FALSE) ? 0 : -1;
}

def int move(const char* src, const char* des) {
    if (!src || !des) return -1;
    return MoveFileA(src, des) ? 0 : -1;
}

def int Rename(const char* src, const char* des) {
    // rename == move in Windows
    return move(src, des);
}

def int rmfile(const char* path) {
    if (!path) return -1;
    return DeleteFileA(path) ? 0 : -1;
}

def int rmdir(const char* path) {
    if (!path) return -1;
    // RemoveDirectoryA 只能删除空目录
    return RemoveDirectoryA(path) ? 0 : -1;
}

def int mkdir(const char* path) {
    if (!path) return -1;
    return CreateDirectoryA(path, NULL) ? 0 : -1;
}
def char* input(char* question) {
    if (!question) return -1;
    printf("%s", question);
    char buf[1024];
    fgets(buf, 1024, (__acrt_iob_func(0)));
    return buf;
}
// 如果你确实需要递归删除非空目录，需自己实现（较复杂）