# AI 使用边界

“如果一段代码是项目的学习价值所在，那么 AI 最多只能提供接口、测试、提示和 review，不能直接替我完成。”

## AI 可以帮我做什么

- 搭工程结构。
- 写 README 和文档。
- 写 CMake 和 CI 配置。
- 搭轻量测试框架。
- 写 examples。
- 写 TODO 提示。
- 做代码 review。
- 解释编译错误。
- 帮我设计测试用例。

## AI 不应该直接替我完成什么

- Matrix 的核心存储逻辑。
- Matrix 的索引访问逻辑。
- Matrix 加法、乘法、转置的核心实现。
- `matmul` 的核心循环。
- 未来 Tensor 的 shape、stride、offset 逻辑。
- 未来 Autograd 的计算图和 backward 逻辑。

## 工作原则

如果一段代码是我需要在白板上讲清楚的，AI 就只提供接口、测试、提示、review 和调试帮助，不直接替我写完。
