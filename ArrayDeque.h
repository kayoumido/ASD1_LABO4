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


    size_type physical_i(size_type logical_i) {
        size_type physicalIndex = (debut + logical_i) % capacity();

        return (physicalIndex >= 0) ? physicalIndex : physicalIndex + capacity();
    }

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
        return buffer.at(physical_i(taille));
    }

    reference back() {
        return buffer.at(physical_i(taille-1));
    }

    value_type front() const {
        return buffer.at(physical_i(0));
    }

    reference front() {
        return buffer.at(physical_i(0));
    }

    void push_back(const_reference value) {
        if(taille < capacity()){
            buffer.at(physical_i(taille)) = value;
            ++taille;
        }
    }

    void push_front(const_reference value){
        if(taille < capacity()) {
            debut = physical_i(capacity() - 1);
            buffer.at(debut) = value;
            ++taille;
        }
    }

    void pop_back() {
        if(taille) {
            // detruire data[i_physique(taille - 1)] => Libérer mémoire ?
            --taille;
        }
    }

    void pop_front() {
        if(taille){
            // detruire data[i_physique(0)] => Libérer mémoire ?
            debut = physical_i(1);
            --taille;
        }
    }

};


#endif /* ArrayDeque_hpp */