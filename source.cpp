#include<iostream>

class tree{
private:
    class node{
    private:
        std::string eng;
        std::string rus;
        node* left;
        node* right;
        public:
        node(std::string a, std::string b):eng(a), rus(b), left(NULL), right(NULL){}
        void insert(std::string a, std::string b){
            if(a>eng&&right) right->insert(a,b);
            else if(a>eng&&!right) right=new node(a,b);
            else if(a<eng&&left) left->insert(a,b);
            else left=new node(a,b);
        }
        void print(){
            if(left) left->print();
            std::cout<<eng<<" - "<<rus<<"\n";
            if(right) right->print();
        }
    };
    node* root;
public:
    tree():root(NULL){}
    void insert(std::string, std::string);
    void print();
};
void tree::insert(std::string a, std::string b){
    if (!root)  root=new node(a,b);
    else root->insert(a,b);
}

void tree::print(){
    root->print();
}
int main(){
    tree dict;
    dict.insert("zero","нуль");
    dict.insert("you","ты");
    dict.insert("up","вверх");
    dict.insert("book","книга");
}
