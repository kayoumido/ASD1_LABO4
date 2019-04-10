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

    /**
     * @brief convert a logical index into a physical one
     *
     * @param logical_i to convert
     * @return the converted index
     */
    size_type physical_i(size_type logical_i) const {
        size_type physicalIndex = (debut + logical_i) % capacity();

        return (physicalIndex >= 0) ? physicalIndex : physicalIndex + capacity();
    }

    /**
     * @brief Calculate the new capacity of the buffer
     * @return the new capacity
     */
    size_type newCapacity() const {
        return (capacity() == 0) ? 1 : 2 * capacity();
    }

    /**
     * @brief  Increase the capacity of the current buffer.
     *         The capacity is increased by doubling the capacity
     *         of the current buffer.
     *         The data stored in the current buffer is copied into the new one starting
     *         at the physical index 0 and not the logical one used previously.
     */
    void increaseCapacity() {
        std::vector<value_type> tmp(newCapacity());

        if(!empty()) {

            for (size_type i = 0; i < this->size(); ++i) {
                tmp.at(i) = this->buffer.at(physical_i(i));
            }
        }

        std::swap(buffer, tmp);
        // reset the logical starting index back to 0
        debut = 0;
    }


public:
    ArrayDeque(size_type capacity = 0) : debut(0), taille(0), buffer(capacity) {}

    /**
     * @brief get the size of the ArrayDeque
     * @return size of the ArrayDeque
     */
    size_type size() const {
        return taille;
    }

    /**
     * @brief get the capacity of the ArrayDeque
     * @return capacity of the ArrayDeque
     */
    size_type capacity() const {
        return buffer.size();
    }

    /**
     * @brief check if the ArrayDeque is empty
     * @return true if it's empty otherwise false
     */
    bool empty() const {
        return !taille;
    }

    /**
     * @brief get the last item in the ArrayDeque
     * @note    this version of the back function was created
     *          for const ArrayDeque and doesn't allow to do :
     *          ArrayDeque.back() = <something>
     *
     * @return the last item in the ArrayDeque
     */
    value_type back() const {
        return buffer.at(physical_i(taille-1));
    }

    /**
     * @brief get the last item in the ArrayDeque
     * @note    this version of the back function was created
     *          for non const ArrayDeque and allows to do :
     *          ArrayDeque.back() = <something>
     *
     * @return the last item in the ArrayDeque
     */
    reference back() {
        return buffer.at(physical_i(taille-1));
    }

    /**
     * @brief get the first item in the ArrayDeque
     * @note    this version of the first function was created
     *          for const ArrayDeque and doesn't allow to do :
     *          ArrayDeque.front() = <something>
     *
     * @return the first item in the ArrayDeque
     */
    value_type front() const {
        return buffer.at(physical_i(0));
    }

    /**
     * @brief get the first item in the ArrayDeque
     * @note    this version of the first function was created
     *          for non const ArrayDeque and allows to do :
     *          ArrayDeque.front() = <something>
     *
     * @return the first item in the ArrayDeque
     */
    reference front() {
        return buffer.at(physical_i(0));
    }

    /**
     * @brief add a new value at the end of the ArrayDeque
     *
     * @param value to add
     */
    void push_back(const_reference value) {
        if(taille >= capacity()) {
            increaseCapacity();
        }

        buffer.at(physical_i(taille)) = value;
        ++taille;
    }

    /**
     * @brief add a new value at the begining of the ArrayDeque
     *
     * @param value to add
     */
    void push_front(const_reference value){
        if(taille >= capacity()) {
            increaseCapacity();
        }

        debut = physical_i(capacity() - 1);
        buffer.at(debut) = value;
        ++taille;
    }

    /**
     * @brief remove the last item
     */
    void pop_back() {
        if(taille) {
            --taille;
        }
    }

    /**
     * @brief remove the first item
     */
    void pop_front() {
        if(taille){
            debut = physical_i(1);
            --taille;
        }
    }


};


#endif /* ArrayDeque_hpp */
