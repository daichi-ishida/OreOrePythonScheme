#include <pybind11/pybind11.h>
#include "add.hpp"

PYBIND11_MODULE(mymodule, m) {
    m.doc() = "my test module";
    m.def("add", &add, "add two numbers");
}