# AI Boundary

“如果一段代码是项目的学习价值所在，那么 AI 最多只能提供接口、测试、提示和 review，不能直接替我完成。”

## AI Can Help With

- Project structure.
- README and documentation.
- CMake and CI configuration.
- Lightweight test framework setup.
- Examples.
- TODO prompts.
- Code review.
- Explaining compiler errors.
- Designing test cases.

## AI Should Not Directly Complete

- Matrix core storage logic.
- Matrix indexing logic.
- Matrix addition, multiplication, and transpose core implementation.
- The core loops inside `matmul`.
- Future Tensor shape, stride, and offset logic.
- Future Autograd graph and backward logic.

## Working Rule

If the code is something the learner should be able to explain at a whiteboard, AI should stay at the level of interface, tests, hints, review, and debugging guidance.
