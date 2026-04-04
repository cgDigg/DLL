/* int_str.h */

#ifndef INT_STR_H
#define INT_STR_H

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * 将整数转换为字符串（动态分配内存）
	 * 调用者必须调用 free_str() 释放返回的指针
	 */
	__declspec(dllimport) char* change_int_to_str(int string);

	/*
	 * 释放由 change_int_to_str 分配的字符串内存
	 * 成功返回 0
	 */
	__declspec(dllimport) int free_str(char* str);

#ifdef __cplusplus
}
#endif

#endif /* INT_STR_H */