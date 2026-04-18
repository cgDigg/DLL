#include <time.h>
#define TIME_API __declspec(dllexport)
TIME_API struct tm get_utc_time(void)
{
	time_t rawtime;
	struct tm tm_buf;

	time(&rawtime);
	gmtime_s(&tm_buf, &rawtime);
	return tm_buf;
}

TIME_API struct tm get_local_time(void)
{
	time_t rawtime;
	struct tm tm_buf;

	time(&rawtime);
	localtime_s(&tm_buf, &rawtime);
	return tm_buf;
}

TIME_API int get_current_year(void)
{
	struct tm t = get_local_time();

	return t.tm_year + 1900;
}

TIME_API int get_current_month(void)
{
	struct tm t = get_local_time();

	return t.tm_mon + 1;
}

TIME_API int get_current_day(void)
{
	struct tm t = get_local_time();

	return t.tm_mday;
}

TIME_API int get_current_hour(void)
{
	struct tm t = get_local_time();

	return t.tm_hour;
}

TIME_API int get_current_minute(void)
{
	struct tm t = get_local_time();

	return t.tm_min;
}

TIME_API int get_current_second(void)
{
	struct tm t = get_local_time();

	return t.tm_sec;
}
