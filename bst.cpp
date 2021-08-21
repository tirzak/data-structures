struct Node {
    int item;
    struct Node *left, *right;
};

class Tree{
   
    Tree();
    ~Tree();
    void insert(int item);
    int search(int item);
private:
    void insertHelp(struct Node* node,int item);
    int searchHelp(struct Node* node,int item);
    int searchHelpIterative(struct Node* node,int item);
    struct Node* root;



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
        searchHelp(node->left,item);
        }
    }
    else if(item>node->item){
        if(node->right!=nullptr){
        searchHelp(node->right,item);
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
}
