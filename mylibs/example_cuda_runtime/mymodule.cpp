#include "print_array_1d.h"
#include "mycuda.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_MODULE(example_cuda_runtime, m)
{
    m.doc() = "my test module";
    m.def("print_array_1d", &print_array_1d<int32_t>, "");
    m.def("print_array_1d", &print_array_1d<double>, "");

    py::class_<cuda_runtime::MyCuda>(m, "MyCuda")
            .def(py::init<>())
            .def("add_arrays_int", &cuda_runtime::MyCuda::add_arrays_int)
            .def("add_arrays_float", &cuda_runtime::MyCuda::add_arrays_float);
}