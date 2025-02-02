#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array;
    uint32_t count0 : 8;
    uint32_t count1 : 8;
};

void array2struct(int arr[], struct pack_array *pak) {
    pak->array = 0;
    pak->count0 = 0;
    pak->count1 = 0;

    for (int i = 0; i < 32; i++) {
        pak->array |= ((uint32_t)arr[i] << (31 - i));

        if (arr[i] == 0) {
            pak->count0++;
        } else {
            pak->count1++;
        }
    }
}

int main() {

    int arr[32];
    for (int i = 0; i < 32; i++) {
        scanf("%u", &arr[i]);
    }

    struct pack_array pak;
    array2struct(arr, &pak);

    printf("%u %u %u\n", pak.array, pak.count0, pak.count1);

    return 0;
}
