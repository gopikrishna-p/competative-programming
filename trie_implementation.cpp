/*
**********************************
 * P.Gopikrishna                  *
 * K L University:)               *
 * Never Give up                  *
 * Hard work never fails:)        *
 *                                *
 *                                *                                                    
 * ********************************
 */
 ////Time complexity for search Q(length OF STRING)
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
 
struct node{
    
    bool is_end;
    int prefixcount;
    struct node* child[26];
}*head;
 
 
 void ini()
 {
     
     head =new node();
     head -> prefixcount=0;
     head-> is_end=false;
  }
 void insert(string word)
 {
     node* current=head;
     current->prefixcount++;
     for(int i=0;i<word.size();i++)
     {
         int l=word[i]-'a';
         if(current->child[l]==NULL)
         {
             current->child[l]=new node();
         }
         current->child[l]->prefixcount++;
         current=current->child[l];
     }
     current->is_end=true;
     
 }
 bool search(string word)
 {
     node* current=head;
     for(int i=0;i<word.size();i++)
     {
         if(current->child[word[i]-'a']==NULL)
            return false;
        current=current->child[word[i]-'a'];
     }
     return current->is_end;
 }
 int wordwithprefix(string prefix)
 {
     node* current=head;
     for(int i=0;i<prefix.size();i++)
     {
         if(current->child[prefix[i]-'a']==NULL)
         {
             return 0;
         }
         else
         {
             current=current->child[prefix[i]-'a'];
         }
     }
     return current->prefixcount;
 
 }
 int main() {
 
	ios::sync_with_stdio(false);
    ini();//to intilize
    insert("gopi"); /////insert word into trie
    insert("gopi");
    int n=search("gopi");// search for the word in trie if it present return 1 else 0
    int h=wordwithprefix("gopi");//it count the frequency of the string
    
    cout<<n<<" "<<h<<endl;



	return 0;
 
}

OUTPUT
1 2

