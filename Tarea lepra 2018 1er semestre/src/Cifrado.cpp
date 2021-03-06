#include "Cifrado.h"


Cifrado::Cifrado():Base()
{
}

Cifrado::Cifrado(string x, string y):Base(x,y)
{
}

Cifrado::~Cifrado()
{
    //dtor
}


string Cifrado::Comienza(string x, string y)
{
    //Se comprueba si, el mensaje posee simbolo o minusculas, y/o , si la clave posee simbolos, minusculas o espacios
    if(Comprobar_error_mensaje(x) == true || Comprobar_error_clave(y) == true){
        cout << "E R R O R" << endl;
        return "";
    }
    else{
            // Se repite la clave hasta que el n� de caracteres supere el n� de caracteres del mensaje
            do{
                y = y + y;
            }while(x.length() > y.length());
            string aux = "";
            int contar_espacios = 0; //Se utiliza para contar el numero de espacios a medida que se recorre el mensaje
            for(int i = 0; i<x.length(); i++){
                    if(x[i] != ' '){
                            if((char_to_number(x[i]) +char_to_number(y[i - contar_espacios])) < 26){                        //Operacion
                                aux += number_to_char(char_to_number(x[i]) + char_to_number(y[i - contar_espacios]) );      //Operacion
                            }
                            else{
                                aux += number_to_char(char_to_number(x[i]) + char_to_number(y[i - contar_espacios]) - 26 ); //Operacion
                            }

                        Procedimiento(x[i],y[i-contar_espacios],aux[i],i);
                    }
                    else{
                        contar_espacios++;
                        aux += " ";
                    }
            }
            SetMensaje(aux); // Guarda el mensaje cifrado
            cout << endl << endl;
            cout << "Mensaje: " << aux << endl;
            cout << endl;
            return aux;
    }
}


