#include <vector>

class MyCuda
{
public:
    MyCuda();
    ~MyCuda();

    std::vector<int> add_arrays_int(std::vector<int>& input1, std::vector<int>& input2);
    std::vector<float> add_arrays_float(std::vector<float>& input1, std::vector<float>& input2);
};