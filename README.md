# C implemented Brainfuck Interpreter

## Setup

```bash
gcc -o brainfuck bf.c main.c
```

## Usage

### File

```bash
$ ./brainfuck hello_bf.bf
Hello, BF!
```

### Stdio

```bash
$ ./brainfuck
[input]: X++++++[->A+++++>B+++++++>C+++++++++++>D++++++++++++>E+++++++++++++++++>F++++++++++++++++++<<<<<<X]>>>>D(72).>E(102)-.>F(108)..+++.<<<<B(42)++.<A(30)++.>>C(66).>D(72)--.<<<A(32)+.
Hello, BF!
```

## CUnit

gcc -o test_bf test_bf.c bf.c -Wall -L/usr/local/lib -lcunit -I/usr/local/include

## History

- New - 2017/11
- Add to github - 2019/04
