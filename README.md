# C implemented Brainfuck Interpreter

[![Build Status](https://travis-ci.org/yo-C-ta/brainfuck-c.svg?branch=master)](https://travis-ci.org/yo-C-ta/brainfuck-c) [![Coverage Status](https://coveralls.io/repos/github/yo-C-ta/brainfuck-c/badge.svg?branch=master)](https://coveralls.io/github/yo-C-ta/brainfuck-c?branch=master) ![GitHub](https://img.shields.io/github/license/yo-C-ta/brainfuck-c.svg)

## Setup

```bash
make brainfuck
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

## CUnit and coverage

```bash
make test && ./test && gcov bf.gcda
```

## History

- New - 2017/11
- Add to github - 2019/04
