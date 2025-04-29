#include "numbers.hpp"

#include <cmath>

namespace math {
	
	namespace details {
		
		bool is_inf(float t) {
			return std::isinf(t);
		}
		bool is_inf(double t) {
			return std::isinf(t);
		}
		bool is_inf(long double t) {
			return std::isinf(t);
		}
		
	};
	
} //! namespace math
