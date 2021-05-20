#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <fmt/core.h>
#include <iostream>

namespace py = pybind11;

template <typename T>
void print_array_1d(py::array_t<T>& x)
{
    const auto &buf = x.request();
    for (int i = 0; i < buf.shape[0]; i++)
    {
        auto v = *x.data(i);
        std::cout << fmt::format("x[{}] = {}", i, v) << std::endl;
    }
}