#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;


enum Directions { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75 };
void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}



class Meal {
	int id;
	char* name;
	double rating;
	char* category;
	double price;
	double tax;
public:
	static int s_id;

#pragma region Constructors
	Meal() {
		id = ++s_id;
	}
	Meal(const char* n, const double& r, const char* c, const double& p, const double& t)
	{
		SetId(++s_id);
		SetName(n);
		SetRating(r);
		SetCategory(c);
		SetPrice(p);
		SetTax(t);
	}
	Meal(const Meal& other) {
		SetId(other.id);
		SetName(other.name);
		SetRating(other.rating);
		SetCategory(other.category);
		SetPrice(other.price);
		SetTax(other.tax);
	}
	Meal(Meal&& other) {
		SetId(other.id);
		SetName(other.name);
		SetRating(other.rating);
		SetCategory(other.category);
		SetPrice(other.price);
		SetTax(other.tax);

		if (other.name) {
			delete other.name;
			other.name = nullptr;
		}
		if (other.category) {
			delete other.category;
			other.category = nullptr;
		}
	}
#pragma endregion

#pragma region Getters
	int GetId()const {
		return id;
	}
	char* GetName()const {
		return name;
	}
	double GetRating() const {
		return rating;
	}
	char* GetCategory()const {
		return category;
	}
	double GetPrice()const {
		return price;
	}
	double GetTax()const {
		return tax;
	}
#pragma endregion

#pragma region Setters
	void SetId(const int& id) {
		this->id = id;
	}
	void SetName(const char* n) {
		int l = strlen(n);
		this->name = new char[l + 1]{};
		strcpy_s(this->name, l + 1, n);
	}

	void SetRating(const double& r) {
		this->rating = r;
	}

	void SetCategory(const char* c) {
		int l = strlen(c);
		this->category = new char[l + 1]{};
		strcpy_s(this->category, l + 1, c);
	}

	void SetPrice(const double& p) {
		this->price = p;
	}

	void SetTax(const double& t) {
		this->tax = t;
	}

	double& operator++() {
		this->rating++;
		return this->rating;
	}

	double& operator--() {
		this->rating--;
		return this->rating;
	}

	double& operator++(int) {
		double temp = this->rating;
		this->rating++;
		return temp;
	}

	double& operator--(int) {
		double temp = this->rating;
		this->rating--;
		return temp;
	}

#pragma endregion

	~Meal()
	{
		delete this->name;
		delete this->category;
	}


#pragma region Operator Overloading
	friend ostream& operator<<(ostream& out, const Meal& obj);
	friend istream& operator>>(istream& in, Meal& obj);

#pragma endregion
};

#pragma region Operator Overloading Body
ostream& operator<<(ostream& out, const Meal& obj) {
	out << "\nMEAL INFO" << endl;
	out << "Meal id : " << obj.id << endl;
	out << "Meal name : " << obj.name << endl;
	out << "Meal rating : " << obj.rating << endl;
	out << "Meal category : " << obj.category << endl;
	out << "Meal price : " << obj.price << "$" << endl;
	out << "Meal tax : " << obj.tax << "%" << endl;
	return out;
}

istream& operator>>(istream& in, Meal& obj) {


	char* name = new char[100]{};
	cout << "Enter name : ";
	in.getline(name, 100);

	double rating = 0;
	cout << "Enter rating : ";
	in >> rating;
	in.ignore();
	in.clear();

	char* category = new char[100]{};
	cout << "Enter category : ";
	in.getline(category, 100);

	double price = 0;
	cout << "Enter price : ";
	in >> price;

	double tax = 0;
	cout << "Enter tax : ";
	in >> tax;

	obj.SetName(name);
	obj.SetRating(rating);
	obj.SetCategory(category);
	obj.SetPrice(price);
	obj.SetTax(tax);

	return in;
}

#pragma endregion


int Meal::s_id = 0;



class Restaurant {
	char* name;
	char* address;
	char* phonenumber;
	double avgcost;
	Meal** meals;
	int count = 0;
public:
#pragma region Getters
	char* GetName()const {
		return name;
	}
	char* GetAddress()const {
		return address;
	}
	char* GetPhone()const {
		return phonenumber;
	}
	double GetAvgCost()const {
		return avgcost;
	}
	Meal** GetMeals()const {
		return meals;
	}
	int GetCount()const {
		return count;
	}
#pragma endregion


#pragma region Setters
	void SetName(const char* name) {
		int l = strlen(name);
		this->name = new char[l + 1]{};
		strcpy_s(this->name, l + 1, name);
	}
	void SetAddress(const char* address) {
		int l = strlen(address);
		this->address = new char[l + 1]{};
		strcpy_s(this->address, l + 1, address);
	}
	void SetPhonenumber(const char* phonenumber) {
		int l = strlen(phonenumber);
		this->phonenumber = new char[l + 1]{};
		strcpy_s(this->phonenumber, l + 1, phonenumber);
	}

	void SetMeals(Meal** meals) {
		this->meals = meals;
	}
private:

	void SetAvgCost(const double& avgcost) {
		this->avgcost = avgcost;
	}
public:
#pragma endregion

#pragma region Helpers
	void CalculateAvgCost() {
		double total = 0;
		for (size_t i = 0; i < count; i++)
		{
			total += meals[i]->GetPrice();
		}
		SetAvgCost(total / count);
	}

	void AddMeal(const Meal* meal) {
		auto newmeals = new Meal * [count + 1]{};
		for (size_t i = 0; i < count; i++)
		{
			newmeals[i] = new Meal(move(*(meals[i])));
		}
		newmeals[count] = new Meal(move(*meal));
		++count;
		meals = newmeals;
		newmeals = nullptr;
	}

	int getMealIndexById(int id) {

		for (size_t i = 0; i < count; i++)
		{
			if (meals[i]->GetId() == id) {
				return i;
			}
		}
		return -1;
	}

	void DeleteMeal(int id) {
		auto newmeals = new Meal * [count - 1]{};
		int index_new = getMealIndexById(id);

		for (size_t i = 0; i < index_new; i++)
		{
			newmeals[i] = meals[i];
		}

		for (size_t i = index_new, i2 = index_new + 1; i < count; i++, i2++)
		{
			newmeals[i] = meals[i2];
		}
		delete[]meals;
		meals = newmeals;
		newmeals = nullptr;
		count--;
	}

	void UpdateMeal(int id, const Meal* meal) {
		int index = getMealIndexById(id);
		if (index == -1) {
			cout << "\nInvalid ID\n" << endl;
		}
		else {

			cout << *(meals[index]) << endl;

			meals[index]->SetName(meal->GetName());
			meals[index]->SetCategory(meal->GetCategory());
			meals[index]->SetPrice(meal->GetPrice());
			meals[index]->SetRating(meal->GetRating());
			meals[index]->SetTax(meal->GetTax());
			cout << "\nMeal with " << id << " ID Updated Successfully\n" << endl;
		}
	}


	void increaseMenuRatingById(int id) {
		int index = getMealIndexById(id);
		if (index == -1) {
			cout << "\nInvlalid ID\n" << endl;
		}
		else {
			double a = meals[index]->GetRating();
			if (a < 10) {

				cout << "Previous Rating: " << (meals[index]->GetRating()) << endl;;
				++a;
				meals[index]->SetRating(a);
				cout << "After Increase Rating: " << meals[index]->GetRating() << endl;;
				cout << "\nMeal Rating with " << id << " ID Increased Successfully" << endl;
			}
			else {
				cout << "Not possible to increase rating of meal in id " << id << " --> Maximum is 10 !!!\n" << endl;
			}
		}
	}


	void decreaseMenuRatingById(int id) {
		int index = getMealIndexById(id);
		if (index == -1) {
			cout << "\nInvalid ID\n" << endl;
		}
		else {

			double a = meals[index]->GetRating();
			if (a > 0) {

				cout << "Previous Rating: " << (meals[index]->GetRating()) << endl;;
				--a;
				meals[index]->SetRating(a);
				cout << "After Decrease Rating: " << meals[index]->GetRating() << endl;;
				cout << "\nMeal Rating with " << id << " ID Decreased Successfully" << endl;
			}
			else {
				cout << "Not possible to decrease rating of meal in id " << id << " --> Minimum is 10 !!!\n" << endl;
			}
		}
	}


	void ShowMenu() {

		cout << "\nAdd Meal to the Menu          1" << endl;
		cout << "Delete Meal From the Menu     2" << endl;
		cout << "Update Meal in the Menu       3" << endl;
		cout << "Make Change in Rating of Meal 4" << endl;
		cout << "Show Meals in the Restaurant  5" << endl;

	}

	friend ostream& operator<<(ostream& out, const Restaurant& r);

#pragma endregion

#pragma region Constructors
	Restaurant(const char* name, const char* address, const char* phone)
	{
		SetName(name);
		SetAddress(address);
		SetPhonenumber(phone);
	}
#pragma endregion


};
ostream& operator<<(ostream& out, const Restaurant& r) {
	out << "\nRESTAURANT INFO" << endl;
	out << "Name : " << r.GetName() << endl;
	out << "Address : " << r.GetAddress() << endl;
	out << "Phone : " << r.GetPhone() << endl << endl;


	for (size_t i = 0; i < r.count; i++)
	{
		bool swapped = 0;
		for (size_t k = 0; k < r.count - i - 1; k++)
		{
			if (r.meals[k]->GetRating() < r.meals[k + 1]->GetRating()) {
				swapped = 1;
				Meal* m = r.meals[k];
				r.meals[k] = r.meals[k + 1];
				r.meals[k + 1] = m;
			}
		}
		if (swapped) {
			break;
		}
	}
	for (size_t i = 0; i < r.count; i++)
	{
		if (r.meals[i]->GetRating() >= 0 && r.meals[i]->GetRating() <= 4) {
			mysetcolor(4, 0);
			out << *(r.meals[i]);
			mysetcolor(7, 0);
		}
		else if (r.meals[i]->GetRating() >= 5 && r.meals[i]->GetRating() <= 8) {
			mysetcolor(6, 0);
			out << *(r.meals[i]);
			mysetcolor(7, 0);
		}
		else if (r.meals[i]->GetRating() >= 9 && r.meals[i]->GetRating() <= 10) {
			mysetcolor(2, 0);
			out << *(r.meals[i]);
			mysetcolor(7, 0);
		}
	}cout << endl;

	return out;
}



#pragma region FileOperations

void WriteInfoToFile(const Restaurant& r) {
	FILE* file;
	fopen_s(&file, "restinfo1.bin", "wb");

	for (size_t i = 0; i < r.GetCount(); i++)
	{
		double l1 = r.GetMeals()[i]->GetId();
		fwrite(&l1, sizeof(int), 1, file);

		int l2 = strlen(r.GetMeals()[i]->GetName());
		fwrite(&l2, sizeof(int), 1, file);
		fwrite(r.GetMeals()[i]->GetName(), sizeof(char), l2, file);

		int l3 = strlen(r.GetMeals()[i]->GetCategory());
		fwrite(&l3, sizeof(int), 1, file);
		fwrite(r.GetMeals()[i]->GetCategory(), sizeof(char), l3, file);

		double l4 = r.GetMeals()[i]->GetPrice();
		fwrite(&l4, sizeof(int), 1, file);

		double l5 = r.GetMeals()[i]->GetRating();
		fwrite(&l5, sizeof(int), 1, file);

		double l6 = r.GetMeals()[i]->GetTax();
		fwrite(&l6, sizeof(int), 1, file);


	}

	fclose(file);

}



void ReadInfoFromFile(const Restaurant& r) {

	FILE* file;
	fopen_s(&file, "restinfo1.bin", "rb");

	if (r.GetCount() == 0) {
		cout << "There are no any info in database !!!" << endl;
	}
	for (size_t i = 0; i < r.GetCount(); i++)
	{
		int id = 0;
		fread_s(&id, sizeof(int), sizeof(int), 1, file);

		int l1 = 0;
		fread_s(&l1, sizeof(int), sizeof(int), 1, file);
		char* name = new char[l1 + 1]{};
		fread_s(name, l1, sizeof(char), l1, file);

		int l2 = 0;
		fread_s(&l2, sizeof(int), sizeof(int), 1, file);
		char* category = new char[l2 + 1]{};
		fread_s(category, l2, sizeof(char), l2, file);


		double price = 0;
		fread_s(&price, sizeof(int), sizeof(int), 1, file);

		double rating = 0;
		fread_s(&rating, sizeof(int), sizeof(int), 1, file);


		double tax = 0;
		fread_s(&tax, sizeof(int), sizeof(int), 1, file);

		r.GetMeals()[i] = new Meal(name, rating, category, price, tax);
	}
	fclose(file);

	cout << "MEAL INFO" << endl;

	for (size_t i = 0; i < r.GetCount(); i++)
	{
		cout << "ID: " << r.GetMeals()[i]->GetId() << endl;
		cout << "Name: " << r.GetMeals()[i]->GetName() << endl;
		cout << "Category: " << r.GetMeals()[i]->GetCategory() << endl;
		cout << "Price: " << r.GetMeals()[i]->GetPrice() << endl;
		cout << "Rating: " << r.GetMeals()[i]->GetRating() << endl;
		cout << "Tax: " << r.GetMeals()[i]->GetTax() << endl;
	}




}









#pragma endregion





void main() {
	Restaurant r("Ela restoran", "Sheki restoran yani", "050-311-72-66");
	while (true) {
		r.ShowMenu();
		int select = 0;
		cout << "Enter the option: ";
		cin >> select;

		system("cls");
		if (select == 1) {
			cin.ignore();
			cin.clear();
			Meal m;
			cin >> m;
			r.AddMeal(&m);
			cout << m.GetName() << "Deleted Successfully !!!" << endl;
			system("cls");
		}

		else if (select == 2) {
			int id = 0;
			cout << "Enter the ID: ";
			cin >> id;
			r.DeleteMeal(id);
			cout << "Meal with " << id << " ID Deleted Successfully" << endl;
		}

		else if (select == 3) {
			//Update
			int id = 0;
			cout << "Enter the ID: ";
			cin >> id;


			cin.ignore();
			cin.clear();
			Meal m;
			cin >> m;
			r.UpdateMeal(id, &m);
		}
		else if (select == 4) {
			//Rating Change
			while (true) {
				char select = ' ';
				cout << "For increase --> i\nFor decrease --> d\nFor Quit --> q\nEnter the option(i/d): ";
				cin >> select;
				system("cls");
				if (select == 'i') {
					int id = 0;
					cout << "Enter ID: ";
					cin >> id;
					r.increaseMenuRatingById(id);
				}
				else if (select == 'd') {
					int id = 0;
					cout << "Enter ID: ";
					cin >> id;
					r.decreaseMenuRatingById(id);

				}
				else if (select == 'q') {
					break;
				}
				else {
					cout << "Invalid Input !!!" << endl;
				}
			}
		}
		else if (select == 5) {
			// Show Meals
			cout << r;
		}


	}
}

