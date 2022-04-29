#include <iostream>
#include <vector>

using namespace std;


class sortingOptions{
    //making the variables
    public:
    int IndexSort;
    int arraySize=0;
    vector<int> MainVector={};
    bool Running=true;
    int SwitchSort=0;


    //making the base list
    void makeList(){
        int Num;
        cout<<"how many items will your list have?";
        cin>>Num;
        for(int i=0;i<Num;i++){
            cout<<"enter value: ";
            int value;
            cin>>value;
            MainVector.push_back(value);
            arraySize++;
        }
    }
    
    //allowing extra items to be inserted
    void InsertItem(){
        cout<<"enter value: ";
        int value;
        cin>>value;
        MainVector.push_back(value);
        arraySize++;
    };

    //sorting the data
    void Sorting(){
        if (SwitchSort<arraySize){
            //variable for making the index to change equal to switch sort
            int IndexCheck=SwitchSort;
            int x=MainVector[SwitchSort];

            //iterators
            auto Iterator=MainVector.begin();
            auto SortingIt=MainVector.begin()+SwitchSort;
            
            for(int i=0;i<arraySize;i++){
                if(x>MainVector[IndexCheck]){
                    x=MainVector[IndexCheck];
                    Iterator=Iterator+IndexCheck;
                }else{
                    IndexCheck++;
                    continue;
                }
            };
            
            MainVector.erase(Iterator);
            MainVector.insert(SortingIt,x);
            SwitchSort++;

            Sorting();
        }else{
            SwitchSort=0;
            cout<<"list has been sorted"<<endl;
            
        };
    };

    void ShowList(){
        cout<<"{";
        for(int i=0;i<arraySize;i++){
            cout<<MainVector.at(i)+" ";
        };
        cout<<"}"<<endl;
    };

};

int main(){
    sortingOptions S;
    while(S.Running==true){
        cout<<"What would you like to do?"<<endl;
        int Option;
        cout<<"1.Make new list | 2.add new item | 3.sort the list | 4.show current list | 5.exit"<<endl;
        cin>>Option;
        if (Option==1){
            S.makeList();
        }else if (Option==2){
            S.InsertItem();
        }else if (Option==3){
            S.Sorting();
        }else if (Option==4){
            S.ShowList();
        }else if (Option==5){
            S.Running=false;
        }else{
            cout<<"number does not exist, please try again"<<endl;
        }
        
    }
}

//big o notation O(n)?
