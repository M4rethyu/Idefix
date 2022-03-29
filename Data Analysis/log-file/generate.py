import numpy as np
import pandas as pd


# Constants
g = 9.81                            # m/s

TIME_START = 120000                 # ms
TIME_INTERVAL = 100                 # ms
TIME_DELAY = 30                     # ms
TIME_UNCERTAINTY = 20               # ms

TIME_PARACHUTE_DEPLOY = 2000        # ms (minimum: 2000ms)
PARACHUTE_DECELERATION_TIME = 1000  # ms
LANDING_DECELERATION_TIME = 100     # ms

DROP_HEIGHT = 300                   # m

GROUND_PRESSURE = 101325            # pas
PRESSURE_GRADIENT = 12              # pas/m
PRESSURE_UNCERTAINTY = 1            # pas

TERMINAL_VELOCITY_PARACHUTE = 3     # m/s


# Derived Constants
FREE_FALL_STEPS = int(np.ceil(TIME_PARACHUTE_DEPLOY/TIME_INTERVAL))
PARACHUTE_DECELERATION_STEPS = int(np.ceil(PARACHUTE_DECELERATION_TIME/TIME_INTERVAL))
LANDING_DECELERATION_STEPS = int(np.ceil(LANDING_DECELERATION_TIME/TIME_INTERVAL))


# ----- Generate height, time, and pressure to be somewhat representative of a real fall -----
# Velocity in free fall
velocity_freefall = np.linspace(0, g * TIME_PARACHUTE_DEPLOY/1000, FREE_FALL_STEPS)
# Transition to parachute
velocity_parachute_deceleration = np.linspace(velocity_freefall[-1], TERMINAL_VELOCITY_PARACHUTE, PARACHUTE_DECELERATION_STEPS+2)[1:-1]
# Landing
velocity_landing = np.linspace(TERMINAL_VELOCITY_PARACHUTE, 0, LANDING_DECELERATION_STEPS+1)[1:]

# Calculate height fallen until parachute is opened
height_above_parachute = (np.sum(velocity_freefall) + np.sum(velocity_parachute_deceleration)) * (TIME_INTERVAL + TIME_DELAY)/1000

# Generate arrays of height for individual phases of fall
height_landing = np.cumsum(velocity_landing)
height_parachuting = np.arange(height_landing[-1], DROP_HEIGHT - height_above_parachute, TERMINAL_VELOCITY_PARACHUTE * (TIME_INTERVAL + TIME_DELAY)/1000)
height_deploying = np.cumsum(velocity_parachute_deceleration[::-1]) * (TIME_INTERVAL + TIME_DELAY)/1000 + height_parachuting[-1]
height_freefalling = np.cumsum(velocity_freefall[::-1]) * (TIME_INTERVAL + TIME_DELAY)/1000 + height_deploying[-1]
# concatenate all phases
height = np.concatenate((height_landing, height_parachuting, height_deploying, height_freefalling))[::-1]

# Calculate pressure from height
pressure = GROUND_PRESSURE + height * PRESSURE_GRADIENT
# Add uncertainty
pressure += np.random.normal(0, PRESSURE_UNCERTAINTY, pressure.shape)
# Calculate height from pressure to transfer uncertainty
height = (pressure - GROUND_PRESSURE) / PRESSURE_GRADIENT

# Generate timestamps
time = np.linspace(TIME_START, TIME_START + height.size * TIME_INTERVAL, height.size)
# Add uncertainty (normally distributed)
time += np.random.normal(0, TIME_UNCERTAINTY, time.shape)

# ----- Generate all other columns. These values have no correlation to a real fall -----
temperatureBMP = np.random.normal(23.5, 1, time.shape)
temperatureMPU = np.random.normal(24.6, 0.2, time.shape)

AcX = np.random.normal(250, 80, time.shape)
AcY = np.random.normal(-300, 100, time.shape)
AcZ = np.random.normal(14600, 200, time.shape)

GyX = np.random.normal(-250, 40, time.shape)
GyY = np.random.normal(70, 25, time.shape)
GyZ = np.random.normal(-170, 35, time.shape)

UV = np.random.normal(0.15, 0.05, time.shape)

# Merge all arrays to single matrix
log = np.stack((time, pressure, height, temperatureBMP, temperatureMPU, AcX, AcY, AcZ, GyX, GyY, GyZ, UV)).transpose()

# Write data to file
df = pd.DataFrame(log)
df.to_csv('log.csv', index=False, header=False)
