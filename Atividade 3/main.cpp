#include <iostream>
#include <stdlib.h>
using namespace std;

class celula
{
private:
	
	string nome;
	string sexo;
	int idade;
	bool bebida;
	celula * proxima;
	
public:
	celula()
	{
		proxima = NULL;
	}
	
	celula(string n)
	{
		nome = n;
	}
	
	celula(string n, celula *p)
	{
		nome = n;
		proxima = p;
	}
	
	celula (string n, string s, int id, bool b, celula *p)
	{
		nome = n;
		sexo = s;
		idade = id;
		bebida = b;
		proxima = p;   	
	}
	
	string getNome()
	{
		return nome;
	}
	
	string getSexo()
	{
		return sexo;
	}
	
	int getIdade()
	{
		return idade;
	}
	
	bool getBebida()
	{
		return bebida;
	}
	
	void setNome(string n)
	{
		nome = n;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
	
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	~lista(){
		esvaziar();
	}
	lista(celula *i)
	{
		inicio = i;
	}
	celula * getInicio()
	{
		return inicio;
	}

	void inserirInicio(string nome, string sexo, int idade, bool bebida)
	{
		celula *nova = new celula(nome, sexo, idade, bebida, inicio);
	//	nova->setNome(n);
	//	nova->setProxima(inicio);
	//	nova->setMediaFinal(m);
		inicio = nova;
	}

	void inserirFim(string nome, string sexo, int idade, bool bebida)
	{
		if(inicio == NULL)
		{
			inserirInicio(nome, sexo, idade, bebida);
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			celula *nova = new celula(nome, sexo, idade, bebida, NULL);
			aux->setProxima(nova); 
		}
	}


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout <<"Nome: "<< aux->getNome() << " Sexo: " << aux->getSexo() << " Idade: " << aux->getIdade() << " Vai beber?"; 
				if(aux->getBebida()==1)
					cout<<" Sim "<<endl;
				else
					cout<<" Nao "<<endl;

				aux = aux->getProxima();
			}
		}
	}
	
	void esvaziar(){
		celula *aux = inicio;
		while(aux != NULL){
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\n----Memoria liberada----\n";
	}
};

int main()
{
	lista listaChurras;
	int op=0;
	string nome, sexo;
	int idade,aux;
	bool bebida;
	do
	{
		cout << "\t\t\tLista do Churrasco\n\n";
		
		cout<<"1_Cadastrar Pessoa.\n";
		cout<<"2_Imprimir Lista.\n";
		cout<<"3_Apagar Lista.\n";
		cout<<"4_Encerrar Programa.\n\n";
		cout<<"Opcao:";
		cin>>op;
		
		switch(op)
		{
		case 1:
			system("cls");
			cout << "\t\t\tCadastrar Pessoa\n\n";
			cout<<"Nome:";cin.ignore();cin>>nome;
			cout<<"Sexo:";cin.ignore();cin>>sexo;
			cout<<"Idade:";cin>>idade;
			cout<<"Ira beber? (1) sim (2) nao:";cin>>aux;
			if(aux==1)
			bebida = true;
			else
			bebida = false;
		
			listaChurras.inserirInicio(nome,sexo,idade,bebida);
			
			cout<<"\n\nCadastro Realizado!!!\n";
			system("pause");system("cls");
					
			break;
		case 2:
			system("cls");
			cout << "\t\t\tImprimir Lista\n\n";
			listaChurras.imprimir();
			cout<<"\n\n"; system("pause");system("cls");
			
			break;
		case 3:
			listaChurras.esvaziar();
			cout<<"\n\n"; system("pause");system("cls");
			break;
		case 4:
			cout<<"\n\nAte logo...\n"; system("pause");
			break;
		default:
			cout<<"\n\nOpcao Invalida!!!\n"; system("pause");system("cls");
			break;
		}
		
		
		
	}while(op!=4);
	

	return 0;
}