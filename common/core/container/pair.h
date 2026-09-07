#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace LBR
{
template <typename T>
class Pair : private std::array<T, 2>
{
public:
    Pair() = default;

    using std::array<T, 2>::operator[];
};
}  // namespace LBR