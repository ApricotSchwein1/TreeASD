#include<iostream>
using namespace std;

class BSTArray{
  int arr[40];
  int root;

public:
  // initialize root to -1 as it is empty initially
  BSTArray(){
    root=-1;
    for(int i=0; i<40; i++){
      arr[i] = -1; // initialize all elements to -1
    }
  }

  // check if tree is empty
  bool isEmpty(){
    if(root == -1){
      return true;
    }
    else{
      return false;
    }
  }

  // insert function
  void insert(int data){
    if(root == -1){
      root = 0;
      arr[root] = data;
    }
    else{
      int currentIndex = root;
      while(true){
        if(data < arr[currentIndex]){
          if(2*currentIndex + 1 < 40 && arr[2*currentIndex + 1] == -1){
            arr[2*currentIndex + 1] = data;
            break;
          }
          else{
            currentIndex = 2*currentIndex + 1;
          }
        }
        else{
          if(2*currentIndex + 2 < 40 && arr[2*currentIndex + 2] == -1){
            arr[2*currentIndex + 2] = data;
            break;
          }
          else{
            currentIndex = 2*currentIndex + 2;
          }
        }
      }
    }
  }

  void printBST(int currentIndex){
    if(arr[currentIndex] == -1){
      return;
    }
    printBST(2*currentIndex + 1);
    cout << arr[currentIndex] << " ";
    printBST(2*currentIndex + 2);
  }

  // delete function
  void remove(int data, int currentIndex){
    if(arr[currentIndex] == -1){
      return;
    }
    if(data < arr[currentIndex]){
      remove(data, 2*currentIndex + 1);
    }
    else if(data > arr[currentIndex]){
      remove(data, 2*currentIndex + 2);
    }
    else{
      if(2*currentIndex + 1 > 39 || arr[2*currentIndex + 1] == -1){
        if(2*currentIndex + 2 > 39 || arr[2*currentIndex + 2] == -1){
          arr[currentIndex] = -1;
        }
        else{
          arr[currentIndex] = arr[2*currentIndex + 2];
        }
      }
      else if(2*currentIndex + 2 > 39 || arr[2*currentIndex + 2] == -1){
        arr[currentIndex] = arr[2*currentIndex + 1];
      }
      else{
        int minIndex = 2*currentIndex + 2;
        while(2*minIndex + 1 < 40 && arr[2*minIndex + 1]!= -1){
          minIndex = 2*minIndex + 1;
        }
        arr[currentIndex] = arr[minIndex];
        arr[minIndex] = -1;
      }
    }
  }

  void remove(int data){
    remove(data, root);
  }

  // searching function
  bool search(int data, int currentIndex){
    if(arr[currentIndex] == -1){
      return false;
    }
    if(data == arr[currentIndex]){
      return true;
    }
    else if(data < arr[currentIndex]){
      return search(data, 2*currentIndex + 1);
    }
    else{
      return search(data, 2*currentIndex + 2);
    }
  }

  bool search(int data){
    return search(data, root);
  }

  // getter function for root
  int getRoot(){
    return root;
  }
};

int main(){
  BSTArray bst;
  int nilai;

  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
      nilai = rand() % 100;
      cout << nilai << " ";
      bst.insert(nilai);
  }

  bst.printBST(bst.getRoot());

  return 0;
}