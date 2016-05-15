#include <iostream>
#include <limits>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <string>
#include <sstream>
#include <functional>
#include <exception>
#include <algorithm>
#include <cstdio>
using namespace std;

template <class type,class UpdatefunctionObject,class QueryfunctionObject>
class SegementTree
{
    vector<type> Tree;
  //  vector<type> LazyTree;
    UpdatefunctionObject Uo;
    QueryfunctionObject Qo;
    int TreeSize(int N)
    {
        if(N==1)
            return 1;
        else if((N&(N-1))==0) // Checking if N is a power of 2
            return 2*N-1;
        //changing all right side bits to 1.
        N = N| (N>>1);
        N = N| (N>>2);
        N = N| (N>>4);
        N = N| (N>>8);
        //Now N+1 is the Base Size
    
            return 2*(N+1)-1;
    }
public:
    SegementTree()
    {
    }
    SegementTree(int size):Tree(0)
    {
        if(size>=0)
        {
            Tree.resize(TreeSize(size));
           // LazyTree.resize(4*largest_power(size));
        }
        else fprintf(stderr,"Size is Negative making size as 0");
    }
    SegementTree(vector<type> &GivenArray)
    {
        BuildTrees(GivenArray);
    }
    
    void PrintTree()
    {   
       
        cout << endl;
        for(size_t i=0;i<Tree.size();i++)
        {
            cout << "[" << i << "]" << "="<< Tree[i] << " ";
        }
    }
private:
    void BuildTrees(vector<type> & Data)
    {   
       
    }
  
};
template <class A>
class Sums
{
public:
   int operator()( A a, A b)
   {
       return a+b;
   }
};
template <class A>
class ADD1
{
public:
    
};

int main(int argc, char **argv)
{
	int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin >> A[i];
    
    SegementTree< int , ADD1<int> , Sums<int> > S(A);
    S.PrintTree();
    return 0;
}
