# Tiny Tensor Session Brief

Use this file to recover context quickly in a new Codex session.

## Current Project

- Main workspace: `C:\Users\Gemo\Documents\Tiny_Tensor`
- GitHub remote: `https://github.com/Gemo555/Tiny_Tensor.git`
- Current branch: `main`
- Project goal: learn deep learning framework internals by hand-writing a tiny C++ tensor framework.
- Current phase: Phase 1, Matrix.

## User Learning Profile

- The user has a C language background and is learning C++ through this project.
- Explain C++ concepts by relating them to C when helpful.
- The user wants core learning code handwritten by themselves.
- AI should explain, review, design tests, debug errors, and update docs, but should not take over Matrix/Tensor/Autograd core implementations.
- The user prefers progress records that show real learning gains, project completion, and future content value, not template-style daily notes.
- The user may later turn this project into self-media learning/process videos.

## Implemented Matrix Features

- `Matrix(rows, cols)`
- `Matrix(rows, cols, value)`
- `rows()`, `cols()`, `size()`, `empty()`
- Non-const and const `operator()(row, col)`
- Bounds checks with `std::out_of_range`
- `fill()`
- `zeros()`
- `ones()`
- `transpose()`
- Naive `matmul()` with `i-k-j` loop order

## Tests

- Test file: `tests/test_matrix.cpp`
- The user can now understand this file.
- Tests cover:
  - default Matrix smoke test
  - construction
  - initialized construction
  - `zeros`, `ones`, `fill`
  - read/write with `operator()`
  - row/column out-of-range errors
  - matmul dimension mismatch
  - non-square transpose concrete values
  - matmul concrete values

## Build And Test Commands

Manual compile:

```powershell
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude src/matrix.cpp tests/test_matrix.cpp -o test_matrix.exe
```

Run tests:

```powershell
$env:RUN_LEARNING_TESTS=1
.\test_matrix.exe
Remove-Item Env:RUN_LEARNING_TESTS
```

CMake/CTest:

```powershell
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
$env:RUN_LEARNING_TESTS=1
ctest --test-dir build --output-on-failure
Remove-Item Env:RUN_LEARNING_TESTS
```

CMake is available at `C:\Program Files\CMake\bin\cmake.exe`.

## Concepts The User Recently Clarified

- `#include "tinytensor/matrix.hpp"` works because `-Iinclude` makes `include/` a header search path.
- `tinytensor/matrix.hpp` is preferred over plain `matrix.hpp` to avoid name/path collisions.
- `namespace tinytensor` gives project names a namespace.
- Anonymous namespace is for `.cpp`-local helpers.
- `std::cout` is normal output; `std::cerr` is error output.
- Prefer `'\n'` for normal newlines; use `std::endl` only when flushing is needed.
- `catch (const std::exception& e)` avoids copying and preserves polymorphic exception behavior.
- Error-path tests are important because invalid inputs are part of the public behavior.
- `undefined reference` means the declaration was seen but the implementation was not linked.
- Smoke tests are minimal tests that confirm the project is not basically broken.
- PowerShell Chinese output may require `chcp 65001`.

## Current Progress Estimate

- Phase 0 engineering skeleton: about 80%.
- Phase 1 Matrix: about 80%.
- Matrix test coverage: about 60%.
- Long-term project: still early, around 10% or less.

## Next Recommended Step

Create `docs/matrix-notes.md`.

Purpose:

- Explain Matrix storage in one-dimensional `std::vector<double>`.
- Explain row-major layout.
- Explain `operator()(row, col)` index mapping.
- Explain `transpose()`.
- Explain `matmul()`.
- Explain why `i-k-j` is cache-friendlier for row-major storage.
- Explain how tests validate these behaviors.

This document should be useful both for learning and future video/script material.
