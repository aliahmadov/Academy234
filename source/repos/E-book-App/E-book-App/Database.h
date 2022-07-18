#pragma once

#include<iostream>
#include<vector>
#include "Entities.h"
#include"DatabaseController.h"

using namespace Entities;
using namespace DatabaseController;

namespace DatabaseSection {
	class Database {
	public:
		vector<Admin>Admins;
		vector<Client>Clients;
		vector<Book>Books;
		void AddAdmin(const Admin& admin) {
			Admins.push_back(admin);
		}
		void AddClient(const Client& client) {
			Clients.push_back(client);
		}
		void AddBook(const Book& book) {
			Books.push_back(book);
		}
	};




	static Database database;
	static void Init() {
		User user("admin", "admin");
		database.AddAdmin(Admin(user, "Elvin Camalzade"));
		database.AddAdmin(Admin(user, "Ali Ahmadov"));
		User user2("client", "client");

		database.AddClient(Client(user2, "Ali Ahmedov"));

		Book b1("Nutshel", "Albahari", 34, 9.8);
		Book b2("Animal Farm", "George Orvel", 12, 7.9);
		Book b3("Tom Sawyer adventures", "Mark Twen", 3.4, 8);
		database.AddBook(b1);
		database.AddBook(b2);
		database.AddBook(b3);

		Client c1(user2, "Ali Ahmadov");
		Client c2(user2, "Hetelem Petelem");
		Client c3(user2, "Coni Coni");
		database.AddClient(c1);
		database.AddClient(c2);
		database.AddClient(c3);




		WriteAdminsToFile(database.Admins);
		WriteBooksToFile(database.Books);
		WriteClientsToFile(database.Clients);


		auto admins = ReadAdmins();
		auto books = ReadBooks();
		auto clients = ReadClients();
		for (size_t i = 0; i < books.size(); i++)
		{
			cout <<"ID: "<< books[i].GetId() << endl;
			cout <<"Author: "<< books[i].GetAuthor() << endl;
			cout << "Title: " << books[i].GetTitle() << endl;
			cout << "Price: " << books[i].GetPrice() << endl;
			cout << "Rating: " << books[i].GetRating() << endl;
		}

		for (size_t i = 0; i < clients.size(); i++)
		{

			cout << "ID: " << clients[i].GetId() << endl;
			cout << "Fullname: " << clients[i].GetFullname() << endl;
			cout << "Username: " << clients[i].GetUser().GetUsername() << endl;
			cout << "Password: " << clients[i].GetUser().GetPassword() << endl;
		}

	}

}