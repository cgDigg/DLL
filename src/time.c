#include <time.h>
#define a __declspec(dllexport)

struct tm get_utc_time(void) {
    time_t rawtime;
    struct tm tm_buf;
    time(&rawtime);
    gmtime_s(&tm_buf, &rawtime);
    return tm_buf;
}

struct tm get_local_time(void) {
    time_t rawtime;
    struct tm tm_buf;
    time(&rawtime);
    localtime_s(&tm_buf, &rawtime);
    return tm_buf;
}

a int get_current_year(void) {
    time_t rawtime;
    struct tm tm_buf;
    time(&rawtime);
    localtime_s(&tm_buf, &rawtime);
    return tm_buf.tm_year + 1900;
}

a int get_current_month(void) {
    time_t rawtime;
    struct tm tm_buf;
    time(&rawtime);
    localtime_s(&tm_buf, &rawtime);
    return tm_buf.tm_mon + 1;
}

a int get_current_day(void) {
    time_t rawtime;
    struct tm tm_buf;
    time(&rawtime);
    localtime_s(&tm_buf, &rawtime);
    return tm_buf.tm_mday;
}

a int get_current_hour(void) {
    time_t rawtime;
    struct tm tm_buf;
    time(&rawtime);
    localtime_s(&tm_buf, &rawtime);
    return tm_buf.tm_hour;
}

a int get_current_minute(void) {
    time_t rawtime;
    struct tm tm_buf;
    time(&rawtime);
    localtime_s(&tm_buf, &rawtime);
    return tm_buf.tm_min;
}

a int get_current_second(void) {
    time_t rawtime;
    struct tm tm_buf;
    time(&rawtime);
    localtime_s(&tm_buf, &rawtime);
    return tm_buf.tm_sec;
}