#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct PHANSO {
	int tu, mau;
};

// Qua tai
bool operator<(PHANSO x, PHANSO y)
{
	return x.tu * y.mau < x.mau * y.tu;
}

ostream &operator<<(ostream &out, PHANSO x)
{
	if (x.tu == 0)
		out << x.tu;
	else
		out << x.tu << "/" << x.mau;
	return out;
}

// Mang mot chieu
void swap(void *x, void *y, int size)
{
	void *temp = malloc(size);
	memcpy(temp, x, size);
	memcpy(x, y, size);
	memcpy(y, temp, size);
	free(temp);
}
template <class T> void sortArr(T *arr, int size, bool (*Compare)(T, T))
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (!Compare(arr[i], arr[j]))
				swap(arr[i], arr[j]);
		}
	}
}
template <class T> bool tangArr(T x, T y)
{
	return x < y;
}
template <class T> bool giamArr(T x, T y)
{
	return !tangArr(x, y);
}
template <class T> void printArr(T *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Danh sach lien ket don
template <class T> struct Node {
	T key;
	Node *next;
};
template <class T> void addHead(Node<T> *&head, T key)
{
	Node<T> *p = new Node<T>;
	if (p != NULL) {
		p->key = key;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else {
			p->next = head;
			head = p;
		}
	}
}
template <class T> void swapNode(Node<T> *x, Node<T> *y)
{
	T temp = x->key;
	x->key = y->key;
	y->key = temp;
}
template <class T>
void sortList(Node<T> *&head, bool (*Compare)(Node<T> *, Node<T> *))
{
	Node<T> *i, *j;
	for (i = head; i != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			if (!Compare(i, j))
				swapNode(i, j);
		}
	}
}
template <class T> bool tangList(Node<T> *x, Node<T> *y)
{
	return x->key < y->key;
}
template <class T> bool giamList(Node<T> *x, Node<T> *y)
{
	return !tangList(x, y);
}
template <class T> void printList(Node<T> *head)
{
	if (head == NULL)
		cout << "NULL" << endl;
	else {
		cout << head->key << "->";
		printList(head->next);
	}
}
template <class T> void delHead(Node<T> *&head)
{
	if (head != NULL) {
		if (head->next == NULL) {
			delete head;
			head = NULL;
		} else {
			Node<T> *temp = head;
			head = head->next;
			delete temp;
		}
	}
}
template <class T> void delList(Node<T> *&head)
{
	while (head != NULL)
		delHead(head);
}
int main()
{
	// Tao du lieu
	int arr1[] = {5, 4, 3, 2, 1, 6, 7, 8, 9};
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	float arr2[] = {5.5, 4.4, 3.3, 2.2, 1.1, 6.6, 7.7, 8.8, 9.9};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	long arr3[] = {10000, 20000, 30000, 40000, -50000, -60000};
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	double arr4[] = {5.1, 4.1, 3.1, 2.1, 1.1, 6.1, 7.1, 8.1, 9.1};
	int size4 = sizeof(arr4) / sizeof(arr4[0]);
	PHANSO arr5[] = {{5, 4}, {4, 3}, {3, 2}, {2, 1},
			 {6, 5}, {7, 6}, {8, 7}, {9, 8}};
	int size5 = sizeof(arr5) / sizeof(arr5[0]);
	string arr6[] = {"lmn", "xyz", "ghi", "abc"};
	int size6 = sizeof(arr6) / sizeof(arr6[0]);

	int i;
	Node<int> *head1 = NULL;
	for (i = 0; i < size1; i++) {
		addHead(head1, arr1[i]);
	}
	Node<float> *head2 = NULL;
	for (i = 0; i < size2; i++) {
		addHead(head2, arr2[i]);
	}
	Node<long> *head3 = NULL;
	for (i = 0; i < size3; i++) {
		addHead(head3, arr3[i]);
	}
	Node<double> *head4 = NULL;
	for (i = 0; i < size4; i++) {
		addHead(head4, arr4[i]);
	}
	Node<PHANSO> *head5 = NULL;
	for (i = 0; i < size5; i++) {
		addHead(head5, arr5[i]);
	}
	Node<string> *head6 = NULL;
	for (i = 0; i < size6; i++) {
		addHead(head6, arr6[i]);
	}
	cout << "Chon 1-mang mot chieu 2-lien ket don : ";
	cin >> i;
	if (i == 1) {
		cout << "Chon 1-tang dan 2-giam dan : ";
		int j;
		cin >> j;
		switch (j) {
		case 1:
			sortArr(arr1, size1, tangArr);
			sortArr(arr2, size2, tangArr);
			sortArr(arr3, size3, tangArr);
			sortArr(arr4, size4, tangArr);
			sortArr(arr5, size5, tangArr);
			sortArr(arr6, size6, tangArr);
			break;
		case 2:
			sortArr(arr1, size1, giamArr);
			sortArr(arr2, size2, giamArr);
			sortArr(arr3, size3, giamArr);
			sortArr(arr4, size4, giamArr);
			sortArr(arr5, size5, giamArr);
			sortArr(arr6, size6, giamArr);
			break;
		default:
			break;
		}
		printArr(arr1, size1);
		printArr(arr2, size2);
		printArr(arr3, size3);
		printArr(arr4, size4);
		printArr(arr5, size5);
		printArr(arr6, size6);
	}
	if (i == 2) {
		cout << "Chon 1-tang dan 2-giam dan : ";
		int j;
		cin >> j;
		switch (j) {
		case 1:
			sortList(head1, tangList);
			sortList(head2, tangList);
			sortList(head3, tangList);
			sortList(head4, tangList);
			sortList(head5, tangList);
			sortList(head6, tangList);
			break;
		case 2:
			sortList(head1, giamList);
			sortList(head2, giamList);
			sortList(head3, giamList);
			sortList(head4, giamList);
			sortList(head5, giamList);
			sortList(head6, giamList);
		default:
			break;
		}
		printList(head1);
		printList(head2);
		printList(head3);
		printList(head4);
		printList(head5);
		printList(head6);
	}
	delList(head1);
	delList(head2);
	delList(head3);
	delList(head4);
	delList(head5);
	delList(head6);
	return 0;
}
