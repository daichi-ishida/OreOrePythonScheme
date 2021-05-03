#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <iostream>

template <typename T>
std::vector<T> add_arrays_vec(std::vector<T>& input1, std::vector<T>& input2) 
{
    if (input1.size() !=input2.size())
    {
        throw std::runtime_error("Input shape must match");
    }

    //Apply resources
    auto output = std::vector<T>(input1.size());

    //Pointer visits numpy.ndarray
    for (int i = 0; i < input1.size(); i++)
    {
        output[i] = input1[i] + input2[i];
    }

    return output;
}