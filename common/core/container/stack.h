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

    bool push(T tx)
    {
        if (full())
        {
            return false;
        }
        (*this)[count] = tx;
        count++;
        return true;
    }

    bool pop(T& rx)
    {
        if (empty())
        {
            return false;
        }
        rx = (*this)[--count];
        return true;
    }

    bool reset()
    {
        count = 0;
        head = 0;
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

private:
    size_t count{0};
};
}  // namespace LBR