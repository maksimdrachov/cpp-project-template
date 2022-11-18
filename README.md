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
cmake -DENABLE_COVERAGE ..
cmake --build . --target coverage
```