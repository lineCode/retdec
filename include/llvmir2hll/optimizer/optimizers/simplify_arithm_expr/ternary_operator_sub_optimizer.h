/**
* @file include/llvmir2hll/optimizer/optimizers/simplify_arithm_expr/ternary_operator_sub_optimizer.h
* @brief A sub-optimization class that optimize ternary operator.
* @copyright (c) 2017 Avast Software, licensed under the MIT license
*/

#ifndef LLVMIR2HLL_OPTIMIZER_OPTIMIZERS_SIMPLIFY_ARITHM_EXPR_TERNARY_OPERATOR_SUB_OPTIMIZER_H
#define LLVMIR2HLL_OPTIMIZER_OPTIMIZERS_SIMPLIFY_ARITHM_EXPR_TERNARY_OPERATOR_SUB_OPTIMIZER_H

#include <string>

#include "llvmir2hll/optimizer/optimizers/simplify_arithm_expr/sub_optimizer.h"
#include "llvmir2hll/support/types.h"

namespace llvmir2hll {

/**
* @brief This optimizer optimizes ternary operator. Examples are mentioned below.
*
* Optimizations are now only on these operators: TernaryOpExpr.
*
* List of performed simplifications (by examples):
*
* @par Operator TernaryOpExpr
* True/False(ConstBool)? anything : anything.
* @code
* return true ? 5 : 10;
* @endcode
* can be optimized to
* @code
* return 5;
* @endcode
*
* Instances of this class have reference object semantics.
*
* This is a concrete sub-optimizer which should not be subclassed.
*/
class TernaryOperatorSubOptimizer final: public SubOptimizer {
public:
	TernaryOperatorSubOptimizer(ShPtr<ArithmExprEvaluator> arithmExprEvaluator);
	virtual ~TernaryOperatorSubOptimizer() override;

	static ShPtr<SubOptimizer> create(ShPtr<ArithmExprEvaluator>
		arithmExprEvaluator);
	virtual std::string getId() const override;

private:
	/// @name Visitor Interface
	/// @{
	using SubOptimizer::visit;
	virtual void visit(ShPtr<TernaryOpExpr> expr) override;
	/// @}
};

} // namespace llvmir2hll

#endif
