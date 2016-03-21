#ifndef HEAP
#define HEAP

#include <vector>

using std::vector;

template <typename T>
class heap
{
public:
    heap();
    ~heap();

    heap(const heap<T> &other);
    heap& operator=(const heap<T> &other);

    void clear();
    size_t size();

    heap& operator<<(const T &data);
    heap& operator>>(T &data);

private:
    vector<T> v;
    void reheapifyUp();
    void reheapifyDown();

};


heap<T>::heap()
{

}

heap<T>::~heap()
{
    v.clear();
}

heap<T>::heap(const heap<T> &other)
{
    v = other.v;
}

heap<T>& heap<T>::operator=(const heap<T> &other)
{
    if (this != &other)
    {
        v.clear();
        v = other.v;
    }
    return *this;
}

void heap<T>::clear()
{
    v.clear();
}

size_t heap<T>::size()
{
    return v.size();
}


#endif // HEAP

