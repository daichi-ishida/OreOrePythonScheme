#include <pybind11/pybind11.h>
#include "add.h"

PYBIND11_MODULE(example_add, m) {
    m.doc() = "my test module";
    m.def("add", &add, "add two numbers");
}