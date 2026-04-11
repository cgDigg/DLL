#include "Python.h"
#include <stdio.h>

__declspec(dllexport) int init_python(void)
{
    Py_Initialize();
    return 0;
}
__declspec(dllexport) int exit_python(void)
{
    Py_Finalize();
    return 0;
}
__declspec(dllexport) int run_python(char *file)
{
    if (!file) return -1;
    FILE *fp = fopen(file, "rb");
    if (!fp) return -1;
    int r = PyRun_SimpleFileExFlags(fp, file, 1, NULL);
    return r;
}   
__declspec(dllexport) int run_python_string(char *code)
{
    if (!code) return -1;
    return PyRun_SimpleStringFlags(code, NULL);
}

__declspec(dllexport) void cmd_python(void) {
    PyRun_InteractiveLoopFlags(stdin, "<stdin>", NULL);
}
