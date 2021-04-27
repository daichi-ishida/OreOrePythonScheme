import os
import sys

# add original module to python path
sys.path.append(os.path.join(os.path.dirname(__file__), '../build/mylibs/example_add/Debug/'))

import example_add

print(example_add.add(2,5))