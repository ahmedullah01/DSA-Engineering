#include <iostream>

// ================= NODE STRUCT =================
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* Root = NULL;   // global root pointer


// ================= INSERT FUNCTION =================
BSTNode* insert(BSTNode* root, int value) {

    // agar tree empty hai to new node banao
    if (root == NULL) {
        BSTNode* temp = new BSTNode();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    // left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // right subtree
    else {
        root->right = insert(root->right, value);
    }

    return root;
}


// ================= DISPLAY (PREORDER) =================
void displaypre(BSTNode* node) {

    if (node != NULL) {
        std::cout << node->data << " ";
        displaypre(node->left);
        displaypre(node->right);
    }
}


// ================= SEARCH =================
void searching(BSTNode* node, int value) {

    if (node == NULL) {
        std::cout << "Not Found\n";
        return;
    }

    if (node->data == value) {
        std::cout << "Found\n";
        return;
    }

    if (value < node->data)
        searching(node->left, value);
    else
        searching(node->right, value);
}


// ================= FIND MIN =================
BSTNode* min(BSTNode* node) {

    if (node->left == NULL)
        return node;

    return min(node->left);
}


// ================= DELETE =================
std::string Delete(BSTNode*& node, int value) {

    if (node == NULL)
        return "Not Found";

    // search left
    if (value < node->data)
        return Delete(node->left, value);

    // search right
    else if (value > node->data)
        return Delete(node->right, value);

    // ===== NODE FOUND =====
    else {

        // Case 1: No child
        if (node->left == NULL && node->right == NULL) {
            delete node;
            node = NULL;
            return "Deleted (No Child)";
        }

        // Case 2: One child (right)
        else if (node->left == NULL) {
            BSTNode* temp = node->right;
            delete node;
            node = temp;
            return "Deleted (One Child)";
        }

        // Case 2: One child (left)
        else if (node->right == NULL) {
            BSTNode* temp = node->left;
            delete node;
            node = temp;
            return "Deleted (One Child)";
        }

        // Case 3: Two children
        else {
            BSTNode* temp = min(node->right);   // inorder successor
            node->data = temp->data;
            return Delete(node->right, temp->data);
        }
    }
}



// ================= MAIN MENU =================
int main() {

    int choice, value;

    while (true) {

        std::cout << "\n===== BST MENU =====\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Display (Preorder)\n";
        std::cout << "3. Search\n";
        std::cout << "4. Delete\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {

            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                Root = insert(Root, value);
                break;

            case 2:
                std::cout << "Tree: ";
                displaypre(Root);
                std::cout << "\n";
                break;

            case 3:
                std::cout << "Enter value: ";
                std::cin >> value;
                searching(Root, value);
                break;

            case 4:
                std::cout << "Enter value: ";
                std::cin >> value;
                std::cout << Delete(Root, value) << "\n";
                break;

            case 5:
                std::cout << "Program Ended\n";
                return 0;

            default:
                std::cout << "Invalid Choice\n";
        }
    }
}