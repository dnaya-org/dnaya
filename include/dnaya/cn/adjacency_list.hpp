#ifndef DNAYA_CN_ADJACENCY_LIST_H
#define DNAYA_CN_ADJACENCY_LIST_H

#include <cassert>
#include <dnaya/cn/types.hpp>
#include <type_traits>
#include <vector>

namespace dnaya::cn
{

template <bool Weighted = false, bool Directed = false> class adjacency_list
{
  using neighbor_t = std::conditional_t<Weighted, weighted_index_t, index_t>;

public:
  explicit adjacency_list(index_t size) : neighbors_(size) {}

  static constexpr auto is_directed = Directed;
  static constexpr auto is_weighted = Weighted;

  auto size() const { return neighbors_.size(); }

  auto add_edge(index_t from, neighbor_t to)
  {
    assert(from < size());
    assert(to < size());

    insert_sorted(neighbors_[from], to);
    if constexpr (!is_directed)
      insert_sorted(neighbors_[to], from);
  }

  auto neighbors(index_t i) const -> const std::vector<neighbor_t>&
  {
    assert(i < neighbors_.size());
    return neighbors_[i];
  }

private:
  static void insert_sorted(std::vector<index_t>& vec, neighbor_t item)
  {
    // TODO: check if exists, multilink is not allowed
    vec.insert(std::upper_bound(vec.begin(), vec.end(), item), item);
  }

  std::vector<std::vector<neighbor_t>> neighbors_;
};

} // namespace dnaya::cn

#endif // DNAYA_CN_ADJACENCY_LIST_H
