#include "Receiver.h"

int main()
{
	char s = '1';
	int line;
	std::string str;
	Receiver res;
	while (s != 'e') {
		std::cout << "What to do:" << std::endl
                << "1.Add a line" << std::endl
                << "2.Replace a line" << std::endl
                << "3.Undo last command" << std::endl;
		std::cin >> s;
		switch (s)
		{
		case '1':
			std::cout << "Where to insert (line number): ";
			std::cin >> line;
			std::cout << "What to insert: ";
			std::cin >> str;
			res.insert(static_cast<size_t>(line), str);
			break;
		case '2':
			std::cout << "What line to replace: ";
			std::cin >> line;
			std::cout << "What to replace with: ";
			std::cin >> str;
			res.replace(static_cast<size_t>(line), str);
			break;
		case '3':
			res.undo();
			break;
		}
		std::cout << "$$$DOCUMENT$$$" << std::endl;
		res.show();
		std::cout << "$$$DOCUMENT$$$" << std::endl;
	}

	return 0;
}
