#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <fmt/core.h>
#include <iostream>

template <typename T>
void print_array(pybind11::array_t<T> x)
{
    const auto &buff_info = x.request();
    const auto &shape = buff_info.shape;
    std::cout << "C++" << std::endl;
    for (auto i = 0; i < shape[0]; i++)
    {
        for (auto j = 0; j < shape[1]; j++)
        {
            auto v = *x.data(i, j);
            std::cout << fmt::format("x[{}, {}] = {}", i, j, v) << std::endl;
        }
    }
}