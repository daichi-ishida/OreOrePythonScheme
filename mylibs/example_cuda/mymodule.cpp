#include "print_array_1d.h"
#include "mycuda.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_MODULE(example_cuda, m)
{
    m.doc() = "my test module";
    m.def("print_array_1d", &print_array_1d<int32_t>, "");
    m.def("print_array_1d", &print_array_1d<double>, "");

    py::class_<MyCuda>(m, "MyCuda")
            .def(py::init<>())
            .def("add_arrays_int", &MyCuda::add_arrays_int)
            .def("add_arrays_float", &MyCuda::add_arrays_float);
}