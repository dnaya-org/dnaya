#ifndef DNAYA_CN_TYPES_H
#define DNAYA_CN_TYPES_H

#include <cstddef>

namespace dnaya::cn {

using index_t = std::size_t;

struct weighted_index_t {
    index_t index;
    double weight;

    auto operator<(const weighted_index_t& other) const
    {
        return index < other.index;
    }
};

namespace detail {
} // namespace detail

// TODO: implement some kind of SFINAE and check for missing member
// functions
template <typename T>
struct network_traits {
    static constexpr auto is_directed = T::is_directed;
    static constexpr auto is_weighted = T::is_weighted;
};

} // namespace dnaya::cn

#endif // DNAYA_CN_TYPES_H
