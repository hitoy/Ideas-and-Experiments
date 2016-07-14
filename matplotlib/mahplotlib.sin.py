#!/usr/bin/env python
import matplotlib.pyplot as plt
import numpy as np

x = np.arange(-np.pi,np.pi,0.001)
y = np.sin(x)
print x,y

plt.plot(x,y,"b")
plt.show()
