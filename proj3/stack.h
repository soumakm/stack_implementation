#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <list>

namespace cop4530 {

	template <typename T>
		class Stack {
			
			public:
				// constructor, desctructor, copy constructor
				Stack(); // default zero parameter constructor
				Stack(const Stack &rhs); // copy constructor
				Stack(Stack && rhs); // move constructor
				
				~Stack(); // destructor

				// copy assignment operator
				const Stack & operator=(const Stack &rhs);
				// move assignment operator
				Stack & operator=(Stack && rhs);

				// member functions
				int size() const; // number of elements
				bool empty() const; // check if list is empty
				void clear(); // delete all elements
				
				void push(const T & val); // adds val to the stack, copy version
				void push(T && val); // move version of push
				void pop(); // removes most recently added element from the stack
				T & top(); // mutator that returns a reference of most recently added element of the Stack
				const T & top() const; // accessor that returns a reference of most recently added element of the Stack
				
				// print out all elements. ofc is deliminitor, it should print oldest element at the first
				void print(std::ostream& os, char ofc = ' ') const; 

			private:
				std::list<T> sList;
		};

	// overloading comparison operators, 
	template <typename T>
		bool operator==(const Stack<T> & lhs, const Stack<T> &rhs);

	template <typename T>
		bool operator!=(const Stack<T> & lhs, const Stack<T> &rhs);
	//returns true if every element of Stack a is smaller than corresponding element of Stack b	
	template <typename T>
		bool operator<=(const Stack<T> & lhs, const Stack<T> &rhs);	

	// overloading output operator
	template <typename T>
		std::ostream & operator<<(std::ostream &os, const Stack<T> &l);

	// include the implementation file here
#include "stack.hpp"

} // end of namespace 4530

#endif
