/*
 * Project: Number Wizard ( Topic created by gemini )
 * Author: Rangerr
 * Description: Pratice POINTERS.
 * Features: Show, Filter Primes, Reverse, Sort, Search.
 */

#include <bits/stdc++.h>
using namespace std;

void showData(int *a, int n);
void filterPrime(int *p , int n);
void reverse(int *start , int *end );
void sort(int *p , int n);
void search(int *p , int n);
int main (){
    int n , choose;
        cout << "Type n: " ; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Type Array[" << i <<"] :";
            cin >> a[i];
        }
    while(true){
        cout << "1. Show Data" <<endl;
        cout << "2. Filter Primes"<<endl;
        cout << "3. Reverse Array"<<endl;
        cout << "4. Sort Array"<<endl;
        cout << "5. Search Number"<<endl;
        cout << "0. Exit"<<endl;
        cout << ">> Your choice: ";
        int *p;
        p = a;
        int *start = p , *end = p + n-1;
        cin >> choose;
        if(choose == 0) break;
        switch (choose)
        {
        case 1:
            showData(a,n);
            break;       
        case 2:
            filterPrime(p,n);
            break;
        case 3:
            reverse(start,end);
            break;
        case 4:
            sort(p,n);
            break;
        case 5:
            search(p , n);
        default:
            cout<<"Wrong number!";
            break;
        }
}
    

    system("pause");
    return 0;
}
// Feature 1: Display array using pointer arithmetic
void showData(int *a, int n){
    cout << a[0] ;
    for (int i = 1; i < n; i++)
    {
        cout <<" | "<< a[i];
    }
    cout << endl;
};
// Feature 2: Find primes and show their memory address
void filterPrime(int *p , int n){
    
    for (int i = 0; i < n; i++)
    {
        bool isPrime = true;

        if(*p < 2) isPrime = false;
        for (int j = 2; j*j <= *p; j++)
        {
            if(*p % j == 0) {
                isPrime=false;
                break;
            }
        }
        if(isPrime == true){
            cout << "Index :" << i << endl << "Number :" << *p << endl;
        }
        p++;
    }
}
// Feature 3: Reverse array using Two Pointers technique
void reverse(int *start , int *end ){

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }   
    cout << "Complete reverse the arr" << endl;
    
}
// Feature 4: Sort using pointers (Bubble Sort logic)
void sort(int *p , int n){
    for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      
            if (*(p + i) > *(p + j)) { 
                int temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    
    }
    cout <<"Complete sort!" <<endl;
}
// Feature 5: Search using pointers
void search(int *p , int n){
    int x , sum = 0;
    cout <<"Type a number you want to find :";
    cin >> x;
    
    for (int i = 0; i < n; i++)
    {
        if(*p == x) sum++;
        p++;
    }
    cout << "The total Number "<< x<< " in arr are:"<<sum<<endl;
    cout<<"Index :";
    if(sum ==0) cout <<"None";
    else
    for (int i = 0; i < n; i++)
    {
        if(*p == x) cout<<i<<" ";
        p++;
    }
    cout <<endl;
}
