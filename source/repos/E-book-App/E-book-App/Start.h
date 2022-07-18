#pragma once
#include<iostream>
#include "Functions.h"
using namespace std;

namespace Start {
	Client CurrentClient;
	class Controller {
	public:
		static void StartProject() {
			DatabaseSection::Init();
			while (true)
			{
				FirstHomeMenu();
				int select = 0;
				cin >> select;
				system("cls");
				if (select == 1) {
					//admin
				}
				else if (select == 2) {

					cin.ignore();
					cin.clear();
					cout << "Enter username : " << endl;
					string username;
					cin >> username;
					cout << "Enter password : " << endl;
					string password;
					cin >> password;
					CurrentClient = GetClient(username, password);
					if (CurrentClient.GetId() != -1) {
						ClientHomeMenu();
					}
					else {
						cout << "ACCESS DENIED" << endl;
					}

					system("pause");
				}
				else {
					cout << "Wrong Selection" << endl;
				}
			}
		}


		static void FirstHomeMenu() {
			cout << "Admin  [1]" << endl;
			cout << "Client [2]" << endl;
		}
		static void ClientHomeMenu() {
			cout << "Show   Books [1]" << endl;
			cout << "Take   Book  [2]" << endl;
			cout << "Return Book  [3]" << endl;

		}
	};
}
