#include <iostream>
#include <vector>

/**
 * Shift each element of the given array to the right by two positions.
 * Elements at the end of the array will wrap around to the front.
 *
 * Example input:  ABCDE
 * Example output: DEABC
 */

// With allocation of memory for a second array.
class Shift {
public:
    // Shifts the vector to the right by 2 positions and returns a new vector.
    std::vector<char> shiftRightBy2(const std::vector<char>& v) {
        std::vector<char> resultArray;

        resultArray.push_back(v[v.size()-2]); resultArray.push_back(v[v.size()-1]);

        for (int i=0; i<v.size()-2; i++) {
            resultArray.push_back(v[i]);
        }

        return resultArray;
    }

    // Shifts the elements of the vector to the right by two positions in-place.
    void shiftRightBy2InPlace(std::vector<char>& v) {
        std::vector<char> resultArray;

        resultArray.push_back(v[v.size()-2]); resultArray.push_back(v[v.size()-1]);

        for (int i=0; i<v.size()-2; i++) {
            resultArray.push_back(v[i]);
        }

        for (int i=0; i<v.size(); i++) {
            v[i] = resultArray[i];
        }
    }

    // Reverses a vector v.
    static void reverse(std::vector<char>& v, int start, int end) {
        while(start < end) {
            char temp = v[start];
            v[start] = v[end];
            v[end] = temp;
            start++; end--;
        }
    }
    // Shifts the vector to the right by n positions (where n is a natural number) and returns a new vector
    void shiftRightByN(std::vector<char>& v, int n) {
        reverse(v, 0, v.size()-1);
        reverse(v, 0, n-1);
        reverse(v, n, v.size()-1);
    }
};

void printVector(const std::vector<char>& v) {
    for (char c : v) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    Shift shifter;
    std::vector<char> array = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    std::cout << "INPUT: ";
    printVector(array);

    std::cout << "shiftRightBy2" << std::endl;
    std::cout << "OUTPUT: ";
    printVector(shifter.shiftRightBy2(array));

    std::cout << "shiftRightBy2InPlace" << std::endl;
    std::cout << "OUTPUT: ";
    shifter.shiftRightBy2InPlace(array);
    printVector(array);

    std::vector<char> array2 = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    std::cout << "shiftRIghtByN" << std::endl;
    std::cout << "OUTPUT: ";
    shifter.shiftRightByN(array2, 5);
    printVector(array2);

    return 0;
}

