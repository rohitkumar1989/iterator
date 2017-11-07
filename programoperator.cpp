#include<iostream>
#define MAX 20
using namespace std;
class stackiter;


class stack{
	friend class stackiter;
	int st[MAX];
	int sp=-1;
	
	public: 
	void push(int val){
		st[++sp]=val;
	}
	int pop(){
		return st[sp--];;
	}
	
	bool isempty(){
		if (sp==-1){
			return 1;
		}else{
			return 0;
		}
	}
	
	bool full(){
		if(sp==19){
			return 1;
		}else{
			return 0;
		}
		
	}


};

class stackiter{
    const	stack &stck;
	int index=0;
	public:
	stackiter(stack &stck):stck(stck){
	    
	}
	void operator ++ (int){
		index++;
	}
	
	bool operator () (){
		return index==(stck.sp)+1;
	}
	
	int operator *(){
		return stck.st[index];
	}
}; 

bool operator == (stack &st1,stack &st2){
	
	stackiter it1(st1), it2(st2);
	
	for(;!it1()&&!it2();it1++,it2++){
		if(*it1!=*it2){
		  return 0;
		}
		
	}
	
	bool ans = it1()&&it2();

	return ans;
}


int main(){
	
	stack s1,s2;
	s1.push(5);
	s2.push(5);
	s1.push(5);
	s1.push(6);
	//s1.pop();
	s2.push(5);
	if(s1==s2){
		cout<<"same";
	}else{
		cout<<"diff";
	}
	
}