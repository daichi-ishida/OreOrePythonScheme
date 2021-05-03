#include "print_array_1d.h"
#include "add_arrays_1d.h"
#include "add_arrays_vec.h"

#include <pybind11/pybind11.h>

PYBIND11_MODULE(example_numpy, m)
{
    m.doc() = "my test module";
    m.def("print_array_1d", &print_array_1d<int32_t>, "");
    m.def("print_array_1d", &print_array_1d<double>, "");
    m.def("add_arrays_1d", &add_arrays_1d<int32_t>, "");
    m.def("add_arrays_1d", &add_arrays_1d<double>, "");
    m.def("add_arrays_vec", &add_arrays_vec<int32_t>, "");
    m.def("add_arrays_vec", &add_arrays_vec<double>, "");
}