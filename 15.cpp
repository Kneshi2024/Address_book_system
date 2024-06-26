#include<iostream>
using namespace std;
#define MAX 1001//通讯录最多存1000个

//界面函数
void showmenu(){
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

};
//定义人的信息结构体
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
//添加通讯录名单
void addaddress(struct addressbook* abs) {
	if (abs->size >= MAX-1) {
		cout << "通讯录已满，无法输入" << endl;
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->arry[abs->size].name = name;
		//性别
		int sex = 0;
		while (true) {
			cout << "请输入性别" << endl;
			cout << "1----男" << endl;
			cout << "2----女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}
		abs->arry[abs->size].sex = sex;
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->arry[abs->size].age = age;
		//手机号
		string phone;
		cout << "请输入手机号" << endl;
		cin >> phone;
		abs->arry[abs->size].phone = phone;
		//住址
		string adress;
		cout << "请输入住址" << endl;
		cin >> adress;
		abs->arry[abs->size].address = adress;
		abs->size++;
		cout << "添加成功" << endl;
	}

	system("pause");
	system("cls");
}
//显示通讯录名单
void showperson(struct addressbook* abs) {
	if (abs->size <= 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0;i < abs->size;i++) {
			cout << "姓名: " << abs->arry[i].name << "\t";
			cout << "性别: " << (abs->arry[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄: " << abs->arry[i].age <<"\t";
			cout << "电话: " << abs->arry[i].phone <<"\t";
			cout << "住址: " << abs->arry[i].address << endl;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}
//判断联系人是否存在(存在返回size的值、不存在返回-1)
int isexist(struct addressbook* abs, string name) {
	for (int i = 0;i < abs->size;i++) {
		if (abs->arry[i].name == name) {
			return i;
		}
	}
	return -1;
};
//根据姓名删除通讯录联系人
void deleteperson(struct addressbook* abs) {
	cout << "你要删除的联系人姓名是:" << endl;
	string name1;
	cin >> name1;
	int ret = isexist(abs, name1);
	if (ret != -1) {
		for (int i = ret;i < abs->size;i++) {
			abs->arry[i] = abs->arry[i+1];
		}
		cout << "删除成功" << endl;
		abs->size--;
	}
	else {
		cout << "查无此人" << endl;
	}
		system("pause");
		system("cls");
}
//查找联系人
void findperson(struct addressbook* abs) {
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret!=-1) {
		cout << "查到此人" << endl;
		cout << "此人的联系方式为" << endl;
		cout << "  姓名:" << abs->arry[ret].name 
			 << "  性别:" << (abs->arry[ret].sex == 1 ? "男" : "女")
			 << "  年龄:" <<abs->arry[ret].age
			 << "  电话:" <<abs->arry[ret].phone
			 << "  住址:" <<abs->arry[ret].address<< endl;
	}
	else {
		cout << "为查到此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyperson(struct addressbook* abs) {
	cout << "请输入你要修改的姓名:" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if(ret!=-1){
		cout << "请输入你要修改的姓名:" << endl;
		string name;
		cin >> name;
		abs->arry[ret].name = name;
		int sex;
		while (true) {
			cout << "请输入你要修改的性别:" << endl;
			cout << "1——男" << endl;
			cout << "2——女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->arry[ret].sex = sex;
				break;
			}
			else {
				cout << "输入错误，请重新输入" << endl;
			}
		}
		cout << "请输入你要修改的年龄:" << endl;
		int age;
		cin >> age;
		abs->arry[ret].age = age;
		cout << "请输入你要修改的电话:" << endl;
		string phone;
		cin >> phone;
		abs->arry[ret].phone = phone;
		cout << "请输入你要修改的住址:" << endl;
		string adress;
		cin >> adress;
		abs->arry[ret].address = adress;
		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人无法修改" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanperson(struct addressbook* abs) {
	cout << "是否真的要清空？" << endl;
	cout << "是请按——1" << endl;
	cout << "否请按——2" << endl;
	int sure;
	cin >> sure;
	if (sure == 1) {
		abs->size = 0;
		cout << "通讯录已清空" << endl;
	}
	system("pause");
	system("cls");
}
int main() {
	//创建通讯录
	struct addressbook abs;
	abs.size = 0;//初始化数量

	while (1) {
		//调用界面函数
		showmenu();
		//选择程序
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			addaddress(&abs);//1、添加联系人
			break;
		case 2:
			showperson(&abs);//2、显示联系人
			break;
		case 3: 
			deleteperson(&abs);
			/*cout << "请输入联系人名称" << endl;
			string name;
			cin >> name;
			int ret = isexist(&abs, name);//3、删除联系人
			if (ret == -1) {
				cout << "查无此人" << endl;
			}
			else {
				cout << "找到此人" << endl;
			}
			system("pause");
			system("cls");
		}*/
			break;
		case 4:
			findperson(&abs);//4、查找联系人
			break;
		case 5:
			modifyperson(&abs);//5、修改联系人
			break;
		case 6:
			cleanperson(&abs);//6、清空联系人
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
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