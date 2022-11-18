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
cmake -DENABLE_TESTING ..
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

