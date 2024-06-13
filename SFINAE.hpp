#pragma once
#include <type_traits>
#include <string>

template <typename T>
typename std::enable_if<std::is_nothrow_copy_constructible<T>::value, bool>::type
NoThrowCopyConstructible(T) {
    return true;
}

template <typename T>
typename std::enable_if<!std::is_nothrow_copy_constructible<T>::value, bool>::type
NoThrowCopyConstructible(T&) {
    return false;
}

//select algorithms on functions based on whether the type is nothrow copy constructible
//used to create flexible and type-safe APis that adapt to properties of the types they work with