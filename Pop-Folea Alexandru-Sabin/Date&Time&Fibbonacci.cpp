#include <iostream>
#include <ctime>
#include <thread>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void Dateandtime(int N)

 {

	time_t now = time(0);
	tm *ltm = localtime(&now);
	cout << ltm->tm_mday <<" / "<< 1 + ltm->tm_mon<<" / "<< 1900 + ltm->tm_year<<" - "<<2 + ltm->tm_hour << ":"<<0 + ltm->tm_min<< endl;
 }

class fib {
	public:
		void operator()(int n) {

			int n1=0,n2=1,n3,i;
			cout<<"Primele 10 valori din Sirul lui Fibonacci: ";
			cout<<n1<<" "<<n2<<" "; 
 for(i=2;i<10;++i)    
 {    
  n3=n1+n2;    
  cout<<n3<<" ";    
  n1=n2;    
  n2=n3;    
 }
 cout<<endl;
   };
 
};

int main()

{
thread th1(Dateandtime, 1);
thread th2(fib(), 1);
th1.join();
th2.join();
return 0;

}