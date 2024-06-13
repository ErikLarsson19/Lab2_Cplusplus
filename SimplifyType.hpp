#pragma once
#include <cstddef>
template<class T>
struct SimplifyType {
	using type = T;
};

template<class T>
using SimplifyType_t = typename SimplifyType<T>::type;

template<class T>
struct SimplifyType<const T> {
	using type = T;
};

template<class T>
struct SimplifyType<T&> {
	using type = T;
};

template<class T>
struct SimplifyType<T*> {
	using type = T;
};

template<class T>
struct SimplifyType<T[]> {
	using type = T;
};

template<class T, size_t N>
struct SimplifyType<T[N]> {
	using type = T;
};

template<class T>
struct BaseType {
    using type = T;
};

//remove const
template<class T>
struct BaseType<const T> {
    using type = typename BaseType<T>::type;
};

//remove referennce
template<class T>
struct BaseType<T&> {
    using type = typename BaseType<T>::type;
};

//remove rvalue reference
template<class T>
struct BaseType<T&&> {
    using type = typename BaseType<T>::type;
};


template<class T>
struct BaseType<T*> {
    using type = typename BaseType<T>::type;
};

//remove array of unknown bound
template<class T>
struct BaseType<T[]> {
    using type = typename BaseType<T>::type;
};

//remove array of known bound
template<class T, size_t N>
struct BaseType<T[N]> {
    using type = typename BaseType<T>::type;
};

template<class T>
using BaseType_t = typename BaseType<T>::type;