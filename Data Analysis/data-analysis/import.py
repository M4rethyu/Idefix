import numpy as np
import matplotlib.pyplot as plt

# Import log file
file = "../log-file/log.csv"
data = np.loadtxt(file, delimiter=",", dtype=float)

# Unpack matrix into arrays
time, pressure, height, temperatureBMP, temperatureMPU, AcX, AcY, AcZ, GyX, GyY, GyZ, UV = np.hsplit(data, 12)

# Plot height and pressure against time
plot1 = plt.subplot2grid((2, 1), (0, 0))
plot2 = plt.subplot2grid((2, 1), (1, 0))

plot1.set_title("Height")
plot1.set_xlabel("time (ms)")
plot1.set_ylabel("height (m)")
plot1.plot(time, height, color="red")

plot2.set_title("Pressure")
plot2.set_xlabel("time (ms)")
plot2.set_ylabel("pressure (pas)")
plot2.plot(time, pressure, color="red")

plt.tight_layout()
plt.show()

