#include <iostream>
using namespace std;

int main() {
  int nums[] = {1,3,6,2,5};

    int numsSize = sizeof(nums)/sizeof(nums[0]); // obtener el tamaño del aaray nums 

    for (int index=0; index<numsSize; index++) {
        cout<<nums[index]<<endl;
    }

    // Implementación más simple que podria solamente funcionar en 
    // versiones nuevas de C++

    // for (int item:nums) {
    //     cout<<item<<endl;
    // }

  return 0;
}
