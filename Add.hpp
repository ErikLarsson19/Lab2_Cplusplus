#pragma once

//Performs compile time addition of two integers
//Generall case
template<int X, int Y>
struct Add {
	static const int value = Add<X - 1, Y + 1>::value;
};

//adds two numbers using recursion, base case = if x is 0 return y, recusive case = return Add(x-1, y+1) Runtime
int AddFun(int x, int y) {
    if (x == 0)
        return y;
    else
        return AddFun(x - 1, y + 1);
};


//Base case for the recursion, stopping the recursive instantiation of the Add template when X reaches 0. SPECIALIZATION of the struct
template<int Y>
struct Add<0, Y> {
    static const int value = Y;
};