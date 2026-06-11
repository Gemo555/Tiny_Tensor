# Tiny Tensor 学习路线与内容叙事

这份文档用于记录我的学习路线，未来可以整理成自媒体经验分享、阶段复盘、项目展示或简历叙事。

它不是单日学习笔记，而是回答一个更长期的问题：

> 我是如何从 C 语言基础出发，一步步理解深度学习框架底层机制的？

## 核心叙事

我没有直接从 PyTorch 或现成框架开始，而是选择从最小的 Matrix 开始，手写一个学习型 Tiny Tensor 项目。

这条路线的重点不是快速造一个完整框架，而是把深度学习底层系统拆成一层一层可以解释、可以验证、可以手写的小问题：

```text
C++ 工程基础
-> Matrix 存储和索引
-> row-major / cache locality
-> transpose / matmul
-> Tensor shape / stride / offset
-> 基础算子
-> Autograd 计算图
-> 简单神经网络训练
-> 性能优化和 AI infra 延伸
```

未来对外分享时，可以把这个项目讲成：

> 我从 C 语言基础出发，用 C++ 从零实现一个微型深度学习计算框架，通过手写 Matrix、Tensor、Autograd 和 matmul 优化，理解深度学习框架背后的数据结构、内存布局、计算图和性能问题。

## 当前起点

我的起点不是“已经很熟 C++”，而是：

- 有 C 语言基础。
- 对缓存、内存访问模式有一定理解。
- 对深度学习框架底层机制感兴趣。
- C++ 的 class、namespace、const、static、vector、operator overload 还在学习中。
- 希望项目中的核心学习代码自己手写，AI 主要负责解释、review、测试设计和工程辅助。

这个起点本身未来可以成为内容价值：不是展示“我一开始就很强”，而是展示“我是怎么把一个复杂系统拆开学的”。

## 路线阶段

### Stage 0：搭工程，不急着写框架

目标：

- 建立 Git 仓库。
- 建立 CMake 工程。
- 建立测试入口。
- 建立 README、roadmap、AI 使用边界。

可分享主题：

- 为什么学习型项目不能一开始就铺满 Tensor、Autograd、CUDA。
- 为什么先搭测试，而不是先堆功能。
- 如何限制 AI 的使用边界，让项目仍然是自己的学习成果。

当前状态：

- 已完成最小工程骨架。
- 已建立 smoke tests 和 learning tests。
- 已建立 AI 使用边界文档。

### Stage 1：Matrix，理解“二维对象如何存在于一维内存”

目标：

- 实现 `Matrix` 基础类。
- 理解 `rows_`、`cols_`、`data_` 三者关系。
- 理解 row-major 存储。
- 实现 `operator()(row, col)`。
- 实现 `fill()`、`zeros()`、`ones()`。
- 实现 `transpose()`。
- 实现 naive `matmul()`。

当前已经完成：

- `Matrix(rows, cols)`
- `Matrix(rows, cols, value)`
- `rows()`、`cols()`、`size()`、`empty()`
- 非 const 和 const 版本 `operator()`
- 越界检查
- `fill()`、`zeros()`、`ones()`
- `transpose()`
- `matmul()`，使用 `i-k-j` 循环顺序

当前掌握：

- C++ 类成员函数的基本写法。
- `.hpp` 声明和 `.cpp` 实现分离。
- `Matrix::` 表示类外实现成员函数。
- `std::vector<double>` 可以作为自动管理内存的一维数组。
- `data_[row * cols_ + col]` 是 row-major 二维到一维映射。
- `transpose` 的核心映射是 `result(j, i) = input(i, j)`。
- `matmul` 的维度要求是 `left.cols == right.rows`。
- `i-k-j` 在 row-major 下可以更连续地访问右矩阵行和结果矩阵行。

可分享主题：

- “矩阵明明是二维的，为什么底层用一维数组存？”
- “C 语言基础如何过渡到 C++ class？”
- “为什么 `m(row, col)` 背后其实是 operator overload？”
- “为什么 matmul 的循环顺序会影响缓存？”
- “学习项目里测试比打印输出更可靠。”

Stage 1 当前完成度估计：

```text
Matrix 最小功能：约 70%
Matrix 测试覆盖：约 35%
Matrix 文档解释：约 40%
```

下一步不是立刻进入 Tensor，而是先补 Matrix 测试和说明。

### Stage 2：Tensor，理解 shape / stride / offset

目标：

- 从二维 Matrix 过渡到多维 Tensor。
- 理解 `shape` 表示每个维度大小。
- 理解 `stride` 表示每个维度走一步跨多少内存。
- 理解 `offset` 如何从多维下标映射到一维存储。
- 理解 contiguous 和 non-contiguous。

未来可分享主题：

- “shape 和 stride 到底是什么？”
- “为什么 transpose 可以不复制数据？”
- “为什么深度学习框架这么在意 contiguous？”
- “Tensor 和 Matrix 的本质区别是什么？”

当前状态：

- 未开始。

### Stage 3：基础算子，理解 Tensor 如何计算

目标：

- 实现 add、sub、mul、div。
- 实现 sum、mean。
- 实现 relu、sigmoid。
- 实现 Tensor matmul。
- 初步理解 broadcasting。

未来可分享主题：

- “深度学习框架里的算子到底是什么？”
- “为什么 broadcasting 需要 shape 规则？”
- “为什么算子测试要比肉眼看输出重要？”

当前状态：

- 未开始。

### Stage 4：Autograd，理解计算图和 backward

目标：

- 理解 `requires_grad`。
- 理解计算图 parents。
- 理解 backward function。
- 理解拓扑排序。
- 理解梯度累积。
- 实现基础 add/mul/matmul/relu/sum backward。

未来可分享主题：

- “自动求导不是魔法，是计算图。”
- “为什么 backward 要反向拓扑顺序？”
- “为什么同一个 Tensor 被多次使用时梯度要累加？”
- “手写 autograd 后再看 PyTorch 会发生什么变化？”

当前状态：

- 未开始。

### Stage 5：训练小模型，形成可展示闭环

目标：

- 实现 Linear。
- 实现 MSELoss。
- 实现 SGD。
- 训练线性回归或小型 MLP。
- 展示 loss 下降。

未来可分享主题：

- “从矩阵乘法到训练一个小模型，中间到底发生了什么？”
- “为什么 optimizer 只是按梯度更新参数？”
- “一个最小深度学习框架需要哪些组件？”

当前状态：

- 未开始。

### Stage 6：性能优化和 AI infra 延伸

目标：

- 比较不同 matmul 循环顺序。
- 尝试 blocked matmul。
- 记录简单 benchmark。
- 未来可选 OpenMP、SIMD、Python binding 或 CUDA 入门。

未来可分享主题：

- “为什么同样是矩阵乘法，不同循环顺序速度不同？”
- “cache locality 如何影响 AI 计算？”
- “AI infra 不是口号，而是内存、算子、调度和性能问题。”

当前状态：

- 未开始。

## 内容记录原则

每个阶段尽量记录四类材料：

| 类型 | 作用 |
| --- | --- |
| 代码实现 | 证明我真的动手写过 |
| 测试结果 | 证明功能不是靠肉眼猜的 |
| 错误记录 | 展示真实学习过程 |
| 概念解释 | 转化成未来可以讲给别人的内容 |

未来每次阶段复盘时，优先回答：

1. 我原来不懂什么？
2. 我今天写出了什么？
3. 我踩了什么坑？
4. 这个坑背后的概念是什么？
5. 这部分在深度学习框架里对应什么？

## 当前可产出的第一期内容草稿方向

标题方向：

- 《我从 C 语言开始，手写一个 Tiny Tensor》
- 《为什么我不直接学 PyTorch，而是先手写 Matrix？》
- 《矩阵是二维的，为什么底层要用一维数组存？》
- 《从 `data_[row * cols + col]` 开始理解深度学习框架》

第一期可以讲：

- 项目目标：不是造轮子炫技，而是理解深度学习底层。
- 起点：C 语言基础，C++ 还在边学边写。
- 第一个核心问题：二维矩阵如何存进一维连续内存。
- 今日成果：Matrix 最小功能闭环跑通。
- 下一期：补测试，解释 transpose 和 matmul。

## 当前阶段状态快照

截至 2026-06-12：

- Phase 0 工程骨架：约 80%。
- Phase 1 Matrix 基础类：约 70%。
- 整体长期项目：仍处于早期，约 10% 以内。
- 当前最大价值：已经建立了从“概念 -> 手写实现 -> 编译错误 -> 测试验证 -> 复盘记录”的学习闭环。
