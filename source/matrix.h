
#pragma once

#include <vector>
#include <deque>
#include <cassert>

// workaround for fucking std::vector<bool> specialization ... better not to use bool at all

template<typename U>
struct ContType {typedef std::vector<U> type;};

template<>
struct ContType<bool> {typedef std::deque<bool> type;};

template<typename T>
class Matrix
{

	typename ContType<T>::type _v;
	size_t _width;
	size_t _height;
public:

	typedef typename ContType<T>::type::iterator iterator;
	typedef typename ContType<T>::type::const_iterator const_iterator;

	Matrix(size_t w, size_t h):
		_v(w*h), _width(w), _height(h)
		{}

	Matrix(): Matrix(0,0){}
	Matrix(const Matrix<T> & o) = default;

	// template<typename U>
	// Matrix(const Matrix<U> & o)
	// {
	// 	_v.resize(o._v.size());
	// 	std::copy(o._v.cbegin(), o._v.cend(), _v.begin());
	// 	_width = _width;
	// 	_height = _height;
	// }

	Matrix<T> & operator=(const Matrix<T> & o) = default;

	T & operator()(size_t i, size_t j)
	{
		assert(i < _width);
		assert(j < _height);

		return _v[i * _height + j];
	}

	const T & operator()(size_t i, size_t j) const
	{
		assert(i < _width);
		assert(j < _height);

		return _v[i * _height + j];
	}

	iterator begin() { return _v.begin();}
	iterator end()   { return _v.end();}
	const_iterator cbegin() const { return _v.cbegin();}
	const_iterator cend()   const { return _v.cend();}

	size_t width() const
	{
		return _width;
	}

	size_t height() const
	{
		return _height;
	}
};
