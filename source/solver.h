
#pragma once

#include <iostream>
#include <iomanip>
#include "matrix.h"

class Solver
{
	int _watermark;
	Matrix<bool>  _visited;
	Matrix<bool>  _escapable;
	Matrix<int>  _puddles;
	const Matrix<int> & _m;

	bool _can_escape(size_t i, size_t j)
	{
		std::fill(_visited.begin(), _visited.end(), false);
		if(_watermark <= _m(i,j))
		{
			// printf("_can_escape(%zu, %zu): %d -> %d\n", i, j, _watermark, true);
			return true;
		}
		bool r = _can_escape_r(i, j);

		// printf("_can_escape(%zu, %zu): %d -> %d\n", i, j, _watermark, r);

		return r;
	}

	bool _can_escape_r(size_t i, size_t j)
	{
		if(i == -1 || i == _m.width() || j == -1 || j == _m.height()) return true;
		if(_escapable(i,j)) return true;
		if(_visited(i, j)) return false;
		if(_watermark <= _m(i, j)) return false;

		_visited(i, j) = true;

		bool r = false;
		r = r || _can_escape_r(i-1, j);
		r = r || _can_escape_r(i+1, j);
		r = r || _can_escape_r(i, j+1);
		r = r || _can_escape_r(i, j-1);

		_escapable(i,j) |= r;

		return r;
	}

	void _find_binary_puddles()
	{
		std::fill(_escapable.begin(), _escapable.end(), false);

		for(size_t i=0; i<_m.width(); ++i)
		{
			for(size_t j=0; j<_m.height(); ++j)
			{
				// _print_puddles();

				if(_m(i,j) + _puddles(i,j) >= _watermark)
				{
					continue;
				}

				bool r = _can_escape(i, j);
				if(!r)
				{
					assert(_watermark > _m(i,j));

					auto new_level = _watermark - _m(i,j);
					_puddles(i, j) = std::max(_puddles(i,j), new_level);
				}
			}
		}
	}

	void _print_puddles()
	{
		for(size_t j=0; j<_m.height(); ++j)
		{
			for(size_t i=0; i<_m.width(); ++i)
			{
				// char c = _puddles(i,j)?'#':'0';
				// std::cout << c;
				std::cout << std::setw(2) << _puddles(i,j);
			}
			std::cout << std::endl;
		}
	}

	void _print_binary(int level)
	{
		for(size_t j=0; j<_m.height(); ++j)
		{
			for(size_t i=0; i<_m.width(); ++i)
			{
				char c = (level <= _m(i,j))?'#':'0';
				std::cout << c;
			}
			std::cout << std::endl;
		}
	}

public:

	Solver(const Matrix<int> & m):
		_m(m),
		_visited(m.width(), m.height()),
		_puddles(m.width(), m.height()),
		_escapable(m.width(), m.height())
	{
		std::fill(_puddles.begin(), _puddles.end(), 0);
	}

	Matrix<int> solve()
	{
		std::vector<int> levels(_m.height() * _m.width());
		std::copy(_m.cbegin(), _m.cend(), levels.begin());
		std::sort(levels.begin(), levels.end(), [](int l, int r){return l > r;});
		auto last = std::unique(levels.begin(), levels.end());

		for(auto it = levels.begin(); it != last; ++it)
		{
			_watermark = *it;
			_find_binary_puddles();
			// _print_puddles();
			// std::cout << std::endl;
		}

		return _puddles;
	}
};
