# tugas-grafika-komputer
Tugas Mata Kuliah Grafika Komputer 2019

## PC Requirment
- Anything that have monitor will do
- Ubuntu or Windows

## Development Environment Setup
### For Ubuntu
```bash
sudo apt-get update
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

### For Windows
- Download & Install MinGW (https://www.ics.uci.edu/~pattis/common/handouts/mingweclipse/mingw.html)
- Download freeglut for MinGW Package (https://www.transmissionzero.co.uk/software/freeglut-devel/)
- Extract `bin`, `include`, and `lib` folder from freeglut package to MinGW installation folder (Default: `C:\MinGW`)
- Restart

## How To Compile and Run Program
### For Ubuntu
Compile:
```bash
g++ filename.cpp -o filename.out -lglut -lGLU -lGL
```
Run:
```bash
./filename.out
```

### For Windows
Compile:
```cmd
g++ filename.cpp -o filename.exe -lfreeglut -lglu32 -lopengl32
```
Run:
```cmd
filename.exe
```

## Reference
- http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/
- https://www.ics.uci.edu/~pattis/common/handouts/mingweclipse/mingw.html
- https://www3.ntu.edu.sg/home/ehchua/programming/opengl/HowTo_OpenGL_C.html