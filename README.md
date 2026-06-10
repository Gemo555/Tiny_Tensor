# Tiny Tensor

Tiny Tensor is a learning project, not a production deep learning framework.

The goal is to understand the foundations behind tensors and deep learning systems by building them slowly: matrix storage, indexing, shape, stride, autograd, and performance work. The current version intentionally stays small and only covers the Phase 0 project skeleton plus the Phase 1 `Matrix` learning surface.

## Current Scope

This repository currently contains:

- A C++17 CMake project.
- A minimal `Matrix` class interface.
- Smoke tests that should pass now.
- Learning tests that describe expected `Matrix` behavior and are expected to fail until the handwritten TODOs are implemented.
- Documentation for the roadmap, learning notes, and AI usage boundaries.

It does not contain Tensor, Autograd, CUDA, Python bindings, neural network modules, optimizers, dataloaders, or a benchmark framework yet.

## Build

```sh
cmake -S . -B build
cmake --build build
```

## Run Tests

Run smoke tests:

```sh
ctest --test-dir build --output-on-failure
```

Or use the helper script:

```sh
bash scripts/test.sh
```

Run learning tests after you start implementing `Matrix`:

```sh
RUN_LEARNING_TESTS=1 ctest --test-dir build --output-on-failure
```

## Run Example

```sh
./build/examples/matrix_basic
```

On Windows with the default CMake generator, the executable may be under a configuration directory:

```sh
./build/examples/Debug/matrix_basic.exe
```

## AI Usage Principle

AI can help with project structure, CMake, tests, examples, docs, TODO prompts, review, and explanations. The core learning code should be handwritten by the learner.

See [docs/ai-boundary.md](docs/ai-boundary.md).

## Roadmap

See [docs/roadmap.md](docs/roadmap.md).
