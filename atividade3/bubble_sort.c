void swap (int* n1, int* n2){
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}


void bubble_sort(int arr[], int n){

for(int i = 0; i < n; i++){
        for( int j = i; j < n; j++){
            if(arr [i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}