#include <iostream>
#include <vector>
struct Node {
    int item;
    struct Node *left, *right;
};

class Tree{

public:   
    Tree();
    ~Tree();
    void insert(int item);
    int search(int item);
    void printTree();
private:
    void insertHelp(struct Node* node,int item);
    int searchHelp(struct Node* node,int item);
    int searchHelpIterative(struct Node* node,int item);
    struct Node* root;
    void printHelp(struct Node* node);



};

Tree::Tree():root{nullptr}{


}
Tree::~Tree(){
}
void Tree::insert(int item){
    if (root == nullptr){
        root = new Node;
        root->left=nullptr;
        root->right=nullptr;
        root->item=item;
    }
    else{
        insertHelp(root,item);
    }
}
void Tree::insertHelp(struct Node* node,int item){
    if(item<node->item){
        if(node->left!=nullptr){
        insertHelp(node->left,item);
        }
        else{
            node->left=new Node;
            node->left->left=nullptr;
            node->left->right=nullptr;
            node->left->item=item;

        }
    }
    else{
        if(node->right!=nullptr){
        insertHelp(node->right,item);
        }
        else{
            node->right=new Node;
            node->right->left=nullptr;
            node->right->right=nullptr;
            node->right->item=item;
            
        }
    }
}
//Search Binary Tree
int Tree::search(int item){
    if (root == nullptr){
        return -1;
    }
    else{
        searchHelp(root,item);
    }
}
int Tree::searchHelp(struct Node* node,int item){
    if(item==node->item) return node->item;
    else if(item<node->item){
        if(node->left!=nullptr){
        return searchHelp(node->left,item);
        }
    }
    else if(item>node->item){
        if(node->right!=nullptr){
        return searchHelp(node->right,item);
        }
    
    }
    else {
        return -1;
        }    

}
int Tree::searchHelpIterative(struct Node* node,int item){
    struct Node* current = node;
    if(item==current->item){
        return item;
    }
    while (current !=nullptr){
        if(item==current->item){
            return item;
        }
        else if(item<current->item){
            current=current->left;
        }
        else{
            current=current->right;
        }        
    }

    return -1;


}
void Tree::printTree(){
    if (root!=nullptr){
        printHelp(root);
    }
}
void Tree::printHelp(struct Node* node){
    if (node == nullptr)
        return;
    printHelp(node->left);
    std::cout<<node->item<<"\n";
    printHelp(node->right);

}

int main(void){
std::vector <int> x ={20,1,2,3,-1,-4,-3};
Tree *bt = new Tree();

for (auto &it: x){
bt->insert(it);
}

int p=bt->search(3);
std::cout<<p<<std::endl;
bt->printTree();
return 0;

}