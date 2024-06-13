#pragma once
//Define the primary template and specialize it for different cases of the function
// Primary here will handle the third case, both m and n are greater than 0
template<int M, int N>
struct Ackermann {
	static const int value = Ackermann<M - 1, Ackermann<M, N - 1>::value>::value;
};

//specialization for when m = 0, Do this in the Ackerman<0, N>
template<int N>
struct Ackermann<0, N> {
	static const int value = N + 1;

};

//specialization for when m>0 and n = 0
template<int M>
struct Ackermann<M, 0> {
	static const int value = Ackermann<M - 1, 1>::value;
};

