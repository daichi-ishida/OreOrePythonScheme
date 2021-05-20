#include "thrust_add.h"
#include <thrust/transform.h>
#include <thrust/copy.h>

void thrust_add_arrays_int(std::vector<int>& input1, std::vector<int>& input2, std::vector<int>& output)
{
    thrust::host_vector<int> h_input1(input1);
    thrust::host_vector<int> h_input2(input2);

    thrust::device_vector<int> d_input1 = h_input1;
    thrust::device_vector<int> d_input2 = h_input2;
    thrust::device_vector<int> d_output(output.size());

    thrust::plus<int> op;
    thrust::transform(d_input1.begin(), d_input1.end(), d_input2.begin(), d_output.begin(), op);

    thrust::copy(d_output.begin(), d_output.end(), output.begin());
}

void thrust_add_arrays_float(std::vector<float>& input1, std::vector<float>& input2, std::vector<float>& output)
{
    thrust::host_vector<float> h_input1(input1);
    thrust::host_vector<float> h_input2(input2);

    thrust::device_vector<float> d_input1 = h_input1;
    thrust::device_vector<float> d_input2 = h_input2;
    thrust::device_vector<float> d_output(output.size());

    thrust::plus<float> op;
    thrust::transform(d_input1.begin(), d_input1.end(), d_input2.begin(), d_output.begin(), op);

    thrust::copy(d_output.begin(), d_output.end(), output.begin());
}