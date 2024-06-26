#include<iostream>
using namespace std;
#define MAX 1001//ͨѶ¼����1000��

//���溯��
void showmenu(){
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;

};
//�����˵���Ϣ�ṹ��
struct person {
	string name;
	int sex=0;
	int age=0;
	string phone;
	string address;
};

struct addressbook {
	struct person arry[MAX];
	int size=0;
};
//���ͨѶ¼����
void addaddress(struct addressbook* abs) {
	if (abs->size >= MAX-1) {
		cout << "ͨѶ¼�������޷�����" << endl;
	}
	else {
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->arry[abs->size].name = name;
		//�Ա�
		int sex = 0;
		while (true) {
			cout << "�������Ա�" << endl;
			cout << "1----��" << endl;
			cout << "2----Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}
		abs->arry[abs->size].sex = sex;
		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->arry[abs->size].age = age;
		//�ֻ���
		string phone;
		cout << "�������ֻ���" << endl;
		cin >> phone;
		abs->arry[abs->size].phone = phone;
		//סַ
		string adress;
		cout << "������סַ" << endl;
		cin >> adress;
		abs->arry[abs->size].address = adress;
		abs->size++;
		cout << "��ӳɹ�" << endl;
	}

	system("pause");
	system("cls");
}
//��ʾͨѶ¼����
void showperson(struct addressbook* abs) {
	if (abs->size <= 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0;i < abs->size;i++) {
			cout << "����: " << abs->arry[i].name << "\t";
			cout << "�Ա�: " << (abs->arry[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "����: " << abs->arry[i].age <<"\t";
			cout << "�绰: " << abs->arry[i].phone <<"\t";
			cout << "סַ: " << abs->arry[i].address << endl;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}
//�ж���ϵ���Ƿ����(���ڷ���size��ֵ�������ڷ���-1)
int isexist(struct addressbook* abs, string name) {
	for (int i = 0;i < abs->size;i++) {
		if (abs->arry[i].name == name) {
			return i;
		}
	}
	return -1;
};
//��������ɾ��ͨѶ¼��ϵ��
void deleteperson(struct addressbook* abs) {
	cout << "��Ҫɾ������ϵ��������:" << endl;
	string name1;
	cin >> name1;
	int ret = isexist(abs, name1);
	if (ret != -1) {
		for (int i = ret;i < abs->size;i++) {
			abs->arry[i] = abs->arry[i+1];
		}
		cout << "ɾ���ɹ�" << endl;
		abs->size--;
	}
	else {
		cout << "���޴���" << endl;
	}
		system("pause");
		system("cls");
}
//������ϵ��
void findperson(struct addressbook* abs) {
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret!=-1) {
		cout << "�鵽����" << endl;
		cout << "���˵���ϵ��ʽΪ" << endl;
		cout << "  ����:" << abs->arry[ret].name 
			 << "  �Ա�:" << (abs->arry[ret].sex == 1 ? "��" : "Ů")
			 << "  ����:" <<abs->arry[ret].age
			 << "  �绰:" <<abs->arry[ret].phone
			 << "  סַ:" <<abs->arry[ret].address<< endl;
	}
	else {
		cout << "Ϊ�鵽����" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyperson(struct addressbook* abs) {
	cout << "��������Ҫ�޸ĵ�����:" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if(ret!=-1){
		cout << "��������Ҫ�޸ĵ�����:" << endl;
		string name;
		cin >> name;
		abs->arry[ret].name = name;
		int sex;
		while (true) {
			cout << "��������Ҫ�޸ĵ��Ա�:" << endl;
			cout << "1������" << endl;
			cout << "2����Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->arry[ret].sex = sex;
				break;
			}
			else {
				cout << "�����������������" << endl;
			}
		}
		cout << "��������Ҫ�޸ĵ�����:" << endl;
		int age;
		cin >> age;
		abs->arry[ret].age = age;
		cout << "��������Ҫ�޸ĵĵ绰:" << endl;
		string phone;
		cin >> phone;
		abs->arry[ret].phone = phone;
		cout << "��������Ҫ�޸ĵ�סַ:" << endl;
		string adress;
		cin >> adress;
		abs->arry[ret].address = adress;
		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "���޴����޷��޸�" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanperson(struct addressbook* abs) {
	cout << "�Ƿ����Ҫ��գ�" << endl;
	cout << "���밴����1" << endl;
	cout << "���밴����2" << endl;
	int sure;
	cin >> sure;
	if (sure == 1) {
		abs->size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	system("pause");
	system("cls");
}
int main() {
	//����ͨѶ¼
	struct addressbook abs;
	abs.size = 0;//��ʼ������

	while (1) {
		//���ý��溯��
		showmenu();
		//ѡ�����
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			addaddress(&abs);//1�������ϵ��
			break;
		case 2:
			showperson(&abs);//2����ʾ��ϵ��
			break;
		case 3: 
			deleteperson(&abs);
			/*cout << "��������ϵ������" << endl;
			string name;
			cin >> name;
			int ret = isexist(&abs, name);//3��ɾ����ϵ��
			if (ret == -1) {
				cout << "���޴���" << endl;
			}
			else {
				cout << "�ҵ�����" << endl;
			}
			system("pause");
			system("cls");
		}*/
			break;
		case 4:
			findperson(&abs);//4��������ϵ��
			break;
		case 5:
			modifyperson(&abs);//5���޸���ϵ��
			break;
		case 6:
			cleanperson(&abs);//6�������ϵ��
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return(0);
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
	return(0);
}