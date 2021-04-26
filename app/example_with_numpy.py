import os
import sys

# add original module to python path
sys.path.append(os.path.join(os.path.dirname(__file__), '../build/mylibs/example_module_with_numpy/Debug/'))

import numpy as np
import example_module_with_numpy

x = np.arange(2*3).reshape((2, 3)).astype(np.int32)
print("python")
for i in range(x.shape[0]):
    for j in range(x.shape[1]):
        print("x[{}, {}] = {}".format(i, j, x[i, j]))

example_module_with_numpy.print_array(x)
