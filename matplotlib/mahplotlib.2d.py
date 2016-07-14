#!/usr/bin/env python
import matplotlib.pyplot as plt
import numpy as np

#x = np.linspace(-5,5,100)
x = np.arange(-5,5,0.01)
y = x**3
plt.axis([-6,6,-10,10])
plt.plot(x,y)
plt.xlim((-20,20))
plt.xlim((-20,20))
plt.grid(True)
plt.show()
