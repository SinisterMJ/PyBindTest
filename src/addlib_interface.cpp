#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "library.h"

namespace py = pybind11;

void init_add_library(py::module_ &mod)
{
    mod.def("addlib", &add_external, "Run C add");
}

PYBIND11_MODULE(add_library, mod) {
    init_add_library(mod);
}