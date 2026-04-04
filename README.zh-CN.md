﻿# 原生 DLL 工程（`dll`）

> **语言：** 简体中文 · [English](README.md)

基于 CMake 的 Windows 工程，在同一解决方案中编译多个动态链接库（`.dll`），涵盖通用工具、数学相关模块以及与 Python C API 交互的桥接库。

---

## 目录

1. [概述](#概述)
2. [构建产物](#构建产物)
3. [环境要求](#环境要求)
4. [仓库结构](#仓库结构)
5. [编译](#编译)
6. [输出目录](#输出目录)
7. [Python 链接说明](#python-链接说明)
8. [开发者协议](#开发者协议)
9. [MIT 许可证](#mit-许可证)

---

## 概述

源码位于 `src/`，头文件位于 `header/`。CMake 将工程拆为多个 `SHARED`（动态库）目标；部分目标链接 Windows 用户接口相关库（`user32`、`shell32`）；另有目标链接 Python 3.13 的导入库，用于在原生代码中与 Python C API 交互。

---

## 构建产物

| 目标（DLL） | 源文件 | 说明 |
|-------------|--------|------|
| `function` | `src/function.c` | 链接 `user32`、`shell32` |
| `cmd` | `src/cmd.c` | — |
| `random` | `src/random.c` | — |
| `python_function` | `src/python_function.c` | 链接 `lib/python313` |
| `value` | `src/value.c` | 额外包含路径：`header` |
| `int_str` | `src/int_str.cpp` | C++ |
| `maths` | `src/maths.c` | — |
| `python` | `src/python.c` | 链接 `lib/python313`；包含 `header/include` |
| `times` | `src/time.c` | — |

---

## 环境要求

| 项目 | 说明 |
|------|------|
| 操作系统 | Windows，使用 MSVC 工具链 |
| CMake | 版本不低于 3.8 |
| 生成器 | 例如已生成的 Visual Studio 解决方案（如 `build/Release` 下） |
| Python（可选） | 若编译含 Python 的目标：在 `lib/` 放置 `python313.lib` 及匹配的 `python313.dll`（头文件路径见 CMake） |

---

## 仓库结构

```text
dll/
├── build/              # CMake / VS 生成目录
├── build.bat           # 一键 Release 构建并整理到 result/
├── header/             # 工程头文件；部分目标从此引用 Python 头文件
├── lib/                # 如 python313.lib、python313.dll（链接 / 运行）
├── result/             # build.bat 执行后的整理输出（见下文）
├── src/                # C/C++ 源码
└── special/            # 项目自用附加目录（若使用）
```

`build/` 存放生成文件；`result/` 为脚本整理后的输出目录，便于分发或测试。

---

## 编译

1. 确认已完成 CMake 配置（例如已在 `build/Release` 下生成 Visual Studio 工程）。
2. 在仓库根目录执行：

   ```bat
   build.bat
   ```

3. 脚本会执行 Release 构建，并将产物复制到 `result` 目录。

若需重新配置 CMake，可根据本机环境修改生成器与路径，例如：

```bat
cmake -S build/Release -B build/Release -G "Visual Studio 17 2022" -A x64
```

若 `CMakeLists.txt` 位置或构建目录布局不同，请相应调整路径与生成器。

---

## 输出目录

`build.bat` 成功后，`result\Release` 下通常包含：

- **`dll/`** — 编译得到的 `.dll`  
- **`lib/`** — 导入库 `.lib`  
- 脚本会视情况删除中间产生的 `.exp` 等文件。

`.dll` 与 `.lib` 分目录存放，便于区分运行时库与导入库。

---

## Python 链接说明

`python` 与 `python_function` 当前链接 `lib/python313`。更换 Python 版本时，请在 `CMakeLists.txt` 中修改对应 `.lib` 路径与头文件目录，并保证运行时 `python3xx.dll` 版本一致。

---

## 开发者协议

使用本仓库中的任何资料（含本文档、源代码及构建产物）时，须遵守：

1. **禁止非法使用。** 不得以违法目的使用项目文件或产物，包括但不限于用于网络攻击、恶意软件、欺诈或其他有害、犯罪行为。
2. **不得更改原有协议。** 不得删除或篡改本开发者协议及随项目分发的 MIT 许可证正文；再分发时必须完整保留上述条款，并与相同资料一并提供且清晰可辨。
3. **禁止制作无意义内容并公开。** 不得基于本项目制作无实质内容、空洞或故意误导的衍生内容并公开发布（例如垃圾仓库、无意义的 fork、冒充原创的搬运等）。

---

## MIT 许可证

本项目采用 **MIT License**，完整条文见仓库根目录 [`LICENSE`](LICENSE) 文件。以下为许可证全文（以英文为准）：

```
MIT License

Copyright (c) 2026 dll project contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
