# Ore-Ore Python Scheme
"OOPS" provides a template project for creating C++ libraries using the CUDA kernels and binding them as Python Modules.

This project aims to help you package your C++ code or code using CUDA (Both runtime and driver API are supported).

 
# Requirement
* CMake 3.17 or later
* CUDAToolkit 11 or later (you can change it in CMakeLists.txt)
* Python
  * numpy is used in the example
* [fmt](https://github.com/fmtlib/fmt) is used for Python-like output in C++
 
# Usage
## Clone template
You can start developing your project as soon as you clone it.
Since it contains submodule, you can clone as shown below
```
git clone --recursive https://github.com/daichi-ishida/OreOrePythonScheme.git
``` 

## Create C++ component
To create your C++ component, please make new directory under *mylibs* by referring to example. You might want to copy and rename it. The minimal directory structure consists of *include*, *src* directories and *CMakeLists.txt*, *mymodule.cpp*. And the C++ library development is done using this *include* and *src* directories. When you introduce external libraries or define macros, please change *CMakeList.txt* in this directory.

## Bind components as Python Module
To bind components you created as Python Module, creating binding code is needed in *mymodule.cpp*.
In that file, you will find "PYBIND11_MODULE". The first argument of "PYBIND11_MODULE" would be the name of the module. See the [pybind11 documentation](https://pybind11.readthedocs.io/en/stable/index.html) for details on how to bind.

# What is "Ore-Ore"?
 
This template provides the environment that enables you to develop component codes, test them, bind them as Python modules and create application using these modules.

This implies that you will create everything yourself from the components.
In Japanese, we use the word "Ore-Ore" for such a creation that is entirely self-made.
That's why I named.
 
# Author
 
* Daichi Ishida
 
# License
 
"OOPS" is under [MIT license](https://en.wikipedia.org/wiki/MIT_License).
 
Enjoy making modules!


# External Project
- **pybind11**: https://github.com/pybind/pybind11
- **GoogleTest**: https://github.com/google/googletest

# TODO
- Writing more detailed documentation.