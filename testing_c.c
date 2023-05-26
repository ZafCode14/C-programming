#include <stdio.h>

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int size = sizeof(arr)/ sizeof(arr[0]);
	int i;
	int sum = 0;
	for(i = 0; i < size; i++){
		if(i % 2 || i == 0){
			int squared = arr[i] * arr[i];	
			printf("%d ", squared);
			sum += squared;

		}else{
						
			continue;
		}

		}
			printf("\nThe sum = %d\n", sum);
}
