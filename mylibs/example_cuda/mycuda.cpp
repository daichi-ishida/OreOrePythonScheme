#include "mycuda.h"

#include "helper_cuda_drvapi.h"

#include <iostream>

MyCuda::MyCuda()
{
    CUdevice device = findCudaDeviceDRV(0, nullptr);
    CuFunctionsManager::create(device);

    // --- Test ---

    CuFunctionsManager::getInstance().loadModule("add");
}

MyCuda::~MyCuda()
{
    CuFunctionsManager::destroy();
}

std::vector<int> MyCuda::add_arrays_int(std::vector<int>& input1, std::vector<int>& input2)
{
    if (input1.size() !=input2.size())
    {
        throw std::runtime_error("Input shape must match");
    }

    //Apply resources
    auto output = std::vector<int>(input1.size());

    const size_t length = input1.size();
    CUdeviceptr input1d, input2d, outputd;
    cuMemAlloc(&input1d, sizeof(int) * length);
    cuMemAlloc(&input2d, sizeof(int) * length);
    cuMemAlloc(&outputd, sizeof(int) * length);

    cuMemcpyHtoD(input1d, input1.data(), sizeof(int) * length);
    cuMemcpyHtoD(input2d, input2.data(), sizeof(int) * length);

    void* kernelArgs[] = { &outputd, &input1d, &input2d };
    CUfunction addIntFunc = CuFunctionsManager::getInstance().getCuFunction("add", "addIntKernel");
    cuLaunchKernel(addIntFunc, (length+31)/32, 1, 1, 32, 1, 1, 0, NULL, kernelArgs, 0);

    cuMemcpyDtoH(output.data(), outputd, sizeof(int) * length);

    cuMemFree(input1d);
    cuMemFree(input2d);
    cuMemFree(outputd);

    return output;
}


std::vector<float> MyCuda::add_arrays_float(std::vector<float>& input1, std::vector<float>& input2)
{
    if (input1.size() !=input2.size())
    {
        throw std::runtime_error("Input shape must match");
    }

    //Apply resources
    auto output = std::vector<float>(input1.size());

    const size_t length = input1.size();
    CUdeviceptr input1d, input2d, outputd;
    cuMemAlloc(&input1d, sizeof(float) * length);
    cuMemAlloc(&input2d, sizeof(float) * length);
    cuMemAlloc(&outputd, sizeof(float) * length);

    cuMemcpyHtoD(input1d, input1.data(), sizeof(float) * length);
    cuMemcpyHtoD(input2d, input2.data(), sizeof(float) * length);

    void* kernelArgs[] = { &outputd, &input1d, &input2d };
    CUfunction addFloatFunc = CuFunctionsManager::getInstance().getCuFunction("add", "addFloatKernel");
    cuLaunchKernel(addFloatFunc, (length+31)/32, 1, 1, 32, 1, 1, 0, NULL, kernelArgs, 0);

    cuMemcpyDtoH(output.data(), outputd, sizeof(float) * length);

    cuMemFree(input1d);
    cuMemFree(input2d);
    cuMemFree(outputd);

    return output;
}
