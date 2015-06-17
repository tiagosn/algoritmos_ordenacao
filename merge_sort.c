/* Merge Sort recursivo */

void partition(int arr[],int low,int high) {

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high) {

    int i,m,k,l,temp[MAX];

    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

/* Merge Sort iterativo */

#define min(A, B) (A < B) ? A : B

// Esta funcao rearranja o vetor a[p..r] em ordem crescente.

void mergesortBU(itemType a[], int p, int r) {
    int i, m;
    for (m = 1; m <= r-p; m = m+m)
       for (i = p; i <= r-m; i += m+m)
          partition(a, i, i+m-1, min(i+m+m-1, r));
}
