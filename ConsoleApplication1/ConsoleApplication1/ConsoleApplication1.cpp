#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//----SETUP------------------------------------------------------
class User
{
private:
	Book b;
	douList ds;
public:
	User()
	{
	};
	void xuatToanBo(douList& ds)
	{
		Node* p = new Node; //node nay dung de duyet danh sach
		for (p = ds.head; p != NULL; p = p->next)
		{
			cout << "****************************\n";
			cout << "Ma so: " << p->data.number << endl;
			cout << "Ten sach: " << p->data.nameBook << endl;
			cout << "Ten tac gia: " << p->data.nameAuthor << endl;
			cout << "The loai: " << p->data.category << endl;
			cout << "Tinh trang: ";
			if (p->data.condition == "true")
				cout << "Con sach \n";
			else
				cout << "Het sach \n";
		}
	}

	void timSach(douList& ds)
	{
		string nameToFind;
		cin.ignore();
		cout << "Quyen sach ban can tim la: ";
		getline(cin, nameToFind);
		Node* p = new Node;
		for (p = ds.head; p != NULL; p = p->next)
		{
			if (nameToFind.compare(p->data.nameBook) == 0)
			{
				cout << "Thong tin cua quyen sach ban can tim la: \n";
				cout << "Ma so: " << p->data.number << endl;
				cout << "Ten tac gia: " << p->data.nameAuthor << endl;
				cout << "Ten sach: " << p->data.nameBook << endl;
				cout << "The loai: " << p->data.category << endl;
				cout << "Tinh trang: ";
				if (p->data.condition == "true")
					cout << "Con sach \n";
				else
					cout << "Het sach \n";
				return;
			}
		}
		cout << "Quyen sach ban tim khong co trong thu vien \n";
	}
};

class QuanThu : public User
{
public:
	Node* taoNode(Book b)
	{
		Node* p;
		p = new Node;
		p->data = b;
		p->next = NULL;
		p->pre = NULL;
		return p;
	}

	void themCuoi(douList& ds, Node* p)
	{
		if (ds.head == NULL)
			ds.head = ds.tail = p;
		else
		{
			ds.tail->next = p;
			p->pre = ds.tail;
			ds.tail = p;
		}
	}
	void Nhap(douList& ds)
	{
		// Nhap thong tin cho sach
		Book b;
		cout << "Nhap ma so: ";
		cin >> b.number;
		cin.ignore();
		cout << "Nhap ten sach: ";
		getline(cin, b.nameBook);
		cout << "Nhap ten tac gia: ";
		getline(cin, b.nameAuthor);
		cout << "Nhap ten the loai: ";
		getline(cin, b.category);
		// Tao mot node moi doc lap bang ham taoNode
		Node* p = new Node;
		p = taoNode(b);
		// Gan node do vao cuoi danh sach
		themCuoi(ds, p);
	}
	void xoaDau(douList& ds)
	{

		if (ds.head == NULL) //kiemtra xem danh sach lien ket co rong hay khong
			ds.tail = NULL;
		Node* p = ds.head;
		ds.head = ds.head->next;
		ds.head->pre = NULL;
		p->next = NULL;
		delete p;
	}

	void xoaCuoi(douList& ds)
	{
		if (ds.tail == NULL)
			ds.head = NULL;
		Node* p = ds.tail;
		ds.tail = ds.tail->pre;
		ds.tail->next = NULL;
		p->pre = NULL;
		delete p;
	}

	void xoaViTriK(douList& ds)
	{
		string confirm, nameBook_temp;
		cin.ignore();
		cout << "Nhap ten quyen sach ban can xoa ra khoi thu vien: ";
		getline(cin, nameBook_temp);
		cout << "Ban co chac la muon xoa hay khong: Yes	 or  No \n";
		cin >> confirm;
		if (confirm == "Yes" || confirm == "yes")
		{
			Node* p = new Node;
			bool flag = false;
			for (p = ds.head; p != NULL; p = p->next)
			{
				if (p->data.nameBook == nameBook_temp)
				{
					flag = true;
					if (p->pre == NULL)
					{
						xoaDau(ds);
						return;
					}
					if (p->next == NULL)
					{
						xoaCuoi(ds);
						return;
					}
					p->pre->next = p->next;
					p->next->pre = p->pre;
					p->next = NULL;
					p->pre = NULL;
					delete p;
					cout << "Da xoa thanh cong quyen: " << p->data.nameBook << endl;
				}
			}
			if (flag == false)
				cout << "Sach ban can xoa khong co trong thu vien!!";
		}
	}
};
class NguoiMuonSach : public User
{
public:
	void muonSach(douList& ds)
	{
		string nameToBorrow;
		cin.ignore();
		cout << "Ban muon muon quyen sach: ";
		getline(cin, nameToBorrow);
		Node* p = new Node;
		for (p = ds.head; p != NULL; p = p->next)
		{
			if (p->data.nameBook.compare(nameToBorrow) == 0)
			{
				if (p->data.condition == "true")
				{
					cout << "Ban da muon thanh cong \n";
					p->data.condition = "false";
				}
				else
					cout << "Quyen sach nay da co nguoi muon! \n";
				return;
			}
		}
		cout << "Quyen sach nay khong co trong thu vien \n";
	}

	void traSach(douList& ds)
	{
		string nameToGiveBack;
		cin.ignore();
		cout << "Nhap ten quyen sach ban muon tra: ";
		getline(cin, nameToGiveBack);
		Node* p = new Node;
		for (p = ds.head; p != NULL; p = p->next)
		{
			if (p->data.nameBook.compare(nameToGiveBack) == 0)
			{
				p->data.condition = "true";
				cout << "Tra sach thanh cong \n";
				return;
			}
		}
		cout << "Quyen sach nay khong co trong thu vien! \n";
	}

};
struct Book
{
	string number;
	string nameBook;
	string nameAuthor;
	string category;
	string condition = "true";
};
struct Node
{
	Book data;
	Node* pre;
	Node* next;
};
struct douList
{
	Node* head;
	Node* tail;
};
void khoiTao(douList& ds)
{
	ds.head = NULL;
	ds.tail = NULL;
}
//---------------------------------------------------------------


void nhapTuFile(douList& ds, ifstream& FileIn)
{
	QuanThu q;
	// Nhap thong tin cho sach
	Book b;
	//	cin.ignore();
	getline(FileIn, b.number, ',');
	//	cin.ignore();
	getline(FileIn, b.nameBook, ',');
	//	cin.ignore();
	getline(FileIn, b.nameAuthor, ',');
	//	cin.ignore();
	getline(FileIn, b.category);

	// Tao mot node moi doc lap bang ham taoNode
	Node* p = new Node;
	p = q.taoNode(b);
	// Gan node do vao cuoi danh sach
	q.themCuoi(ds, p);
}
void loadData(ifstream& FileIn, douList& ds)
{
	int n;
	FileIn >> n;
	for (int i = 0; i < n; i++)
	{
		nhapTuFile(ds, FileIn);
	}
}

void Menu()
{
	cout << "================================Library UIT=======================================\n";
	cout << "= 0. Tat app						                         =\n";
	cout << "= 1. Them sach vao thu vien							 =\n";
	cout << "= 2. Muon sach thu vien								 =\n";
	cout << "= 3. Tra sach thu vien								 =\n";
	cout << "= 4. Hien thi thong tin cua sach						 =\n";
	cout << "= 5. Hien thi thong tin cua tat ca sach dang co trong thu vien			 =\n";
	cout << "= 6. Xoa sach									 =\n";
	cout << "==================================================================================\n";

}
int Chon()
{
	int n;
	cin >> n;
	if (n >= 0 && n <= 5)
		return n;
	else
	{
		cout << "Yeu cau khong hop le, vui long nhap lai!";
		return Chon();
	}
}
void Xuli(douList& ds)
{
	NguoiMuonSach ms;
	QuanThu q;
	User u;
	int chon = Chon();
	switch (chon)
	{
	case 0:
		exit(1);
		break;
	case 1:
		q.Nhap(ds);
		cout << "Ban da them mot quyen sach\n";
		break;
	case 2:
		ms.muonSach(ds);
		break;
	case 3:
		ms.traSach(ds);
		break;
	case 4:
		//		cout << "Thong tin cua cac quyen sach dang co trong thu vien la: \n";
		u.timSach(ds);
		break;
	case 5:
		u.xuatToanBo(ds);
		break;
	case 6:
		q.xoaViTriK(ds);
		break;
	}
}


int main()
{
	ifstream File;
	File.open("dataThuVien.txt");
	Book b;
	douList ds;
	khoiTao(ds);
	User u();
	Menu();
	loadData(File, ds);
	while (true)
	{
		cout << "Lua chon cua ban la: ";
		Xuli(ds);
	}
	File.close();
}