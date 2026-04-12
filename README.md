# Native DLL Collection (`dll`)

> **Language:** English · [简体中文](README.zh-CN.md)

A CMake-based Windows project that builds multiple shared libraries (`.dll`) in one solution—utilities, math helpers, and Python C API bridges.

---

## Table of contents

- [Native DLL Collection (`dll`)](#native-dll-collection-dll)
  - [Table of contents](#table-of-contents)
  - [Overview](#overview)
  - [Built artifacts](#built-artifacts)
  - [Requirements](#requirements)
  - [Repository layout](#repository-layout)
  - [install](#install)
  - [Build](#build)
  - [Output layout](#output-layout)
  - [Python linkage](#python-linkage)
  - [Developer agreement](#developer-agreement)
  - [static](#static)
  - [License (MIT)](#license-mit)

---

## Overview

This repository contains C/C++ sources under `src/` and headers under `header/`. CMake defines several `SHARED` or `static`targets; some link against the Win32 API (`user32`, `shell32`), and two targets link against the Python 3.13 import library for embedding or extending Python from native code.

---

## Built artifacts

| Target (DLL) | Source | Notes |
|--------------|--------|-------|
| `function` | `src/function.c` | Links `user32`, `shell32` |
| `cmd` | `src/cmd.c` | — |
| `random` | `src/random.c` | — |
| `python_function` | `src/python_function.c` | Links `lib/python313` |
| `value` | `src/value.c` | Extra include: `header` |
| `int_str` | `src/int_str.cpp` | C++ |
| `maths` | `src/maths.c` | — |
| `python` | `src/python.c` | Links `lib/python313`; includes `header/include` |
| `times` | `src/time.c` | — |
| `cpuid` | `cpu.asm`, `lib/cpu.c` | MASM at repo root (avoids VS `Release\\src\\` obj path bug) |

---

## Requirements

| Item | Details |
|------|---------|
| OS | Windows (MSVC toolchain) |
| CMake | ≥ 3.20 |
| Generator | Visual Studio (e.g. solution under `result`) |
| Python (optional) | Python 3.13 dev files: `python313.lib` and matching `python313.dll` under `lib/` for `python` / `python_function` targets |

---

## Repository layout

```text
dll/
├── build/              # CMake / VS build tree (generated)
├── build.bat           # One-click Release build + stage to result/
├── header/             # Project headers; Python headers may be referenced from here for some targets
├── lib/                # e.g. python313.lib, python313.dll (link / runtime)
├── result/             # Staged output after build.bat (see below)
├── src/                # C/C++ sources      
├── install.bat         #install tool bat
├── bat/                # Batch files
```

Keep generated files under `build/`; treat `result/` as a staging folder for redistributable binaries.

---

## install
after install, you can find the install path in `install.bat`
```bat
install.bat
```

---

## Build

1. Ensure the CMake project is configured (e.g. Visual Studio solution already generated under `build/Release`).
2. From the repository root, run:
```bat
build.bat
```
3. This runs `cmake --build build/Release --config Release` and then copies the Release output into `result/`.

To reconfigure CMake from scratch (example):

```bat
cmake -S build/Release -B build/Release -G "Visual Studio 17 2022" -A x64
```

Adjust the generator and paths if your `CMakeLists.txt` location or build folder layout differs.

---

## Output layout

After a successful `build.bat` run, under `result/Release` you typically get:

- **`dll/`** — built `.dll` files  
- **`lib/`** — import `.lib` files  
- Intermediate `.exp` files are removed in the script where applicable.

---

## Python linkage

Targets `python` and `python_function` link against `lib/python313`. To use another Python version, update the import library path and include directories in `CMakeLists.txt` and ensure the runtime `python3xx.dll` matches.

---

## Developer agreement

When using materials from this project (including this documentation, source code, and build outputs), you agree to the following:

1. **No illegal use.** You must not use project files or artifacts for unlawful purposes, including but not limited to attacks, malware, fraud, or other harmful or criminal activity.
2. **Do not alter the original terms.** You must not remove or change this developer agreement or the MIT license as distributed with the project. Any redistribution must keep these terms intact and clearly associated with the same materials.
3. **No meaningless public distribution.** You must not create meaningless, empty, or deliberately misleading derivative content based on this project and publish it publicly (for example spam repositories, junk forks, or reposts presented as substantive original work).

---

## static
We set the `static` compile mode for all targets.
you can only find this line in `CMakeLists.txt`:
```cmake
if(0)
```
and change it to `if(1)` and rebuild,you can get static library.


## License (MIT)

This project is licensed under the [MIT License](LICENSE).

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
