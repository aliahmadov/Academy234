#pragma once
#pragma once
#include<iostream>
#include<vector>
using namespace std;


namespace Entities {

	class Entity {
	public:
		int myId;
		static int ID;
		Entity()
		{
			myId = ++ID;
		}
		int GetId()const {
			return myId;
		}

		void SetId(const int& id) {
			this->myId = id;
		}
	};

	int Entity::ID = 1000;

	class User :public Entity {
		string username;
		string password;
	public:
		User() {
			myId = -1;
		}
		User(const string& username, const string& password)
			:Entity()
		{
			SetUsername(username);
			SetPassword(password);
		}
		string GetUsername()const {
			return username;
		}
		string GetPassword()const {
			return password;
		}

		void SetUsername(const string& username) {
			this->username = username;
		}
		void SetPassword(const string& password) {
			this->password = password;
		}
	};

	class Base {
		string fullname;
	public:
		Base()
		{

		}
		Base(const string& fullname)
		{
			this->fullname = fullname;
		}
		string GetFullname()const {
			return fullname;
		}

		void SetFullname(const string& fullname) {
			this->fullname = fullname;
		}
	};

	class Admin :public Entity, public Base {
		User user;
		string fullname;
	public:
		Admin()
		{

		}

		Admin(const User& user, const string& fullname)
			:Entity(), Base(fullname)
		{
			this->user = user;
		}
		User GetUser()const {
			return user;
		}

		void SetUser(const User& user) {
			this->user = user;
		}

	};

	struct Date {
		int day;
		int month;
		int year;
	};

	class Book :public Entity {
		string title;
		string author;
		double price;
		double rating;
	public:
		Book() {

		}
		Book(const string& title, const string& author,
			const double& price, const double& rating)
			:Entity()
		{
			SetTitle(title);
			SetAuthor(author);
			SetPrice(price);
			SetRating(rating);
		}


		void SetTitle(const string& title) {
			this->title = title;
		}
		void SetAuthor(const string& author) {
			this->author = author;
		}

		void SetPrice(const double& price) {
			this->price = price;
		}
		void SetRating(const double& rating) {
			this->rating = rating;
		}

		string GetTitle()const {
			return title;
		}
		string GetAuthor()const {
			return author;
		}

		double GetPrice()const {
			return price;
		}
		double GetRating()const {
			return rating;
		}
	};

	struct BookReservation {
		Book book;
		Date takeIn;
		Date takeOut;
		double totalPayment;
	};

	class Client :public Entity, public Base {
		User user;
		vector<BookReservation> rents;
	public:
		Client() {
			myId = -1;
		}
		Client(const User& user, const string& fullname)
			:Base(fullname), Entity()
		{
			this->user = user;
		}

		User GetUser()const {
			return user;
		}

		void SetUser(const User& user) {
			this->user = user;
		}

		void TakeBook(Book book, int days, Date takeIn) {
			BookReservation rent;
			rent.book = book;
			rent.takeIn = takeIn;

			rent.totalPayment = book.GetPrice() * days;
			rent.takeOut.day += days;

			rents.push_back(rent);
			cout << user.GetUsername() << " took book succesfully" << endl;
			cout << "Payment : " << rent.totalPayment << "$" << endl;

		}
	};



}

