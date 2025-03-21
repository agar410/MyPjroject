#ifndef NSDLL_H_INCLUDED
#define NSDLL_H_INCLUDED


template<typename T>
class Node {

private:
T data;

Node<T> *pre,*next;

public:
Node() {

data = T();

pre = next = NULL;

}
Node(const T& e ) {

data = e;

pre = next = NULL;

}
T& getData() {
return data;

}
Node* getNode() {
return this;

}
void setData(const T& e) {
data = e;

}
Node* getPre() {
return pre;

}
void setPre(Node* p) {
pre = p;

}
Node* getNext() {
return next;

}
void setNext(Node* p) {
next = p;

}
void show(bool isShowPtr=false) {

cout << "(" ;
if (isShowPtr ) cout << pre << ", ";
cout << data;

if (isShowPtr ) cout << "," << next;
cout << ")" ;
}
friend ostream& operator<<(ostream& os, const Node<T>& nd) {

os << nd.data;

return os;

}
};


template<typename T>
class DLL {

private:
Node<T> *head, *tail;

int _n; // size;

public:
DLL() {
head = tail = NULL;

_n = 0;

}
~DLL() {
Node<T> *t1=head;

Node<T> *t2;

while ( t1!=NULL ) {
t2=t1->getNext();

delete t1;

t1 = t2;

}
}

void insBeg(const T& e) {
Node<T> *tmp = new Node<T>(e);

if ( _n==0 ) {
head = tail = tmp;

_n = 1;

return;

}
tmp->setNext(head);

head->setPre(tmp);

head = tmp;

_n++;

}
void insEnd(const T& e) {
Node<T> *tmp = new Node<T>(e);

if ( _n==0 ) {
head = tail = tmp;

_n = 1;

return;

}
tail->setNext(tmp);

tmp->setPre(tail);

tail = tmp;

_n++;

}
void delEnd() {

Node<T> *tmp=tail;

if ( _n==1 ) {
head = tail = NULL;

} else {
Node<T> * newTail = tail->getPre();
newTail->setNext(NULL);

tail = newTail;

}
delete tmp;

_n--;

}
void delBeg() {

Node<T> *tmp=head;

if ( _n==1 ) {
head = tail = NULL;

} else {
Node<T> * newHead = head->getNext();
newHead->setPre(NULL);

head = newHead;

}
delete tmp;

_n--;

}
Node<T>* getHead() {
return head;

}
Node<T>* getTail() {
return tail;

}
T& getEnd() {
return tail->getData();

}
T& getBeg() {
return head->getData();

}
int size() {

return _n;

}

vector<T> toVector() {
vector<T> nv;
Node<T> *t1=head;

Node<T> *t2;

while ( t1!=NULL ) {
t2=t1->getNext();

nv.push_back(t1->getData());

t1 = t2;

}
return nv;

}

void show(bool isShowPtr=false) {

Node<T> *t1=head;

Node<T> *t2;

while ( t1!=NULL ) {
t2=t1->getNext();

t1->show(isShowPtr);

t1 = t2;

}
cout << endl;

}
};


#endif // NSDLL_H_INCLUDED

