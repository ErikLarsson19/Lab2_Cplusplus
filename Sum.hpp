#pragma once
//takes a container as template parameter
template <class CONT>
auto Sum(const CONT& cont) {
	//constant reference to container type, use auto for return type enables automatic type deduction based on return statement
	using ElementType = typename std::remove_const<typename std::remove_reference<decltype(*cont.begin())>::type>::type;
	//decltype gets type of container element, remove_const and remove_reference remove const and reference from type

	//initialize sum with 0
	ElementType sum = 0;
	
	//iterate over container and add elements to sum
	for (const auto& item : cont) {
		sum += item;
	}
	return sum;
}

