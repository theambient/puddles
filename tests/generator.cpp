
#include <cstdlib>
#include <fstream>
#include <cassert>

// internal tool quick and dirty

int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		printf("usage: generator <seed> <height> <width>\n");
		return 1;
	}

	unsigned seed, width, height;

	sscanf(argv[1], "%u", &seed);
	sscanf(argv[2], "%u", &height);
	sscanf(argv[3], "%u", &width);

	assert(seed >= 0);
	assert(height >= 0);
	assert(width >= 0);

	srand(seed);

	printf("%d %d\n", height, width);

	for(size_t j=0; j<height; ++j)
	{
		for(size_t i=0; i<width; ++i)
		{
			int val = rand();
			printf("%d", val);

			if(i+1 != width)
			{
				printf(" ");
			}
		}

		printf("\n");
	}

	return 0;
}
