#ifndef NSALGORITHMS_H_INCLUDED

#define NSALGORITHMS_H_INCLUDED


int shapBetween(int x, int a, int b) {
    return x%(b-a+1) + a;
}

template<typename T>
int findMinPos(T* data, int L, int R) {
	int minPos=L;
	for ( int i=L+1; i<=R; ++i ){
		if ( data[i]<data[minPos] ){ 
			minPos = i;
		}
	}
	return minPos;
}

template<typename T>
void selectSort(T* ary, int n) {
for ( int run=0; run<n-1; ++run ) {
	// [ run, n-1 ]
	int minPos = findMinPos(ary, run, n-1);
	swap( ary[run], ary[minPos] );
}
}


template<typename T>
void rotateOneRight(T* data, int L, int R) {

int t=data[R];

for ( int k=R-1; k>=L; --k )

{ data[k+1] = data[k];
}
data[L] = t;
}


template<typename T>
void insertSort(T* data, int n) {
for ( int i=1; i<n; ++i )

{ // 假設[0]~[i-1]是排好的
// 要把[i]插入正確的位置[j]

// 找[j]：從最左邊找起（[0]~[i]），找第1個大於等於[i]者
int j; // 找[j]

for ( j=0; j<=i; ++j )

{ if ( data[j]>=data[i] )

{ break;

}
}
rotateOneRight(data, j,i);
}
}


template<typename T>
void bubbleSort(T* data, int n) {
bool isSwap = true;

for ( ;isSwap; )
{ isSwap = false;

for ( int i=0; i<n-1; ++i )

{ if ( data[i]>data[i+1] )

{ swap( data[i], data[i+1] );

isSwap = true;

}
}
}
}


template<typename T>
int findIndex(T* data, int n, const T& key) {
for ( int i=0; i<n; ++i )

{ if ( data[i]==key )
{ return i;

}
}
return -1;
}


template<typename T>
int binSearchIndex(T* data, int n, const T& key) {
if ( n<=0 ) return -1;

int m = n/2;

if ( data[m]==key ) return m;


if ( key<data[m] ) {

return binSearchIndex(data, m-1, key);

}

return binSearchIndex(data+m, n-m, key)+m;

}


template<typename T>
void aryShuffle(T* ary, int n) {
for ( int i=0; i<n-1; ++i ) {

int x = shapBetween( rand(), i, n-1 );

swap( ary[i], ary[x] );

}
}


template<typename T>
void aryReverse(T* ary, int n) {
for ( int i=0, j=n-1; i<j; ++i,--j ) {
swap( ary[i], ary[j] );

}
}


template<typename T>
void showAry(T* ary, int n) {
cout << "["; // [ 1, 23, 52 ]

for ( int i=0; i<n; ++i ) {

if ( i!=0 ) {
cout << ",";

}
cout << setw(3) << ary[i];
}
cout << " ]" << endl;

}


// Partition with cut point at l

int myCut(int* A, int l, int r, int x) {
swap(A[l], A[r]);
int s=l;

for ( int i=l; i<r; ++i ) {

if ( A[i]<=x ) {
swap( A[s], A[i] );

++s;
}
}
swap( A[s], A[r] );

return s;

}


int myCut(int* A, int l, int r) {

int x = A[l];

swap(A[l], A[r]);
int s=l;

for ( int i=l; i<r; ++i ) {

if ( A[i]<=x ) {
swap( A[s], A[i] );

++s;
}
}
swap( A[s], A[r] );

return s;

}


void quickSort(int* A, int l, int r) {

if ( l>=r ) return;

int cut = myCut(A, l, r);

quickSort(A, 0, cut-1);

quickSort(A, cut+1, r);

}

#endif // NSALGORITHMS_H_INCLUDED

