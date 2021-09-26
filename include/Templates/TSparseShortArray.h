#pragma once

template <class T>
struct TSparseShortArray
{
	int size;
	char* indices;
	T* items;

	TSparseShortArray() = default;
	~TSparseShortArray() = default;
};
