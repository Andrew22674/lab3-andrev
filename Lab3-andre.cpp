#include <iostream>
#include <vector>
#include <cmath> 
#include <string>

using namespace std;

bool paridad(int, int);//calcular "P" para el segundo ejercicio
void balanceado(string); //determina si una secuencia de parentesis, corchetes y llaves estan balanceados
bool balance(vector<char>);//determina si hay la misma cantidad de (), [] y {}
void ej2(vector<int>, int, int);// codigo de Hamming

int main(){
	int menu = 0;

	while(menu != 3){
		cout << "Ingrese numero de ejercicio: " << endl << " 1. Ej1 \n 2. Ej2 \n 3. Salir";
		cout << endl;
		cin >> menu;


		switch(menu){
			case 1:{//balanceados
				cout << "Ingrese secuencia de parentesis, corchetes y llaves: " << endl;
				string secuencia;
				cin >> secuencia;
				balanceado(secuencia);
				break;
			}
			case 2:{
				vector<int> v;
				cout << "Ingrese bits: ";
				string leerbits;
				cin >> leerbits;
				for(int i = 0; i< leerbits.size();i++){
					int i2 = leerbits.at(i);
					if(i2 == 48){
						v.push_back(0);
					}else{
						v.push_back(1);
					}
				}

				for(int i = 0; i<v.size(); i++){
					cout << v[i];
				}
				int d = v.size();
				cout << endl << "d: " << d << endl;
				int p = 1;
				while(paridad(v.size(), p) == false){
					p += 1;
				}
				cout << endl << "p: " << p << endl;
				ej2(v, d, p);
				break;
 			}
			default:{
				return 0;
			}
		}
		cout << endl;
	}





	return 0;
}


void ej2(vector<int> v, int d, int p){
	int total = d + p;

	vector<int> reservados;
	vector<int> bitsfinal;
	cout << "reservados: " << endl;	
	for(int i =0; i< p; i++){
		reservados.push_back(pow (2,i));
		cout << reservados[i] << " ";
	}

	cout << endl;

	for(int i = 0; i< total; i++){
		bitsfinal.push_back(2);
	}

	for(int i = 0; i<bitsfinal.size(); i++){
		bool x = true;
		for(int j = 0; j < reservados.size(); j++){
			if(reservados[j] == i){
				x = false;
			}else{
				x = true;
			}
		}
		if(x == true){
			bitsfinal[i] = i;
		}
		x = true;
	}

	
	
}

bool paridad(int d, int p){
	if(pow (2,p) >= (d + p + 1)){
		return true;
	}
	else{
		return false;
	}
}



void balanceado(string secuencia){
	vector<char> v;

	for(int i = 0 ; i < secuencia.size(); i++){
		v.push_back(secuencia.at(i));

	}

	if(balance(v) == true){//si hay la misma cantidad de {} y [] y ()
		vector<char> v2;
		for(int i = 0; i<v.size(); i++){
			if(v.at(i) == '{' || v.at(i) == '(' || v.at(i) == '['){
				/*si el elemento en "i" del primer vector es uno de estos caracteres, se agrega al segundo vector*/
				v2.push_back(v.at(i));
			}else{
				/* si el elemento en "i" del primer vector es "}" y el ultimo elemento del segundo es "{", 
				se elimina el ultimo elemento del segundo vector, y lo mismo se hace con los otros elementos*/

				if(v.at(i) == '}' && v2.back() == '{' ){ 
					v2.pop_back();
				}
				else if(v.at(i) == ')' && v2.back() == '('){
					v2.pop_back();
				}
				else if(v.at(i) == ']' && v2.back() == '['){
                                        v2.pop_back();
                                }

			}
		}
		if (v2.empty()){//si el vector 2 esta vacio, significa que esta balanceado
			cout << "Balanceado";
		}else{
			cout << "No balanceado";
		}

	}else{
		cout << "No balanceado";
	}

	
	cout << endl;
	
}


bool balance(vector<char> v){
       	int llaves1 = 0, corchetes1 = 0, parentesis1 = 0;
       	int llaves2 = 0, corchetes2 = 0, parentesis2 = 0;

	for(int i = 0; i < v.size(); i++){
		if(v.at(i) == '{'){
			llaves1 += 1;
		}
		else if(v.at(i) == '}'){
			llaves2 += 1;
		}
		else if(v.at(i) == '('){
			parentesis1 += 1;
		}
		else if(v.at(i) == ')'){
			parentesis2 += 1;
		}
		else if(v.at(i) == '['){
			corchetes1 += 1;
		}
		else if(v.at(i) == ']'){
			corchetes2 += 1;
		}

	}
	if(llaves1 == llaves2 && corchetes1 == corchetes2 && parentesis1 == parentesis2){
		return true;
	}else{
		return false;
	}

}

