#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>

namespace py = pybind11;

template <typename T>
py::array_t<T> add_arrays_1d(py::array_t<T>& input1, py::array_t<T>& input2) 
{
    // Get info from input1, input2
    const auto buf1 = input1.request();
    const auto buf2 = input2.request();

    if (buf1.ndim !=1 || buf2.ndim !=1)
    {
        throw std::runtime_error("Number of dimensions must be one");
    }

    if (buf1.size !=buf2.size)
    {
        throw std::runtime_error("Input shape must match");
    }

    //Apply resources
    auto result = py::array_t<T>(buf1.size);
    py::buffer_info buf3 = result.request();

    //Obtain numpy.ndarray data pointer
    T* ptr1 = (T*)buf1.ptr;
    T* ptr2 = (T*)buf2.ptr;
    T* ptr3 = (T*)buf3.ptr;

    //Pointer visits numpy.ndarray
    for (int i = 0; i < buf1.shape[0]; i++)
    {
        ptr3[i] = ptr1[i] + ptr2[i];
    }

    return result;
}