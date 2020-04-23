//median till -1 is encountered in input stream
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> max_heap;
priority_queue<int ,vector<int> ,greater<int> > min_heap;

void add(int num){
    if(!min_heap.empty() && num> min_heap.top()){
        min_heap.push(num);
    }
    else{
        max_heap.push(num);
    }


    if(fabs(min_heap.size()-max_heap.size())>1){
        if(max_heap.size()>min_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        else{
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

}

float get_median(){
    if(max_heap.size()>min_heap.size()){
        return max_heap.top();
    }

    else if(min_heap.size()> max_heap.size()){
        return min_heap.top();
    }

    else{
        return (min_heap.top()+ max_heap.top())/2;
    }
}


int main() {
   int n;
   cin>>n;

   while(n!=0){
       if(n!=-1){
           add(n);
       }

       else{
           cout<<get_median();
           cout<<endl;
       }

       cin>>n;
   }
}
