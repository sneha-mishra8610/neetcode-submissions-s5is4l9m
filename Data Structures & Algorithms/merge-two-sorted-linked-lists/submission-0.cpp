class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(t1!=NULL||t2!=NULL){
            if(t1==NULL){
            temp->next=t2;
            t2=t2->next;
            temp=temp->next;
            }
            else if(t2==NULL){
            temp->next=t1;
            t1=t1->next;
            temp=temp->next;
            }else{
                if(t1->val>t2->val){
                    temp->next=t2;
                    t2=t2->next;
                    temp=temp->next;
                }else{            
                    temp->next=t1;
                    t1=t1->next;
                    temp=temp->next;
                }
            }
        }
        while(t1!=NULL){
            temp->next=t1;
            t1=t1->next;
            temp=temp->next;
        }
        while(t2!=NULL){
            temp->next=t2;
            t2=t2->next;
            temp=temp->next;
        }
        head=head->next;
        return head;
    }
};