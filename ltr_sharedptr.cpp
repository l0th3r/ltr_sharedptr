#include "ltr_sharedptr.h"

using namespace ltr;

#pragma region Constructors and Destructors

template<class T>
SharedPtr<T>::SharedPtr(const T* ptr) : m_ptr(ptr), m_counter(new unsigned int(0))
{
	if (ptr != nullptr)
		(*m_counter)++;
}

template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr& sptr) : SharedPtr(sptr.m_ptr)
{
	m_counter = sptr.m_counter;
	(*m_counter)++;
}

template<class T>
SharedPtr<T>::~SharedPtr()
{
	(*m_counter)--;
	
	if (this->getRefCount() <= 0)
	{
		delete m_ptr;
		delete m_counter;
	}
}

#pragma endregion

#pragma region Methods

template<class T>
unsigned int SharedPtr<T>::getRefCount()
{
	return *m_counter;
}

#pragma endregion

#pragma region Operators

template<class T>
T& SharedPtr<T>::operator*()
{
	return *m_ptr;
}

template<class T>
T& SharedPtr<T>::operator->()
{
	return m_ptr;
}

template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(const MakeSharedPtr<T>& msptr)
{
	this = msptr.m_sharedPtr;
	return *this;
}


#pragma endregion

#pragma region MakeSharedPtr

template<class T>
MakeSharedPtr<T>::MakeSharedPtr()
{
	m_sharedPtr = new SharedPtr<T>(new T());
}
#pragma endregion