import numpy as np
import matplotlib.pyplot as plt

# Load the data
data1 = np.loadtxt('Data_1.txt')
data2 = np.loadtxt('Data_2.txt')

def find_peaks(data):
    maxima = []
    minima = []
    for i in range(1, len(data) - 1):
        if data[i] > data[i - 1] and data[i] > data[i + 1]:
            maxima.append(i)
        elif data[i] < data[i - 1] and data[i] < data[i + 1]:
            minima.append(i)
    return maxima, minima

# Find peaks in both datasets
maxima1, minima1 = find_peaks(data1)
maxima2, minima2 = find_peaks(data2)

# Plotting the results for Data 1
plt.figure(figsize=(12, 6))
plt.plot(data1, label='Data 1')
plt.scatter(maxima1, data1[maxima1], color='red', label='Maxima', marker='o')
plt.scatter(minima1, data1[minima1], color='blue', label='Minima', marker='o')
plt.title('Maxima and Minima for Data 1')
plt.xlabel('Index')
plt.ylabel('Amplitude')
plt.legend()
plt.grid()
plt.show()

# Plotting the results for Data 2
plt.figure(figsize=(12, 6))
plt.plot(data2, label='Data 2')
plt.scatter(maxima2, data2[maxima2], color='red', label='Maxima', marker='o')
plt.scatter(minima2, data2[minima2], color='blue', label='Minima', marker='o')
plt.title('Maxima and Minima for Data 2')
plt.xlabel('Index')
plt.ylabel('Amplitude')
plt.legend()
plt.grid()
plt.show()

# Print the results
print("Maxima Indices for Data 1:", maxima1)
print("Minima Indices for Data 1:", minima1)
print("Maxima Indices for Data 2:", maxima2)
print("Minima Indices for Data 2:", minima2)
