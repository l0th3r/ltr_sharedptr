#include <iostream>

#include "ltr_sharedptr.h"

class Data
{
public:
	Data(int value = 30)
	{
		m_value = value;
	}

	int m_value;
};

int main(void)
{
	ltr::SharedPtr<Data> ptrData = ltr::MakeSharedPtr<Data>();

	std::cout << "Hello World !" << std::endl;
	std::cin.get();

	return 0;
}
