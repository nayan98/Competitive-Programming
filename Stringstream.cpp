#include <sstream>
#include<iostream>

using namespace std;

int main() {
  
   //It splits the string on space by default.
   stringstream s("hi hello namaste");
   string si;
   
   while(s>>si)
   cout<<si<<endl;
   //output-
   //hi
   //hello
   //namaste
   
   //Use of str function
   stringstream s1;
   s1.str("Hello hi namaste");
   cout<<s1.str()<<endl;
   //output
   //Hello hi namste
   
   //Converting string into numbers
   
   stringstream s2("123");
   int x;
   s2>>x;
   cout<<x<<endl;
   //output
   //123 - as a integer
   
   //if you are trying to split string of integers and store it in integers
   stringstream s3("1 2 3");
   int x1;
   while(s3>>x1)
   cout<<x1<<endl;
   //output
   //1
   //2
   //3
   
   
   stringstream s4("1,2,3");
   int x2;
   char ch;
   s4>>x2;
   s4>>ch;
   cout<<x2<<endl;
   s4>>x2;
   s4>>ch;
   cout<<x2<<endl;
   s4>>x2;
   s4>>ch;
   cout<<x2<<endl;
   
   //output
   //1
   //2
   //3
   
   //splitting ',' separated integer string with loop
   stringstream s6("1,2,3");
   //int x2;
   //char ch;
   while(s6>>x2>>ch)
   cout<<x2<<endl;
   cout<<ch<<endl;
   cout<<x2<<endl;//this extra cout is for last integer because it will get stored in x2 but eof will reach due to ch after that 
   //so loop will end.
   
   //output
   //1
   //2
   //3
   
   
   
   
   // this will show that string stream by default splits on spaces therefore space before 2 will not be there
   stringstream s5("1,    2,3");
   int x3;
   
   s5>>x3;
   s5>>ch;
   cout<<x3<<endl;
   s5>>x3;
   s5>>ch;
   cout<<x3<<endl;
   s5>>x3;
   s5>>ch;
   cout<<x3<<endl;
   
   //Splitting ',' separated string using getline 
   string input = "abc,def,ghi";
   stringstream ss(input);
   string token;

while(getline(ss, token, ',')) {
    cout << token << '\n';
}
   
   
   
   
}
