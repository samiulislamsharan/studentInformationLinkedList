#include<iostream>

using namespace std;

class node {
public:
	int studentId;
	string name;
	string grade;
	node* next;
};

node* head = new node();

// Function to check if a record already exists or not.
bool check(int x) {
	if (head == NULL) {
		return false;
	}

	node* t = new node;
	t = head;

	while (t != NULL) {
		if (t->studentId == x) {
			return true;
		}
		t = t->next;
	}

	return false;
}

void insertRecord(int studentId, string name, string grade) {
	// If a record already exists
	if (check(studentId)) {
		cout << "Student with this record already exists" << endl;
		return;
	}

	// Creating a node to insert a record
	node* t = new node();
	t->studentId = studentId;
	t->name = name;
	t->grade = grade;
	t->next = NULL;

	// Insert at beginning
	if (head == NULL || (head->studentId >= t->studentId)) {
		t->next = head;
		head = t;
	}

	// Insert at middle or end
	else {
		node* c = head;
		while (c->next != NULL && c->next->studentId < t->studentId) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}
	cout << "Record inserted successfully" << endl;
}

// Searching record by studentID if it exists.
void searchRrcord(int studentId) {
	// If head is NULL
	if (!head) {
		cout << "No such record available." << endl;
		return;
	}
	// Otherwise
	else {
		node* p = head;
		while (p) {
			if (p->studentId == studentId) {
				cout << "Student ID\t" << p->studentId << endl;
				cout << "Name\t" << p->name << endl;
				cout << "Grade\t" << p->grade << endl;

				return;
			}
			p = p->next;
		}

		if (p == NULL) {
			cout << "\nNo such record available.\n" << endl;
		}
	}
}

// Function to delete record(s) by studentId if it exists.
int deleteRecord(int studentId) {
	node* t = head;
	node* p = NULL;

	//Deletion at beginning.
	if (t != NULL && t->studentId == studentId) {
		head = t->next;
		delete t;

		cout << "Record deleted successfully\n" << endl;
		return 0;
	}

	// Deletion at othe than beginning
	while (t != NULL && t->studentId == studentId) {
		p = t;
		t = t->next;
	}
	if (t == NULL) {
		cout << "Record does not exist\n" << endl;
		return -1;
		p->next = t->next;

		delete t;
		cout << "Record deleted successfully\n" << endl;

		return 0;
	}
}

// Show record(s)
void showRecord() {
	node* p = head;
	if (p == NULL) {
		cout << "No record available\n" << endl;
	}
	else {
		cout << "------------\t------\t\t-------" << endl;
		cout << "|Student ID|\t|Name|\t\t|Grade|" << endl;
		cout << "------------\t------\t\t-------" << endl;

		// Until p is not NULL
		while (p != NULL) {
			cout << p->studentId
				<< "    \t"
				<< p->name << "\t\t"
				<< p->grade << "\t"
				<< endl;

			p = p->next;
		}
	}
}

int main() {
	head = NULL;
	int id, choice;
	string name, grade;

	while (true) {
		cout << "\nStudent record management\n"
			<< "***************************\n"
			<< "\tPress:\n"
			<< "\t1 to create a new record\n"
			<< "\t2 to delete a record\n"
			<< "\t3 to search a record\n"
			<< "\t4 to view all record(s)\n"
			<< "\t5 Exit\n";
		
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter Student ID: ";
			cin >> id;
			cout << "Enter student Name: ";
			cin >> name;
			cout << "Enter student Grade: ";
			cin >> grade;
			insertRecord(id, name, grade);
			break;
		case 2:
			cout << "Enter Student ID: ";
			cin >> id;
			deleteRecord(id);
			break;
		case 3:
			cout << "Enter Student ID: ";
			cin >> id;
			searchRrcord(id);
			break;
		case 4:
			showRecord();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "Invalid input, try again!" << endl;
			break;
		}
	}
	return 0;
}