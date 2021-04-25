import os
import sys

# add original module to python path
sys.path.append(os.path.join(os.path.dirname(__file__), '../build/mylibs/example_module/Debug/'))

import example_module

print(example_module.add(2,5))