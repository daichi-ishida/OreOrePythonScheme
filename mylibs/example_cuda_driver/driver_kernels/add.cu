
extern "C"
{
    __global__ void addIntKernel(int* c, const int* a, const int* b)
    {
        int i = threadIdx.x;
        c[i] = a[i] + b[i];
    }

    __global__ void addFloatKernel(float* c, const float* a, const float* b)
    {
        int i = threadIdx.x;
        c[i] = a[i] + b[i];
    }
}