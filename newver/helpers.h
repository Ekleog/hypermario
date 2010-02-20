/**
 * @author Lenoa
 */

#ifndef HELPERS_INCLUDED
#define HELPERS_INCLUDED 1

#include <algorithms>

template<typename T>
T &Min(T &A, T &B, T &C)
	{ return std::min(std::min(A, B), C); }
template<typename T>
T &Max(T &A, T &B, T &C)
	{ return std::max(std::max(A, B), C); }

template<typename T>
T &Min(T &A, T &B, T &C, T &D)
	{ return std::min(std::min(A, B), std::min(C, D)); }
template<typename T>
T &Max(T &A, T &B, T &C, T &D)
	{ return std::max(std::max(A, B), std::max(C, D)); }

template<typename T>
const T &Min(const T &A, const T &B, const T &C)
	{ return std::min(std::min(A, B), C); }
template<typename T>
const T &Max(const T &A, const T &B, const T &C)
	{ return std::max(std::max(A, B), C); }

template<typename T>
const T &Min(const T &A, const T &B, const T &C, const T &D)
	{ return std::min(std::min(A, B), std::min(C, D)); }
template<typename T>
const T &Max(const T &A, const T &B, const T &C, const T &D)
	{ return std::max(std::max(A, B), std::max(C, D)); }

#endif // HELPERS_INCLUDED

