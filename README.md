# NEO

## Dependence
[Click here](./thirdparty/README.md)

## Clone
```
git clone git@github.com:Shirasawa-CN/Neo.git
```

## Build
### linux
```
cd /thirdparty/scintilla/qt/ScintillaEdit
python3 ./WidgetGEn.py
qmake
make

cd ../../../
cmake

```

### windows
powershell
```
cd ../qt/ScintillaEdit
qmake6
```

REALEASE

```
nmake
```

DEBUG

```
nmake /F Makefile.Debug
```



