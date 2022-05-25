#pragma once

namespace ltr
{
	template<class T>
	class SharedPtr
	{
	private:
		SharedPtr(T* ptr = nullptr);

	public:
		unsigned int getRefCount();

		T& operator*();
		T& operator->();

		SharedPtr<T>& operator=(const SharedPtr<T>& msptr);
		
		template<class... Args>
		static inline SharedPtr<T> Make(Args... args)
		{
			auto sptr = SharedPtr<T>(new T(args...));
			return sptr;
		}

		~SharedPtr();

	private:
		T* m_ptr;
		unsigned int* m_counter;

	};

#pragma region Constructors and Destructors

	template<class T>
	SharedPtr<T>::SharedPtr(T* ptr) : m_ptr(ptr), m_counter(new unsigned int(0))
	{
		if (ptr != nullptr)
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
	SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& sptr)
	{
		this->m_ptr = sptr.m_ptr;
		this->m_counter = sptr.m_counter;

		return *this;
	}


#pragma endregion

#pragma region MakeSharedPtr

#pragma endregion
}