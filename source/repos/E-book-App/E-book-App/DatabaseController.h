#pragma once
#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include"Entities.h"
#include<Windows.h>
#include<fstream>
using namespace std;

using namespace Entities;

int admin_count = 0;
namespace DatabaseController {

	void WriteAdminsToFile(vector<Admin> admins) {

		ofstream fout("admins.txt", ios::app);
		fout << admins.size() << endl;
		if (fout.is_open())
		{
			for (size_t i = 0; i < admins.size(); i++)
			{
				fout << admins[i].GetFullname() << " " << admins[i].GetUser().GetUsername() << " " << admins[i].GetUser().GetPassword() << " " << admins[i].GetId() << endl;
			}

		}
		fout.close();
	}

	vector<Admin> ReadAdmins() {
		vector<Admin>admins;

		ifstream fin("admins.txt");

		if (fin.is_open()) {
			int count = 0;
			fin >> count;
			for (size_t i = 0; i < count; i++)
			{

				string name;
				fin >> name;

				string surname;
				fin >> surname;

				string fullname = name + " " + surname;

				string username;
				fin >> username;

				string password;
				fin >> password;

				int id = 0;
				fin >> id;

				User user;
				Admin admin;
				user.SetUsername(username);
				user.SetPassword(password);

				admin.SetFullname(fullname);
				admin.SetId(id);
				admin.SetUser(user);

				admins.push_back(admin);
			}
			fin.close();
		}
		return admins;
	}



	void WriteBooksToFile(vector<Book> books) {

		ofstream fout("books.txt", ios::app);
		if (fout.is_open())
		{
			fout << books.size() << endl;
			for (size_t i = 0; i < books.size(); i++)
			{
				fout << books[i].GetId() << endl;
				fout << books[i].GetRating() << endl;
				fout << books[i].GetPrice() << endl;
				fout << books[i].GetAuthor() << endl;;
				fout << books[i].GetTitle() << endl;;
				fout << "============================================" << endl;
			}

		}
		fout.close();
	}


	vector<Book> ReadBooks() {
		vector<Book>books;
		ifstream fin("books.txt");

		if (fin.is_open()) {
			int count = 0;
			fin >> count;
			for (size_t i = 0; i < count; i++)
			{
				int id = 0;
				fin >> id;

				double rating = 0;
				fin >> rating;

				double price = 0;
				fin >> price;

				string author;
				std::getline(fin, author);

				std::getline(fin, author);

				string title;
				std::getline(fin, title);

				string line;
				fin >> line;

				Book book;
				book.SetAuthor(author);
				book.SetPrice(price);
				book.SetRating(rating);
				book.SetTitle(title);
				book.SetId(id);

				books.push_back(book);
			}
			fin.close();
		}
		return books;
	}




	void WriteClientsToFile(vector<Client>clients)
	{
		ofstream fout("clients.txt", ios::app);

		if (fout.is_open()) {
			fout << clients.size() << endl;
			for (size_t i = 0; i < clients.size(); i++)
			{
				fout << clients[i].GetId() << endl;
				fout << clients[i].GetFullname() << endl;
				fout << clients[i].GetUser().GetUsername() << endl;
				fout << clients[i].GetUser().GetPassword() << endl;
				/*fout << clients[i].GetRents()[i].takeIn.day <<" / "<< clients[i].GetRents()[i].takeIn.month<<" / "<< clients[i].GetRents()[i].takeIn.year;
				fout << clients[i].GetRents()[i].takeOut.day <<" / "<< clients[i].GetRents()[i].takeOut.month<<" / "<< clients[i].GetRents()[i].takeOut.year;
				for (size_t k = 0; k < clients[i].GetRents().size(); k++)
				{
					fout << clients[i].GetRents()[k].book.GetId() << endl;
					fout << clients[i].GetRents()[k].book.GetAuthor() << endl;
					fout << clients[i].GetRents()[k].book.GetTitle() << endl;
					fout << clients[i].GetRents()[k].book.GetPrice() << endl;
					fout << clients[i].GetRents()[k].book.GetRating() << endl;
				}*/
				fout << "=====================================================================================" << endl;
			}
		}
		fout.close();
	}


	vector<Client> ReadClients() {

		ifstream fin("clients.txt");
		vector<Client>clients;
		if (fin.is_open()) {
			int count = 0;
			fin >> count;
			for (size_t i = 0; i < count; i++)
			{
				int id = 0;
				fin >> id;

				string fullname;
				getline(fin, fullname);
				getline(fin, fullname);

				string username;
				fin >> username;

				string password;
				fin >> password;

				string line;
				fin >> line;

				User user;
				user.SetUsername(username);
				user.SetPassword(password);
				Client client;

				client.SetFullname(fullname);
				client.SetUser(user);
				client.SetId(id);

				clients.push_back(client);
			}

			fin.close();
		}
		return clients;
	}

}







#pragma once
