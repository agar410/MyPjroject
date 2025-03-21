#ifndef NSARRAY1D_H_INCLUDED
#define NSARRAY1D_H_INCLUDED

#include "./nsAlgorithms.h"


template<typename T>
class MyArray {

private:
protected:
T* _data;
int _n, _m;
// _n: size,m: capacity
T guard;

public:
MyArray(int c=10) {

_m = c;

_n = 0;

_data = new T[_m];

}

MyArray(const MyArray<T>& ary) {
_m = ary._m;

_n = ary._n;

_data = new T[_m];

for ( int i=0; i<_n; ++i ) {

_data[i] = ary[i];
}
}

MyArray<T>& operator=( const MyArray<T>& ary) {
if ( this == &ary ) {

return *this;
}
delete [] _data;


_m = ary._m;

_n = ary._n;

_data = new T[_m];

for ( int i=0; i<_n; ++i ) {

_data[i] = ary._data[i];
}
return *this;
}

~MyArray() {
delete [] _data;

}

T& operator[](int idx) {
if ( idx<0 || idx>=_n ) {
return guard;

}
return _data[idx];

}

MyArray<T>& push(const T& el) {

if ( _n == _m ) { // overflow
// doubling stategy: _¿¼Wµ¦²¤
T* tmp = new T[_m*2];

for ( int i=0; i<_n; ++i ) {

tmp[i] = _data[i];
}
delete [] _data;

_data = tmp;

_m *= 2;

}
_data[_n++] = el;
// _data[_n++] = el; ==> _data[_n] = el; _n++;
// _data[++_n] = el; ==> _n++; _data[_n] = el;

return *this;
}

//logic operator
bool operator==(const MyArray<T>& ary) {
if ( _n != ary._n ) {
return false;

}
int minN = min( _n, ary._n);

for ( int i=0; i<minN; ++i ) {

if ( _data[i]!=ary._data[i] ) {

return false;

}
}
return true;

}

bool operator<(const MyArray<T>& ary) {
int minN = min( _n, ary._n);

int i=0;

for ( ; i<minN; ++i ) {
if ( _data[i]==ary._data[i] ) {

continue;

}
if ( _data[i]<ary._data[i] ) {

return true;

} else {
return false;

}
}
return _n < ary._n;

}

bool operator!=(const MyArray<T>& ary) {
// ary1 < ary2 ==>
ary1.operator!=(ary2)

return !(operator==(ary));
}

bool operator<=(const MyArray<T>& ary) {
// ary1 < ary2 ==>
ary1.operator<=(ary2)

return operator<(ary) || operator==(ary);
}

bool operator>(const MyArray<T>& ary) {
// ary1 < ary2 ==>
ary1.operator>(ary2)

return !(operator<=(ary));
}

bool operator>=(const MyArray<T>& ary) {
// ary1 < ary2 ==>
ary1.operator>=(ary2)

return !(operator<(ary));
}

friend ostream& operator<<(ostream& os, const MyArray<T>& ary) {

os << "[ ";

for ( int i=0; i<ary._n; ++i ) {

if ( i!=0 ) {
os << ",";

}
os << setw(4) << ary._data[i];
}
os << " ]" << endl;

return os;

}

void selSort() {

::selectSort(_data, _n);

}
void bubbleSort() {

::bubbleSort(_data, _n);

}
void insertSort() {

::insertSort(_data, _n);

}
int findIndex(const T& key) {
return ::findIndex(_data, _n, key);
}
int binSearchIndex(const T& key) {
return ::binSearchIndex(_data, _n, key);
}

void shuffle() {

::aryShuffle(_data, _n);

}

void reverse() {

::aryReverse(_data, _n);

}
};


class MyArrayInt : public MyArray<int> {
protected:
private:
static int cnt;

public:
MyArrayInt() {

if ( MyArrayInt::cnt==0 ) {
srand((unsigned)time(NULL));

}
++MyArrayInt::cnt;
}

MyArrayInt(int n=10, int a=0, int b=100) {

MyArrayInt();

appendRand(n, a, b);

} 
~MyArrayInt() { --MyArrayInt::cnt; } 
MyArrayInt& 
operator=(const 
MyArrayInt& 
ary) 
{ 

MyArray<int>::operator=(ary); return *this; 
} 
friend ostream& operator<<(ostream& os, const MyArrayInt& ary) { os << "[ "; 
for 
( 
int 
i=0; 
i<ary._n; 
++i 
) 
{ 
 
if 
( 
i!=0 
) 
{ 

push( shapBetween(rand(), a, b) ); 
} 
} 
}; 
int MyArrayInt::cnt = 0; 
#endif // NSARRAY1D_H_INCLUDED 
