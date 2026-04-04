#include <windows.h>
#ifndef PYTHON_FUNCTION_H
#define PYTHON_FUNCTION_H

#ifdef __cplusplus
extern "C" {
#endif

	// 注意：这些函数由 DLL 导出，在 EXE 中应视为 dllimport
#if defined(PYTHON_FUNCTION_DLL_EXPORTS)
#define PYTHON_API __declspec(dllexport)
#else
#define PYTHON_API __declspec(dllimport)
#endif

// 修复：函数名应为 add_，参数类型补全
	PYTHON_API int add_(int number1, int number2);

	PYTHON_API int cmd_run(const char* cmd);
	PYTHON_API int python_in_path_test(void);
	PYTHON_API int print_str(const char* string);
	PYTHON_API int time_down(int time_ms);
	PYTHON_API int start_python(void);
	PYTHON_API int multiply(int a, int b);
	PYTHON_API int strings_equal(char* string1, char* string2);
	PYTHON_API int python_run_module(char* module_);

	// 修复：添加缺失的分号
	PYTHON_API int dll_run_int(char* dll, char* function_, char* argv);
	PYTHON_API int error(HWND hwnd, char* title, char* massege_);

#ifdef __cplusplus
}
#endif

#endif // PYTHON_FUNCTION_H