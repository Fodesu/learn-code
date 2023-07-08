#include <bits/stdc++.h>
#include <endian.h>

using namespace std;

template<typename T>
int getIndex(T arr[], int begin, int end) {
    T a = arr[begin];
    int l = begin + 1, r = end;
    while(l < r) {

        while(r >= begin && arr[r] > a) r--;
        while(l <= end && arr[l] <= a) l++;
        if(l < r) 
            swap(arr[l], arr[r]);
    }
    swap(arr[begin], arr[r]);
    return r;
}
template<typename T>
void quicksort(T arr[], int begin, int end) {
    if(begin < end) {
        int p = getIndex(arr,  begin, end);
        quicksort(arr,  begin, p - 1);
        quicksort(arr, p + 1, end);
    }
}


int main() {

    int a[] = {10, 2, 3, 5, 7, 8, 290, 123};
    for(auto c : a) {
        cout << c << ' ';
    }
    cout << '\n';

    quicksort(a, 0, 7);

    for(auto iter = begin(a); iter != end(a); iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';

}