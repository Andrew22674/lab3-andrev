#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

bool paridad(int, int);//calcular "P" para el segundo ejercicio
void balanceado(string);
bool balance(vector<char>);
int main(){
	int menu = 0;

	while(menu != 3){
		cout << "Ingrese numero de ejercicio: " << endl << " 1. Ej1 \n 2. Ej2 \n 3. Salir";
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

				break;
 			}
		}
	}





	return 0;
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
		if (v2.empty()){
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

