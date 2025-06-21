#include <bits/stdc++.h>
using namespace std;
struct Node{
   int data;
   char ch;
   Node*left;
   Node*right;
};
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
Node*create(int data,char ch,Node*left,Node*right)
{
   Node*nnode=new Node;
   nnode->data=data;
   nnode->ch=ch;
   nnode->left=left;
   nnode->right=right;
   return nnode;
}
string find(Node*root,string temp)
{
   Node*z=root;
   string ans="";
   for(auto it:temp)
   {
      if(it=='0')
      {
         z=z->left;
      }
      else z=z->right;

      if(!z->left && !z->right)
      {
         ans+=z->ch;
         z=root;
      }
   }
   return ans;
}
void encode(Node*root,unordered_map<char,string>&mp,string s)
{
  if(!root) return ;
  if(!root->right && !root->left)
  {
    mp[root->ch]=s;
    return ;
  }
  encode(root->left,mp,s+"0");
  encode(root->right,mp,s+"1");
}
void func(string s)
{
  unordered_map<char,int>mpp;
  for(auto it:s)
  {
     mpp[it]++;
  }
  priority_queue<Node*,vector<Node*>,Compare>pq;
  for(auto it:mpp)
  {
     pq.push(create(it.second,it.first,NULL,NULL));
  }
  while(pq.size()>1)
  {
     Node*left=pq.top();
     pq.pop();
     Node*right=pq.top();
     pq.pop();
     pq.push(create(left->data+right->data,'\0',left,right));
  }
  Node*root=pq.top();
  unordered_map<char,string>mp;
  encode(root,mp,"");
  string ans="";
  for(auto it:s)
  {
    ans+=mp[it];
  }
  cout<<ans<<endl;
  cout<<"The decoded string is"<<endl;
  cout<<fin(root,ans);
}
string fin(Node*root,string ans)
{
     Node*temp=root;
    string an="";
    for(int i=0;i<ans.length();i++)
    {
      if(ans[i]=='0')
      {
         temp=temp->left;
      }
      else {
         temp=temp->right;
      }
      if(!temp->left && !temp->right)
      {
         an+=temp->ch;
         temp=root; 
      }
    }
   return an;
   }
int main()
{
  string s;
  cin>>s;
  func(s);
  return 0;
}