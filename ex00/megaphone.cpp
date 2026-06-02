
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		int j = 1;
		while(av[j])
		{
			std::string str = av[j];
			int i = 0;
			while(str[i])
			{
				char c = str[i];
				std::cout << (char)toupper(c);
				i++;
			}
			if (av[j + 1])
				std::cout << ' ';
			j++;
		}
		std::cout << '\n';
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}
