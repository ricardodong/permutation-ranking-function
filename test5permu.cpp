#include <iostream>
#include <algorithm>
using namespace std;

int MRrank(const int *array, const int size){
	int elePosi[size];
	int arrayCpy[size];
	
	int a[size-1];
	//feels like reverse order of the input array
		
    for(int i=0; i < size ; i++){
		arrayCpy[i] = array[i];
	}	
	for(int i=0; i < size ; i++){
		elePosi[arrayCpy[i]] = i;
	}
	
	for(int i = size-1 ; i >= 0 ; i--){
		//O(n) 
	    a[i-1] = arrayCpy[i];
		swap(arrayCpy[i], arrayCpy[elePosi[i]]);
		elePosi[a[i-1]] = elePosi[i];
		elePosi[i] = i;
	}
	
	int rank = 0;
	for (int i=0; i < size-2 ;i++){
		rank = (i+3) * (a[i] + rank);
	}
	rank += a[size-2];
	
	return rank;
}

int factor(const short i) {
	int factor = 1;
	for (short k = 1; k <= i; ++k) {
		factor *= k;
	}
	return factor;
}

int lexRank(const int *array, const int size){
	int arrayCpy[size];
		
    for(int i=0; i<size ; i++){
		arrayCpy[i] = array[i];
	}
	
	for (int i = 0; i < size; ++i ) {
		for (int j = i+1; j < size; ++j) {
			//O(n square)
			if (arrayCpy[j] > arrayCpy[i] && arrayCpy[j] > 0) {
				--arrayCpy[j];
			}
		}
		//cout<<arrayCpy[i]<<" ";
	}
	//cout<<endl;
	
	int rank = 0;
	for (short i = 0; i < size; i++) {
		rank += arrayCpy[i] * factor(size-i-1);
	}
	return rank;
}

int main(){
	int fivePerm[5]={0,1,2,3,4};
	int size = 5;
    do{
        //cout << fivePerm[0] << ' ' << fivePerm[1] << ' '<< fivePerm[2] << ' ';
        //cout << fivePerm[3] << ' ' << fivePerm[4] <<'\n';
        cout<<MRrank(fivePerm, size)<<endl;
    }
    while (next_permutation(fivePerm,fivePerm+5));
	
	return 0;
}
