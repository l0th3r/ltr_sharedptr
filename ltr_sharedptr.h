#pragma once

namespace ltr
{
	template<class T>
	class MakeSharedPtr;

	template<class T>
	class SharedPtr
	{
	public:
		SharedPtr(const T* ptr = nullptr);
		SharedPtr(const SharedPtr& sharedptr);

		unsigned int getRefCount();

		T& operator*();
		T& operator->();

		SharedPtr<T>& operator=(const MakeSharedPtr<T>&);

		~SharedPtr();

	private:
		T* m_ptr;
		unsigned int* m_counter;

	};

	template<class T>
	class MakeSharedPtr
	{
	private:
		SharedPtr<T>* m_sharedPtr;

	public:
		MakeSharedPtr();
	};
}