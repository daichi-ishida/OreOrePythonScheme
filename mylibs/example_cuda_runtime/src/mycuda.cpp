#include "mycuda.h"

#include <cuda_runtime.h>
#include "../runtime_kernels/thrust_add.h"

#include "helper_cuda_rtapi.h"

#include <iostream>

MyCuda::MyCuda()
{
    findCudaDevice(0, nullptr);
}

MyCuda::~MyCuda()
{
}

std::vector<int> MyCuda::add_arrays_int(std::vector<int>& input1, std::vector<int>& input2)
{
    if (input1.size() !=input2.size())
    {
        throw std::runtime_error("Input shape must match");
    }

    //Apply resources
    std::vector<int> output(input1.size());
    thrust_add_arrays_int(input1, input2, output);

    return output;
}


std::vector<float> MyCuda::add_arrays_float(std::vector<float>& input1, std::vector<float>& input2)
{
    if (input1.size() !=input2.size())
    {
        throw std::runtime_error("Input shape must match");
    }

    //Apply resources
    std::vector<float> output(input1.size());
    thrust_add_arrays_float(input1, input2, output);

    return output;
}
