#include <stdio.h>
#include <stdlib.h>

// Load the data from a file
void load_data(const char *file_path, double *data, int *size) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%lf", &data[i]) != EOF) {
        i++;
    }
    *size = i;
    fclose(file);
}

// Find peaks and valleys
void find_peaks_and_valleys(double *data, int size, int *peaks, int *valleys, int *num_peaks, int *num_valleys) {
    *num_peaks = 0;
    *num_valleys = 0;
    for (int i = 1; i < size - 1; i++) {
        if (data[i] > data[i - 1] && data[i] > data[i + 1]) {
            peaks[*num_peaks] = i;
            (*num_peaks)++;
        }
        if (data[i] < data[i - 1] && data[i] < data[i + 1]) {
            valleys[*num_valleys] = i;
            (*num_valleys)++;
        }
    }
}

int main() {
    const int max_size = 1000;
    double data[max_size];
    int peaks[max_size];
    int valleys[max_size];
    int size;
    int num_peaks, num_valleys;

    // Load and process the first dataset
    load_data("Data_1.txt", data, &size);
    find_peaks_and_valleys(data, size, peaks, valleys, &num_peaks, &num_valleys);

    printf("Data 1:\n");
    printf("Peaks:\n");
    for (int i = 0; i < num_peaks; i++) {
        printf("Index: %d, Value: %.2f\n", peaks[i], data[peaks[i]]);
    }
    printf("Valleys:\n");
    for (int i = 0; i < num_valleys; i++) {
        printf("Index: %d, Value: %.2f\n", valleys[i], data[valleys[i]]);
    }

    // Load and process the second dataset
    load_data("Data_2.txt", data, &size);
    find_peaks_and_valleys(data, size, peaks, valleys, &num_peaks, &num_valleys);

    printf("Data 2:\n");
    printf("Peaks:\n");
    for (int i = 0; i < num_peaks; i++) {
        printf("Index: %d, Value: %.2f\n", peaks[i], data[peaks[i]]);
    }
    printf("Valleys:\n");
    for (int i = 0; i < num_valleys; i++) {
        printf("Index: %d, Value: %.2f\n", valleys[i], data[valleys[i]]);
    }

    return 0;
}
