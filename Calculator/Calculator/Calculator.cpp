
/*
   Calculator.cpp

   Simple Calculator



   Mustafa HATÝPOÐLU
 
*/



#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;


void title () 
{
    
    for (auto j{ 0 }; j < 40; ++j)
       cout << "#";
    cout << endl;
    
    for (auto j{ 0 }; j < 15; ++j)
       cout << "#";
   
    cout <<  "CALCULATOR" ;
   

    for (auto j{ 0 }; j < 15; ++j)
       cout << "#";
    cout << endl;

    for (auto j{ 0 }; j < 40; ++j)
       cout << "#";
    cout << endl;

}

class Term {  // Numbers and operators are stored together. Example : [5+][9*][100+][8]

  public:
     double number;
     char operation;

};


string sNumbers;  
vector <Term> terms;


   // The string which is given by user must add to vector so dynamic memory is used
void addToVector( string& s ) {
    
    Term temp;
    size_t i;

    while (1)
    {   
    
       temp.number = stod ( s, &i );  //"stod" set 'i' value to location of operation automatically
       
       if (s[i] == '\0')
       {
          temp.operation = '\0';   // We understand from NULL whether procedure is finished or not
       }

       else
       {
          temp.operation = s[i];
       }
       
       terms.push_back(temp);

       if ( temp.operation == '\0' )
          break;

       s = s.substr(i+1);
          
    }
    

}

   // Prints each elements of vector
void print(const vector<Term>& v)
{
   
   for ( const Term& i : v)
      cout << i.number << " " << i.operation;

   cout << endl;


}

  // if there is 1 element and also its operation equals '\0' -> it means calculation has completed
bool isFinish(const vector<Term>& v)
{
   return (v[0].operation == '\0');
}


double Multiply ( const double& a, const double& b ){ return a * b; }
double Divide( const double& a, const double& b ) { return a / b; }
double Add( const double& a, const double& b ) { return a + b; }
double Substract( const double& a, const double& b ) { return a - b; }



void calculate ( vector<Term>& v, const char& op )
{
   
   
   int counter_operator{0};

   while( 1 )
   {
      for (auto i = v.begin(); i != v.end(); ++i )
      {
      
         if ( i->operation == op )
         {
           if ( op == '*' )   // Term is calculated up to operator
              (i+1)->number = Multiply ( i->number, (i+1)->number );
           else if ( op == '/' )
              (i + 1)->number = Divide( i->number, (i + 1)->number );
           else if (op == '+')
              (i + 1)->number = Add( i->number, (i + 1)->number );
           else if (op == '-')
              (i + 1)->number = Substract( i->number, (i + 1)->number );
      
           v.erase ( i );  // After the erase, vector size must reduce by 1
           ++counter_operator;
           break;
         }
       
      }
      
      if ( counter_operator == 0 ) // If there are not any procedure, calculate stops
      {
      
         return;
      
      }
      else
      {
      
         counter_operator = 0;
      
      }
   }



}

int main()
{
 
  title();
  cout << endl << "Input An Equation : " << endl;
  cin >> sNumbers;
  system("cls");

  for ( auto i{0}; i < 2; ++i )  //
  {
    
     cout << "calculating .";
     Sleep(500);
     system( "cls" );

     cout << "calculating ..";
     Sleep(500);
     system ( "cls" );

     cout << "calculating ...";
     Sleep(500);
     system("cls");

  
  
  }
   
  addToVector( sNumbers );

  calculate( terms, '*' );
  //print( terms );
  calculate( terms, '/' );
  //print(terms);
  calculate( terms, '+' );
  //print(terms);
  calculate( terms, '-' );
  //print(terms);
 
  if ( isFinish(terms) )
     cout << "The Answer is : " << endl << terms[0].number << endl;
  else
     cout << "Failed :( " << endl << terms[0].number << endl;
     
   
       
      
  

  
}

