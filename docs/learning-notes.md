# 学习笔记

## 2026-06-12

### 今天实现了什么

- 理解并实现了 `Matrix(rows, cols)` 构造函数。
- 理解并实现了 `Matrix(rows, cols, value)` 构造函数。
- 实现了 `rows()`、`cols()`、`size()`、`empty()` 的读取逻辑。
- 实现了 `operator()(row, col)` 的非 const 和 const 版本。
- 实现了 `fill()`、`zeros()`、`ones()`。
- 实现了 `transpose()`。
- 实现了 naive `matmul()`，并使用了 `i-k-j` 循环顺序。

### 今天遇到的 bug

- 一开始把 `data_` 写成了 `data` 或 `data_resize`。
- `for` 循环忘记写 `++i`。
- `zeros()` 里创建了矩阵但忘记 `return m`。
- `transpose()` 里一开始把映射方向写反了。
- `matmul()` 里一开始使用了未声明的 `m`。
- 同时存在两个目录：`C:\Users\Gemo\Tiny_Tensor` 和 `C:\Users\Gemo\Documents\Tiny_Tensor`，导致改动写进了另一个副本。

### 我对 Matrix 存储的理解

- `rows_` 保存行数。
- `cols_` 保存列数。
- `data_` 是一维 `std::vector<double>`，真正存储所有元素。
- 当前不变量是：`data_.size() == rows_ * cols_`。

### 我对 row-major / column-major 的理解

- 当前项目使用 row-major。
- 对于 `(row, col)`，一维下标是：`row * cols_ + col`。
- 同一行内相邻列在内存中连续。

### 我对 matmul 的理解

- 矩阵乘法要求：左矩阵列数等于右矩阵行数。
- 维度不匹配时抛出 `std::invalid_argument`。
- 当前实现使用三层循环：`i -> k -> j`。
- 在 row-major 下，`i-k-j` 可以连续访问 `other(k, j)` 和 `m(i, j)`，并复用 `(*this)(i, k)`。

### 哪些地方是 AI 提示过，但我自己手写的

- Matrix 构造函数的状态初始化。
- `operator()` 的越界检查和下标映射。
- `fill()` 的遍历赋值。
- `zeros()` 和 `ones()` 的创建、填充、返回流程。
- `transpose()` 的新矩阵 shape 和元素映射。
- `matmul()` 的维度检查和 `i-k-j` 循环结构。

### 明天要做什么

- 统一只使用主仓库目录：`C:\Users\Gemo\Documents\Tiny_Tensor`。
- 网络恢复后运行 `git push`，把本地提交推到 GitHub。
- 给 `transpose()` 和 `matmul()` 增加更细的测试，例如非方阵转置、维度不匹配、具体数值结果。
- 重新整理 README 中“下一步”的提示，让它和当前进度一致。
