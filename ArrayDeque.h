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
        return taille;
    }

    size_type capacity() const {
        return buffer.size();
    }

    bool empty() const {
        return !taille;
    }

    value_type back() const {
        return buffer.at(taille-1);
    }

    reference back() {
        return buffer.at(taille-1);
    }

    value_type front() const {
        return buffer.at(debut);
    }

    reference front() {
        return buffer.at(debut);
    }

    void push_back(const_reference value) {
    }

    void push_front(const_reference value){
        if(empty()) {
            buffer.at(debut) = value;
        } else if(debut != 0) {
            buffer.at(debut-1) = value;
            --debut;
        }else if(){
            TODO
        }
    }

    void pop_back() {
    }

    void pop_front() {
    }

};


#endif /* ArrayDeque_hpp */