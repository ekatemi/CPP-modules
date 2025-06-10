#ifndef ARRAY_HPP
#define ARRAY_HPP

// Construction with no parameter: Creates an empty array.
// • Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
// • Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.

template <typename T>
class Array
{
private:
    T *el;
    unsigned int len;

public:
    Array() : el(NULL), len(0) {};
    Array(unsigned int n) : el(new T[n]()), len(n) {};
    Array(const Array &src) : el(new T[src.len]), len(src.len)
    {
        for (unsigned int i = 0; i < len; i++)
        {
            el[i] = src.el[i];
        }
    };
    Array &operator=(const Array &src)
    {
        if (this != &src)
        {
            delete[] el;
            len = src.len;
            el = new T[len];
            for (std::size_t i = 0; i < len; ++i)
            {
                el[i] = src.el[i];
            }
        }
        return *this;
    };
    ~Array() { delete[] el };

    int size() const
    {
        return len;
    };
};

#endif
