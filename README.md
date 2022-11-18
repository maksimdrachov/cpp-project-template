- Configure, build and run executable:

```bash
cd build
cmake ..
cmake --build . --target main
cd app
./main
```

- Unit testing (`googletest`)

```bash
cd build 
cmake -DENABLE_TESTING=ON ..
cmake --build . --target unit_tests
cd tests
./unit_tests
```

- Code coverage (`gcov`)

```
cd build
cmake -DENABLE_TESTING=ON -DENABLE_COVERAGE -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --target coverage
```

- Check for memory leaks (`valgrind`)

```bash
cd build/app
valgrind --leak-check=yes ./main 6 3
```

- Static analysis (`clang-tidy`)

```bash
cd build
cmake -DENABLE_CLANG_TIDY=ON ..
cmake --build . --target main
```

- Formatting code (`clang-format`)

```bash
cd build
cmake -DENABLE_CLANG_FORMAT=ON ..
cmake --build . --target clang-format
```

- Build visualization (`graphviz`)

```bash
cd build
cmake --graphviz=build.dot ..
cmake --build . --target main
dot -Tpng -o build.png build.dot #convert to png image
```

[info](https://cmake.org/cmake/help/latest/module/CMakeGraphVizOptions.html)