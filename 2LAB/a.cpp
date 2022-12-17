# include <iostream>
# include <algorithm>
# include <cassert>
# include <cmath>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
void search(Node* head ,int k){   
    int x = 2147483647 , cnt = 0, ans, y;
    Node* current = head; 
    while (current != NULL) {
        if(k >=0 && current->val>=0){
            y = abs(current->val-k);
        }
        else if((current->val>=0 && k<0) || (current->val<0 && k>=0)){
            y = abs(abs(k)+abs(current->val));
        }
        else if(k<0 && current->val <0){
            y = abs(abs(current->val)-abs(k));
        }

        if (y < x){
            x = y;
            ans = cnt;
        }
        current = current->next; 
        cnt++;
    }
    cout<< ans;
    return;
}
 
int main() {
  int n, k;
  cin >> n;
 
  Node *head = NULL, *tail = NULL;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cin >> k;
  search(head, k);
  return 0;
}