
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "except.h"
#include "solver.h"

Matrix<int> read(const std::string & path)
{
	std::ifstream fin(path);

	int height;
	int width;

	fin >> height;
	fin >> width;

	std::string line;
	std::getline(fin, line);

	auto m = Matrix<int>(width, height);

	for(size_t j=0; j<height; ++j)
	{
		std::getline(fin, line);

		ENFORCE(fin.good());

		std::istringstream ist(line);
		ENFORCE(ist.good());

		for(size_t i=0; i<width; ++i)
		{
			int val;
			ist >> val;

			ENFORCE(!ist.fail());

			m(i,j) = val;
		}

		ENFORCE(ist.eof());
	}

	fin.close();

	return std::move(m);
}


void write(const Matrix<bool> & m, const std::string & path)
{
	std::ofstream fout(path);

	for(size_t j=0; j<m.height(); ++j)
	{
		for(size_t i=0; i<m.width(); ++i)
		{
			char c = m(i,j)?'#':'0';
			fout << c;
		}

		fout << std::endl;
	}

	fout.close();
}

void show_usage()
{
	printf("usage: puddles <input> <output>\n");
}

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		show_usage();
		return 1;
	}

	std::string in = argv[1];
	std::string out = argv[2];

	auto m = read(in);

	Solver solver(m);
	auto s = solver.solve();

	write(s, out);

	return 0;
}
