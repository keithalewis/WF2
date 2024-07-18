// comparer_builder.h - functor that defines arbitrary sort order.
// Test problem 2.
#pragma once
#include <functional>
#include <type_traits>
#include <vector>

namespace WF2 {

	template<class T>
	class comparer_builder {
		std::vector<std::function<bool(const T&, const T&)>> comparers;
	public:
		bool operator()(const T& lhs, const T& rhs) const
		{
			for (const auto& comparer : comparers) {
				if (comparer(lhs, rhs)) {
					return true;
				}
				if (comparer(rhs, lhs)) {
					return false;
				}
			}

			return false; // all elements equivalent
		}
		template<class R>
		comparer_builder& by(R T::* pm)
		{
			comparers.emplace_back([pm](const T& lhs, const T& rhs) {
				if constexpr (std::is_member_function_pointer_v<R T::*>) {
					return (lhs.*pm)() < (rhs.*pm)();
				}
				else {
					return lhs.*pm < rhs.*pm;
				}
			});

			return *this;
		}
	};

} // namespace WF
