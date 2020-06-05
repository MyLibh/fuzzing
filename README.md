# Fuzzing

### Links

1. [libFuzzer](https://llvm.org/docs/LibFuzzer.html)
2. [Presentation[EN]](https://docs.google.com/presentation/d/1sxOu0u06xIocd4DEBFAwXct8wEoZB8MgURw4ylP14zM/edit?usp=sharing)
3. [Presentation[RU]]()

### Build info

Compiled with
```bash
    clang++ -g -fsanitize=fuzzer -std=c++20 fuzzer.cpp -o fuzzer
```

Run
```bash
    ./fuzzer CORPUS -max_len=4096
```