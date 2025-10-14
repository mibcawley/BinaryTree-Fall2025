//
// Created by we7289 on 2/18/2021.
//

#include <iostream>
#include "TreeT.h"

int main(void) {

    TreeT<int> treeA;
    ///

    //TreeT<int> treeB;

    //treeB = treeA;

    TreeT<int>* tree = new TreeT<int>;

    tree->Add(5);
    tree->Add(1);
    tree->Add(10);
    tree->Add(2);

    if (tree->Contains(10))
    {
        std::cout << "We have a 10" << std::endl;
    }
    if (!tree->Contains(0))
    {
        std::cout << "We do NOT have a 0" << std::endl;
    }

    tree->ResetIterator(IN_ORDER);
    for (int i = 0; i < tree->Size(); i++) {
        cout << tree->GetNextItem() << " ";
    }
    cout << endl;

    delete tree;

    return 0;
}