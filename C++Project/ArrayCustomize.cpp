////=>>> Array insertion
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n=5, pos=1, value=100;
//    int arr[100]= {10,20,30,40,50};
//
//    for(int i=n; i>=pos; i--)
//    {
//        arr[i]=arr[i-1];
//    }
//
//    arr[pos]=value;
//    n+=1;
//
//    for(int i=0; i<n; i++)
//    {
//        cout<< arr[i]<<" ";
//    }
//
//    return 0;
//}
//
////=>>> Array insertion (two value)
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n=5, pos=1, value1=100,value2=200;
//    int arr[100]= {10,20,30,40,50};
//
//    for(int i=n+1; i>=pos; i--)
//    {
//        arr[i]=arr[i-2];
//    }
//
//    arr[pos]=value1;
//    arr[pos+1]=value2;
//    n+=2;
//
//    for(int i=0; i<n; i++)
//    {
//        cout<< arr[i]<<" ";
//    }
//
//    return 0;
//}
//
////=>>> Array deletion
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n=5, pos=1;
//    int arr[100]= {10,20,30,40,50};
//
//    for(int i=pos; i<n; i++)
//    {
//        arr[i]=arr[i+1];
//    }
//
//    n-=1;
//
//    for(int i=0; i<n; i++)
//    {
//        cout<< arr[i]<<" ";
//    }
//
//    return 0;
//}
//
////=>>> Array deletion (two value)
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n=5, pos1=1,pos2=2;
//    int arr[100]= {10,20,30,40,50};
//
//    for(int i=pos1; i<n; i++)
//    {
//        arr[i]=arr[i+2];
//    }
//
//    n-=2;
//
//    for(int i=0; i<n; i++)
//    {
//        cout<< arr[i]<<" ";
//    }
//
//    return 0;
//}
//
