import os
import sys

# add original module to python path
sys.path.append(os.path.join(os.path.dirname(__file__), '../build/mylibs/example_cuda_driver/Debug/'))

import numpy as np
import example_cuda_driver # type: ignore

size = 5
a = np.arange(size)
b = np.random.randint(0, 10, size)

print("check print_array_1d")
print("python")
for i in range(a.shape[0]):
    print("x[{}] = {}".format(i, a[i]))

print("C++")
example_cuda_driver.print_array_1d(a)

print("")


print("check add_arrays_cuda")
print("numpy add")
c1 = np.add(a, b)
example_cuda_driver.print_array_1d(c1)
print("CUDA add")
mycuda = example_cuda_driver.MyCuda()
c2 = mycuda.add_arrays_int(a, b)
example_cuda_driver.print_array_1d(c2)