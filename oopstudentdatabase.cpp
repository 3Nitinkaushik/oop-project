
#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
	int roll;
	string Name;
	string Dept;
	int Marks;
    int Controlsystem;
    int Oop;
    int Computernetwork;
    int Errorcorrecting;
    int Economics;
	Node* next;

};

// Stores the head of the Linked List
Node* head = new Node();

// Check Function to check that if
// Record Already Exist or Not
bool check(int x)
{
	// Base Case
	if (head == NULL)
		return false;

	Node* t = new Node;
	t = head;

	// Traverse the Linked List
	while (t != NULL) {
		if (t->roll == x)
			return true;
		t = t->next;
	}

	return false;
}

// Function to insert the record
void Insert_Record(int roll, string Name,
				string Dept, int Marks,int Controlsystem,int Oop, int Computernetwork, int Errorcorrecting, int Economics)
{
	// if Record Already Exist
	if (check(roll)) {
		cout << "Student with this "
			<< "record Already Exists\n";
		return;
	}

	// Create new Node to Insert Record
	Node* t = new Node();
	t->roll = roll;
	t->Name = Name;
	t->Dept = Dept;
	t->Marks = Marks;
    t->Computernetwork= Computernetwork;
    t->Controlsystem=Controlsystem;
    t->Oop=Oop;
    t->Errorcorrecting=Errorcorrecting;
    t->Economics=Economics;
	t->next = NULL;

	// Insert at Begin
	if (head == NULL
		|| (head->roll >= t->roll)) {
		t->next = head;
		head = t;
	}

	// Insert at middle or End
	else {
		Node* c = head;
		while (c->next != NULL
			&& c->next->roll < t->roll) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}

	cout << "Record Inserted "
		<< "Successfully\n";
}

// Function to search record for any
// students Record with roll number
void Search_Record(int roll)
{
	// if head is NULL
	if (!head) {
		cout << "No such Record "
			<< "Available\n";
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) {
			if (p->roll == roll) {
				cout << "Roll Number\t"
					<< p->roll << endl;
				cout << "Name\t\t"
					<< p->Name << endl;
				cout << "Department\t"
					<< p->Dept << endl;
				cout << "Total Marks\t\t"
					<< p->Marks << endl;
                
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record "
				<< "Available\n";
	}
}

// Function to delete record students
// record with given roll number
// if it exist
int Delete_Record(int roll)
{
	Node* t = head;
	Node* p = NULL;

	// Deletion at Begin
	if (t != NULL
		&& t->roll == roll) {
		head = t->next;
		delete t;

		cout << "Record Deleted "
			<< "Successfully\n";
		return 0;
	}

	// Deletion Other than Begin
	while (t != NULL && t->roll != roll) {
		p = t;
		t = t->next;
	}
	if (t == NULL) {
		cout << "Record does not Exist\n";
		return -1;
		p->next = t->next;

		delete t;
		cout << "Record Deleted "
			<< "Successfully\n";

		return 0;
	}
}

// Function to display the Student's
// Record
void Show_Record()
{
	Node* p = head;
	if (p == NULL) {
		cout << "No Record "
			<< "Available\n";
	}
	else {
		cout << "Index\tName\tCourse"
			<< "\tTotal Marks\n";

		// Until p is not NULL
		while (p != NULL) {
			cout << p->roll << " \t"
				<< p->Name << "\t"
				<< p->Dept << "\t"
				<< p->Marks << endl;
			p = p->next;
		}
	}
}
//Function to update record 
void UpdateRecord(int roll,
	string Name,
	string Dept){
        //if no data is inserted
        if (!head) {
		cout << "No such Record "
			<< "Available\n";
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) {
			if (p->roll == roll) {
				p->Dept= Dept;
                p->Name= Name;
                cout<<"Student details are updated"<<endl;
				return ;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record "
				<< "Available\n";
	}


    }
void UpdateMarks(int roll,int Marks,int Controlsystem,int Oop, int Computernetwork, int Errorcorrecting, int Economics){
//for first node(head)
if (!head) {
		cout << "No such Record "
			<< "Available\n";
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) {
			if (p->roll == roll) {
				
				p->Marks= Marks;
                p->Controlsystem= Controlsystem;
                p->Oop= Oop;
                p->Computernetwork= Computernetwork;
                p->Errorcorrecting= Errorcorrecting;
                p->Economics= Economics;
                cout<<"Student marks are updated"<<endl;
				return ;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record "
				<< "Available\n";
	}

}
void Marksheet(int roll){
    if (!head) {
		cout << "No such Record "
			<< "Available\n";
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) {
			if (p->roll == roll) {
                cout<<"\tRoll : "<<roll<<"\tName : "<<p->Name<<"\tCourse: "<<p->Dept<<"\tTotal Marks: "<<p->Marks<<endl;
                cout<<"\t Subject                               \tMarks\n";
                cout<<"\t"<<"Control System and Instrumentation"<<"\t"<<p->Controlsystem<<endl;
                cout<<"\t"<<"Object Oriented programming       "<<"\t"<<p->Oop<<endl;
                cout<<"\t"<<"Computer Networking               "<<"\t"<<p->Computernetwork<<endl;
                cout<<"\t"<<"Error correcting codes            "<<"\t"<<p->Errorcorrecting<<endl;
                cout<<"\t"<<"Economics                         "<<"\t"<<p->Economics<<endl;
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record "
				<< "Available\n";
	}
}
// Driver code
int main()
{
	head = NULL;
	string Name, Course;
	int Roll, Marks;
    int Controlsystem,Oop, Computernetwork, Errorcorrecting, Economics;

	// Menu-driven program
	while (true) {
		cout << "\n\t\tWelcome to Student Record "
				"Management System\n\n\tPress\n\t1 to "
				"create a new Record\n\t2 to delete a "
				"student record\n\t3 to Search a Student "
				"Record\n\t4 to view all students \n\t5 to Update "
                "Student's Record\n\t6 to "
                "View marksheet of a Student\n\t7 to Modify "
                "Student's " 
				"Marks\n\t8 to Exit\n";
		cout << "\nEnter your Choice\n";
		int Choice;

		// Enter Choice
		cin >> Choice;
		if (Choice == 1) {
            cin.ignore();
			cout << "Enter Name of Student\n";
			getline(cin,Name);
			cout << "Enter Roll Number of Student\n";
			cin >> Roll;
            if(!check(Roll)){
			cout << "Enter Course of Student \n";
			cin >> Course;
            cout<<"Enter Marks of student in Control System and Instrumentation \n";
            cin>>Controlsystem;
            cout<<"Enter Marks of student in Object Oriented programming\n";
            cin>>Oop;
            cout<<"Enter Marks of student in Computer Networking\n";
            cin>>Computernetwork;
            cout<<"Enter Marks of student in Error correcting codes\n";
            cin>>Errorcorrecting;
            cout<<"Enter Marks of student in Economics\n";
            cin>>Economics;
			Marks= Controlsystem+Oop+Computernetwork+Errorcorrecting+Economics;
            cout<<"Total marks of student : "<<Marks<<endl;
			Insert_Record(Roll, Name, Course, Marks,Controlsystem,Oop, Computernetwork, Errorcorrecting, Economics);}
            else{cout << "Student with this "
			<< "record Already Exists\n";}
		}
		else if (Choice == 2) {
			cout << "Enter Roll Number of Student whose "
					"record is to be deleted\n";
			cin >> Roll;
			Delete_Record(Roll);
		}
		else if (Choice == 3) {
			cout << "Enter Roll Number of Student whose "
					"record you want to Search\n";
			cin >> Roll;
			Search_Record(Roll);
		}
		else if (Choice == 4) {
			Show_Record();
		}
        else if(Choice==5){
            cout<<"Enter roll no. of of student"<<endl;
            cin>>Roll;
            if(check(Roll)){
                cin.ignore();
			    cout << "Enter Name of Student\n";
			    getline(cin,Name);
                cout<<"Enter Course of Student"<<endl;
                cin>>Course;
                UpdateRecord(Roll,Name,Course);
            }
            else{cout<<"No record Found"<<endl;}
        }
        else if(Choice==6){
            cout<<"Enter roll no. of student"<<endl;
            cin>>Roll;
            Marksheet(Roll);
        }
        else if(Choice==7){
            cout<<"Enter roll no. of student"<<endl;
            cin>>Roll;
            if(check(Roll)){
                 cout<<"Enter Marks of student in Control System and Instrumentation \n";
            cin>>Controlsystem;
            cout<<"Enter Marks of student in Object Oriented programming\n ";
            cin>>Oop;
            cout<<"Enter Marks of student in Computer Networking\n ";
            cin>>Computernetwork;
            cout<<"Enter Marks of student in Error correcting codes \n";
            cin>>Errorcorrecting;
            cout<<"Enter Marks of student in Economics\n ";
            cin>>Economics;
			Marks= Controlsystem+Oop+Computernetwork+Errorcorrecting+Economics;
            cout<<"Total marks of student : "<<Marks<<endl;
            UpdateMarks(Roll,Marks,Controlsystem,Oop, Computernetwork, Errorcorrecting, Economics);
            }
            else{cout<<"No record Found"<<endl;}
        }
		else if (Choice == 8) {
			exit(0);
		}
		else {
			cout << "Invalid Choice "
				<< "Try Again\n";
		}
	}
	return 0;}
