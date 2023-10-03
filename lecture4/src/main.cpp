#include "LinkedList.h"

int main(){
    LinkedList<int> list;

    list.setElement(5 , 0);
    list.setElement(10, 0);
    list.setElement(15, 0);
    
    list.showList();

    list.getElement(1);
    list.deleteNode(2);

    list.showList();

    return 0;
}