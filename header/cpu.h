#ifndef CPU_H
#define CPU_H
#define API __declspec(dllexport)
#if __cplusplus
extern "C" {
#endif
API char* GetCpuVendor();
#if __cplusplus
}
#endif
#endif
