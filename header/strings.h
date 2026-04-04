#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#pragma comment(lib, "string.lib")
#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief Returns the length of the input string.
	 *
	 * @param str Pointer to the null-terminated string.
	 * @return int Length of the string, or -1 if str is NULL.
	 */
	__declspec(dllimport) int string_length(const char* str);

	/**
	 * @brief Compares two strings for equality.
	 *
	 * @note There is a bug in the original implementation: it compares string2 with itself.
	 *       This header assumes the intended behavior is to compare string1 and string2.
	 *
	 * @param string1 First string.
	 * @param string2 Second string.
	 * @return int
	 *         - -1 if either string is NULL,
	 *         - 0 if strings are equal,
	 *         - 1 if strings are different.
	 */
	__declspec(dllimport) int strings_check(char* string1, char* string2);

	/**
	 * @brief Concatenates two strings into a newly allocated buffer.
	 *
	 * @param string1 First string (must not be NULL).
	 * @param string2 Second string (must not be NULL).
	 * @param butter_size Size of the allocated buffer (must be > strlen(string1)+strlen(string2)).
	 * @return const char* Pointer to concatenated string on success, NULL on failure.
	 *         The caller must free the returned pointer using string_free().
	 */
	__declspec(dllimport) const char* string_add(char* string1, char* string2, int butter_size);

	/**
	 * @brief Frees memory allocated by string_add.
	 *
	 * @param str Pointer returned by string_add.
	 */
	__declspec(dllimport) void string_free(const char* str);

#ifdef __cplusplus
}
#endif

#endif // STRING_UTILS_H