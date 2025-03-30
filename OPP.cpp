#include<iostream>
#include<fstream>
using namespace std;

struct stStudents
{
	string FirstName;
	string SecondName;

};

void SaveIDFile(string ID)
{
	fstream HistoryFile;
	HistoryFile.open("HistoryID.txt", ios::app);
	if (HistoryFile.is_open())
	{
		HistoryFile << ID << endl;
		HistoryFile.close();
	}
}

class ClBankClients
{
private:
	string _ClientID;
	string _ClientPassword;
public:
	// Proprety set
	void setClientID(string ClientID)
	{
		SaveIDFile(ClientID);
		_ClientID = ClientID;
	}
	void setClientPassword(string ClientPassword)
	{
		_ClientPassword = ClientPassword;
	}
	// Peoprety get
	string getClientID()
	{
		return _ClientID;
	}
	string getClientPassword()
	{
		return _ClientPassword;
	}
	__declspec(property(get = getClientID, put = setClientID)) string ClientID;
};

class ClStudents
{
public:
	string FirstName;
	string SecondName;
	string FullName()
	{
		return FirstName + " " + SecondName;
	}
private :
	int Mark1 = 19 ;
	int Mark2 = 18 ;
	int AverageMark1()
	{
		return (Mark1 + Mark2) / 2;
	}
public:
	int Mark3;
	int Mark4;
	int AverageMark()
	{
		return (AverageMark1() + Mark2 + Mark3) / 3;
	}

};

class clsCalculator
{
private:
	int _Result = 0;
	int _LastNumber = 0;
	string _OperType = "";
	int _PreviousResult = 0;
	bool _IsZero(int Number)
	{
		return (Number == 0);
	}
public:
	void Clear()
	{
		_PreviousResult = _Result;
		_Result = 0;
		_OperType = "Clearing";
		_LastNumber = 0;
	}
	void Add(int Number)
	{
		_PreviousResult = _Result;
		_Result += Number;
		_OperType = "Adding";
		_LastNumber = Number;
	}
	void Substr(int Number)
	{
		_PreviousResult = _Result;
		_Result -= Number;
		_OperType = "Substracting";
		_LastNumber = Number;
	}
	void Multiply(int Number)
	{
		_PreviousResult = _Result;
		_Result *= Number;
		_OperType = "Multiplaying";
		_LastNumber = Number;
	}
	void Divise(int Number)
	{
		if (_IsZero(Number)) { Number = 1; }
		_PreviousResult = _Result;
		_Result /= Number;
		_OperType = "Divising";
		_LastNumber = Number;
	}
	void CancelingLastOperation()
	{
		_Result = _PreviousResult ;
		_OperType = "Canceling Last Operation";
		_LastNumber = 0;
	}
	void PrintResult()
	{
		printf("\nResult After %s %d is : %d", _OperType.c_str(), _LastNumber, _Result);
	}
};

class clsAddress
{
private:
	string _AddressLine1;
	string _AddressLine2;
	string _POBox;
	string _ZipCode;
public:

	clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
	{
		_AddressLine1 = AddressLine1;
		_AddressLine2 = AddressLine2;
		_POBox = POBox;
		_ZipCode = ZipCode;
	}
	//Copy Constructor :
	clsAddress(clsAddress & Old_obj)
	{
		_AddressLine1 = Old_obj.AddressLine1();
		_AddressLine2 = Old_obj.AddressLine2();
		_POBox = Old_obj.POBox();
		_ZipCode = Old_obj.ZipCode();
	}

	void SetAddressLine1(string AddressLine1)
	{
		_AddressLine1 = AddressLine1;
	}
	void SetAddressLine2(string AddressLine2)
	{
		_AddressLine2 = AddressLine2;
	}
	void SetPOBox(string POBox)
	{
		_POBox = POBox;
	}
	void SetZipCode(string ZipCode)
	{
		_ZipCode = ZipCode;
	}
	string AddressLine1()
	{
		return _AddressLine1;
	}
	string AddressLine2()
	{
		return _AddressLine2;
	}
	string POBox()
	{
		return _POBox;
	}
	string ZipCode()
	{
		return _ZipCode;
	}
	void PrintAddress()
	{
		cout << "\t\tAddress:\n";
		cout << "======================================================\n";
		cout << "\nAddress Line 1 : " << _AddressLine1;
		cout << "\nAddress Line 2 : " << _AddressLine2;
		cout << "\nPOBox : " << _POBox;
		cout << "\nZipCode : " << _ZipCode;
		cout << "\n======================================================\n";
	}
};

class clsPerson1
{
public:
	string FullName;
	clsPerson1()
	{
		cout << "\nHi,I'm Mohamed Benlajdid . ";
		cout << "\nThis is the Constructor Fonction . ";
	}

	~clsPerson1()
	{
		cout << "\nI'm The Destructor one . ";
	}
};

void Fonc1()
{
	clsPerson1 Person1;
}

void Fonc2()
{
	clsPerson1 * Person2 = new clsPerson1;
	// You Have Write Delete( new == Delete)
	delete Person2;
}

class clsA
{
public:
	int Var;
	static int Counter;
	clsA()
	{
		Counter++;
	}
	void Print()
	{
		cout << "\nVar = " << Var;
		cout << "\nCounter = " << Counter;
	}
};

int clsA::Counter = 0; // Inialisation outside the class .

class clsB
{
public:
	int Fonction1()
	{
		return 10;
	}
	static int Fonction2()
	{
		return 20;
	}
};

class clsPerson
{
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}
	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	int ID()
	{
		return _ID;
	}
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string FirstName()
	{
		return _FirstName;
	}
	string LastName()
	{
		return _LastName;
	}
	string Email()
	{
		return _Email;
	}
	string Phone()
	{
		return _Phone;
	}
	void Print()
	{
		cout << "\t\tInfo\n";
		cout << "==========================================================\n";
		cout << "\nID : " << _ID;
		cout << "\nFirst Name : " << _FirstName;
		cout << "\nLast Name : " << _LastName;
		cout << "\nFull Name : " << FullName();
		cout << "\nEmail : " << _Email;
		cout << "\nPhone : " << _Phone;
		cout << "\n==========================================================\n";
	}
	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent seccessfully to email : " <<
			_Email;
		cout << "\nSubject : " << Subject;
		cout << "\nBody : " << Body;
	}
	void SendSMS(string Message)
	{
		cout << "\nThe following SMS sent seccessfully to Phone : " <<
			_Phone;
		cout << "\nMessage : " << Message;
	}
};

class clsEmployee
{
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _Title;
	string _Email;
	string _Phone;
	int _Salary;
	string _Department;
public:
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}
	clsEmployee(int ID, string FirstName, string LastName,
		string Title, string Email, string Phone, int Salary, string Department)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Title = Title;
		_Email = Email;
		_Phone = Phone;
		_Salary = Salary;
		_Department = Department;
	}
	int ID()
	{
		return _ID;
	}
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	void SetTitle(string Title)
	{
		_Title = Title;
	}
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	void SetSalary(int Salary)
	{
		_Salary = Salary;
	}
	void SetDepartment(string Department)
	{
		_Department = Department;
	}
	string FirstName()
	{
		return _FirstName;
	}
	string LastName()
	{
		return _LastName;
	}
	string Title()
	{
		return _Title;
	}
	string Email()
	{
		return _Email;
	}
	string Phone()
	{
		return _Phone;
	}
	int Salary()
	{
		return _Salary;
	}
	string Department()
	{
		return _Department;
	}
	void Print()
	{
		cout << "\t\tInfo\n";
		cout << "==========================================================\n";
		cout << "\nID : " << _ID;
		cout << "\nFirst Name : " << _FirstName;
		cout << "\nLast Name : " << _LastName;
		cout << "\nFull Name : " << FullName();
		cout << "\nTitle : " << _Title;
		cout << "\nEmail : " << _Email;
		cout << "\nPhone : " << _Phone;
		cout << "\nSalary : " << _Salary;
		cout << "\nDepartment : " << _Department;
		cout << "\n==========================================================\n";
	}
	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent seccessfully to email : " <<
			_Email;
		cout << "\nSubject : " << Subject;
		cout << "\nBody : " << Body;
	}
	void SendSMS(string Message)
	{
		cout << "\nThe following SMS sent seccessfully to Phone : " <<
			_Phone;
		cout << "\nMessage : " << Message;
	}
};

int main()
{

	clsPerson Person1(10, "Mohamed", "Benlajdid", "benm21158@gmail.com", "0656008876");
	Person1.Print();

	Person1.SendEmail("Dear Friend", "I trust you keeping very well");
	Person1.SendSMS("I Hope you doing well , call me later please ");

	clsEmployee Employee1(11, "Mohamed", "Benlajdid", "Co-Chef",
		"benm21158@gmail.com", "0684869985",10000,"CrystalGarden");
	Employee1.Print();

	Employee1.SendEmail("Mr Benlajdid","Hello Mr Mohamed ,You Did a good job.");
	Employee1.SendSMS("I Hope accept our work request");

	system("pause>0");
}