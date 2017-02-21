### System Requirements
- Visual Studio 2015 (https://visualstudio.com/downloads)
- ReSharper C++ 2017.1 EAP 2 (https://download.jetbrains.com/resharper/JetBrains.ReSharperUltimate.2017.1.EAP2.exe)
- CMake (https://cmake.org/downloads)
- Boost (https://sourceforge.net/projects/boost/files/boost-binaries/1.61.0/boost_1_61_0-msvc-14.0-32.exe/download)

### Getting Started
1. Simply get a copy of the repo &mdash; clone or download straight.
2. Make directory `build` in the root directory of the repo.
3. Invoke command `cmake -G "Visual Studio 14 2015" -DBOOST_ROOT=_PATH_TO_BOOST_ ..` from the build directory.
4. Open generated solution `cpp-russia-2017.sln` in the Visual Studio and build it.

For example:
```
cd C:\
git clone https://github.com/AndreyG/cpp-russia-2017.git
cd cpp-russia-2017
mkdir build
cd build
cmake -G "Visual Studio 14 2015" -DBOOST_ROOT="C:/local/boost_1_61_0" ..
```
