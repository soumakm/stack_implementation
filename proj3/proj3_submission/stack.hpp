
     // default zero parameter constructor
    template <typename T>      
    Stack<T>::Stack( )
      { }
    
    // copy constructor
    template <typename T>  
    Stack<T>::Stack( const Stack<T> & rhs )
    {
         clear();
         for( auto & x : rhs.sList )
            sList.push_back( x );
    }
    
    // move constructor
    template <typename T>
    Stack<T>::Stack( Stack<T> && rhs )
      : sList{ rhs.sList }
    {
        sList.clear();
    }

    // destructor
    template <typename T>
    Stack<T>::~Stack( )
    {
        clear();
        sList.~list();
    }

    // copy assignment operator
    template <typename T>
    const typename cop4530::Stack<T> & Stack<T>::operator= ( const Stack<T> & rhs )
    {

        if (rhs.sList == this->sList)
            return *this;
      
        clear();
        for( auto & x : rhs.sList )
            sList.push_back( x );

        return *this;
    }
    
    // move assignment operator
    template <typename T>
    typename cop4530::Stack<T> & Stack<T>::operator= ( Stack<T> && rhs )
    {    
        sList = rhs.sList;
        return *this;
    }
    
    // member functions
    // Return number of elements currently in the list.
    template <typename T>
    int Stack<T>::size( ) const
      { return sList.size(); }

    // Return true if the list is empty, false otherwise.
    template <typename T>  
    bool Stack<T>::empty( ) const
      { return sList.size( ) == 0; }

    //clear the list
    template <typename T>  
    void Stack<T>::clear( )
    {
        sList.clear();
    }


    template <typename T>
    void Stack<T>::push( const T & x )
      { sList.push_back(x); }
    
    template <typename T>
    void Stack<T>::push( T && x )
      { sList.push_back(x); }
    
    template <typename T>
    void Stack<T>::pop()
      { sList.pop_back(); }

    template <typename T>
    T & Stack<T>::top()
      { return sList.back(); }

    template <typename T>
    const T & Stack<T>::top( ) const
      { return sList.back(); }
        
    // print out all elements. ofc is deliminitor, check
    template <typename T>
    void Stack<T>::print(std::ostream & os, char ofc ) const  
    {
        for(auto & x : sList )
        {
            os << x << ofc;
        }
        os << std::endl;
    }
   
   // overloading comparison operators, check
    template <typename T>
        bool operator==(const Stack<T> & lhs, const Stack<T> & rhs)
        {
            
            if(lhs.size() == rhs.size())
            {
                Stack<T> lhs_t = Stack<T>(lhs);
                Stack<T> rhs_t = Stack<T>(rhs);
                for(int i=0; i< lhs.size();i++)
                {
                    if(lhs_t.top() != rhs_t.top())
                        return false;
                    lhs_t.pop();
                    rhs_t.pop();
                }
               // lhs_t.~Stack();
               // rhs_t.~Stack();
                return true;    
            }
            else
            {
                return false;
            }
        }
    //check
    template <typename T>
        bool operator!=(const Stack<T> & lhs, const Stack<T> &rhs)
        {
            return !operator==(lhs, rhs);

        }
//returns true if every element of Stack a is smaller than corresponding element of Stack b 
    template <typename T>
        bool operator<=(const Stack<T> & lhs, const Stack<T> &rhs)
        {
            if(lhs.size() == rhs.size())
            {
                Stack<T> lhs_t = Stack<T>(lhs);
                Stack<T> rhs_t = Stack<T>(rhs);
                for(int i=0; i< lhs.size();i++)
                {
                    if(lhs_t.top() > rhs_t.top())
                        return false;
                    lhs_t.pop();
                    rhs_t.pop();
                }

                return true;    
            }
            else if (lhs.size() < rhs.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }    
    // overloading output operator, check
    template <typename T>
        std::ostream & operator<<(std::ostream &os, const Stack<T> &l) 
        {
            l.print(os, ' ');
            return os;
        }  
