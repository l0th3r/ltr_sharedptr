#include <iostream>

#include "ltr_sharedptr.h"

using namespace ltr;

class Data
{
public:
	Data(int id, int value = 30) : m_id(id), m_value(value) {}
	
	int m_id;
	int m_value;
};

int main(void)
{
	ltr::SharedPtr<Data> d = ltr::SharedPtr<Data>::Make(10, 50);

	std::cout << "Hello World !" << std::endl;
	std::cin.get();

	return 0;
}
