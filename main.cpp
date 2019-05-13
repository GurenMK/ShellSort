//Alexander Urbanyak

#include <iostream>
#include <cstdlib>

void shell_sort(int data[], std::size_t size);

int main() {
    int my_array[] = {11, 7, 8, 19, 24, 82, 0, 5, 16, 23, 12, 20, 4, 45, 66};

    std::cout << "Unsorted array:\t";
    for(std::size_t i = 0; i < 15; i++)
        std::cout << my_array[i] << ' ';
    std::cout << '\n';

    shell_sort(my_array, 15);

    std::cout << "Sorted array:\t";
    for(std::size_t i = 0; i < 15; i++)
        std::cout << my_array[i] << ' ';
    std::cout << '\n';

    return 0;
}

void shell_sort(int data[], std::size_t size){
    int gap = size / 2;
    while (gap > 0) {
        for (std::size_t i = gap; i < size; i++) {
            int left = i - gap;         //position of the leftmost value in the array
            int right = left + gap;     //position of the rightmost value in the array
            while(left >= 0 && data[left] > data[right]) {
                int temp = data[left];
                data[left] = data[right];
                data[right] = temp;

                left -= gap;
                right = left + gap;
            }
        }
        gap /= 2;
    }
}