#include <iostream>
#include <unistd.h> 
#include <stdlib.h> 
#include <string> 
#include <sstream>


using namespace std;

int main()
{
	int flag=1;
	char buf[80];
	string a;
	string sTmp;

	while(flag==1)
	{
		getcwd(buf, sizeof(buf)); 
		cout<<"1033357_hw1"<<buf<<"> ";
		getline(cin,a);
	    istringstream istr(a);
		
		istr >> sTmp;  //get a word
		if(sTmp=="cd")
		{
			istr >> sTmp; //get a word	
			if(sTmp=="..")	
			{
				chdir("/home");
			}
			else
			{
			}
		}
		else
		{
			if(a=="exit")
			{
				cout<<"bye bye!"<<endl;
				flag=0;
			}
			else
			{
			      cout << "[CMD] "<<sTmp << " ";
			      if (istr.eof() == 0)
			      {
				     cout << "[ARGV] ";
			      }
			      while (istr.eof()==0)
			      {
				     istr >> sTmp; //get a word
				     cout << sTmp ;
				     if (istr.eof() == 0)
				     {
				           cout << ", ";
				     }
			      }
			      cout <<endl;
			}
		}
	}
	return 0;
}
