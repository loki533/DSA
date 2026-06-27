#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data1,Node *next1){
            data=data1;
            next=next1;
        }

        Node(int data1){
            data=data1;
            next=nullptr;
        }
    };

Node* convert_arr_to_LL(vector<int> &arr){
    Node* dummynode=new Node(-1);
    Node* temp = dummynode;

    for(int i=0;i<arr.size();i++){
        temp->next =new Node(arr[i]);
        temp = temp->next;
    }

    return dummynode->next;

}

Node* sorttwolinkedlist(Node* list1,Node* list2){
    vector<int> arr1;
    Node* temp1 = list1;
    Node* temp2 = list2;

    while(temp1 != NULL){
        arr1.push_back(temp1->data);
        temp1= temp1->next;
    }

    while(temp2!=NULL){
        arr1.push_back(temp2->data);
        temp2=temp2->next;
    }

    sort(arr1.begin(),arr1.end());

    return convert_arr_to_LL(arr1);
            
    
}


// optimal approach -> in-place merging

Node* Merge2sorted(Node *list1,Node *list2){
    Node* dummy = new Node(-1);
    Node* New_LL = dummy;

    while(list1!=NULL && list2!=NULL){
        if(list1->data<list2->data){
            New_LL->next=list1;
            list1=list1->next;
        }

        else{
            New_LL->next=list2;
            list2=list2->next;
        }
        New_LL=New_LL->next;
    }

    if(list1!=NULL){ //link the remaining
            New_LL->next=list1;
        }


    else{
        
            New_LL->next=list2;
        }


    return dummy->next;
}

