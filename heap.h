#ifndef HEAP
#define HEAP

#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

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
    bool empty();

    heap& operator<<(const T &data);
    heap& operator>>(T &data);

private:
    vector<T> v;
    void reheapifyUp(size_t child_index);
    void reheapifyDown(size_t parent_index);

};

template <typename T>
heap<T>::heap()
{

}

template <typename T>
heap<T>::~heap()
{
    v.clear();
}

template <typename T>
heap<T>::heap(const heap<T> &other)
{
    v = other.v;
}

template <typename T>
heap<T>& heap<T>::operator=(const heap<T> &other)
{
    if (this != &other)
    {
        v.clear();
        v = other.v;
    }
    return *this;
}

template <typename T>
void heap<T>::clear()
{
    v.clear();
}

template <typename T>
size_t heap<T>::size()
{
    return v.size();
}

template <typename T>
bool heap<T>::empty()
{
    return v.empty();
}

template <typename T>
heap<T>& heap<T>::operator<<(const T &data)
{
    v.push_back(data);
    reheapifyUp(v.size()-1);
    return *this;
}

template <typename T>
heap<T>& heap<T>::operator>>(T &data)
{
    data = v.front();
    v.front() = v.back();
    v.pop_back();
    reheapifyDown(0);
}

template <typename T>
void heap<T>::reheapifyUp(size_t child_index)
{
    if (child_index == 0)
        return;
    size_t parent_index = ((child_index+1)/2)-1;
    if (v[parent_index] < v[child_index])
    {
        swap(v[parent_index], v[child_index]);
        reheapifyUp(parent_index);
    }
}

template <typename T>
void heap<T>::reheapifyDown(size_t parent_index)
{
    size_t child_index = ((parent_index + 1)*2)-1;
    if (child_index < v.size())
    {
        if (child_index + 1 < v.size() && v[child_index] < v[child_index+1])
            child_index+=1;
        if (v[parent_index] < v[child_index])
        {
            swap(v[parent_index],v[child_index]);
            reheapifyDown(child_index);
        }
    }
    else
        return;
}


#endif // HEAP

