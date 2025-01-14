#pragma once
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

#include "core/byte_array/tokenizer/token.hpp"
#include "python/fetch_pybind.hpp"

namespace fetch {
namespace byte_array {

void BuildToken(pybind11::module &module)
{
  namespace py = pybind11;
  py::class_<Token, fetch::byte_array::ConstByteArray>(module, "Token")
      .def(py::init<>())
      .def(py::init<char const *>())
      .def(py::init<const std::string &>())
      .def(py::init<const fetch::byte_array::ConstByteArray &>())
      .def(py::init<const fetch::byte_array::ConstByteArray &, const std::size_t &,
                    const std::size_t &>())
      .def("character", &Token::character)
      .def("SetChar", &Token::SetChar)
      .def("SetLine", &Token::SetLine)
      .def("line", &Token::line)
      .def("type", &Token::type)
      .def("SetType", &Token::SetType);
}

}  // namespace byte_array
}  // namespace fetch
