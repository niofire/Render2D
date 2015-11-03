#pragma once
#define NULL 0
#include <iostream>
/* The rPtr class
 *
 *
 *
 *
*/

#define rPtr_CAST(new_type,rPtr_var) *((rPtr<new_type>*)&rPtr_var);

template <class T>
class rPtr
	{
	public:
		rPtr(void);

		//constructor + allocate memory
		rPtr(T* ptr);

		//copy constructor
		rPtr(const rPtr&);

		//removes all references and update the number of handles
		~rPtr(void);

		//Allocate a memory location to the rPtr.
		void alloc(T* ptr);

		//Debug function
		//int* get_num_handle_ptr() { return _num_handles_allocaterPtr;}

		//Clears the pointer's reference and updates the number of handles
		void clear();

		bool is_null() { return _ptr == NULL;}
		int num_handles() { return _num_handles_allocaterPtr == NULL ?  0 :  *_num_handles_allocaterPtr;}
		//------------------------------------------------
		//			Operators
		//------------------------------------------------
		rPtr	&operator=(rPtr &ptr) {
			this->clear();
			//update the num of allocated handles
			this->_num_handles_allocaterPtr = ptr._num_handles_allocaterPtr;
			this->add_handle();
	
			this->_ptr = ptr._ptr;
			return *this;
		};

		T& value() 
		{
			return *_ptr;
		}




		T*	operator->() const  {
			return _ptr;
		};


	private:
		void delete_unused_memory();
		void add_handle();
		int* _num_handles_allocaterPtr;
		T* _ptr;
};

template <class T>
rPtr<T>::rPtr()
{
	_num_handles_allocaterPtr = NULL;
	_ptr = NULL;

}

template <class T>
rPtr<T>::rPtr(T* ptr)
{
	_num_handles_allocaterPtr = NULL;
	_ptr = NULL;

	alloc(ptr);
}
template <class T>
rPtr<T>::rPtr(const rPtr& ptr)
{
	this->_ptr = NULL;
	this->_num_handles_allocaterPtr = NULL;

	//update the num of allocated handles
	this->_num_handles_allocaterPtr = ptr._num_handles_allocaterPtr;
	this->add_handle();
	
	this->_ptr = ptr._ptr;
}

template <class T>
rPtr<T>::~rPtr()
{
	this->clear();
}

template <class T>
void rPtr<T>::alloc(T* ptr)
{
	//clear previous reference
	this->clear();

	//store the newly allocated pointer
	_num_handles_allocaterPtr = new int(1);
	_ptr = ptr;
}


template <class T>
void rPtr<T>::clear()
{
	if(this->_num_handles_allocaterPtr != NULL)
	{
		*_num_handles_allocaterPtr = *_num_handles_allocaterPtr - 1;
		this->delete_unused_memory();
	}

	this->_ptr = NULL;
	this->_num_handles_allocaterPtr = NULL;
}

template <class T>
void rPtr<T>::add_handle()
{
	if(_num_handles_allocaterPtr != NULL)
		*_num_handles_allocaterPtr = *_num_handles_allocaterPtr + 1;
}

template <class T>
void rPtr<T>::delete_unused_memory()
{
	if(*_num_handles_allocaterPtr == 0)
	{
		delete _ptr;
		_ptr = NULL;

		delete _num_handles_allocaterPtr;
		_num_handles_allocaterPtr = NULL;
	}
}