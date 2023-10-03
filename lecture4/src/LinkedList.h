#pragma once

#include <optional>
#include <iostream>


template <typename DataType>
class LinkedList{
    struct Node {
        Node * next;
        DataType data;
    } *head;
    
public:
    LinkedList():head(nullptr){};


    LinkedList(LinkedList&& tList){
        head = tList.head;
    }

    ~LinkedList(){
        Node* curNode = head;
        while(curNode->next != nullptr){
            free(curNode);
            curNode = curNode->next;
        }
    }

    void addNode(Node* newNode, int position){
        Node* curNode = head;
        if (curNode != nullptr){
            if (position == 0){
                newNode->next = curNode;
                head = newNode;
            }
            else{
                size_t curPosition = 0;
                while (curNode != nullptr){
                    if (curPosition == position - 1){
                        newNode->next = curNode->next;
                        curNode->next = newNode;
                    }
                    curPosition++;
                    curNode = curNode->next;
                }
            }
        }
        else{
            head = newNode;
        }
    }

    void deleteNode(int position){
        Node* curNode = head;
        Node* nextNode = curNode->next;
        int curPosition = 0;
        if (position == 0){
            head = nextNode;
        }
        while(nextNode != nullptr){
            if (curPosition == position - 1){
                curNode->next = nextNode->next;
                free(nextNode);
            }
            curNode = curNode->next;
            nextNode = curNode->next;
            curPosition++;
        }
    }

    std::optional<DataType> getElement(size_t position){
        Node* curNode = head;
        size_t curPosition = 0;
        while(curNode != nullptr){
            if (curPosition == position){
                std::cout << curNode->data;
                break;
            }
            curPosition++;
            curNode = curNode->next;
        }
    }

    std::optional<DataType> setElement(DataType data, size_t position){
        addNode(new Node{
            0,
            data
        }, position);
    }

    void showList(){
        Node* curNode = head;
        while(curNode != nullptr){
            std::cout << curNode->data << " ";
            curNode = curNode->next;
        }
        std::cout << "\n";
    }
};