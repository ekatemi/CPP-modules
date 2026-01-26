#ifndef BAG_HPP
# define BAG_HPP

/// не помню точно что здесь было
class bag {

public:
    virtual ~bag() {}
    virtual void insert(int value) = 0;
    virtual void print() const = 0;
    virtual void clear() = 0;
};

#endif