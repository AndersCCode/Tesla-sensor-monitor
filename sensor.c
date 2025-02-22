#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Sensor {
    int id;
    float value;
}; // test

float average(struct Sensor *sensors, int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += sensors[i].value;
    }
    return sum / count;
}

int main() {
    int num_sensors = 3;
    struct Sensor *sensors = malloc(num_sensors * sizeof(struct Sensor));
    
    // Mock sensor data (like LDAP attributes)
    sensors[0] = (struct Sensor){1, 75.5};
    sensors[1] = (struct Sensor){2, 82.0};
    sensors[2] = (struct Sensor){3, 90.1};

    clock_t start = clock();
    float avg = average(sensors, num_sensors);
    clock_t end = clock();

    printf("Average sensor value: %.2f\n", avg);
    if (avg > 85) printf("Warning: System overheating!\n");
    printf("Time taken: %f ms\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);

    free(sensors); // Clean up
    return 0;
}