#pragma once
#define NULL 0
#include <iostream>
#include "render2D_typedef.h"
#define VOID_ASSIGNMENT(type, left,right) *((type*)left) = *((type*)right);
/* The rPtr class
 *
 *
 *
 *
 */
namespace Render2D
{
	class void_rPtr
	{
	public:
		void_rPtr(void);

		//constructor + allocate memory
		void_rPtr(void* ptr);

		//copy constructor
		void_rPtr(const void_rPtr&);

		//removes all references and update the number of handles
		~void_rPtr(void);

		//Allocate a memory location to the low_rPtr.
		void alloc(void* ptr);
		void alloc(U32 byte_size);
		//Debug function
		//int* get_num_handle_ptr() { return _num_handles_allocatelow_rPtr;}

		//Clears the pointer's reference and updates the number of handles
		void clear();

		void* get_voirPtr() { return _ptr; }
		bool is_null() { return _ptr == NULL; }
		int num_handles() { return _num_handles_allocated == NULL ? 0 : *_num_handles_allocated; }
		//------------------------------------------------
		//			Operators
		//------------------------------------------------
		void_rPtr	&operator=(void_rPtr &ptr) {
			this->clear();
			//update the num of allocated handles
			this->_num_handles_allocated = ptr._num_handles_allocated;
			this->add_handle();

			this->_ptr = ptr._ptr;
			return *this;
		};

	private:
		void delete_unused_memory();
		void add_handle();
		int* _num_handles_allocated;
		void* _ptr;
	};

}