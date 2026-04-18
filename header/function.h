#ifndef FUNCTION_H
#define FUNCTION_H

#ifdef __cplusplus
extern "C" {
#endif

	// Windows 类型兼容（确保 BOOL、DWORD 等可用）
#include <windows.h>

// 如果作为静态库或直接编译使用，可定义 UTILS_DLL_STATIC
// 否则默认按 DLL 导入处理
#ifdef UTILS_DLL_STATIC
#define UTILS_API
#else
#ifdef UTILS_DLL_EXPORTS
	// 编译 DLL 时导出
#define UTILS_API __declspec(dllexport)
#else
	// 使用 DLL 时导入
#define UTILS_API __declspec(dllimport)
#endif
#endif

// 1. 控制台错误打印
	__declspec(dllimport) int __stdcall error_(const char* error_information);

	// 2. 弹窗错误提示
	__declspec(dllimport) int __stdcall error_w(const char* error_information, const char* error_title);

	// 3. 隐藏输入（无回显）
	__declspec(dllimport) BOOL __stdcall hide_question(
		const char* question,
		char* output_buffer,
		size_t buffer_size
	);

	// 4. 带自定义字符（如 *）的密码输入
	// 返回实际输入长度（>=0），失败返回 -1
	__declspec(dllimport) int __stdcall hide_and_with(
		const char* question,
		char* output_buffer,
		size_t buffer_size,
		char hide_char
	);

	// 5. 获取命令行参数个数
	__declspec(dllimport) int __stdcall get_argc(void);

	// 6. 获取第 index 个命令行参数（UTF-8 编码）
	// buffer_size 应 >= 256 推荐
	__declspec(dllimport) BOOL __stdcall get_argv(int index, char* buffer, int buffer_size);

	// 7. 等待并返回用户按下的键
	// 返回值：
	//   > 0: 普通 ASCII 字符（如 'a' = 97）
	//   < 0: 特殊键（如 -72 = ↑, -80 = ↓）
	//   0: 错误
	__declspec(dllimport) int __stdcall wait_for_key(void);
	__declspec(dllimport) int __stdcall keybord_getch();
	__declspec(dllimport) int Error_windows(const char* Error);
	__declspec(dllimport) const char* string_add(const char* string1, const char* string2, int butter_size);
	__declspec(dllimport) void free_string(char* address);
	// 1. 定义回调函数的类型：无参，返回 char*
	typedef char* (*CallbackFunc)(void);

	// 2. 定义 DLL 中目标函数的类型：接受 CallbackFunc，返回 char*
	typedef char* (*DllFunction)(CallbackFunc);
	__declspec(dllimport) int run_dll_no_header(const char* dll_name, const char* function_name);
	__declspec(dllimport) int show_hide_cursor(int mode);
	__declspec(dllimport) int show_message(char* title, char* imformation, long enter);
	__declspec(dllimport) int check(const char* string1, const char* string2);

#ifdef __cplusplus
}
#endif

#endif // UTILS_DLL_H