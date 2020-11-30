#ifndef DNAYA_DYN_VGZ3_H
#define DNAYA_DYN_VGZ3_H

// Verri, Gueleri, Zheng, Zhang, and Zhao
// https://arxiv.org/abs/1802.04186

#include <cassert>
#include <dnaya/cn/types.hpp>
#include <valarray>

namespace dnaya::dyn
{

// TODO: discuss which member functions a "system" class would have.
// (the function here only updates the state)
template <typename Network, typename Container>
auto vgz3(const Network&, Container state, double alpha) -> Container
{
  static_assert(std::is_same_v<std::valarray<double>, typename Container::value_type>);
  static_assert(!cn::network_traits<Network>::is_directed);
  static_assert(!cn::network_traits<Network>::is_weighted);

  // TODO: assert parameter D

  assert(alpha > 0);
  assert(alpha < 0.5);

  // TODO: clone container in size but do not initialize the elements
  auto result = state;

  using cn::index_t;
  // TODO: maybe use verri/cool::indices here
  for (index_t i = 0; i < state.size(); ++i) {
    // TODO: implement actual dynamics
  }

  return result;
}

} // namespace dnaya::dyn

#endif // DNAYA_DYN_VGZ3_H
