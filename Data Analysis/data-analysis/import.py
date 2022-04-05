import numpy as np
import matplotlib.pyplot as plt

# Import log file
file = "../log-file/log.csv"
data = np.loadtxt(file, delimiter=",", dtype=float)

# Unpack matrix into arrays
time, pressure, height, temperatureBMP, temperatureMPU, AcX, AcY, AcZ, GyX, GyY, GyZ, UV = np.hsplit(data, 12)

# Plot height and pressure against time
plotHeight = plt.subplot2grid((3, 4), (0, 0))
plotPressure = plt.subplot2grid((3, 4), (1, 0))
plotUV = plt.subplot2grid((3, 4), (2, 0))
plotTempBMP = plt.subplot2grid((3, 4), (0, 1))
plotTempMPU = plt.subplot2grid((3, 4), (1, 1))
plotAcX = plt.subplot2grid((3, 4), (0, 2))
plotAcY = plt.subplot2grid((3, 4), (1, 2))
plotAcZ = plt.subplot2grid((3, 4), (2, 2))
plotGyX = plt.subplot2grid((3, 4), (0, 3))
plotGyY = plt.subplot2grid((3, 4), (1, 3))
plotGyZ = plt.subplot2grid((3, 4), (2, 3))


plotHeight.set_title("Height")
plotHeight.set_xlabel("time (ms)")
plotHeight.set_ylabel("height (m)")
plotHeight.plot(time, height, color="red")

plotPressure.set_title("Pressure")
plotPressure.set_xlabel("time (ms)")
plotPressure.set_ylabel("pressure (pas)")
plotPressure.plot(time, pressure, color="darkblue")

plotUV.set_title("UV")
plotUV.set_xlabel("time (ms)")
plotUV.set_ylabel("UVI")
plotUV.plot(time, UV, color="magenta")


#----------------------
plotTempBMP.set_title("TemperatureBMP")
plotTempBMP.set_xlabel("temperature (°C)")
plotTempBMP.set_ylabel("time (ms)")
plotTempBMP.plot(time,temperatureBMP, color="blue")

plotTempMPU.set_title("TemperatureMPU")
plotTempMPU.set_xlabel("temperature (°C)")
plotTempMPU.set_ylabel("time (ms)")
plotTempMPU.plot(time,temperatureMPU, color="blue")


#----------------------
plotAcX.set_title("AcX")
plotAcX.set_xlabel("time (ms)")
plotAcX.set_ylabel("x")
plotAcX.plot(time,AcX, color="green")

plotAcY.set_title("AcY")
plotAcY.set_xlabel("time (ms)")
plotAcY.set_ylabel("y")
plotAcY.plot(time,AcY, color="green")

plotAcZ.set_title("AcZ")
plotAcZ.set_xlabel("time (ms)")
plotAcZ.set_ylabel("z")
plotAcZ.plot(time,AcZ, color="green")


#----------------------
plotGyX.set_title("GyX")
plotGyX.set_xlabel("time (ms)")
plotGyX.set_ylabel("x")
plotGyX.plot(time,GyX, color="yellow")

plotGyY.set_title("GyY")
plotGyY.set_xlabel("time (ms)")
plotGyY.set_ylabel("y")
plotGyY.plot(time,GyY, color="yellow")

plotGyZ.set_title("GyZ")
plotGyZ.set_xlabel("time (ms)")
plotGyZ.set_ylabel("z")
plotGyZ.plot(time,GyZ, color="yellow")


plt.tight_layout()
plt.show()

