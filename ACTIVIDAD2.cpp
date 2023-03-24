#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

float suma(float, float);
float resta(float, float);
float multiplicacion(float, float);
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();

int main(){
    int opg;
    do{
        cout<<"\nOptions menu:\n1.-Exercise 1\n2-Exercise 2\n3.-Exercise 3\n4.-Exercise 4\n5.-Exercise 5\n6.-Exit"<<"\nEnter an option: ";
        cin>>opg;
        switch (opg)
        {
        case 1:ejercicio1();
            break;
        case 2:ejercicio2();
            break;
        case 3:ejercicio3();
            break;
        case 4:ejercicio4();
            break;
        case 5:ejercicio5();
            break;
        case 6:cout<<"Logging out of the system...";
            break;
        default:cout<<"Invalid opcion"<<endl;
            break;
        }
    } while (opg!=6);
    
    return 0;
}

void ejercicio1(){
    float a,b,op,resultado;
    cout<<"Exercise 1\n";
    cout<<"Give me the first number: ";
    cin>>a;
    cout<<"Give me the second number: ";
    cin>>b;
    do{
        cout<<"1.-Sum\n2.-Substraction\n3.-Multiplication\n0.-Exit\nEnter the desired option: ";
        cin>>op;
        if (op==0){ 
            cout<<"Leaving exercise 1..."<<endl;
        }
        
        else if (op==1){
            resultado=suma(a,b);
            cout <<"The result of the sum is: "<< resultado << endl;
        }
        else if (op==2){
            resultado=resta(a,b);
            cout <<"The result of the subtraction is: "<< resultado << endl;
        }
        else if (op==3){
            resultado=multiplicacion(a,b);
            cout <<"The result of multiplication is: "<< resultado << endl;
        }
        else{
            cout<<"Wrong opcion: ";
        }
    }while (op!=0);
}

void ejercicio2(){
    int num;
    cout<<"\nExercise 2";
    cout<<"\nEnter an odd number: ";
    cin>>num;
    while (num%2==0){
        cout<<"Error the number is not odd";
        cout<<"\nEnter an odd number:";
        cin>>num;
    }
    cout<<"The number entered it is odd";
}

void ejercicio3(){
   float i=0,total=0;
   cout<<"\nExercise 3"<<endl;
   for(int i=0;i<=100;i++){
    if (i%2==0){
    total=total+i;
    }    
   }
   cout<<"The sum of all even numbers from 1 to 100 is: "<<total<<endl;
}


void ejercicio4(){
    float promedio=0,totaln=0,valor;
    cout<<"\nExercise 4"<<endl;
    cout<<"Enter the total values you want to enter: ";
    cin>>totaln;
    for (int j= 0; j<totaln; j++)
    {
        cout<<"Enter the "<<j+1<<" value: ";
        cin>>valor;
        promedio=promedio+valor;
    }
    promedio=promedio/totaln;
    cout<<"The average is: "<<promedio<<endl;
    }

void ejercicio5(){
    float r,num1=-1,i=1;
    cout<<"Exercise 5"<<endl;
    srand(time(0));
    r=rand()%100+1;
    while (num1!=r){
      cout<<"Enter your attempt "<<i<<" :";
      cin>>num1;
      i++;
      if(num1<r){
         cout<<"Error!,The magic number is bigger"<<endl;
      }
      else if(r<num1){
      cout<<"Error!,The magic number is smaller"<<endl;
      }
    }
    cout<<"You hit the magic numer "<<r<<" after "<<i<<" attempts."<<endl ;
}
float suma(float a,float b){
    float suma;
    suma=a+b;
    return suma;
}

float resta(float a,float b){
    float resta;
    resta=a-b;
    return resta;
}

float multiplicacion(float a,float b){
    float multi;
    multi=a*b;
    return multi;
}

