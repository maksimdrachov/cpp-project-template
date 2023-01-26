# C++ project template

A template for a modern C++ project that follows good practices such as:

- checking for memory leaks (`valgrind`)
- static analysis (`clang-tidy`)
- code formatting (`clang-format`)
- unit testing (`googletest`)
- code coverage statistics (`gcov/lcov`)
- build visualization (`graphviz`)

Continuous integration is handled automatically by:

- `Github` actions (upon pushing to the repo), or
- `Jenkins` automation server (running locally)

Documentation is generated using `doxygen`, hosted by Github pages.

Tested on Ubuntu.

## Getting started

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
rm CMakeCache.txt
cmake -DENABLE_TESTING=ON ..
cmake --build . --target unit_tests
cd tests
./unit_tests
```

- Code coverage (`gcov`)

```
cd build
rm CMakeCache.txt
cmake -DENABLE_TESTING=ON -DENABLE_COVERAGE -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --target coverage
```

- Check for memory leaks (`valgrind`)

```bash
cd build/app
valgrind --tool=memcheck ./main 6 3
```

- Static analysis (`clang-tidy`)

```bash
cd build
rm CMakeCache.txt
cmake -DENABLE_CLANG_TIDY=ON ..
cmake --build . --target main
```

- Formatting code (`clang-format`)

```bash
cd build
rm CMakeCache.txt
cmake -DENABLE_CLANG_FORMAT=ON ..
cmake --build . --target clang-format
```

In case you want to preserve the special formatting of a particular code block such as a matrix initialization, add the following directives around the block:

```cpp
// clang-format off
Mat4<Scalar> m;
m(0, 0) = x[0]; m(0, 1) = x[1]; m(0, 2) = x[2]; m(0, 3) = -dot(x, eye);
m(1, 0) = y[0]; m(1, 1) = y[1]; m(1, 2) = y[2]; m(1, 3) = -dot(y, eye);
m(2, 0) = z[0]; m(2, 1) = z[1]; m(2, 2) = z[2]; m(2, 3) = -dot(z, eye);
m(3, 0) = 0.0;  m(3, 1) = 0.0;  m(3, 2) = 0.0;  m(3, 3) = 1.0;
// clang-format on
```

- Build visualization (`graphviz`)

```bash
cd build
rm CMakeCache.txt
cmake --graphviz=build.dot ..
cmake --build . --target main
dot -Tpng -o build.png build.dot #convert to png image
```

[additional info](https://cmake.org/cmake/help/latest/module/CMakeGraphVizOptions.html)

## Additional useful commands

- Valgrind
  - Memory profiling: collect information about how your program uses memory
  ```bash
  valgrind --tool=massif program_name
  ```  
  - Threading errors: detect and diagnose errors related to the use of threads
  ```bash
  valgrind --tool=helgrind program_name
  ```  
  - IO errors: detect and diagnose errors related to input/output operations 
  ```bash
  valgrind --tool=lackey program_name
  ```  
  - Cachegrind: collect detailed information about the use of the cache memory
  ```bash
  valgrind --tool=cachegrind program_name
  ```
  - Massif: collect detailed information about the memory usage of your program over time
  ```bash
  valgrind --tool=massif --time-unit=ms program_name
  ```

## Jenkins

Upon installing Jenkins (inside a Docker container):

1. Install Docker plugin
2. Dashboard -> Manage Jenkins -> Configure Clouds
   - Add a new cloud: Docker
   - Docker cloud details
     - Docker Host URL: `tcp://172.18.0.3:2375`
     - Enabled: Turn on
3. Create a job
   - Pipeline
   - General
     - GitHub project: `https://github.com/maksimdrachov/cpp-project-template`
     - Build Triggers - Poll SCM: `* * * * *` (Poll every minute)
   - Pipeline
     - Definition: Pipeline script from SCM
     - SCM: Git
       - Repository URL: `https://github.com/maksimdrachov/cpp-project-template`
     - Script Path: Jenkinsfile

## Github actions

## Sources

[kigster/cmake-project-template](https://github.com/kigster/cmake-project-template)

[An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/)

[A very clean example of a C++ library](https://github.com/pmp-library/pmp-library)

[Another C++ project template](https://github.com/franneck94/CppProjectTemplate)

[Code Coverage Testing for C++](https://www.danielsieger.com/blog/2022/03/06/code-coverage-for-cpp.html)

[Using clang-tidy with CMake](https://www.danielsieger.com/blog/2021/12/21/clang-tidy-cmake.html)

## TODO

- [ ] Add doc/doxygen
- [ ] Add GitHub actions
- [ ] Add badges

