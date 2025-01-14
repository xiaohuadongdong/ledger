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

#include "vectorise/fixed_point/serializers.hpp"

#include "core/serializers/byte_array_buffer.hpp"

#include "gtest/gtest.h"

namespace fetch {
namespace serializers {

TEST(FixedPointSerialisationTest, IntegerSerialisation)
{
  for (int i(-100); i < 100; ++i)
  {
    fetch::fixed_point::FixedPoint<32, 32> a(i);
    fetch::serializers::ByteArrayBuffer    b;
    b << a;
    b.seek(0);
    fetch::fixed_point::FixedPoint<32, 32> c;
    b >> c;
    EXPECT_EQ(a, c);
    EXPECT_EQ(int(a), i);
  }
}

TEST(FixedPointSerialisationTest, DecimalSerialisation)
{
  for (float i(-10); i < 10; i += 0.12345f)
  {
    fetch::fixed_point::FixedPoint<32, 32> a(i);
    fetch::serializers::ByteArrayBuffer    b;
    b << a;
    b.seek(0);
    fetch::fixed_point::FixedPoint<32, 32> c;
    b >> c;
    EXPECT_EQ(a, c);
    EXPECT_FLOAT_EQ(float(a), i);
  }
}

}  // namespace serializers
}  // namespace fetch
