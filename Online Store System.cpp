/*Assignment 2: Problem 3*/
/*Roll No: 2018-CS-613*/
/*Name: M Yahya*/

#include <iostream>
#include <string>
using namespace std;

class Product {
public:
	string m_name;
	int m_ID;
	float m_price;
	int m_quantity;

	void SetProduct(string name, int id, float price, int quantity) {
		m_name = name;
		m_ID = id;
		m_price = price;
		m_quantity = quantity;
	}

	/*Setter*/
	void setName() {
		cout << "Enter Product Name: ";       cin >> m_name;
	}
	void setID() {
		cout << "Enter Product ID: ";         cin >> m_ID;
	}
	void setPrice() {
		cout << "Enter Product Price: ";      cin >> m_price;
	}
	void setQuantity() {
		cout << "Enter Product Quantity: ";   cin >> m_quantity;
	}

	/*Getter*/
	string getName() {
		return m_name;
	}
	int getID() {
		return m_ID;
	}
	float getPrice() {
		return m_price;
	}
	int getQuantity() {
		return m_quantity;
	}

	void Display() {
		//cout << "Following are the Product Details: \n";
		cout << "Product Name: " << m_name << endl;
		cout << "Product ID: " << m_ID << endl;
		cout << "Product Price: " << m_price << endl;
		cout << "Product Quantity: " << m_quantity << endl;
		cout << endl;
	}

};

class Node {
public:
	Product item;
	Node* next;
	Node* prev;
	Node(Product pro) {
		item = pro;
		next = NULL;
		prev = NULL;
	}

};

class ProductList {
public:
	Node* head, * tail;
	ProductList() {
		head = NULL;
		tail = NULL;
	}

	void InsertProduct(Product pro) {
		Node* temp = new Node(pro);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}

	void Search_Name(string name) {
		Node* temp = head;
		int flag = 0;
		if (head->item.getName() == name) {
			cout << "\nWe Have This Item: \n";
			cout << "Following are the Details: \n";
			head->item.Display();
			flag++;
		}
		else if (tail->item.getName() == name) {
			cout << "\nWe Have This Item: \n";
			cout << "Following are the Details: \n";
			tail->item.Display();
			flag++;
		}
		else {
			cout << "Searching.....\n";
			while (temp != NULL) {
				if (temp->item.getName() == name) {
					cout << "\nWe Have This Item: \n";
					cout << "Following are the Details: \n";
					temp->item.Display();
					flag++;
				}
				temp = temp->next;
			}
		}
		if (flag == 0) {
			cout << "We Do Not Have This Product!\n";
		}
	}

	void Remove(string name) {
		Node* temp = head;
		int flag = 0;
		if (head->item.getName() == name) {
			temp->next->prev = NULL;
			head = temp->next;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			flag++;
			cout << "\nItem Has Been removed \n";
			cout << "Updated List is: \n";
		}
		else if (tail->item.getName() == name) {
			temp = tail;
			tail = temp->prev;
			temp->prev->next = NULL;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			flag++;
			cout << "\nItem Has Been removed \n";
			cout << "Updated List is: \n";
		}
		else {
			while (temp != NULL) {
				cout << "Searching......\n";
				if (temp->item.getName() == name) {
					cout << "We Found!\n";
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					temp->next = NULL;
					temp->prev = NULL;
					delete temp;
					flag++;
					cout << "\nItem Has Been removed \n";
					cout << "Updated List is: \n";
					break;
				}
				temp = temp->next;
			}
		}
		if (flag == 0) {
			cout << "We Do Not Have This Item!\n";
		}
	}

	void Update(string name) {
		Node* temp = head;
		int flag = 0;
		if (head->item.getName() == name) {
			cout << "Updating Item " << head->item.getName() << "....... \n";
			head->item.setName();
			head->item.setPrice();
			head->item.setQuantity();
			flag++;
			cout << "\nItem Has Been Updated \n";
			cout << "Updated List is: \n";
		}
		else if (tail->item.getName() == name) {
			cout << "Updating Item " << tail->item.getName() << "....... \n";
			tail->item.setName();
			tail->item.setPrice();
			tail->item.setQuantity();
			flag++;
			cout << "\nItem Has Been Updated \n";
			cout << "Updated List is: \n";
		}
		else {
			while (temp != NULL) {
				cout << "Searching......\n";
				if (temp->item.getName() == name) {
					cout << "Updating Item " << temp->item.getName() << "....... \n";
					temp->item.setName();
					temp->item.setPrice();
					temp->item.setQuantity();
					flag++;
					cout << "\nItem Has Been Updated \n";
					cout << "Updated List is: \n";
					break;
				}
				temp = temp->next;
			}
		}
		if (flag == 0) {
			cout << "We Do Not Have This Item!\n";
		}
	}

	void Sort_Name() {
		Node* temp = head;
		Node* temp2 = temp->next;
		Node* hold = head;
		while (temp2 != NULL) {
			int i = 0;
			int j = 0;
			if (temp->item.getName()[i] > temp2->item.getName()[j]) {
				cout << "Swap!\n";
				Product obj = temp2->item;
				temp2->item = temp->item;
				temp->item = obj;
			}
			temp2 = temp2->next;
			temp = temp->next;
		}
		cout << "Check\n";
	}

	void TotalBill() {
		cout << "you are here\n";
		Node* temp = head;
		
		float totalBill = 0;
		int quantity;
		int flag = 0;
		int option = -1;
		int repeat;

		while (option != 0) {
			cout << "\nTo Buy Product: Enter 1\n";
			cout << "To see you current bill: Enter 2\n";
			cout << "To Exist the Menu: Enter 0\n";

			cin >> option;
			if (option == 1) {
				cout << "Enter Product Name You Want to Buy: ";
				string name;
				cin >> name;
				cout << "temp: "; 
				temp->item.Display();
				if (temp->item.getName() == name) {
					cout << "\nWe Have This Item: \n";
					cout << "\tPrice Rs: " << temp->item.getPrice() << endl;
					cout << "\tEnter Quantity: ";
					cin >> quantity;
					totalBill += temp->item.getPrice() * quantity;
					cout << "\tTotal Bill: " << totalBill;
					flag++;
					break;
				}
				else if (tail->item.getName() == name) {
					cout << "\nWe Have This Item: \n";
					cout << "\tPrice Rs: " << tail->item.getPrice() << endl;
					cout << "\tEnter Quantity: ";
					cin >> quantity;
					totalBill += tail->item.getPrice() * quantity;
					cout << "\tTotal Bill: " << totalBill;
					flag++;
					break;
				}
				else {

					cout << "Searching.....\n";
					while (temp != NULL) {
						if (temp->item.getName() == name) {
							cout << "\nWe Have This Item: \n";
							cout << "\tPrice Rs: " << temp->item.getPrice() << endl;
							cout << "\tEnter Quantity: ";
							cin >> quantity;
							totalBill += temp->item.getPrice() * quantity;
							cout << "\tTotal Bill: " << totalBill;
							flag++;
							break;
						}
						temp = temp->next;
					}
				}
				if (flag == 0) {
					cout << "We Do Not Have This Product!\n";
				}
			}
			else if (option == 2) {
				cout << "\tYour current bill is: " << totalBill << " Rs" << endl;
			}
		}

	}

	void Display() {
		int count = 1;
		Node* ptr = head;
		while (ptr != NULL) {
			cout << "Item " << count << ": \n";
			ptr->item.Display();
			ptr = ptr->next;
			count++;
		}
		cout << endl;
	}
};



class User : public ProductList{
public:
	string m_name;
	int m_ID;
	string m_phoneNo;
	string m_purDate;

	void setUser(string name, int id, string phone, string purchase) {
		m_name = name;
		m_ID = id;
		m_phoneNo = phone;
		m_purDate = purchase;
	}

	/*Setter*/
	void setUserName() {
		cout << "Enter User Name: ";       cin >> m_name;
	}
	void setUserID() {
		cout << "Enter User ID: ";         cin >> m_ID;
	}
	void setUserPhone() {
		cout << "Enter User Phone No: ";      cin >> m_phoneNo;
	}
	void setPurDate() {
		cout << "Enter Purchase Date: ";   cin >> m_purDate;
	}

	/*Getter*/
	string getUserName() {
		return m_name;
	}
	int getUserID() {
		return m_ID;
	}
	string getUserPhone() {
		return m_phoneNo;
	}
	string getPurDate() {
		return m_purDate;
	}

	void BuyProduct() {
		ProductList product;
		cout << "Enter Product Name: ";
		string name;
		cin >> name;
		product.Search_Name(name);
		cout << "You made it\n";
	}

	void UserDisplay() {
		cout << "\nUser Details\n";
		cout << "User Name: " << m_name << endl;
		cout << "User ID: " << m_ID << endl;
		cout << "User Phone No.: " << m_phoneNo << endl;
		cout << "User Purchase Date: " << m_purDate << endl;
		cout << endl;
	}

};


class UserNode {
public:
	User person;
	ProductList *proPtr;
	UserNode* next;
	UserNode* prev;
	UserNode(User obj) {
		person = obj;
		next = NULL;
		prev = NULL;
	}
};



class UserList {
public:
	UserNode* head, * tail;
	UserList() {
		head = NULL;
		tail = NULL;
	}

	void Add(User person) {
		UserNode* temp = new UserNode(person);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}

	bool Search_User(string name) {
		UserNode* temp = head;
		int flag = 0;
		if (head->person.getUserName() == name) {
			cout << "\nUser Exist: \n";
			cout << "User Details: \n";
			head->person.UserDisplay();
			flag++;
			return true;
		}
		else if (tail->person.getUserName() == name) {
			cout << "\nUser Exist: \n";
			cout << "User Details: \n";
			tail->person.UserDisplay();
			flag++;
			return true;
		}
		else {
			cout << "Searching.....\n";
			while (temp != NULL) {
				if (temp->person.getUserName() == name) {
					cout << "\nUser Exist: \n";
					cout << "User Details: \n";
					temp->person.UserDisplay();
					flag++;
					return true;
				}
				temp = temp->next;
			}
		}
		if (flag == 0) {
			cout << "User Does not Exist!\n\n";
			return false;
		}
	}

	void Update_User(string name) {
		UserNode* temp = head;
		int flag = 0;
		if (head->person.getUserName() == name) {
			cout << "Updating User: " << head->person.getUserName() << "....... \n";
			head->person.setUserName();
			head->person.setUserPhone();
			head->person.setPurDate();
			flag++;
			cout << "\nUser Has Been Updated \n";
			cout << "Updated List is: \n";
		}
		else if (tail->person.getUserName() == name) {
			cout << "Updating User: " << tail->person.getUserName() << "....... \n";
			tail->person.setUserName();
			tail->person.setUserPhone();
			tail->person.setPurDate();
			flag++;
			cout << "\nUser Has Been Updated \n";
			cout << "Updated List is: \n";
		}
		else {
			while (temp != NULL) {
				cout << "Searching......\n";
				if (temp->person.getUserName() == name) {
					cout << "Updating User: " << temp->person.getUserName() << "....... \n";
					temp->person.setUserName();
					temp->person.setUserPhone();
					temp->person.setPurDate();
					flag++;
					cout << "\nUser Has Been Updated \n";
					cout << "Updated List is: \n";
					break;
				}
				temp = temp->next;
			}
		}
		if (flag == 0) {
			cout << "User Does Not Exist!\n";
			cout << "List does not Update!\n";
		}
	}

	void Remove_User(string name) {
		UserNode* temp = head;
		int flag = 0;
		if (head->person.getUserName() == name) {
			temp->next->prev = NULL;
			head = temp->next;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			flag++;
			cout << "\nUser Has Been removed \n";
			cout << "Updated List is: \n";
		}
		else if (tail->person.getUserName() == name) {
			temp = tail;
			tail = temp->prev;
			temp->prev->next = NULL;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			flag++;
			cout << "\nUser Has Been removed \n";
			cout << "Updated List is: \n";
		}
		else {
			while (temp != NULL) {
				cout << "Searching......\n";
				if (temp->person.getUserName() == name) {
					cout << "We Found!\n";
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					temp->next = NULL;
					temp->prev = NULL;
					delete temp;
					flag++;
					cout << "\nUser Has Been removed \n";
					cout << "Updated List is: \n";
					break;
				}
				temp = temp->next;
			}
		}
		if (flag == 0) {
			cout << "User Does not Exist!\n\n";
		}
	}

	void Sort_PurDate() {
		UserNode* temp = head;
		UserNode* temp2 = temp->next;
		while (temp2 != NULL) {
			for (int i = 0; i < temp->person.getPurDate().length(); i++) {
				for (int j = 0; j < temp2->person.getPurDate().length(); j++) {
					if (temp->person.getPurDate()[i] > temp2->person.getPurDate()[j]) {
						User obj = temp2->person;
						temp2->person = temp->person;
						temp->person = obj;
					}
				}
			}
			temp2 = temp2->next;
			temp = temp->next;
		}
		cout << "Check\n";
	}

	void UserCheck(string name) {
		UserNode* temp = head;
		ProductList pro;
		if (temp->person.getUserName() == name) {
			cout << "You are already a customer!" << endl;
			temp->person.BuyProduct();
		}
		else {
			while (temp != NULL) {
				if (temp->person.getUserName() == name) {
					cout << "You are already a customer!" << endl;
				}
				temp = temp->next;
			}
		}
	}


	
    

	void Display() {
		cout << "\nDisplaying User Details: \n";
		int count = 1;
		UserNode* ptr = head;
		while (ptr != NULL) {
			cout << "User " << count << ": \n";
			ptr->person.UserDisplay();
			count++;
			ptr = ptr->next;
		}
	}

};






int main() {
	/*************************Product Class Implementation*************************************/

	Product pro1, pro2, pro3, pro4;
	pro1.SetProduct("pastery", 111, 25, 150);
	pro2.SetProduct("bread", 112, 05, 500);
	pro3.SetProduct("custerd", 113, 30, 500);
	pro4.SetProduct("cake", 113, 30, 500);

	ProductList list1;
	list1.InsertProduct(pro1);
	list1.InsertProduct(pro2);
	list1.InsertProduct(pro3);
	list1.InsertProduct(pro4);


	/************************************************************************/

/*************************User Class Implementation*************************************/

	User user1, user2, user3;
	user1.setUser("alex", 44, "0321-02157", "8/1/2019");
	user2.setUser("maria", 45, "0321-95565", "9/20/2019");
	user3.setUser("jane", 46, "0321-78455", "2/15/2019");

	UserList userList1;
	userList1.Add(user1);
	userList1.Add(user2);
	userList1.Add(user3);







	/************************************************************************/

		/*Making User Interface Menu*/
	int select = -1;
	cout << "\t\tTo Product Class: Enter 1";
	cout << "\t\tTo User Class: Enter 2 \n\t\t\t\t\t\t";
	cin >> select;
	if (select == 1) {
		/*For Product Class*/
		int option = -1;
		while (option != 0) {
			cout << endl << endl;
			cout << "To Search Item by Name: Enter 1 \n";
			cout << "To Remove Item: Enter 2 \n";
			cout << "To Update Item: Enter 3 \n";
			cout << "To Insert New Product: Enter 4 \n";
			cout << "To Sort By Name: Enter 5 \n";
			cout << "To Calculate Total Bill: Enter 6 \n";
			cout << "To Exit: Enter 0\n";

			cin >> option;
			if (option == 1) {
				string name;
				cout << "Enter Product Name To Search: ";    cin >> name;
				list1.Search_Name(name);
			}
			else if (option == 2) {
				string name;
				cout << "Enter Product Name To Search: ";    cin >> name;
				list1.Remove(name);
				list1.Display();
			}
			else if (option == 3) {
				string name;
				cout << "Enter Product Name To Search: ";    cin >> name;
				list1.Update(name);
				list1.Display();
			}
			else if (option == 4) {
				Product pro4;
				pro4.setName();
				pro4.setID();
				pro4.setPrice();
				pro4.setQuantity();

				list1.InsertProduct(pro4);
				cout << "Product Has Been Inserted!\n";
				list1.Display();
			}
			else if (option == 5) {
				list1.Sort_Name();
				list1.Display();
			}
			else if (option == 6) {
				list1.TotalBill();
			}

		}
	}
	/*For User Class*/
	else if (select == 2) {
		int choice = -1;
		while (choice != 0) {
			cout << "To Add User: Enter 1 \n";
			cout << "To Search User: Enter 2 \n";
			cout << "To Update User: Enter 3 \n";
			cout << "To Remove User: Enter 4 \n";
			cout << "To Sort By PurDate: Enter 5 \n";
			cout << "To buy product: Enter 6 \n";

			cin >> choice;
			if (choice == 1) {
				User person;
				person.setUserName();
				person.setUserID();
				person.setUserPhone();
				person.setPurDate();
				userList1.Add(person);
				cout << "User is Added!\n";
				userList1.Display();
			}
			else if (choice == 2) {
				string name;
				cout << "Enter User Name: ";     cin >> name;
				userList1.Search_User(name);
			}
			else if (choice == 3) {
				string name;
				cout << "Enter User Name To Search: ";     cin >> name;
				userList1.Update_User(name);
				userList1.Display();
			}
			else if (choice == 4) {
				string name;
				cout << "Enter User Name To Search: ";     cin >> name;
				userList1.Remove_User(name);
				userList1.Display();
			}
			else if (choice == 5) {
				userList1.Sort_PurDate();
				userList1.Display();
			}
			else if (choice == 6) {
				string name;
				cout << "Enter you name: ";
				cin >> name;
				userList1.UserCheck(name);
			}
		}
	}


	system("pause");
	return 0;
}