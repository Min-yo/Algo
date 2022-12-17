#include <iterator>
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

// ------------------------------------------------------------------------------------------------
// This would be in a header file -----------------------------------------------------------------

// Type trait helper to identify iterators --------------------------------------------------------
template<typename T, typename = void>
struct is_iterator { static constexpr bool value = false; };
template<typename T>
struct is_iterator<T, typename std::enable_if<!std::is_same<typename std::iterator_traits<T>::value_type, void>::value>::type> {
    static constexpr bool value = true;
};

// The List class ---------------------------------------------------------------------------------
template <typename T>
class List {
    // Sub class for a Node -----------
    struct Node {
        T data{};
        Node* next{};
        Node* previous{};
        Node() {}
        Node(Node* const n, Node* const p) : next(n), previous(p) {}
        Node(Node* const n, Node* const p, const T& d) : next(n), previous(p), data(d) {}
    };

    // Private list data and functions --------
    Node* head{};
    size_t numberOfElements{};
    void init() { head = new Node(); head->next = head; head->previous = head; numberOfElements = 0; }

public:
    struct iterator;    // Forward declaration

    // Constructor --------------------
    List() { init(); }
    explicit List(const size_t count) { init(); insert(begin(), count); }
    explicit List(const size_t count, const T& value) { init(); insert(begin(), count, value); };
    template <typename Iter>
    List(const Iter& first, const Iter& last) { init(); insert(begin(), first, last); }
    List(const List& other) { init(), insert(begin(), other.begin(), other.end()); };

    List(List&& other) : head(other.head), numberOfElements(other.numberOfElements) { other.init(); }
    List(const std::initializer_list<T>& il) { init(); insert(begin(), il.begin(), il.end()); }
    template <int N> List(T(&other)[N]) { init(); insert(begin(), std::begin(other), std::end(other)); }
    template <int N> List(const T(&other)[N]) { init(); insert(begin(), std::begin(other), std::end(other)); }


    // Assignment ---------------------
    List& operator =(const List& other) { clear(); insert(begin(), other.begin(), other.end()); return *this; }
    List& operator =(List&& other) { clear(); head = other.head; numberOfElements = other.numberOfElements; other.init(); return *this; }
    List& operator =(const std::initializer_list<T>& il) { clear(); insert(begin(), il.begin(), il.end()); return *this; }
    template <int N> List& operator =(const T(&other)[N]) { clear(); insert(begin(), std::begin(other), std::end(other)); return *this; }
    template <int N> List& operator =(T(&other)[N]) { clear(); insert(begin(), std::begin(other), std::end(other)); return *this; }

    template <typename Iter> void assign(const Iter& first, const Iter& last) { clear(); insert(begin(), first, last); }
    template <int N> void assign(const T(&other)[N]) { clear(); insert(begin(), std::begin(other), std::end(other)); return *this; }
    template <int N> void assign(T(&other)[N]) { clear(); insert(begin(), std::begin(other), std::end(other)); return *this; }
    void assign(const size_t count, const T& value) { clear(); insert(begin(), count, value); }
    void assign(const std::initializer_list<T>& il) { clear(); insert(begin(), il.begin(), il.end()); }

    // Destructor ---------------------
    ~List() { clear(); delete head; }

    // Element Access -----------------
    T& front() { return *begin(); }
    T& back() { return *(--end()); }

    // Iterators ----------------------
    iterator begin() const { return iterator(head->next, head); }
    iterator end() const { return iterator(head, head); }

    // Capacity -----------------------
    size_t size() const { return numberOfElements; }
    bool empty() { return size() == 0; }

    // Modifiers ----------------------
    void clear();

    iterator insert(const iterator& insertBeforePosition, const T& value);
    iterator insert(const iterator& insertBeforePosition);
    template <class Iter, std::enable_if_t<is_iterator<Iter>::value, bool> = true>
    iterator insert(const iterator& insertBeforePosition, const Iter& first, const Iter& last);
    iterator insert(const iterator& insertBeforePosition, const size_t& count, const T& value);
    iterator insert(const iterator& insertBeforePosition, const std::initializer_list<T>& il);

    iterator erase(const iterator& posToDelete);
    iterator erase(const iterator& first, const iterator& last);

    void pop_front() { erase(begin()); };
    void push_front(const T& d) { insert(begin(), d); }

    void pop_back() { erase(--end()); };
    void push_back(const T& d) { insert(end(), d); }

    void resize(size_t count, const T& value);
    void resize(size_t count);

    void swap(List& other) { std::swap(head, other.head); std::swap(numberOfElements, other.numberOfElements); }

    // Operations --------------------
    void reverse();

    // Non standard inefficient functions --------------------------
    T& operator[](const size_t index) const { return begin()[index]; }

    // ------------------------------------------------------------------------
    // Define iterator capability ---------------------------------------------
    struct iterator {

        // Definitions ----------------
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        // Data -----------------------
        Node* iter{};
        Node* head{};

        // Constructor ----------------
        iterator(Node* const node, Node* const h) : iter(node), head(h) {};
        iterator() {};

        // Dereferencing --------------
        reference operator*() const { return iter->data; }
        reference operator->() const { return &**this; }

        // Arithmetic operations ------
        iterator operator++() { iter = iter->next; return *this; }
        iterator operator--() { iter = iter->previous; return *this; }
        iterator operator++(int) { iterator tmp = *this; ++* this; return tmp; }
        iterator operator--(int) { iterator tmp = *this; --* this; return tmp; }

        iterator operator +(const difference_type& n) const {
            iterator temp{ *this };  difference_type k{ n }; if (k > 0) while (k--)++temp; else while (k++)--temp; return temp;
        }
        iterator operator +=(const difference_type& n) {
            difference_type k{ n }; if (k > 0) while (k--)++* this; else while (k++)--* this; return *this;
        };
        iterator operator -(const difference_type& n) const {
            iterator temp{ *this };  difference_type k{ n }; if (k > 0) while (k--)--temp; else while (k++)++temp; return temp;
        }
        iterator operator -=(const difference_type& n) {
            difference_type k{ n }; if (k > 0) while (k--)--* this; else while (k++)++* this; return *this;
        };
        // Comparison ----------------- (typical space ship implementation)
        bool operator ==(const iterator& other) const { return iter == other.iter; };
        bool operator !=(const iterator& other) const { return iter != other.iter; };
        bool operator < (const iterator& other) const { return other.iter - iter < 0; };
        bool operator <= (const iterator& other) const { return other.iter - iter <= 0; };
        bool operator > (const iterator& other) const { return other.iter - iter > 0; };
        bool operator >= (const iterator& other) const { return other.iter - iter >= 0; };

        // Special non standard functions -----------------
        difference_type operator-(const iterator& other) const;
        reference operator[] (const size_t index);
    };
};


// ------------------------------------------------------------------------------------------------
// Implementation of list functions. This would normally go into a TCC file -----------------------

// List class functions ---------------
template <typename T>
void List<T>::clear() {

    for (Node* nextNode{}, * currentNode(head->next); currentNode != head; currentNode = nextNode) {
        nextNode = currentNode->next;
        delete currentNode;
    }
    delete head;
    init();
}
template <typename T>
typename List<T>::iterator List<T>::insert(const List<T>::iterator& insertBeforePosition, const T& value)
{
    Node* nodeInsertBeforePosition = insertBeforePosition.iter;
    Node* newNode = new Node(nodeInsertBeforePosition, nodeInsertBeforePosition->previous, value);
    nodeInsertBeforePosition->previous = newNode;
    (newNode->previous)->next = newNode;
    ++numberOfElements;
    return iterator(newNode, head);
}
template <typename T>
typename List<T>::iterator List<T>::insert(const List<T>::iterator& insertBeforePosition)
{
    Node* nodeInsertBeforePosition = insertBeforePosition.iter;
    Node* newNode = new Node(nodeInsertBeforePosition, nodeInsertBeforePosition->previous);
    nodeInsertBeforePosition->previous = newNode;
    (newNode->previous)->next = newNode;
    ++numberOfElements;
    return iterator(newNode, head);
}

template <typename T>
template <class Iter, std::enable_if_t<is_iterator<Iter>::value, bool>>
typename List<T>::iterator List<T>::insert(const List<T>::iterator& insertBeforePosition, const Iter& first, const Iter& last) {
    iterator result(insertBeforePosition.iter, head);
    if (first != last) {
        result = insert(insertBeforePosition, *first);
        Iter i(first);
        for (++i; i != last; ++i)
            insert(insertBeforePosition, *i);
    }
    return result;
}

template <typename T>
typename List<T>::iterator List<T>::insert(const List<T>::iterator& insertBeforePosition, const size_t& count, const T& value) {

    iterator result(insertBeforePosition.iter, head);
    if (count != 0u) {
        result = insert(insertBeforePosition, value);
        for (size_t i{ 1u }; i < count; ++i)
            insert(insertBeforePosition, value);
    }
    return result;
}

template <typename T>
typename List<T>::iterator List<T>::insert(const List<T>::iterator& insertBeforePosition, const std::initializer_list<T>& il) {
    return insert(insertBeforePosition, il.begin(), il.end());
}

template <typename T>
typename List<T>::iterator List<T>::erase(const List<T>::iterator& posToDelete) {

    iterator result = posToDelete;
    ++result;

    Node* nodeToDelete = posToDelete.iter;

    if (nodeToDelete != head) {

        nodeToDelete->previous->next = nodeToDelete->next;
        nodeToDelete->next->previous = nodeToDelete->previous;

        delete nodeToDelete;
        --numberOfElements;
    }
    return result;
}

template <typename T>
typename List<T>::iterator List<T>::erase(const List<T>::iterator& first, const List<T>::iterator& last) {
    iterator result{ end() };
    if (first == begin() && last == end())
        clear();
    else {
        while (first != last)
            first = erase(first);
        result = last;
    }
    return result;
}

template <typename T>
void List<T>::resize(size_t count) {
    if (numberOfElements < count)
        for (size_t i{ numberOfElements }; i < count; ++i)
            insert(end());
    else
        while (count--)
            pop_back();
}
template <typename T>
void List<T>::resize(size_t count, const T& value) {
    if (numberOfElements < count)
        for (size_t i{ numberOfElements }; i < count; ++i)
            insert(end(), value);
    else
        while (count--)
            pop_back();
}
template <typename T>
void List<T>::reverse() {
    const Node* oldHead = head;

    for (Node* nptr = head; ; nptr = nptr->previous) {
        std::swap(nptr->next, nptr->previous);
        if (nptr->previous == oldHead) // Previous was the original next
            break;
    }
}

// ------------------------------------
// Iterator functions -----------------
template <typename T>
typename List<T>::iterator::difference_type List<T>::iterator::operator-(const iterator& other) const {

    difference_type result{};
    Node* nptr = head;

    int indexThis{ -1 }, indexOther{ -1 }, index{};

    do {
        nptr = nptr->next;
        if (nptr == iter)
            indexThis = index;
        if (nptr == other.iter)
            indexOther = index;
        ++index;
    } while (nptr != head);

    if (indexThis >= 0 and indexOther >= 0)
        result = indexThis - indexOther;
    return result;
}
template <typename T>
typename List<T>::iterator::reference List<T>::iterator::operator[] (const size_t index) {
    Node* nptr = head->next;
    for (size_t i{}; i < index and nptr != head; ++i, nptr = nptr->next)
        ;
    return nptr->data;
}
int main() {
    List<int> list{ 1,2,3 };
    for (const int i : list)
        std::cout << i << '\n';
    List<int>::iterator iter = list.begin();
    std::cout << '\n' << iter[1] << '\n';
}