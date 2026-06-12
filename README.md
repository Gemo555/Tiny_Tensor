# Tiny Tensor

Tiny Tensor 是一个学习型深度学习底层项目，不是成熟的生产级深度学习框架。

这个项目的目标不是“尽快做完一个完整框架”，而是从零理解深度学习框架背后的机制：矩阵存储、索引访问、shape、stride、autograd、性能优化等。

当前阶段只做 Phase 0 工程骨架和 Phase 1 的 `Matrix` 基础类。

## 当前状态

已经完成：

- C++17 + CMake 工程骨架。
- 最小自写测试框架。
- `Matrix` 基础存储：`rows_`、`cols_`、`data_`。
- 构造函数：`Matrix(rows, cols)`、`Matrix(rows, cols, value)`。
- 查询接口：`rows()`、`cols()`、`size()`、`empty()`。
- 二维索引访问：`operator()(row, col)`。
- 越界检查：非法索引抛出 `std::out_of_range`。
- 填充和工厂函数：`fill()`、`zeros()`、`ones()`。
- 转置：`transpose()`。
- 朴素矩阵乘法：`matmul()`，当前使用 `i-k-j` 循环顺序。
- Matrix 基础行为测试：构造、索引、越界、转置、矩阵乘法、维度错误。

暂时不做：

- Tensor。
- Autograd。
- CUDA。
- Python Binding。
- NN Module。
- Optimizer。
- Dataloader。
- 完整 benchmark 框架。

## 构建

```sh
cmake -S . -B build
cmake --build build
```

如果当前环境还没有 CMake，也可以先用 `g++` 直接编译测试：

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude src/matrix.cpp tests/test_matrix.cpp -o test_matrix.exe
```

## 运行测试

运行 smoke tests：

```sh
ctest --test-dir build --output-on-failure
```

运行完整 Matrix learning tests：

```sh
RUN_LEARNING_TESTS=1 ctest --test-dir build --output-on-failure
```

如果使用 `g++` 直接编译：

```powershell
.\test_matrix.exe
$env:RUN_LEARNING_TESTS=1
.\test_matrix.exe
Remove-Item Env:RUN_LEARNING_TESTS
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

AI 可以帮我搭工程结构、写 CMake、写测试、写示例、写文档、写 TODO 提示、做 code review、解释编译错误、设计测试用例。

但是核心学习代码要我自己手写，尤其是 Matrix 存储、索引、转置、矩阵乘法，以及未来 Tensor shape/stride 和 Autograd backward。

详见 [docs/ai-boundary.md](docs/ai-boundary.md)。

## 学习路线

- 当前进度报告：[docs/learning-notes.md](docs/learning-notes.md)
- 面向未来内容分享的学习路线：[docs/content-roadmap.md](docs/content-roadmap.md)
- 长期 roadmap：[docs/roadmap.md](docs/roadmap.md)
