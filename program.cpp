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
	stackiter* createtraversal();

};

class stackiter{
    const	stack* stck;
	int index=0;
	public:
    stackiter(stack* stck):stck(stck){
        
    }
	void first(){
		index=0;
	}
	void next(){
		index++;
	}
	
	bool isdone(){
		return index==stck->sp+1;
	}
	
	int currentitem(){
		return stck->st[index];
	}
}; 

bool operator == (stack &st1,stack &st2){
	
	stackiter *it1=st1.createtraversal(), *it2=st2.createtraversal();
	
	for(it1->first(),it2->first();!it1->isdone()&&!it2->isdone();it1->next(),it2->next()){
		if(it1->currentitem()!=it2->currentitem()){
		  return 0;
		}
		
	}
	
	bool ans = it1->isdone()&&it2->isdone();
	delete it1;
	delete it2;
	return ans;
}
stackiter* stack::createtraversal(){
		return new stackiter(this);
	}

int main(){
	
	stack s1,s2;
	s1.push(5);
	s2.push(5);
	s1.push(5);
	s1.push(6);
	s1.pop();
	s2.push(5);
	if(s1==s2){
		cout<<"same";
	}else{
		cout<<"diff";
	}
	
}