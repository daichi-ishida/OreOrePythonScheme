import os
import sys

# add original module to python path
sys.path.append(os.path.join(os.path.dirname(__file__), '../build/mylibs/example_numpy/Debug/'))

import numpy as np
import example_numpy

size = 5
a = np.arange(size)
b = np.random.randint(0, 10, size)

print("check print_array_1d")
print("python")
for i in range(a.shape[0]):
    print("x[{}] = {}".format(i, a[i]))

print("C++")
example_numpy.print_array_1d(a)

print("")

# print("check add_arrays_1d")
# print("numpy add")
# c1 = np.add(a, b)
# example_numpy.print_array_1d(c1)
# print("C++ add")
# c2 = example_numpy.add_arrays_1d(a, b)
# example_numpy.print_array_1d(c2)

print("check add_arrays_vec")
print("numpy add")
c1 = np.add(a, b)
example_numpy.print_array_1d(c1)
print("C++ add")
c2 = example_numpy.add_arrays_vec(a, b)
example_numpy.print_array_1d(c2)