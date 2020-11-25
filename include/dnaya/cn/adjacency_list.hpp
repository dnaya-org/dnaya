#ifndef DNAYA_CN_ADJACENCY_LIST_H
#define DNAYA_CN_ADJACENCY_LIST_H

#include <cassert>
#include <dnaya/cn/types.hpp>
#include <vector>

namespace dnaya::cn
{

template <bool Weighted = false, bool Directed = false> class adjacency_list
{
public:
  explicit adjacency_list(index_t size) : neighbors_(size) {}

  static constexpr auto is_directed = Directed;
  static constexpr auto is_weighted = Weighted;

  auto size() const { return neighbors_.size(); }

  auto add_edge(index_t from, index_t to)
  {
    assert(from < size());
    assert(to < size());

    insert_sorted(neighbors_[from], to);
    if constexpr (!is_directed)
      insert_sorted(neighbors_[to], from);
  }

private:
  static void insert_sorted(std::vector<index_t>& vec, index_t item)
  {
    vec.insert(std::upper_bound(vec.begin(), vec.end(), item), item);
  }

  std::vector<std::vector<index_t>> neighbors_;
};

} // namespace dnaya::cn

#endif // DNAYA_CN_ADJACENCY_LIST_H
