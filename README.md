# Tiny Tensor

Tiny Tensor 是一个学习型深度学习底层项目，不是成熟的生产级深度学习框架。

这个项目的目标不是“尽快做完一个框架”，而是从零理解深度学习框架背后的机制：矩阵存储、索引访问、shape、stride、autograd、性能优化等。当前版本只初始化 Phase 0 工程骨架和 Phase 1 的 `Matrix` 学习接口。

## 当前范围

现在仓库里只有这些内容：

- C++17 + CMake 工程骨架。
- 最小 `Matrix` 类接口。
- 现在应该通过的 smoke tests。
- 描述 Matrix 预期行为的 learning tests，这些测试要等你手写实现后再打开。
- roadmap、学习笔记模板、AI 使用边界文档。

现在不会提前创建 Tensor、Autograd、CUDA、Python Binding、NN Module、Optimizer、Dataloader 或完整 benchmark 框架。

## 构建

```sh
cmake -S . -B build
cmake --build build
```

## 运行测试

运行现在应该通过的 smoke tests：

```sh
ctest --test-dir build --output-on-failure
```

也可以使用脚本：

```sh
bash scripts/test.sh
```

当你开始手写 `Matrix` 后，再打开 learning tests：

```sh
RUN_LEARNING_TESTS=1 ctest --test-dir build --output-on-failure
```

## 运行例子

```sh
./build/examples/matrix_basic
```

Windows 默认 CMake 生成器有时会把可执行文件放到配置目录里，例如：

```sh
./build/examples/Debug/matrix_basic.exe
```

## AI 使用原则

AI 可以帮你搭工程结构、写 CMake、写测试、写示例、写文档、写 TODO 提示、做 code review、解释编译错误、设计测试用例。

但是核心学习代码要你自己手写，尤其是 Matrix 存储、索引、转置、矩阵乘法这些部分。

详见 [docs/ai-boundary.md](docs/ai-boundary.md)。

## Roadmap

详见 [docs/roadmap.md](docs/roadmap.md)。
