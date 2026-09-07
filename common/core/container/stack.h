#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace LBR
{
template <typename T, size_t N>
class Stack : private std::array<T, N>
{
public:
    Stack() = default;

    bool push(const T& tx)
    {
        if (full())
        {
            return false;
        }
        std::array<T, N>::operator[](count) = tx;
        count++;
        return true;
    }

    bool pop(T& rx)
    {
        if (empty())
        {
            return false;
        }
        rx = std::array<T, N>::operator[](--count);
        return true;
    }

    void reset()
    {
        count = 0;
    }

    bool empty() const
    {
        return count == 0;
    }

    bool full() const
    {
        return count == N;
    }

    size_t size() const
    {
        return count;
    }

    size_t capacity() const
    {
        return N;
    }

    T& operator[](size_t index)
    {
        return std::array<T, N>::operator[](index);
    }

    const T& operator[](size_t index) const
    {
        return std::array<T, N>::operator[](index);
    }

    int find(const T& val) const
    {
        for (int i = 0; i < count; i++)
        {
            if ((*this)[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    bool contains(const T& val) const
    {
        return find(val) != -1;
    }

private:
    size_t count{0};
};
}  // namespace LBR