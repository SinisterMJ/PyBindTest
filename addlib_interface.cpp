#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include "library.h"

namespace py = pybind11;

void init_add_c(py::module_ &mod)
{
    mod.def("addc", &add_external, "Run C add");
}

PYBIND11_MODULE(add_c, mod) {
    init_add_c(mod);
    py::class_<Container>(mod, "Container")
        .def(py::init([]()
            { 
                Container* c = new Container();
                for (int i = 0; i < 3; ++i)
                    c->lineData[i] = new shortLine;
                return c;
            }))
        .def_readwrite("Count", &Container::Count)
        .def_property("data", [](Container& obj)
        {
            auto dtype = py::dtype(py::format_descriptor<short>::format());
            return pybind11::array(dtype, { obj.Count }, { sizeof(short) }, obj.data, nullptr);
        },
        [](Container& p, std::vector<short> val) {
            // p.Count = val.size(); // not for now
            std::memcpy(p.data, val.data(), val.size() * sizeof(short));
        }
        )
        .def_property("timestamps", [](Container& obj)
        {
            auto dtype = py::dtype(py::format_descriptor<short>::format());
            return pybind11::array(dtype, { obj.Count }, { sizeof(short) }, obj.timestamps, nullptr);
        },
        [](Container& p, std::vector<short> val) {
            std::memcpy(p.timestamps, val.data(), val.size() * sizeof(short));
        }
        )
        .def("__exit__", [] (Container& obj) {
            for (int i = 0; i < 3; ++i)
                delete obj.lineData;
         });
}