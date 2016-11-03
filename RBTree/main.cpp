#include "bs_tree.cpp"
#include "rb_tree.h"

void showMenu();

using namespace std;

int main()
{
    RBTree<int> tree;
    cout << "<Is empty>" << endl << endl;
    showMenu();

    int choice;
    cin >> choice;

    while(choice != 7)
    {
        switch(choice)
        {
        case 1:
            {
                cout << "Enter data for inserting" << endl;
                int newData;
                cin >> newData;
                tree.insert(newData);
                cout << "Inserting" << endl;
                break;
            }

        case 2:
            {
                cout << "Enter data for deliting:" << endl;
                int deleteData;
                cin >> deleteData;
                tree.remove(deleteData);
                break;
            }

        case 3:
            {
                tree.printTree();
                break;
            }

        case 4:
            {
                tree.print(RBTree<int>::Order::IN);
                cout << endl;
                break;
            }

        case 5:
            {
                tree.print(RBTree<int>::Order::PRE);
                cout << endl;
                break;
            }

        case 6:
            {
                tree.print(RBTree<int>::Order::POST);
                cout << endl;
                break;
            }
        }
        showMenu();
        cin >> choice;
    }

    return 0;
}

void showMenu()
{
    cout << "What do you want to do?" << endl;
    cout << "1.Insert" << endl;
    cout << "2.Delete" << endl;
    cout << "3.Show" << endl;
    cout << "4.Inorder" << endl;
    cout << "5.Preorder" << endl;
    cout << "6.Postorder" << endl;
    cout << "7.Exit" << endl;
}
