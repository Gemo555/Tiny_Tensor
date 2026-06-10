# Roadmap

这个 roadmap 只详细写最近两周。后面的长期阶段只简单列方向，避免现在一次性铺太大。

## 当前目标：Phase 0 + Phase 1

Phase 0：创建工程骨架，包括 Git、CMake、测试、CI、脚本和基础文档。

Phase 1：创建一个学习型 `Matrix` 接口。核心实现会保留为 `TODO(handwrite)`，让你自己手写矩阵存储、索引、转置和矩阵乘法。

## Week 1

- 搭建工程结构。
- 配置 CMake。
- 添加 smoke tests。
- 理解 `Matrix` 应该如何存储数据。
- 手写基础构造函数。
- 理解并验证 `rows()`、`cols()`、`size()`。
- 手写 `operator()(row, col)`。
- 手写 `fill`、`zeros`、`ones`。
- 每实现一点，就补一点基础测试。

## Week 2

- 手写 `transpose`。
- 手写 naive `matmul`。
- 写维度不匹配测试。
- 写越界访问测试。
- 手动记录几个矩阵规模的简单耗时。
- 在 `docs/learning-notes.md` 里总结 Matrix 设计。

## 后续方向

- Tensor 的 shape、stride、offset 和 contiguous 存储。
- 基础 Tensor 算子。
- Autograd 计算图和 backward。
- 简单神经网络层和优化器。
- CPU 性能实验。
- 更后期再考虑 Python binding 或 CUDA。
