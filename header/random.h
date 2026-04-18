// mylib.h

#ifndef MYLIB_H
#define MYLIB_H

#ifdef _WIN32
#ifdef MYLIB_EXPORTS
#define MYLIB_API __declspec(dllexport)
#else
#define MYLIB_API __declspec(dllimport)
#endif
#else
    // 支持 GCC/Clang（Linux/macOS）：默认无修饰
#define MYLIB_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

    // 生成 [small_number, large_number] 范围内的随机整数
    MYLIB_API int radom(int small_number, int large_number);

    // 从字符串中随机返回一个字符（包括可能返回 '\0'）
    MYLIB_API char radon_str(char* string, int index);

#ifdef __cplusplus
}
#endif

#endif // MYLIB_H