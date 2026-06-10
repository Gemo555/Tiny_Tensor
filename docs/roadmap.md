# Roadmap

This roadmap intentionally focuses on the next two weeks. Later phases are listed only as direction, not as code to generate now.

## Current Goal: Phase 0 + Phase 1

Phase 0 creates the project skeleton: Git, CMake, tests, CI, scripts, and basic documentation.

Phase 1 creates a learning-oriented `Matrix` interface. The core implementation is intentionally left as `TODO(handwrite)` so the learner can build the storage and indexing logic by hand.

## Week 1

- Set up the project structure.
- Configure CMake.
- Add smoke tests.
- Understand `Matrix` storage.
- Handwrite the basic constructor.
- Handwrite `rows()`, `cols()`, and `size()` behavior.
- Handwrite `operator()(row, col)`.
- Handwrite `fill`, `zeros`, and `ones`.
- Add basic tests as each behavior becomes clear.

## Week 2

- Handwrite `transpose`.
- Handwrite naive `matmul`.
- Add dimension mismatch tests.
- Add out-of-range access tests.
- Keep a simple performance note by manually timing a few matrix sizes.
- Summarize the Matrix design in `docs/learning-notes.md`.

## Later Direction

- Tensor shape, stride, offset, and contiguous storage.
- Basic tensor operators.
- Autograd computation graph and backward pass.
- Simple neural network layers and optimizer.
- CPU performance experiments.
- Optional Python binding or CUDA exploration much later.
