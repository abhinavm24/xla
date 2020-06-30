#pragma once

#include "tensorflow/compiler/xla/types.h"
#include "torch_xla/csrc/ir.h"
#include "torch_xla/csrc/reduction.h"

namespace torch_xla {
namespace ir {
namespace ops {

class MseLoss : public Node {
 public:
  MseLoss(const Value& input, const Value& target, ReductionMode reduction);

  std::string ToString() const override;

  NodePtr Clone(OpList operands) const override;

  XlaOpVector Lower(LoweringContext* loctx) const override;

  ReductionMode reduction() const { return reduction_; }

 private:
  ReductionMode reduction_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_xla