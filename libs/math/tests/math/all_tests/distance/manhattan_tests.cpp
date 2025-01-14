//------------------------------------------------------------------------------
//
//   Copyright 2018-2019 Fetch.AI Limited
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
//------------------------------------------------------------------------------

#include "core/random/lcg.hpp"
#include "math/distance/manhattan.hpp"
#include "math/tensor.hpp"

#include "gtest/gtest.h"

using namespace fetch::math::distance;
using namespace fetch::math;

template <typename T>
class ManhattenTest : public ::testing::Test
{
};

using MyTypes = ::testing::Types<fetch::math::Tensor<float>, fetch::math::Tensor<double>,
                                 fetch::math::Tensor<fetch::fixed_point::FixedPoint<16, 16>>,
                                 fetch::math::Tensor<fetch::fixed_point::FixedPoint<32, 32>>>;

TYPED_TEST_CASE(ManhattenTest, MyTypes);

TYPED_TEST(ManhattenTest, simple_test)
{
  using SizeType = typename TypeParam::SizeType;

  Tensor<double> A = Tensor<double>(3);
  A.Fill(0);
  A.Set(SizeType{0}, 1);
  EXPECT_EQ(0, Manhattan(A, A));

  Tensor<double> B = Tensor<double>(3);
  B.Fill(0);
  B.Set(SizeType{1}, 1);
  EXPECT_EQ(Manhattan(A, B), 2);

  B.Fill(0);
  B.Set(SizeType{1}, 2);
  EXPECT_EQ(Manhattan(A, B), 3);

  B.Fill(0);
  B.Set(SizeType{0}, 1);
  B.Set(SizeType{1}, 1);
  EXPECT_EQ(Manhattan(A, B), 1);
}
