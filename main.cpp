#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> to_int;
map<int, string> to_str;

int numeros[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char romanos[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

char* Romans(int num){
    char *romano = new char[30];
    char pos = 0;
    for( int i = 0; i < 13; i++) {
        while(num >= numeros[i] ) {
            num -= numeros[i];
            romano[pos++] = romanos[i][0];
            if(romanos[i][1] != '\0')
                romano[pos++] = romanos[i][1];
        }
    }
    romano[pos] = '\0';
    return romano;

}



int main() {
    int numero;
    char valor[50] ;
    char *letra  ;
    for(numero=1; numero <= 4000; numero++) {
        letra = Romans(numero);
        to_int[letra] = numero;
        to_str[numero] = letra;
        delete[] letra;
    }
    while(scanf("%s", valor) == 1) {
        if(valor[0] >= '0' && valor[0] <= '9') {
            sscanf(valor, "%d", &numero);
            cout << to_str[numero] << endl;
        } else
            cout << to_int[valor] << endl;
    }
    return 0;
}