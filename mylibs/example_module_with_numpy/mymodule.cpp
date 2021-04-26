#include "print_array.h"
#include <pybind11/pybind11.h>

PYBIND11_MODULE(example_module_with_numpy, m)
{
    m.doc() = "my test module";
    m.def("print_array", &print_array<int32_t>, "");
    m.def("print_array", &print_array<double>, "");
}