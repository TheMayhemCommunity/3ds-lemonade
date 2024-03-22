@echo off
mkdir build
cd build
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 %*
cmake .. -G "Visual Studio 17 2022" -DUSE_SYSTEM_SDL2=ON -DALLOW_EXTERNAL_SPIRV_TOOLS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DENABLE_QT_TRANSLATION=ON -DCITRA_ENABLE_COMPATIBILITY_REPORTING=ON -DSDL2_LIBRARY="D:\TMC\3ds-lemonade\externals/sdl2/SDL2.lib" -DSDL2_INCLUDE_DIR="D:\TMC\3ds-lemonade\externals/sdl2/SDL/include" -DENABLE_COMPATIBILITY_LIST_DOWNLOAD=ON -DUSE_DISCORD_PRESENCE=ON
msbuild citra.sln /verbosity:minimal /property:Configuration=Release
cd ..