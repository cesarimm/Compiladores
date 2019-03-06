#include <bits/stdc++.h>

using namespace std;

/*int main() 
{ 
    // Empty Queue 
    queue<int> myqueue; 
    myqueue.push(0); 
    myqueue.push(1); 
    myqueue.push(2); 
    // queue becomes 0, 1, 2 
  
    myqueue.pop_back(); 
    myqueue.pop(); 
    // queue becomes 2 
  
    // Printing content of queue 
    while (!myqueue.empty()) { 
        cout << ' ' << myqueue.front(); 
        myqueue.pop(); 
    } 
}*/

int main ()
{
  std::deque<int> mydeque;
  int sum (0);
  mydeque.push_back (10);
  mydeque.push_back (20);
  mydeque.push_back (30);
  mydeque.push_front (30);
   
   mydeque.pop_front();
   
  while (!mydeque.empty())
  {
  	cout<<mydeque.back()<<endl;
    sum+=mydeque.back();
    mydeque.pop_back();
  }

  std::cout << "The elements of mydeque add up to " << sum << '\n';

  return 0;
}
