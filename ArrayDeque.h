#ifndef ArrayDeque_hpp
#define ArrayDeque_hpp

#include <vector>

template < class T >
class ArrayDeque
{
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

private:
    std::vector<value_type> buffer;
    size_type debut;
    size_type taille;

public:
    ArrayDeque(size_type capacity = 0) : debut(0), taille(0), buffer(capacity) {
    }

    size_type size() const {
    }

    size_type capacity() const {
    }

    bool empty() const {
    }

    reference back() const {
    }

    reference front() const {
    }

    void push_back(const_reference value) {
    }

    void push_front(const_reference value){
    }

    void pop_back() {
    }

    void pop_front() {
    }

};


#endif /* ArrayDeque_hpp */