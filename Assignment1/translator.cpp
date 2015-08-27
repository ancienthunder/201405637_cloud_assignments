#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <map>
#include <fstream>
#define ll long long
#define ull unsigned long long
#define FOR(i, n) for (int i = 0; i < n; i++)
#define si(x) scanf("%d", &x);
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	ofstream myfile;	
	string line;
	ifstream file("32bit_hello.asm");
	myfile.open("64bit_converted_hello.asm");
	if(file.is_open())
	{
		while ( getline (file,line) )
    	{
    		if(line.find("extern printf") != -1  || line.find("popad") != -1 || line.find("push dword message") != -1)
    		{
    		}
    		else
    		{
    			int pos;
    			if(line.find("global main") != string::npos)
    			{
    				pos = line.find("global main");
    				line.replace(pos, -1, "global _start");
    				myfile<<line<<"\n";
    			}
    			else if(line.find("main:") != string::npos)
    			{
    				pos = line.find("main:");
    				line.replace(pos, -1, "_start:");
    				myfile<<line<<"\n";
    			}
    			else if(line.find("pushad") != string::npos)
    			{
    				pos = line.find("pushad");
    				line.replace(pos, -1, "mov rax, 1");
    				myfile<<line<<"\n";
    				line.replace(pos, -1, "mov rdi, 1");
    				myfile<<line<<"\n";
    			}
    			else if(line.find("call printf") != string::npos)
    			{
    				pos = line.find("call printf");
    				line.replace(pos, -1, "mov rsi, message");
    				myfile<<line<<"\n";
    				line.replace(pos, -1, "mov rdx, 13");
    				myfile<<line<<"\n";
    				line.replace(pos, -1, "syscall");
    				myfile<<line<<"\n";
    			}
    			else if(line.find("add esp, 4") != string::npos)
    			{
    				pos = line.find("add esp, 4");
    				line.replace(pos, -1, "mov rax, 60");
    				myfile<<line<<"\n";
    				line.replace(pos, -1, "mov rdi, 0");
    				myfile<<line<<"\n";
    			}
    			else if(line.find("ret") != string::npos)
    			{
    				pos = line.find("ret");
    				line.replace(pos, -1, "syscall");
    				myfile<<line<<"\n";
    			}
    			else
    				myfile<<line<<"\n";
    		}

    	}
    	file.close();
	}
	else
		cout<<"Could not open file"<<endl;
	myfile.close();

	return 0;
}