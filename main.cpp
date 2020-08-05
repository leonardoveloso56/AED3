#include <iostream>
#include<vector>
#include<string>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
	
	int op = 0;
	vector<string> piadas;
	string piada="";
	int i = 0;
	
	do
	{
	
	cout<<"\t\t\tPiadinhas!\n\n";
	
	cout<<"Piadas Cadastradas "<<piadas.size()<<"\n\n";
	
	cout<<"1)- Cadastrar Piadas\n";
	cout<<"2)- Contar Piada\n";
	cout<<"3)- Sair\n\n";
	cout<<"Digite a opcao:";
	cin>>op;
	
	switch(op)
	{
		
	case 1:
		cout<<"Escreva sua piada:";
		cin.ignore(); getline(cin,piada);
		piadas.push_back(piada);
		piada="";
		system("cls");
		break;
	case 2:
		if(piadas.size()==0)
		{
			cout<<"\nNao existe piadas cadastradas\n\n";
			system("pause");
			system("cls");
		}
		else
		{
			srand((unsigned)time(0));
			i = rand()%(piadas.size());
			cout<<"\n\n"<<piadas[i]<<"\n\n";
			system("pause");
			system("cls");
		}
		
		break;
	
	default:
		if(op==3)
			cout<<"\n\nAte mais!...\n\n";
		else
		cout<<"\n\nOpcao Incorreta, Tente Novamente!\n\n";
		system("pause");
		system("cls");
		break;
	}
	
	}while(op!=3);
	
	
	return 0;
}