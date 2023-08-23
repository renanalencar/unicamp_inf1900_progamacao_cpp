
# Atividade prática 2: Funções, Ponteiros e Strings

Desenvolva um programa que utilize uma matriz de caracteres para simular uma tela de arte ASCII com uma dimensão
inicial de 20x40, para isso use alocação dinâmica de memória.

## Referência

- [Using GCC with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)
- [Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux)
- [Step 1: A Basic Starting Point](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html#)
- [Error while configuring CMake project: Running 'nmake' '-?' failed](https://stackoverflow.com/questions/69338088/error-while-configuring-cmake-project-running-nmake-failed)
## Autores
- [@rottaveira](https://www.github.com/rottaveira)
- [@renanalencar](https://www.github.com/renanalencar)


## Deploy

Para fazer o deploy desse projeto rode

```bash
  cmake -S . -B Build -G "MinGW Makefiles"
  cmake --build INF1900_M1_lab2\
  make matriz
```

