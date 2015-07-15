
#pragma once

#include <iostream>
#include "matrix.h"

class Solver
{
	Matrix<bool>  _visited;
	Matrix<bool>  _puddles;
	const Matrix<int> & _m;

	bool _can_escape(size_t i, size_t j, int val)
	{
		std::fill(_visited.begin(), _visited.end(), false);

		return _can_escape_r(i, j, val);
	}

	bool _can_escape_r(size_t i, size_t j, int val)
	{
		if(i == -1 || i == _m.width() || j == -1 || j == _m.height()) return true;
		if(_visited(i, j)) return false;
		if(val < _m(i, j)) return false;

		_visited(i, j) = true;

		bool r = false;
		r = r || _can_escape_r(i-1, j, val);
		r = r || _can_escape_r(i+1, j, val);
		r = r || _can_escape_r(i, j+1, val);
		r = r || _can_escape_r(i, j-1, val);

		return r;
	}

	void _print_puddles()
	{
		for(size_t j=0; j<_m.height(); ++j)
		{
			for(size_t i=0; i<_m.width(); ++i)
			{
				char c = _puddles(i,j)?'#':'0';
				std::cout << c;
			}
			std::cout << std::endl;
		}
	}

public:

	Solver(const Matrix<int> & m):
		_m(m),
		_visited(m.width(), m.height()),
		_puddles(m.width(), m.height())
	{
		std::fill(_puddles.begin(), _puddles.end(), false);
	}

	Matrix<bool> solve()
	{
		for(size_t i=0; i<_m.width(); ++i)
		{
			for(size_t j=0; j<_m.height(); ++j)
			{
				// _print_puddles();
				_puddles(i, j) = !_can_escape(i, j, _m(i,j));
			}
		}

		return _puddles;
	}
};
