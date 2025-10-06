#include <iostream>
#include <iomanip>

using namespace std;


void menu (){
    int opcio;

    switch(opcio){

        case 00:

        break;

        case 01:
            cout << setfill('*') <<setw(20)<< endl;
            cout << "* 01: Llegir dades *" << endl;
            cout << setfill('*') <<setw(20)<< endl;
            cout << "Numero de linies: " << mob.llegirDades() << endl;
            break;

        case 02:
            int opcio_dist;
            cout << setfill('*') <<setw(25)<< endl;
            cout << "* 02: Nombre transports *" << endl;
            cout << setfill('*') <<setw(25)<< endl;
            cin>> opcio_dist;
                switch(opcio_dist){
                     case 1:
                        cout << "Distància Menys de 500 metres ==> "<< mob.nombretransports[opcio_dist] << endl; //mostrar el vector de transports,
                        cout << setfill('*') <<setw(25)<< endl;
                     break;

                     case 2:
                        cout << "Distància De 500 a 2.000 metres ==> "<< mob.nombretransports[opcio_dist] << endl; //mostrar el vector de transports,
                        cout << setfill('*') <<setw(25)<< endl;
                     break;

                     case 3:
                        cout << "Distància De 2.000 a 5.000 metres ==> "<< mob.nombretransports[opcio_dist]  << endl; //mostrar el vector de transports,
                        cout << setfill('*') <<setw(25)<< endl;
                     break;

                     case 4:
                        cout << "Distància De 5.000 a 10.000 metres ==> "<< mob.nombretransports[opcio_dist]  << endl; //mostrar el vector de transports,
                        cout << setfill('*') <<setw(25)<< endl;
                     break;

                     case 5:
                        cout << "Distància De 10.000 a 50.000 metres ==> "<< mob.nombretransports[opcio_dist] << endl; //mostrar el vector de transports,
                        cout << setfill('*') <<setw(25)<< endl;
                     break;

                     case 6:
                        cout << "Distància De 50.000 a 100.000 metres ==> "<< mob.nombretransports[opcio_dist] << endl; //mostrar el vector de transports,
                        cout << setfill('*') <<setw(25)<< endl;
                     break;

                     case 7:
                        cout << "Distància Més de 100.000 metres ==> "<< mob.nombretransports[opcio_dist] << endl; //mostrar el vector de transports,
                        cout << setfill('*') <<setw(25)<< endl;
                     break;

                     case default:
                         cerr << "error en el switch de distancia";
                     break;

                }
            break;

        case 03:
            int opcio_dist;
            cout << setfill('*') <<setw(37)<< endl;
            cout << "* 03: Nombre persones per transport *" << endl;
            cout << setfill('*') <<setw(37)<< endl;
            cin>> opcio_dist;

                switch(opcio_dist){
                     case 1:
                        cout << "Distància Menys de 500 metres "<< endl; //mostrar el vector de transports,
                        vector <pair <string int>> v;
                        v = mob.ombrePersonesPerTransport(opcio_dist);
                        for (auto i:v){
                            cout << i << " : " <<v.first << " => " << v.second;
                        }
                     break;

                     case 2:
                        cout << "Distància De 500 a 2.000 metres "<< mob.nombrePersonesPerTransport << endl; //mostrar el vector de transports,
                        vector <pair <string int>> v;
                        v = mob.ombrePersonesPerTransport(opcio_dist);
                        for (auto i:v){
                            cout << i << " : " <<v.first << " => " << v.second;
                        }
                     break;

                     case 3:
                        cout << "Distància De 2.000 a 5.000 metres "<< mob.nombrePersonesPerTransport << endl; //mostrar el vector de transports,
                        vector <pair <string int>> v;
                        v = mob.ombrePersonesPerTransport(opcio_dist);
                        for (auto i:v){
                            cout << i << " : " <<v.first << " => " << v.second;
                        }
                     break;

                     case 4:
                        cout << "Distància De 5.000 a 10.000 metres "<< mob.nombrePersonesPerTransport << endl; //mostrar el vector de transports,
                        vector <pair <string int>> v;
                        v = mob.ombrePersonesPerTransport(opcio_dist);
                        for (auto i:v){
                            cout << i << " : " <<v.first << " => " << v.second;
                        }
                     break;

                     case 5:
                        cout << "Distància De 10.000 a 50.000 metres "<< mob.nombrePersonesPerTransport << endl; //mostrar el vector de transports,
                        vector <pair <string int>> v;
                        v = mob.ombrePersonesPerTransport(opcio_dist);
                        for (auto i:v){
                            cout << i << " : " <<v.first << " => " << v.second;
                        }
                     break;

                     case 6:
                        cout << "Distància De 50.000 a 100.000 metres "<<mob.nombrePersonesPerTransport<< endl; //mostrar el vector de transports,
                        vector <pair <string int>> v;
                        v = mob.ombrePersonesPerTransport(opcio_dist);
                        for (auto i:v){
                            cout << i << " : " <<v.first << " => " << v.second;
                        }
                     break;

                     case 7:
                        cout << "Distància Més de 100.000 metres "<< << endl; //mostrar el vector de transports,
                        vector <pair <string int>> v;
                        v = mob.ombrePersonesPerTransport(opcio_dist);
                        for (auto i:v){
                            cout << i << " : " <<v.first << " => " << v.second;
                        }
                     break;

                     case default:
                         cerr << "error en el switch de distancia";
                     break;
                }
            break;

        case 04:
             vector <pair <string double>> v;
                        v = mob.mesRapid();
            cout << setfill('*') <<setw(20)<< endl;
            cout << "* 04: Més ràpid *" << endl;
            cout << setfill('*') <<setw(20)<< endl;

            cout<<"Menys de 500 metres : "<<v.at(1).first<<" => " <<v.at(1).second<<endl;
            cout<<"De 500 a 2.000 metres : "<<v.at(2).first <<" => "<<v.at(2).second<<endl;
            cout<<"De 2.000 a 5.000 metres : "<<v.at(3).first <<" => "<<v.at(3).second<<endl;
            cout<<"De 5.000 a 10.000 metres : "<<v.at(4).first <<" => "<<v.at(4).second<<endl;
            cout<<"De 10.000 a 50.000 metres : "<<v.at(5).first <<" =>"<<v.at(5).second<<endl;
            cout<<"De 50.000 a 100.000 metres : "<<v.at(6).first <<" => "<<v.at(6).second<<endl;
            cout<<"Més de 100.000 metres : "<<v.at(7).first <<" => "<<v.at(7).second<<endl;

       default:
            cout << "*  Opcio invalida  *" << endl;
            cout << "********************" << endl;
        break;

        }
    }

main (){

Mobilitat mob;
menu();

return 0;
}
