#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
	shared_ptr<ListNode<T>> jump;
};

shared_ptr<ListNode<int>> copy_list(shared_ptr<ListNode<int>>& head){
	if(!head){
		return nullptr;
	}
	// 1st we need copy node
	shared_ptr<ListNode<int>> p = head;
	while(p->next){
		shared_ptr<ListNode<int>> temp = make_shared<ListNode<int>>(ListNode<int>{p->data,p->next,nullptr});
		p->next = temp;
		p = temp->next;
	}
	// 2nd copy jump link
	p = head;
	while(p){
		if(p->jump){
			p->next->jump = p->jump->next;
		}
		p = p->next->next;
	}
	// restore next link
	p = head;
	shared_ptr<ListNode<int>> res = p->next;
	while(p->next){
		shared_ptr<ListNode<int>> tmp = p->next;
		p->next = tmp->next;
		p=tmp;
	}
	return res;
}

int main(){
	
}