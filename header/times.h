// time_utils.h（文件名 times.h，与 DLL / 应用共用）

#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#ifdef _WIN32
#ifdef TIME_UTILS_STATIC
#define TIME_API
#elif defined(TIME_UTILS_EXPORTS)
#define TIME_API __declspec(dllexport)
#else
#define TIME_API __declspec(dllimport)
#endif
#else
#define TIME_API
#endif

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

TIME_API struct tm get_utc_time(void);
TIME_API struct tm get_local_time(void);

TIME_API int get_current_year(void);
TIME_API int get_current_month(void);
TIME_API int get_current_day(void);
TIME_API int get_current_hour(void);
TIME_API int get_current_minute(void);
TIME_API int get_current_second(void);

#ifdef __cplusplus
}
#endif

#endif
