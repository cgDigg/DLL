@echo off
setlocal


if exist "%cd%\make.bat" (
    echo 执行 make.bat...
    call make.bat
    if errorlevel 1 (
        echo fail: make failed
        echo fail >> result.txt
        exit /b 1
    )


    if not exist "build\CMakeCache.txt" (
        echo error:no setup file
        echo fail >> result.txt
        exit /b 1
    )

    echo build....
    cmake --build build --config Release
    if errorlevel 1 (
        echo error: build failed
        echo fail >> result.txt
        exit /b 1
    )


    if exist "build\Release\" (

        if exist "result\" rmdir /s /q result
        move "build\Release" "result"
        if errorlevel 1 (
            echo error: can not rename file
            echo fail >> result.txt
            exit /b 1
        )
    ) else (
        exit /b 1
    )

) else (
    echo fail: NO make.bat
    echo fail >> result.txt
    exit /b 1
)

echo success
echo success >> result.txt
exit /b 0