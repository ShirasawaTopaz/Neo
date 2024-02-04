# NEO

## Dependence
[Click here](./thirdparty/README.md)

## Clone
```
git clone git@github.com:Shirasawa-CN/Neo.git
```

## Build
### linux

<b>DO NOT USE build.sh</b>

```
cd thirdparty/Lua
make
cd ../Scintilla/gtk
make
cd ../qt/ScintillaEdit
mkdir build
python WidgetGen.py
cd build
qmake6 ..
make
cd ../../../../../
mkdir build
cd build
cmake ..
make
```

### windows
msys2
```
pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-qt6-base
```

powershell
```
cd /thirdparty/Scintilla/win32
mingw32-make 
cd ../qt
qmake6
mingw32-make

cd ../../../
cmake
```