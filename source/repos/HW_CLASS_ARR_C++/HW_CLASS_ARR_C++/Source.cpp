#include<iostream>
#include<cassert>
using namespace std;



class IntArr {
	int* arr;
	size_t size;

	void SetSize(const size_t& size) {
		assert(size > 0 && "Array Size cannot be less than 0");
		this->size = size;
	}
public:
	IntArr() : arr(nullptr), size(0)
	{

	}
	IntArr(const IntArr& other)
	{
		SetArr(other.GetArr());
	}

	IntArr operator=(const IntArr& other) {
		SetArr(other.GetArr());
		return *this;
	}
	IntArr(int* arr, const size_t& size)
	{
		SetArr(arr);
		SetSize(size);
	}

	int* GetArr()const {
		return arr;
	}

	size_t GetSize()const {
		return size;
	}

	void SetArr(int* arr) {
		this->arr = arr;
	}

	void AddElementToStart(int a) {
		auto newarray = new int[size + 1]{};
		int index = 0;
		newarray[index] = a;
		index++;
		for (size_t i = 0; i < size; i++)
		{
			newarray[index] = arr[i];
			index++;
		}
		size++;
		arr = newarray;
		newarray = nullptr;
	}

	void AddElementToEnd(int a) {
		auto newarray = new int[size + 1]{};
		int index = 0;
		for (size_t i = 0; i < size; i++)
		{
			newarray[index] = arr[i];
			index++;
		}
		newarray[index] = a;
		size++;
		arr = newarray;
		newarray = nullptr;
	}
	void Copy(int*& newarr) {
		newarr = new int[size] {};
		newarr = arr;
	}
	void print() {
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}cout << endl;
	}

	void Update(int index, int a) {
		arr[index] = a;
	}
};


void main() {

	size_t size = 5;
	int* myarray = new int[] {1, 2, 3, 4, 5};
	int* mynewarray;
	IntArr arr(myarray, size);

	arr.AddElementToEnd(10);
	arr.AddElementToEnd(20);
	arr.AddElementToStart(90);
	arr.AddElementToStart(90);
	arr.Update(5, 55);
	arr.Copy(mynewarray);
	arr.print();
}





