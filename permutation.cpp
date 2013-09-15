#include<iostream>
#include<string>
#include<vector>

using namespace std;
typedef vector<string> Slist;
typedef Slist::iterator SIter;

int factorial(int n)
{
	int val = 1;
	while(n>0) {
	  val *= n--;
	}
 	return val;
}

string all_but(char c, string s)
{
	return s.erase(s.find(c),1);
}

void append_c_to_list(Slist& subList, char c, Slist& newList)
{
	for(int i= 0; i <subList.size(); ++i)
	{
	    char cstr[2] ={c, '\0'};
		string s(cstr);
		newList.push_back(s.append(subList[i]));
	}
}

void appendList(string s, Slist& sList)
{

	for (int i=0; i< s.size(); ++i)
	{
		Slist subList;
		if(s.size() == 2){
		  //add as is the current string
		  sList.push_back(s);
		  //add the reverse of the current string
		  char rev[3] ={s[1], s[0], '\0'};
		  string r(rev);
		  sList.push_back(r);
		  return;
		}
		
		char c = s[i];
		string all_but_c = all_but(c,s);
		subList.clear();
		appendList(all_but_c, subList);
		append_c_to_list(subList, c, sList);
	}

	return;
}


void dumpList(Slist& l)
{
  SIter it;
  int i=1;
  for(it=l.begin(); it != l.end(); ++it) {
		cout<<i++<<".  "<<*it<<endl;
  }
}

main()
{
	Slist perm;
	string s("abcd");
	appendList(s, perm);
	cout<<"String : "<<s<<"   Expected permutations:  "<< factorial(s.size()) <<endl;
	dumpList(perm);
}