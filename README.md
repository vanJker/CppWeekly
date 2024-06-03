# C++ Weekly & Best Practices

MAKE C++ MORE FUN AND ACCESSIBLE

C++20 - MODERN TECHNIQUES

GAMES, BROWERS, OPERATING SYSTEMS

[COMPILER EXPLOER](https://godbolt.org/)
 - zoom: 100%
 - font size: 16

Options for compiler:

```bash
-std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wpedantic -fsanitize=undefined,address
```

## The Tools

Windows 10

[Visual Studio](https://visualstudio.microsoft.com/) 2019 Community edition

- Clang Power Tools
- ClangFormat
- [cppcheck-vs-addin](https://github.com/VioletGiraffe/cppcheck-vs-addin) vsix

[LLVM](https://releases.llvm.org/download.html) 17.0.1 Win64

[Cppcheck](https://cppcheck.sourceforge.io/) 2.13 Win64

## Hello World

Commit: [1ef0bb3](https://github.com/vanJker/CppWeekly/commit/1ef0bb359914c032a8290034d8c3128bfcec368f)

.clang.tidy file's content should be:

```
Checks: '*, -llvmlibc-restrict-system-libc-headers, -abseil-*, -fuchsia-*, -google-*'
```

- [C++ Weekly - clang-tidy Checks To Avoid](https://www.youtube.com/watch?v=oxpsHk1yq88)

## clang-tidy Checks To Avoid

```
Checks: '*, -llvmlibc-*, -abseil-*, -fuchsia-*, -google-*'
```

## Documentation

> You can find manuals in [cppreference](https://en.cppreference.com/)

- [std::format](https://en.cppreference.com/w/cpp/utility/format/format)
- [std::print](https://en.cppreference.com/w/cpp/utility/format/format)