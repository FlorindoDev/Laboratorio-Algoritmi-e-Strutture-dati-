
#include <iostream>
#include <random>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/stack/stack.hpp"
#include "../../zlasdtest/queue/queue.hpp"


#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/list/list.hpp"

#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"

#include "../../bst/bst.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../zlasdtest/bst/bst.hpp"
#include "../../zlasdtest/binarytree/binarytree.hpp"
#include "../../zlasdtest/iterator/iterator.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"

#include "../../hashtable/clsadr/htclsadr.hpp"
#include "../../hashtable/opnadr/htopnadr.hpp"
#include "../../zlasdtest/hashtable/hashtable.hpp"


/* ************************************************************************** */

using namespace std;


/* ************************************************************************** */


/* ******************************************************************************* */
/*                                  Test Esercizio 1                               */
/* ******************************************************************************* */


void stestVectorOfVectorInt(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of Vector<Vector<int>> Test:*****************" << endl;
  
    try { 
        
      lasd::Vector<lasd::Vector<int>> vec(3);
      Empty(loctestnum, loctesterr, vec, false);
      cout<<"\n~Prima riga~\n";
      vec[0].Resize(3);
      SetAt(loctestnum, loctesterr, vec[0], true, 0, 1);
      SetAt(loctestnum, loctesterr, vec[0], true, 1, 2);
      SetAt(loctestnum, loctesterr, vec[0], true, 2, 3);
      cout<<"\n~Seconda riga~\n";
      vec[1].Resize(3);
      SetAt(loctestnum, loctesterr, vec[1], true, 0, 3);
      SetAt(loctestnum, loctesterr, vec[1], true, 1, 2);
      SetAt(loctestnum, loctesterr, vec[1], true, 2, 1);
      cout<<"\n~Terza riga~\n";
      vec[2].Resize(3);
      SetAt(loctestnum, loctesterr, vec[2], true, 0, 2);
      SetAt(loctestnum, loctesterr, vec[2], true, 1, 3);
      SetAt(loctestnum, loctesterr, vec[2], true, 2, 1);
      lasd::Vector<lasd::Vector<int>> Copyvec(vec);
      EqualVector(loctestnum, loctesterr, vec, Copyvec, true);
  
      for(lasd::ulong i = 0; i<vec.Size(); i++){
        cout<<"\n~Riga "<< i + 1<<  "\n";
        TraversePreOrder(loctestnum, loctesterr, vec[i], true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec[i], true, &TraversePrint<int>);
      }

      cout<<"\n~Riga 1\n";
      FoldPreOrder(loctestnum, loctesterr, vec[0], false, &FoldAdd<int>, 0, 12);
      FoldPostOrder(loctestnum, loctesterr, vec[0], true, &FoldMultiply<int>, 1, 6);

      cout<<"\n~Riga 2\n";
      FoldPreOrder(loctestnum, loctesterr, vec[1], true, &FoldAdd<int>, 0, 6);
      FoldPostOrder(loctestnum, loctesterr, vec[1], false, &FoldMultiply<int>, 1, 12);

      cout<<"\n~Altri test~\n";
      EqualVector(loctestnum, loctesterr, vec, Copyvec, true);
      Empty(loctestnum, loctesterr, vec, false);
      vec.Clear();
      Empty(loctestnum, loctesterr, vec, true);
      

      
    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! qui" << endl;
    }
    cout << "End of Vector<Vector<int>> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;

}

void stestVectorOfVectorDouble(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of Vector<Vector<double>> Test:*****************" << endl;
  
    try { 
        
      lasd::Vector<lasd::Vector<double>> vec(3);
      Empty(loctestnum, loctesterr, vec, false);
      cout<<"\n~Prima riga~\n";
      vec[0].Resize(3);
      SetAt(loctestnum, loctesterr, vec[0], true, 0, 1.5);
      SetAt(loctestnum, loctesterr, vec[0], true, 1, 5.7);
      SetAt(loctestnum, loctesterr, vec[0], true, 2, 6.0);
      cout<<"\n~Seconda riga~\n";
      vec[1].Resize(3);
      SetAt(loctestnum, loctesterr, vec[1], true, 0, 6.0);
      SetAt(loctestnum, loctesterr, vec[1], true, 1, 5.7);
      SetAt(loctestnum, loctesterr, vec[1], true, 2, 1.5);
      cout<<"\n~Terza riga~\n";
      vec[2].Resize(3);
      SetAt(loctestnum, loctesterr, vec[2], true, 0, 5.7);
      SetAt(loctestnum, loctesterr, vec[2], true, 1, 6.0);
      SetAt(loctestnum, loctesterr, vec[2], true, 2, 1.5);
      lasd::Vector<lasd::Vector<double>> Copyvec(vec);
      EqualVector(loctestnum, loctesterr, vec, Copyvec, true);

  
      cout<<"\n~Riga 2~\n";
      FoldPreOrder(loctestnum, loctesterr, vec[1], true, &FoldAdd<double>, 0.0, 13.2);
      FoldPostOrder(loctestnum, loctesterr, vec[1], false, &FoldMultiply<double>, 1.0, 66.0);
      
      cout<<"\n~Altri test~\n";
      EqualVector(loctestnum, loctesterr, vec, Copyvec, true);
      Empty(loctestnum, loctesterr, vec, false);
      vec.Clear();
      Empty(loctestnum, loctesterr, vec, true);
      
    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! qui" << endl;
    }
    cout << "End of Vector<Vector<double>> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;

}

void stestVectorOfVectorString(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of Vector<Vector<string>> Test:*****************" << endl;
  
    try { 
        
      lasd::Vector<lasd::Vector<string>> vec(3);
      Empty(loctestnum, loctesterr, vec, false);
      cout<<"\n~Prima riga~\n";
      vec[0].Resize(3);
      SetAt(loctestnum, loctesterr, vec[0], true, 0, string("A"));
      SetAt(loctestnum, loctesterr, vec[0], true, 1, string("B"));
      SetAt(loctestnum, loctesterr, vec[0], true, 2, string("C"));
      cout<<"\n~Seconda riga~\n";
      vec[1].Resize(3);
      SetAt(loctestnum, loctesterr, vec[1], true, 0, string("C"));
      SetAt(loctestnum, loctesterr, vec[1], true, 1, string("B"));
      SetAt(loctestnum, loctesterr, vec[1], true, 2, string("A"));
      cout<<"\n~Terza riga~\n";
      vec[2].Resize(3);
      SetAt(loctestnum, loctesterr, vec[2], true, 0, string("B"));
      SetAt(loctestnum, loctesterr, vec[2], true, 1, string("C"));
      SetAt(loctestnum, loctesterr, vec[2], true, 2, string("A"));
      lasd::Vector<lasd::Vector<string>> Copyvec(vec);
      EqualVector(loctestnum, loctesterr, vec, Copyvec, true);

      

      for(lasd::ulong i = 0; i<vec.Size(); i++){
        cout<<"\n~Riga "<< i + 1<<  "\n";
        TraversePreOrder(loctestnum, loctesterr, vec[i], true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, vec[i], true, &TraversePrint<string>);
      }

      cout<<"\n~Riga 1\n";
    
      MapPreOrder(loctestnum, loctesterr, Copyvec[0], true, [](string & str) { MapStringAppend(str, string("<")); });
      TraversePreOrder(loctestnum, loctesterr, Copyvec[0], true, &TraversePrint<string>);

      FoldPreOrder(loctestnum, loctesterr, Copyvec[0], true, &FoldStringConcatenate, string("?"), string("?A<B<C<"));
      
      cout<<"\n~Altri test~\n";
      FoldPreOrder(loctestnum, loctesterr, Copyvec[1], true, &FoldStringConcatenate, string("?"), string("?CBA"));
      EqualVector(loctestnum, loctesterr, vec, Copyvec, false);
      Empty(loctestnum, loctesterr, vec, false);
      vec.Clear();
      Empty(loctestnum, loctesterr, vec, true);
      
    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! qui" << endl;
    }
    cout << "End of Vector<Vector<String>> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;

}

void stestVectorIntensivo(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of Vector<int> Intesive Test:*****************" << endl;
  
    try { 
      lasd::SortableVector<int> vec(1000);
      int j = 1;
      for(ulong i = vec.Size()-1; i>0; i--){
        SetAt(loctestnum, loctesterr, vec, true, i, j);
        j++;
      }
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      vec.Sort();
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! qui" << endl;
    }
    cout << "End of Vector<int> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;

}

void stestVectorOfList(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of Vector<List<int>> Intesive Test:*****************" << endl;
  
    try { 
      lasd::Vector<lasd::List<int>> vec(2);
      Empty(loctestnum, loctesterr, vec[0], true);
      Size(loctestnum, loctesterr, vec[0], true, 0);

      GetFront(loctestnum, loctesterr, vec[0], false, 0); //1
      GetBack(loctestnum, loctesterr, vec[0], false, 0); //2

      Exists(loctestnum, loctesterr, vec[0], false, 0);

      TraversePreOrder(loctestnum, loctesterr, vec[0], true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec[0], true, &TraversePrint<int>);
      FoldPreOrder(loctestnum, loctesterr, vec[0], true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(loctestnum, loctesterr, vec[0], true, &FoldAdd<int>, 0, 0);

      RemoveFromFront(loctestnum, loctesterr, vec[0], false); //3
      FrontNRemove(loctestnum, loctesterr, vec[0], false, 0); //4

      cout<<"\n~Riga 1\n";
      InsertAtBack(loctestnum, loctesterr, vec[0], true, 4); //5
      InsertAtFront(loctestnum, loctesterr, vec[0], true, 5);
      InsertAtFront(loctestnum, loctesterr, vec[0], true, 9);
      InsertAtBack(loctestnum, loctesterr, vec[0], true, 2);
      InsertAtFront(loctestnum, loctesterr, vec[0], true, 1);

      cout<<"\n~Riga 2\n";
      InsertAtBack(loctestnum, loctesterr, vec[1], true, 1); //5
      InsertAtFront(loctestnum, loctesterr, vec[1], true, 2);
      InsertAtFront(loctestnum, loctesterr, vec[1], true, 3);
      InsertAtBack(loctestnum, loctesterr, vec[1], true, 4);
      InsertAtFront(loctestnum, loctesterr, vec[1], true, 5);

      //vec.Sort();

      for(lasd::ulong i = 0; i<vec.Size(); i++){
        cout<<"\n~Riga "<< i + 1<<  "\n";
        TraversePreOrder(loctestnum, loctesterr, vec[i], true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, vec[i], true, &TraversePrint<int>);
      }

      RemoveFromFront(loctestnum, loctesterr, vec[0], true);
      RemoveFromFront(loctestnum, loctesterr, vec[1], true);
      EqualList(loctestnum, loctesterr, vec[0], vec[1], false);
    
    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! qui" << endl;
    }
    cout << "End of Vector<int> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;

}

void stestVector_ListInt(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of Vector<int>/List<int> Intesive Test:*****************" << endl;
    try {
      lasd::Vector<int> vec(3);
      Empty(loctestnum, loctesterr, vec, false); 
      SetAt(loctestnum, loctesterr, vec, true, 0, 1);
      SetAt(loctestnum, loctesterr, vec, true, 1, 2);
      SetAt(loctestnum, loctesterr, vec, true, 2, 3);
      lasd::List<int> lis;
      InsertAtFront(loctestnum,loctesterr, lis, true, 10);
      InsertAllC(loctestnum,loctesterr,lis,true,vec);
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<int>);
      lis.Clear();

      InsertAllM(loctestnum,loctesterr,lis,true,std::move(vec));
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<int>);

      InsertAtFront(loctestnum,loctesterr, lis, true, 12);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      RemoveAll(loctestnum,loctesterr,lis,false,vec);
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<int>);

      InsertSomeC(loctestnum,loctesterr,lis,true,vec);
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<int>);

      lis.Clear();
      InsertSomeM(loctestnum,loctesterr,lis,true,std::move(vec));
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      RemoveSome(loctestnum,loctesterr,lis,true,vec);
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! qui" << endl;
    }
    cout << "End of Vector<int>/List<int> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;

}

void stestVector_ListString(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of Vector<string>/List<string> Intesive Test:*****************" << endl;
    try {
      lasd::Vector<string> vec(3);
      Empty(loctestnum, loctesterr, vec, false); 
      SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
      lasd::List<string> lis;
      InsertAtFront(loctestnum,loctesterr, lis, true, string("F"));
      InsertAllC(loctestnum,loctesterr,lis,true,vec);
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<string>);
      lis.Clear();

      InsertAllM(loctestnum,loctesterr,lis,true,std::move(vec));
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<string>);

      InsertAtFront(loctestnum,loctesterr, lis, true, string("H"));

      RemoveAll(loctestnum,loctesterr,lis,false,vec);
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<string>);

      InsertSomeC(loctestnum,loctesterr,lis,true,vec);
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<string>);

      lis.Clear();
      InsertSomeM(loctestnum,loctesterr,lis,true,std::move(vec));
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<string>);

      RemoveSome(loctestnum,loctesterr,lis,true,vec);
      TraversePostOrder(loctestnum, loctesterr, lis, true, &TraversePrint<string>);

    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! qui" << endl;
    }
    cout << "End of Vector<string>/List<string> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;

}

template<typename Data>
void TestCircularity(uint & testnum, uint & testerr,lasd::QueueVec<Data> & que,const Data & d ,bool chk, ulong rep) {
  bool tst;
  testnum++;
  try {
    cout << " " << testnum << " (" << testerr << ") Test Circularity Of QueueVec: ";

    que.Enqueue(d);
    que.Enqueue(d);
    for(ulong i=0;i<rep;i++){
        que.Enqueue(d);
        que.Dequeue();
    }


    cout << ((tst = chk) ? "Correct" : "Error") << "!" << endl;
  }
  catch (exception & exc) {
    cout << " " << exc.what() << ": " << ((tst = !chk) ? "Correct" : "Error") << "!" << endl;
  }
  testerr += (1 - (uint) tst);
}

template<typename Data>
void EnqueueIntensive(uint & testnum, uint & testerr,lasd::Queue<Data> & Q,const ulong nelem,const Data& d ,bool chk) {
  bool tst;
  testnum++;
  try {
    cout << " " << testnum << " (" << testerr << ") Intensive Enqueue elements: " << nelem << ": ";
    for(ulong i=0;i<nelem;i++){
      Q.Enqueue(d);
    } 
    cout << ((tst = chk) ? "Correct" : "Error") << "!" << endl;
  }
  catch (exception & exc) {
    cout << " " << exc.what() << ": " << ((tst = !chk) ? "Correct" : "Error") << "!" << endl;
  }
  testerr += (1 - (uint) tst);
}

template<typename Data>
void DequeueIntensive(uint & testnum, uint & testerr,lasd::Queue<Data> & Q,const ulong nelem, bool chk) {
  bool tst;
  testnum++;
  try {
    cout << " " << testnum << " (" << testerr << ") Intensive Dequeue elements: " << nelem << ": ";
    for(ulong i=0;i<nelem;i++){
      Q.Dequeue();
    } 
    cout << ((tst = chk) ? "Correct" : "Error") << "!" << endl;
  }
  catch (exception & exc) {
    cout << " " << exc.what() << ": " << ((tst = !chk) ? "Correct" : "Error") << "!" << endl;
  }
  testerr += (1 - (uint) tst);
}

void stestQueueVecInt(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of QueueVec<int> Intesive Test:*****************" << endl;
    try {
      lasd::QueueVec<int> Qvec;
      EnqueueC(loctestnum, loctesterr, Qvec, 1);
      EnqueueC(loctestnum, loctesterr, Qvec, 2);

      Empty(loctestnum, loctesterr, Qvec, false);
      Size(loctestnum, loctesterr, Qvec, true, 2);

      HeadNDequeue(loctestnum, loctesterr, Qvec, true, 1);
      Head(loctestnum, loctesterr, Qvec, true, 2);
      Qvec.Clear();
      TestCircularity(loctestnum,loctesterr,Qvec,1,true,1000);
      Qvec.Clear();
      EnqueueIntensive(loctestnum, loctesterr,Qvec,10000,1, true);
      DequeueIntensive(loctestnum, loctesterr,Qvec,10000, true);

    
    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! qui" << endl;
    }
    cout << "End of QueueVec<int> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;

}


void stestQueueListInt(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "*****************Begin of QueueList<int> Intesive Test:*****************" << endl;
    try {
      lasd::QueueLst<int> queue;
      Head(loctestnum,loctesterr, queue, false, 1);
      EnqueueC(loctestnum,loctesterr, queue, 1);
      queue.Clear();
      EnqueueM(loctestnum,loctesterr, queue, 1);

      EnqueueIntensive(loctestnum, loctesterr,queue,10000,1, true);
      DequeueIntensive(loctestnum, loctesterr,queue,10000, true);

      lasd::QueueLst<int> copqueue(queue);

      EqualQueue(loctestnum, loctesterr, queue, copqueue, true);
      NonEqualQueue(loctestnum, loctesterr, queue, copqueue, false);

    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "End of QueueList<int> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

template<typename Data>
void PushIntensive(uint & testnum, uint & testerr,lasd::Stack<Data> & stk,const Data & d ,bool chk, ulong rep){
  bool tst;
  testnum++;
  try {
    cout << " " << testnum << " (" << testerr << ") Stress Test Of Stack(push): " << rep << ": ";   
    for(ulong i=0;i<rep;i++){
        stk.Push(d);
    }  
    cout << ((tst = chk) ? "Correct" : "Error") << "!" << endl;
  }
  catch (exception & exc) {
    cout << " " << exc.what() << ": " << ((tst = !chk) ? "Correct" : "Error") << "!" << endl;
  }
  testerr += (1 - (uint) tst);
}

template<typename Data>
void PopIntensive(uint & testnum, uint & testerr,lasd::Stack<Data> & stk,bool chk, ulong rep){
  bool tst;
  testnum++;
  try {
    cout << " " << testnum << " (" << testerr << ") Stress Test Of Stack(Pop): " << rep << ": "; 
    for(ulong i=0;i<rep;i++){
        stk.Pop();
    }  
    cout << ((tst = chk) ? "Correct" : "Error") << "!" << endl;
  }
  catch (exception & exc) {
    cout << " " << exc.what() << ": " << ((tst = !chk) ? "Correct" : "Error") << "!" << endl;
  }
  testerr += (1 - (uint) tst);
}

void stestStackVecInt(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of StackVec<int> Intesive Test:*****************" << endl;
  try {
    lasd::StackVec<int> stack;
    Top(loctestnum,loctesterr, stack, false, 0);
    Pop(loctestnum,loctesterr, stack, false);
    PushC(loctestnum,loctesterr, stack, 1);
    TopNPop(loctestnum,loctesterr, stack, true, 1);
    PushM(loctestnum,loctesterr, stack, 2);
    PushIntensive(loctestnum, loctesterr,stack,1, true, 10000);
    PopIntensive(loctestnum, loctesterr,stack, true, 10000);
    lasd::StackVec<int> copstack(stack);
    EqualStack(loctestnum, loctesterr, stack, copstack, true);
    NonEqualStack(loctestnum, loctesterr, stack, copstack, false);

    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "End of StackVec<int> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void stestStackLstInt(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of StackList<int> Intesive Test:*****************" << endl;
  try {
    lasd::StackLst<int> stack;
    Top(loctestnum,loctesterr, stack, false, 0);
    Pop(loctestnum,loctesterr, stack, false);
    PushC(loctestnum,loctesterr, stack, 1);
    TopNPop(loctestnum,loctesterr, stack, true, 1);
    PushM(loctestnum,loctesterr, stack, 2);
    PushIntensive(loctestnum, loctesterr,stack,1, true, 10000);
    PopIntensive(loctestnum, loctesterr,stack, true, 10000);
    lasd::StackLst<int> copstack(stack);
    EqualStack(loctestnum, loctesterr, stack, copstack, true);
    NonEqualStack(loctestnum, loctesterr, stack, copstack, false);

    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "End of StackList<int> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void TestListeRemove(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Remove on list<int> Intesive Test:*****************" << endl;
  try {

    
    lasd::Vector<int> vec(8);
    SetAt(loctestnum, loctesterr, vec, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec, true, 4, 5);
    SetAt(loctestnum, loctesterr, vec, true, 5, 6);
    SetAt(loctestnum, loctesterr, vec, true, 6, 7);
    SetAt(loctestnum, loctesterr, vec, true, 7, 8);
    lasd::List<int> lst(vec);
    Empty(loctestnum, loctesterr, lst, false);
    Size(loctestnum, loctesterr, lst, true, 8);

    RemoveAll(testnum, testerr, lst, true, vec);

    Empty(loctestnum, loctesterr, lst, true);
    Size(loctestnum, loctesterr, lst, true, 0);

    Exists(loctestnum, loctesterr, lst, false, 7);
    Remove(loctestnum, loctesterr, lst, false, 7);  

    lasd::List<int> lst2(vec);

    Exists(loctestnum, loctesterr, lst2, false, 22); 
    Remove(loctestnum, loctesterr, lst2, false, 22);

    Empty(loctestnum, loctesterr, lst2, false);
    Size(loctestnum, loctesterr, lst2, true, 8);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "End of list<int> Intesive Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void testCasiLimite(uint & testnum, uint & testerr){
  uint localtestnum=0;
  uint localtesterr=0;

  cout << "\n--------Test su Casi limite:--------\n\n";

  try{
    cout << "\n\n--LIST:--\n\n";

    {

    lasd::List<int> lista;
    RemoveFromFront(localtestnum, localtesterr, lista,false);
    FrontNRemove(localtestnum, localtesterr, lista, false, 0);

    InsertAtFront(localtestnum, localtesterr, lista, true, 5);
    InsertAtBack(localtestnum, localtesterr, lista, true, 12);

    lasd::List<int> lista2;

    EqualList(localtestnum, localtesterr, lista, lista2, false);
    NonEqualList(localtestnum, localtesterr, lista, lista2, true);

    lista.Clear();

    EqualList(localtestnum, localtesterr, lista, lista2, true);
    NonEqualList(localtestnum, localtesterr, lista, lista2, false);

    }

    {

      lasd::List<int> lista;

      lasd::Vector<int> vec{3};
      vec[0]=0;
      vec[1]=1;
      vec[2]=2;

      Remove(localtestnum, localtesterr, lista, false, 5);
      RemoveAll(localtestnum, localtesterr, lista, false, vec);
      RemoveSome(localtestnum, localtesterr, lista, false, vec);
      

      InsertAllM(localtestnum, localtesterr, lista, true, std::move(vec));
      vec[0]=0;
      vec[1]=5;
      vec[2]=2;
      InsertSomeM(localtestnum, localtesterr, lista, true, std::move(vec));
      vec[0]=57;

      InsertM(localtestnum, localtesterr, lista, true, std::move(vec[0]));

      vec[0]=0;
      vec[1]=1;
      vec[2]=2;

      lasd::List<int> lista2;

      InsertAllC(localtestnum, localtesterr, lista2, true, vec);
      vec[0]=3;
      InsertSomeC(localtestnum, localtesterr, lista2, true, vec);
      vec[0]=89;

      InsertC(localtestnum, localtesterr, lista2, true, vec[0]);

      lasd::List<int> lista3;

      NonEqualLinear(localtestnum, localtesterr, lista3, vec, true);
      vec.Clear();
      EqualLinear(localtestnum, localtesterr, lista3, vec, true);

      GetAt(localtestnum, localtesterr, lista3, false, 0, 0);
      GetFront(localtestnum, localtesterr, lista3, false, 0);
      GetBack(localtestnum, localtesterr, lista3, false, 0);

      SetAt(localtestnum, localtesterr, lista3, false, 0, 0);
      SetFront(localtestnum, localtesterr, lista3, false, 1);
      SetBack(localtestnum, localtesterr, lista3, false, 2);
      

    }

    cout << "\n\n--QUEUE:--\n\n";

    {

      lasd::QueueVec<int> queue;
      lasd::QueueVec<int> queue2;
      
      Head(localtestnum,localtesterr, queue, false, 0);
      Dequeue(localtestnum,localtesterr, queue, false);
      HeadNDequeue(localtestnum,localtesterr, queue, false, 0);
      EnqueueC(localtestnum,localtesterr, queue, 7);
      EnqueueM(localtestnum,localtesterr, queue, 6);
      EqualQueue(localtestnum,localtesterr, queue, queue2, false);

      queue=queue2;

      lasd::Vector<int> vec{0};

      lasd::QueueVec<int> que(std::move(vec));

      Head(localtestnum,localtesterr, que, false, 0);
      Dequeue(localtestnum,localtesterr, que, false);
      HeadNDequeue(localtestnum,localtesterr, que, false, 0);
      EnqueueC(localtestnum,localtesterr, que, 7);
      EnqueueM(localtestnum,localtesterr, que, 6);


    }

    {

      lasd::QueueLst<int> queue;
      lasd::QueueLst<int> queue2;
      
      Head(localtestnum,localtesterr, queue, false, 0);
      Dequeue(localtestnum,localtesterr, queue, false);
      HeadNDequeue(localtestnum,localtesterr, queue, false, 0);
      EnqueueC(localtestnum,localtesterr, queue, 7);
      EnqueueM(localtestnum,localtesterr, queue, 6);
      EqualQueue(localtestnum,localtesterr, queue, queue2, false);

      queue=queue2;

      lasd::Vector<int> vec{0};

      lasd::QueueLst<int> que(std::move(vec));

      Head(localtestnum,localtesterr, que, false, 0);
      Dequeue(localtestnum,localtesterr, que, false);
      HeadNDequeue(localtestnum,localtesterr, que, false, 0);
      EnqueueC(localtestnum,localtesterr, que, 7);
      EnqueueM(localtestnum,localtesterr, que, 6);


    }

    cout << "\n\n--STACK:--\n\n";

    {
      lasd::StackVec<int> stk;
      lasd::StackVec<int> stk2;

      Top(localtestnum,localtesterr, stk, false, 0);
      Pop(localtestnum,localtesterr, stk, false);
      TopNPop(localtestnum,localtesterr, stk, false, 0);
      PushC(localtestnum,localtesterr, stk, 7);
      PushM(localtestnum,localtesterr, stk, 6);
      EqualStack(localtestnum,localtesterr, stk, stk2, false);

      stk=stk2;

      lasd::Vector<int> vec{0};

      lasd::StackVec<int> que(std::move(vec));

      Top(localtestnum,localtesterr, que, false, 0);
      Pop(localtestnum,localtesterr, que, false);
      TopNPop(localtestnum,localtesterr, que, false, 0);
      PushC(localtestnum,localtesterr, que, 7);
      PushM(localtestnum,localtesterr, que, 6);

      
    }

    { 
      lasd::StackLst<int> stk;
      lasd::StackLst<int> stk2;

      Top(localtestnum,localtesterr, stk, false, 0);
      Pop(localtestnum,localtesterr, stk, false);
      TopNPop(localtestnum,localtesterr, stk, false, 0);
      PushC(localtestnum,localtesterr, stk, 7);
      PushM(localtestnum,localtesterr, stk, 6);
      EqualStack(localtestnum,localtesterr, stk, stk2, false);


      stk=stk2;

      lasd::Vector<int> vec{0};

      lasd::StackLst<int> que(std::move(vec));

      Top(localtestnum,localtesterr, que, false, 0);
      Pop(localtestnum,localtesterr, que, false);
      TopNPop(localtestnum,localtesterr, que, false, 0);
      PushC(localtestnum,localtesterr, que, 7);
      PushM(localtestnum,localtesterr, que, 6);

      

    }




  }catch(...){
    std::cout << "\nUnmanaged Error\n";
  }

  testnum+=localtestnum;
  testerr+=localtesterr;

}


/* ************************************************************************** */
void stestFlorindo(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  stestVectorOfVectorInt(loctestnum, loctesterr);
  stestVectorOfVectorDouble(loctestnum, loctesterr);
  stestVectorOfVectorString(loctestnum, loctesterr);
  stestVectorOfList(loctestnum, loctesterr);
  //stestVectorIntensivo(loctestnum, loctesterr);
  stestVector_ListInt(loctestnum, loctesterr);
  stestVector_ListString(loctestnum, loctesterr);
  stestQueueVecInt(loctestnum, loctesterr);
  stestQueueListInt(loctestnum, loctesterr);
  stestStackVecInt(loctestnum, loctesterr);
  stestStackLstInt(loctestnum, loctesterr);
  testCasiLimite(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;

}

void stestFlorindoSecondo(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  TestListeRemove(testnum , testerr);

  testnum += loctestnum;
  testerr += loctesterr;
  
}


void TestFlorindoA(uint & testnum, uint & testerr) {
  stestFlorindo(testnum, testerr); //1
  stestFlorindoSecondo(testnum, testerr);
  cout << endl << "Test A (Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}

/* ******************************************************************************* */
/*                                 Test Esercizio 2                                */
/* ******************************************************************************* */

void RemoveAllWhitMax(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of BST<int> Remove all Test:*****************" << endl;
  try {

    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    MaxNRemove(loctestnum, loctesterr, bst, true, 5);
    MaxNRemove(loctestnum, loctesterr, bst, true, 4);
    MaxNRemove(loctestnum, loctesterr, bst, true, 3);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    MaxNRemove(loctestnum, loctesterr, bst, true, 2);
    MaxNRemove(loctestnum, loctesterr, bst, true, 1);
    MaxNRemove(loctestnum, loctesterr, bst, true, 0);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    Empty(loctestnum, loctesterr, bst, false);
    Size(loctestnum, loctesterr, bst, true, 6);

    RemoveMax(loctestnum, loctesterr, bst, true);
    RemoveMax(loctestnum, loctesterr, bst, true);
    RemoveMax(loctestnum, loctesterr, bst, true);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    RemoveMax(loctestnum, loctesterr, bst, true);
    RemoveMax(loctestnum, loctesterr, bst, true);
    RemoveMax(loctestnum, loctesterr, bst, true);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);

    Size(loctestnum, loctesterr, bst, true, 3);

    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Root(loctestnum,loctesterr,bst, true, 4);
    Min(loctestnum,loctesterr,bst, true, 1);
    Max(loctestnum,loctesterr,bst, true, 4);
    MaxNRemove(loctestnum, loctesterr, bst, true, 4);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, bst, true, 2);
    Root(loctestnum,loctesterr,bst, true, 3);
    MaxNRemove(loctestnum, loctesterr, bst, true, 3);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, bst, true, 1);
    Root(loctestnum,loctesterr,bst, true, 1);
    IsLeaf<int>(loctestnum,loctesterr, bst.Root(),true);
    bst.Clear();
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 2);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    Size(loctestnum, loctesterr, bst, true, 3);

    IsLeaf<int>(loctestnum,loctesterr, bst.Root().LeftChild().LeftChild(), true);
    MinNRemove(loctestnum, loctesterr, bst, true, 1);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, bst, true, 2);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    Size(loctestnum, loctesterr, bst, true, 3);
    Remove(loctestnum, loctesterr, bst, true, 2);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, bst, true, 2);
    Root(loctestnum,loctesterr,bst, true, 5);
    IsLeaf<int>(loctestnum,loctesterr, bst.Root().LeftChild(), true);
    GetElement(loctestnum,loctesterr,bst.Root().LeftChild(), true , 1);
    MaxNRemove(loctestnum, loctesterr, bst, true, 5);
    MaxNRemove(loctestnum, loctesterr, bst, true, 1);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine del test della cancellazione di tutti i elementi del BST tramite la rimozione del MAX (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void RemoveAllWhitMin(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of BST<int> Remove all Test:*****************" << endl;
  try {

    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    MinNRemove(loctestnum, loctesterr, bst, true, 0);
    MinNRemove(loctestnum, loctesterr, bst, true, 1);
    MinNRemove(loctestnum, loctesterr, bst, true, 2);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    MinNRemove(loctestnum, loctesterr, bst, true, 3);
    MinNRemove(loctestnum, loctesterr, bst, true, 4);
    MinNRemove(loctestnum, loctesterr, bst, true, 5);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    Empty(loctestnum, loctesterr, bst, false);
    Size(loctestnum, loctesterr, bst, true, 6);

    RemoveMin(loctestnum, loctesterr, bst, true);
    RemoveMin(loctestnum, loctesterr, bst, true);
    IsLeaf<int>(loctestnum,loctesterr, bst.Root().LeftChild(), true);
    GetElement(loctestnum,loctesterr, bst.Root().LeftChild(), true,2);
    RemoveMin(loctestnum, loctesterr, bst, true);
    lasd::BST<int> bst2(bst);
    IsLeaf<int>(loctestnum,loctesterr, bst2.Root().RightChild().RightChild(), true);
    GetElement(loctestnum,loctesterr, bst2.Root().RightChild().RightChild(), true,5);
    EqualBST(loctestnum, loctesterr, bst, bst2);
    TraverseInOrder(loctestnum, loctesterr, bst2, true, &TraversePrint<int>);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    RemoveMin(loctestnum, loctesterr, bst, true);
    RemoveMin(loctestnum, loctesterr, bst, true);
    NonEqualBST(loctestnum, loctesterr, bst, bst2);
    RemoveMin(loctestnum, loctesterr, bst, true);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    bst.Clear();
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    bst = std::move(bst2);
    NonEqualBST(loctestnum, loctesterr, bst, bst2);
    TraverseInOrder(loctestnum, loctesterr, bst2, true, &TraversePrint<int>);
    InsertC(loctestnum, loctesterr, bst, false, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, false, 4);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    Root(loctestnum,loctesterr,bst, true, 3);

    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine del test della cancellazione di tutti i elementi del BST tramite la rimozione del MIN (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void RemoveAllWhitPredecessore(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of BST<int> Remove all Test:*****************" << endl;
  try {

    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    PredecessorNRemove(loctestnum, loctesterr, bst, true, 6, 5);
    PredecessorNRemove(loctestnum, loctesterr, bst, true, 5, 4);
    PredecessorNRemove(loctestnum, loctesterr, bst, true, 4, 3);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    PredecessorNRemove(loctestnum, loctesterr, bst, true, 3, 2);
    PredecessorNRemove(loctestnum, loctesterr, bst, true, 2, 1);
    PredecessorNRemove(loctestnum, loctesterr, bst, true, 1, 0);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    FoldInOrder(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 15);

    RemovePredecessor(loctestnum, loctesterr, bst, true, 3);
    RemovePredecessor(loctestnum, loctesterr, bst, true, 6);
    RemovePredecessor(loctestnum, loctesterr, bst, true, 1);
    RemovePredecessor(loctestnum, loctesterr, bst, true, 4);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    RemovePredecessor(loctestnum, loctesterr, bst, true, 2);
    RemovePredecessor(loctestnum, loctesterr, bst, true, 5);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    
    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine del test della cancellazione di tutti i elementi del BST tramite la rimozione del Predecessore (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void RemoveAllWhitSucessore(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of BST<int>/BST<String> Remove all Test:*****************" << endl;
  try {

    {

      lasd::BST<string> bst;

      Empty(loctestnum, loctesterr, bst, true);
      Size(loctestnum, loctesterr, bst, true, 0);

      Remove(loctestnum, loctesterr, bst, false, string("Ciaone."));

      InsertC(loctestnum, loctesterr, bst, true, string("D"));
      InsertC(loctestnum, loctesterr, bst, true, string("E"));
      InsertC(loctestnum, loctesterr, bst, true, string("B"));
      InsertC(loctestnum, loctesterr, bst, true, string("A"));
      InsertC(loctestnum, loctesterr, bst, true, string("C"));
      InsertC(loctestnum, loctesterr, bst, true, string("F"));

      Remove(loctestnum, loctesterr, bst, true, string("D"));
      Remove(loctestnum, loctesterr, bst, false, string("S"));

      TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<string>);

      lasd::BST<string> bst2(std::move(bst));

      Empty(loctestnum, loctesterr, bst2, false);
      Size(loctestnum, loctesterr, bst2, true, 5);

      NonEqualBST(loctestnum, loctesterr, bst, bst2);

      //ripeto
      bst2 = std::move(bst);

      Empty(loctestnum, loctesterr, bst2, true);
      Size(loctestnum, loctesterr, bst2, true, 0);

      Empty(loctestnum, loctesterr, bst, false);
      Size(loctestnum, loctesterr, bst, true, 5);

      NonEqualBST(loctestnum, loctesterr, bst, bst2);

      bst2 = bst;

      EqualBST(loctestnum, loctesterr, bst, bst2);

      lasd::Vector<string> vec(5);

      vec[0] = string("E");
      vec[1] = string("B");
      vec[2] = string("A");
      vec[3] = string("C");
      vec[4] = string("F");

      lasd::BST<string> bst3(std::move(vec));

      EqualBST(loctestnum, loctesterr, bst2, bst3);
    }

    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    TraversePreOrder(loctestnum, loctesterr, bst, true, &TraversePrint<double>);


    SuccessorNRemove(loctestnum, loctesterr, bst, true, 0, 1);
    SuccessorNRemove(loctestnum, loctesterr, bst, true, 1, 2);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    SuccessorNRemove(loctestnum, loctesterr, bst, true, 2, 3);
    SuccessorNRemove(loctestnum, loctesterr, bst, true, 3, 4);
    SuccessorNRemove(loctestnum, loctesterr, bst, true, 4, 5);
    SuccessorNRemove(loctestnum, loctesterr, bst, true, -1, 0);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    Empty(loctestnum, loctesterr, bst, false);
    Size(loctestnum, loctesterr, bst, true, 6);

    RemoveSuccessor(loctestnum, loctesterr, bst, true, 0);
    RemoveSuccessor(loctestnum, loctesterr, bst, true, 1);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    RemoveSuccessor(loctestnum, loctesterr, bst, true, 2);
    RemoveSuccessor(loctestnum, loctesterr, bst, true, 3);
    RemoveSuccessor(loctestnum, loctesterr, bst, true, 4);
    RemoveSuccessor(loctestnum, loctesterr, bst, true, -1);

    TraverseInOrder(loctestnum, loctesterr, bst,  true, &TraversePrint<int>);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine del test della cancellazione di tutti i elementi del BST tramite la rimozione del Sucessore (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void RemoveItem(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of BST<Double> Remove Test:*****************" << endl;
  try {

    lasd::BST<double> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 8.5);
    InsertC(loctestnum, loctesterr, bst, true, 7.2);
    InsertC(loctestnum, loctesterr, bst, true, 4.9);
    InsertC(loctestnum, loctesterr, bst, true, 9.36);
    InsertC(loctestnum, loctesterr, bst, true, 10.5);
    InsertC(loctestnum, loctesterr, bst, true, 11.23);

    Empty(loctestnum, loctesterr, bst, false);
    Size(loctestnum, loctesterr, bst, true, 6);

    TraversePreOrder(loctestnum, loctesterr, bst, true, &TraversePrint<double>);

    Remove(loctestnum, loctesterr, bst, true, 11.23);
    Remove(loctestnum, loctesterr, bst, true, 8.5);

    TraversePreOrder(loctestnum, loctesterr, bst, true, &TraversePrint<double>);
    FoldPreOrder(loctestnum, loctesterr, bst, true, &FoldAdd<double>, 0.0, 31.96);

    Remove(loctestnum, loctesterr, bst, true, 7.2);

    TraversePreOrder(loctestnum, loctesterr, bst, true, &TraversePrint<double>);

    Remove(loctestnum, loctesterr, bst, true, 10.5);
    TraversePreOrder(loctestnum, loctesterr, bst, true, &TraversePrint<double>);

    Empty(loctestnum, loctesterr, bst, false);
    Size(loctestnum, loctesterr, bst, true, 2);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine Test di prova della rimozione (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void RemoveItem2(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of BST<int> Remove Test:*****************" << endl;
  try {

    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 20);
    InsertC(loctestnum, loctesterr, bst, true, 15);
    InsertC(loctestnum, loctesterr, bst, true, 10);
    InsertC(loctestnum, loctesterr, bst, true, 7);
    InsertC(loctestnum, loctesterr, bst, true, 17);
    InsertC(loctestnum, loctesterr, bst, true, 16);
    InsertC(loctestnum, loctesterr, bst, true, 19);
    InsertC(loctestnum, loctesterr, bst, true, 11);
    InsertC(loctestnum, loctesterr, bst, true, 25);
    InsertC(loctestnum, loctesterr, bst, true, 23);
    InsertC(loctestnum, loctesterr, bst, true, 22);
    InsertC(loctestnum, loctesterr, bst, true, 24);
    InsertC(loctestnum, loctesterr, bst, true, 30);
    InsertC(loctestnum, loctesterr, bst, true, 31);
    InsertC(loctestnum, loctesterr, bst, true, 33);

    Empty(loctestnum, loctesterr, bst, false);
    Size(loctestnum, loctesterr, bst, true, 15);

    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Remove(loctestnum, loctesterr, bst, true, 7);
    Remove(loctestnum, loctesterr, bst, true, 16);

    Size(loctestnum, loctesterr, bst, true, 13);

    TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Remove(loctestnum, loctesterr, bst, true, 15);
    Size(loctestnum, loctesterr, bst, true, 12);

    TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    HasLeftChild<int>(loctestnum, loctesterr, bst.Root(), true);
    GetElement(loctestnum, loctesterr, bst.Root().LeftChild(), true, 17);

    Remove(loctestnum, loctesterr, bst, true, 20);
    Size(loctestnum, loctesterr, bst, true, 11);
    TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    GetElement(loctestnum, loctesterr, bst.Root(), true, 22);

    lasd::BST<int> bst2 {std::move(bst)};
  

    Remove(loctestnum, loctesterr, bst2, true, 31);
    Remove(loctestnum, loctesterr, bst2, true, 25);
    Size(loctestnum, loctesterr, bst2, true, 9);
    HasRightChild<int>(loctestnum, loctesterr, bst2.Root(), true);
    GetElement(loctestnum, loctesterr, bst2.Root().RightChild(), true, 30);
    TraverseBreadth(loctestnum, loctesterr, bst2, true, &TraversePrint<int>);

    lasd::BST<int> bst3 = bst2;
    EqualBT(loctestnum, loctesterr, bst3, bst2);

    bst3.Clear();
    TraverseBreadth(loctestnum, loctesterr, bst2, true, &TraversePrint<int>);
    NonEqualBT(loctestnum, loctesterr, bst3, bst2);

    lasd::BST<int> bst4 {};
    Root(loctestnum, loctesterr, bst4, false, 0);
    TraverseBreadth(loctestnum, loctesterr, bst4, true, &TraversePrint<int>);

    bst = std::move(bst4);

    Root(loctestnum, loctesterr, bst, false, 0);
    Size(loctestnum, loctesterr, bst, true, 0);
    Empty(loctestnum, loctesterr, bst, true);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine Test di prova della rimozione (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void VisiteInt(lasd::BinaryTree<int> & bt, uint & testnum, uint & testerr) {
  uint  loctestnum = testnum;
  uint loctesterr = testerr;
  try {
    Traverse(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    TraverseInOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    TraverseBreadth(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    Fold(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 28);
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 28);
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 28);
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 28);
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 28);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum = loctestnum;
  testerr = loctesterr;
}

void TraversMappaleCostructBTV(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of BTV<Iint> Remove Test:*****************" << endl;
  try {

    {
    lasd::Vector<int> vec;
    lasd::BinaryTreeVec<int> bt(vec);
    Size(loctestnum, loctesterr, bt, true, 0);
    Root(loctestnum, loctesterr, bt, false, 0);
    lasd::BinaryTreeVec<int> bt2(std::move(vec));

    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, bt2, true, &TraversePrint<int>);

    EqualBT(loctestnum, loctesterr, bt, bt2);
    

    lasd::BinaryTreeLnk<int> bt3;
    Root(loctestnum, loctesterr, bt3, false, 0);

    }

    lasd::Vector<int> vec(8);

    SetAt(loctestnum, loctesterr, vec, true, 0, 0);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 2);
    SetAt(loctestnum, loctesterr, vec, true, 3, 3);
    SetAt(loctestnum, loctesterr, vec, true, 4, 4);
    SetAt(loctestnum, loctesterr, vec, true, 5, 5);
    SetAt(loctestnum, loctesterr, vec, true, 6, 6);
    SetAt(loctestnum, loctesterr, vec, true, 7, 7);


    lasd::BinaryTreeVec<int> btv(vec);
    VisiteInt(btv,loctestnum,loctesterr);

    lasd::BinaryTreeVec<int> btv2(std::move(vec));
    VisiteInt(btv2,loctestnum,loctesterr);

    lasd::BinaryTreeVec<int> btv3(btv);
    VisiteInt(btv3,loctestnum,loctesterr);
    EqualBT(loctestnum, loctesterr, btv3, btv2);

    btv.Clear();
    VisiteInt(btv3,loctestnum,loctesterr);

    lasd::BinaryTreeVec<int> btv4(std::move(btv2));
    VisiteInt(btv4,loctestnum,loctesterr);

    NonEqualBT(loctestnum, loctesterr, btv4, btv2);

    btv2.Clear();
    Empty(loctestnum, loctesterr, btv2, true);
    VisiteInt(btv4,loctestnum,loctesterr);
    NonEqualBT(loctestnum, loctesterr, btv4, btv2);

    btv2 = std::move(btv4);
    NonEqualBT(loctestnum, loctesterr, btv4, btv2);
    VisiteInt(btv2,loctestnum,loctesterr);

    btv4.Clear();
    VisiteInt(btv2,loctestnum,loctesterr);
    NonEqualBT(loctestnum, loctesterr, btv4, btv2);

    btv = btv2;
    EqualBT(loctestnum, loctesterr, btv, btv2);
    VisiteInt(btv,loctestnum,loctesterr);

    //MapPreOrder(loctestnum, loctesterr, btv2, true, MapDoubleNPrint<int>);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Costruttori e operatori di assegnazione (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void TraversMappaleCostructBTL(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of BTL<Iint> Remove Test:*****************" << endl;
  try {

    {
    lasd::Vector<int> vec(8);

    SetAt(loctestnum, loctesterr, vec, true, 0, 0);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 2);
    SetAt(loctestnum, loctesterr, vec, true, 3, 3);
    SetAt(loctestnum, loctesterr, vec, true, 4, 4);
    SetAt(loctestnum, loctesterr, vec, true, 5, 5);
    SetAt(loctestnum, loctesterr, vec, true, 6, 6);
    SetAt(loctestnum, loctesterr, vec, true, 7, 7);

    lasd::BinaryTreeLnk<int> btl(vec);
    VisiteInt(btl,loctestnum,loctesterr);

    lasd::BinaryTreeLnk<int> btl2(std::move(vec));
    VisiteInt(btl2,loctestnum,loctesterr);
    EqualBT(loctestnum, loctesterr, btl2, btl);
    btl.Clear();
    NonEqualBT(loctestnum, loctesterr, btl2, btl);
    //std::cout<<(btl2 != btl);

    lasd::BinaryTreeLnk<int> btl3(btl2);
    VisiteInt(btl3,loctestnum,loctesterr);
    EqualBT(loctestnum, loctesterr, btl2, btl3);
    std::cout<<(btl2 == btl3);

    lasd::BinaryTreeLnk<int> btl4(std::move(btl2));
    VisiteInt(btl4,loctestnum,loctesterr);
    NonEqualBT(loctestnum, loctesterr, btl4, btl2);

    btl2 = std::move(btl4);
    VisiteInt(btl2,loctestnum,loctesterr);
    NonEqualBT(loctestnum, loctesterr, btl4, btl2);

    btl = btl2;
    EqualBT(loctestnum, loctesterr, btl, btl2);
    VisiteInt(btl,loctestnum,loctesterr);

  }
  lasd::Vector<int> vec{0};
  lasd::BinaryTreeLnk<int> btl(vec);
  Size(loctestnum, loctesterr, btl, true, 0);
  Root(loctestnum, loctesterr, btl, false, 0);
  lasd::BinaryTreeLnk<int> btl2(std::move(vec));
  Size(loctestnum, loctesterr, btl2, true, 0);
  Root(loctestnum, loctesterr, btl2, false, 0);
  EqualBT(loctestnum, loctesterr, btl, btl2);
  TraversePreOrder(loctestnum, loctesterr, btl, true, &TraversePrint<int>);

    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Costruttori e operatori di assegnazione (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void MutableIteratorTestPre(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori Mutabili Pre BST<int> Test:*****************" << endl;
  try {


    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    Min(loctestnum, loctesterr, bst, false, 0);
    Max(loctestnum, loctesterr, bst, false, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    lasd::BTPreOrderMutableIterator<int> Itr(bst);

    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 1);
    SetItrValue(loctestnum, loctesterr, Itr, true, 10);
    GetItrValue(loctestnum, loctesterr, Itr, true, 10);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    lasd::BTPreOrderIterator<int> Itr2(Itr);
    GetItrValue(loctestnum, loctesterr, Itr2, true, 2);

    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);
    TraversePreOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Itr.Reset();
    Terminated(loctestnum, loctesterr,Itr, false);
    lasd::BTPreOrderMutableIterator<int> Itr3(std::move(Itr));
    Terminated(loctestnum, loctesterr,Itr, true);

    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);
    ++Itr3;
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 10);
    SetItrValue(loctestnum, loctesterr, Itr3, true, 7);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 7);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 2);

    Itr = Itr3;
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);

    Itr.Reset();

    Itr = std::move(Itr3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);

    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void MutableIteratorTestPost(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori Mutabili Post BST<int> Test:*****************" << endl;
  try {


    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    Min(loctestnum, loctesterr, bst, false, 0);
    Max(loctestnum, loctesterr, bst, false, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    lasd::BTPostOrderMutableIterator<int> Itr(bst);

    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    SetItrValue(loctestnum, loctesterr, Itr, true, 10);
    GetItrValue(loctestnum, loctesterr, Itr, true, 10);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 1);
    ++Itr;
    lasd::BTPostOrderIterator<int> Itr2(Itr);
    GetItrValue(loctestnum, loctesterr, Itr2, true, 5);

    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);
    TraversePostOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Itr.Reset();
    Terminated(loctestnum, loctesterr,Itr, false);
    lasd::BTPostOrderMutableIterator<int> Itr3(std::move(Itr));
    Terminated(loctestnum, loctesterr,Itr, true);

    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);
    ++Itr3;
    TraversePostOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 10);
    SetItrValue(loctestnum, loctesterr, Itr3, true, 7);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 7);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 1);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 5);

    Itr = Itr3;
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);

    Itr.Reset();

    Itr = std::move(Itr3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);

    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void MutableIteratorTestIn(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori Mutabili In BST<int> Test:*****************" << endl;
  try {


    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    Min(loctestnum, loctesterr, bst, false, 0);
    Max(loctestnum, loctesterr, bst, false, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    lasd::BTInOrderMutableIterator<int> Itr(bst);

    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 1);
    SetItrValue(loctestnum, loctesterr, Itr, true, 10);
    GetItrValue(loctestnum, loctesterr, Itr, true, 10);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    lasd::BTInOrderIterator<int> Itr2(Itr);
    GetItrValue(loctestnum, loctesterr, Itr2, true, 3);

    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Itr.Reset();
    Terminated(loctestnum, loctesterr,Itr, false);
    lasd::BTInOrderMutableIterator<int> Itr3(std::move(Itr));
    Terminated(loctestnum, loctesterr,Itr, true);

    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);
    ++Itr3;
    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 10);
    SetItrValue(loctestnum, loctesterr, Itr3, true, 7);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 7);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 2);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);

    Itr = Itr3;
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);

    Itr.Reset();

    Itr = std::move(Itr3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);

    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void MutableIteratorTestBth(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori Mutabili Bth BST<int> Test:*****************" << endl;
  try {


    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    Min(loctestnum, loctesterr, bst, false, 0);
    Max(loctestnum, loctesterr, bst, false, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    lasd::BTBreadthMutableIterator<int> Itr(bst);

    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 1);
    SetItrValue(loctestnum, loctesterr, Itr, true, 10);
    GetItrValue(loctestnum, loctesterr, Itr, true, 10);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    lasd::BTBreadthIterator<int> Itr2(Itr);
    GetItrValue(loctestnum, loctesterr, Itr2, true, 0);

    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);
    TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Itr.Reset();
    Terminated(loctestnum, loctesterr,Itr, false);
    lasd::BTBreadthMutableIterator<int> Itr3(std::move(Itr));
    Terminated(loctestnum, loctesterr,Itr, true);

    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);
    ++Itr3;
    TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 10);
    SetItrValue(loctestnum, loctesterr, Itr3, true, 7);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 7);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 4);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);

    Itr = Itr3;
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);

    Itr.Reset();

    Itr = std::move(Itr3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);

    bst.Clear();
    lasd::BTBreadthMutableIterator<int> Itr10(bst);


    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void IteratorTestBth(uint & testnum, uint & testerr, const lasd::BinaryTree<int> & bt){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori BTV/BTL Bth<int> Test:*****************" << endl;
  try {

    lasd::BTBreadthIterator<int> Itr(bt);

    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 1);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    lasd::BTBreadthIterator<int> Itr2(Itr);
    GetItrValue(loctestnum, loctesterr, Itr2, true, 5);
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);
    TraverseBreadth(loctestnum, loctesterr, bt, true, &TraversePrint<int>);

    Itr.Reset();
    Terminated(loctestnum, loctesterr,Itr, false);
    lasd::BTBreadthIterator<int> Itr3(std::move(Itr));
    Terminated(loctestnum, loctesterr,Itr, true);

    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);
    ++Itr3;
    TraverseBreadth(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 1);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 4);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 5);

    Itr = Itr3;
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);

    Itr.Reset();

    Itr = std::move(Itr3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);

    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void IteratorTestPre(uint & testnum, uint & testerr, const lasd::BinaryTree<int> & bt){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori BTV/BTL Pre<int> Test:*****************" << endl;
  try {

    lasd::BTPreOrderIterator<int> Itr(bt);

    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 1);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    lasd::BTPreOrderIterator<int> Itr2(Itr);
    GetItrValue(loctestnum, loctesterr, Itr2, true, 0);
    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);
    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);

    Itr.Reset();
    Terminated(loctestnum, loctesterr,Itr, false);
    lasd::BTPreOrderIterator<int> Itr3(std::move(Itr));
    Terminated(loctestnum, loctesterr,Itr, true);

    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);
    ++Itr3;
    TraversePreOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 1);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 5);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);

    Itr = Itr3;
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);

    Itr.Reset();

    Itr = std::move(Itr3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);

    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void IteratorTestPost(uint & testnum, uint & testerr, const lasd::BinaryTree<int> & bt){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori BTV/BTL Post<int> Test:*****************" << endl;
  try {

    lasd::BTPostOrderIterator<int> Itr(bt);

    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 1);
    ++Itr;
    lasd::BTPostOrderIterator<int> Itr2(Itr);
    GetItrValue(loctestnum, loctesterr, Itr2, true, 2);
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);
    TraversePostOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);

    Itr.Reset();
    Terminated(loctestnum, loctesterr,Itr, false);
    lasd::BTPostOrderIterator<int> Itr3(std::move(Itr));
    Terminated(loctestnum, loctesterr,Itr, true);

    GetItrValue(loctestnum, loctesterr, Itr3, true, 5);
    ++Itr3;
    TraversePostOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 1);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 2);

    Itr = Itr3;
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);

    Itr.Reset();

    Itr = std::move(Itr3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 5);

    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void IteratorTestIn(uint & testnum, uint & testerr, const lasd::BinaryTree<int> & bt){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori BTV/BTL Post<int> Test:*****************" << endl;
  try {

    lasd::BTInOrderIterator<int> Itr(bt);

    GetItrValue(loctestnum, loctesterr, Itr, true, 5);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 1);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 0);
    ++Itr;
    lasd::BTInOrderIterator<int> Itr2(Itr);
    GetItrValue(loctestnum, loctesterr, Itr2, true, 3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);
    TraverseInOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);

    Itr.Reset();
    Terminated(loctestnum, loctesterr,Itr, false);
    lasd::BTInOrderIterator<int> Itr3(std::move(Itr));
    Terminated(loctestnum, loctesterr,Itr, true);

    GetItrValue(loctestnum, loctesterr, Itr3, true, 5);
    ++Itr3;
    TraverseInOrder(loctestnum, loctesterr, bt, true, &TraversePrint<int>);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 1);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 0);
    ++Itr3;
    GetItrValue(loctestnum, loctesterr, Itr3, true, 3);

    Itr = Itr3;
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 2);
    ++Itr;
    GetItrValue(loctestnum, loctesterr, Itr, true, 4);
    ++Itr;
    Terminated(loctestnum, loctesterr,Itr, true);

    Itr.Reset();

    Itr = std::move(Itr3);
    GetItrValue(loctestnum, loctesterr, Itr, true, 3);
    GetItrValue(loctestnum, loctesterr, Itr3, true, 5);

    

    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void IteratorTestInBigNumber(uint & testnum, uint & testerr, const lasd::BinaryTree<int> & bt , const lasd::LinearContainer<int> & lin){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************Begin of Iteratori BTV/BTL Post<int> Test:*****************" << endl;
  try {

    lasd::BTBreadthIterator<int> Itr(bt);
    
    ulong cont = 0;
    while(!Itr.Terminated()){
      GetItrValue(loctestnum, loctesterr, Itr, true, lin[cont]);
      ++Itr;
      cont++;
    }
    Terminated(loctestnum, loctesterr,Itr, true);

    //Itr.Clear();
    //Terminated(loctestnum, loctesterr,Itr, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test Iteratori (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void stestFlorindoAlberiBTS(uint & testnum, uint & testerr) {
  RemoveAllWhitMax(testnum , testerr);
  RemoveAllWhitMin(testnum , testerr);
  RemoveAllWhitPredecessore(testnum , testerr);
  RemoveAllWhitSucessore(testnum , testerr);
  RemoveItem(testnum , testerr);
  RemoveItem2(testnum , testerr);
}

void stestFlorindoAlberiVecELink(uint & testnum, uint & testerr) {
  TraversMappaleCostructBTV(testnum,testerr);
  TraversMappaleCostructBTL(testnum,testerr);
}


template <typename Data>
void EqualBTP(uint & testnum, uint & testerr, const lasd::BinaryTreeLnk<Data> & bt1, const lasd::BinaryTreeLnk<Data> & bt2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") QUIIIIIIIII " << ((tst = (bt1 == bt2)) ? "" : "not ") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}


void stestFlorindoIteratori(uint & testnum, uint & testerr) {
  MutableIteratorTestPre(testnum,testerr);
  MutableIteratorTestPost(testnum,testerr);
  MutableIteratorTestIn(testnum,testerr);
  MutableIteratorTestBth(testnum,testerr);
  {
    uint loctestnum = 0, loctesterr = 0;
    //BTL e BTV
    
    lasd::Vector<int> vec{6};

    SetAt(loctestnum,loctesterr, vec, true, 0,3);
    SetAt(loctestnum,loctesterr, vec, true,1,1);
    SetAt(loctestnum,loctesterr, vec, true,2,4);
    SetAt(loctestnum,loctesterr, vec, true,3,5);
    SetAt(loctestnum,loctesterr, vec, true,4,0);
    SetAt(loctestnum,loctesterr, vec, true,5,2);

    lasd::BinaryTreeVec<int> btv(vec);

    Empty(loctestnum,loctesterr, btv, false);
    Size(loctestnum,loctesterr, btv, true, 6);

    IteratorTestBth(testnum,testerr, btv);
    IteratorTestPre(testnum,testerr, btv);
    IteratorTestPost(testnum,testerr, btv);
    IteratorTestIn(testnum,testerr, btv);

    lasd::BinaryTreeLnk<int> btl(vec);

    IteratorTestBth(testnum,testerr, btl);
    IteratorTestPre(testnum,testerr, btl);
    IteratorTestPost(testnum,testerr, btl);
    IteratorTestIn(testnum,testerr, btl);

    testnum += loctestnum;
    testerr += loctesterr;
  }

  {
    uint loctestnum = 0, loctesterr = 0;
    lasd::Vector<int> vec{200};
    for (ulong i = 0; i < 200; i++){
      vec[i] = 2 * (i - 25);
      
    }
    
    lasd::BinaryTreeVec<int> btv(vec);
    

    IteratorTestInBigNumber(loctestnum, loctesterr, btv , vec);
    

    lasd::BinaryTreeLnk<int> btl(vec);
    lasd::BinaryTreeLnk<int> btl2(vec);
    //EqualBTP(loctestnum, loctesterr, btl2,btl);
    IteratorTestInBigNumber(loctestnum, loctesterr, btl , vec);
    //Traverse(loctestnum, loctesterr, btl, true, &TraversePrint<int>);
    //Traverse(loctestnum, loctesterr, btl2, true, &TraversePrint<int>);
  

    testnum += loctestnum;
    testerr += loctesterr;
  }
}


void TestFlorindoB(uint & testnum, uint & testerr) {

  cout << endl << "~*~#~*~ Test Alberi e Iteratori ~*~#~*~ " << endl;
  stestFlorindoAlberiBTS(testnum, testerr); //1
  stestFlorindoAlberiVecELink(testnum,testerr);
  stestFlorindoIteratori(testnum,testerr);
  cout << endl << "Test B(Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}


/* ******************************************************************************* */
/*                                 Test Esercizio 3                                */
/* ******************************************************************************* */

void HashMapTestCLS(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************HashMapCLS<int> Move and copy assegmaneto e costruttore Test:*****************" << endl;
  try {
    {
      lasd::HashTableClsAdr<int> htclsadr{5};
      // InsertC(loctestnum,loctesterr,htclsadr,vec);
      // CountHT(loctestnum,loctesterr,htclsadr,vec,127);
      
      InsertC(loctestnum, loctesterr, htclsadr, 5);
      InsertC(loctestnum, loctesterr, htclsadr, 6);
      InsertC(loctestnum, loctesterr, htclsadr, 7);
      InsertC(loctestnum, loctesterr, htclsadr, 8);
      InsertC(loctestnum, loctesterr, htclsadr, 9);

      Size(loctestnum, loctesterr, htclsadr , true, 5);

      Exists(loctestnum, loctesterr, htclsadr, true, 6);
      Exists(loctestnum, loctesterr, htclsadr, false, 11);
      Exists(loctestnum, loctesterr, htclsadr, true, 9);

      Remove(loctestnum, loctesterr, htclsadr, 9);

      Size(loctestnum, loctesterr, htclsadr , true, 4);
      Exists(loctestnum, loctesterr, htclsadr, false, 9);

      lasd::HashTableClsAdr<int> htclsadr3{0};
      InsertM(loctestnum, loctesterr, htclsadr3, 10);
      Size(loctestnum, loctesterr, htclsadr3 , true, 1);
      Exists(loctestnum, loctesterr, htclsadr3, true, 10);
      NonEqualHT(loctestnum,loctesterr,htclsadr,htclsadr3);

      lasd::HashTableClsAdr<int> htclsadr2{5};
      
      htclsadr2 = htclsadr;

      EqualHT(loctestnum,loctesterr,htclsadr,htclsadr2);

      Remove(loctestnum, loctesterr, htclsadr, 5);
      Remove(loctestnum, loctesterr, htclsadr, 6);
      Remove(loctestnum, loctesterr, htclsadr, 7);
      Remove(loctestnum, loctesterr, htclsadr, 8);
      Size(loctestnum, loctesterr, htclsadr , true, 0);
      Exists(loctestnum, loctesterr, htclsadr, false, 6);

      NonEqualHT(loctestnum,loctesterr,htclsadr,htclsadr2);

      htclsadr = std::move(htclsadr2);
      Size(loctestnum, loctesterr, htclsadr , true, 4);
      Size(loctestnum, loctesterr, htclsadr2 , true, 0);

      Exists(loctestnum, loctesterr, htclsadr, true, 6);
      Exists(loctestnum, loctesterr, htclsadr, false, 11);

      Exists(loctestnum, loctesterr, htclsadr2, false, 6);

      lasd::Vector<int> vec(4);
      vec[0] = 5;
      vec[1] = 6;
      vec[2] = 7;
      vec[3] = 8;

      lasd::HashTableClsAdr<int> htclsadr5{htclsadr};
      EqualHT(loctestnum,loctesterr,htclsadr,htclsadr5);
      Size(loctestnum, loctesterr, htclsadr5 , true, 4);
      Empty(loctestnum, loctesterr, htclsadr5, false);
      CountHT(loctestnum, loctesterr, htclsadr5, vec,4);

      lasd::HashTableClsAdr<int> htclsadr6{std::move(htclsadr)};
      EqualHT(loctestnum,loctesterr,htclsadr6,htclsadr5);
      Size(loctestnum, loctesterr, htclsadr6 , true, 4);
      Empty(loctestnum, loctesterr, htclsadr6, false);
      CountHT(loctestnum, loctesterr, htclsadr6, vec,4);

    }

    lasd::Vector<int> con2(127);
      for (uint i = 0; i < 127; i++) {
        con2[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
      }

    lasd::Vector<int> con = con2;
    lasd::HashTableClsAdr<int> ht(83, std::move(con2));
    
    lasd::Vector<int> vec(50);
    for (int i = 0; i < 50; ++i) {
      vec[i] = 2 * (i - 25);
    }

    Size(loctestnum, loctesterr, ht, true, 125);
    for (int i = 0; i < 127; i += 17) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    for (int i = 0; i < 127; i += 24) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 119);
    for (int i = 0; i < 127; i += 24) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 1);
    for (int i = 0; i < 127; i += 12) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 125);
    for (int i = 0; i < 127; i += 20) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 2);
    for (int i = 0; i < 127; i += 17) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 117);
    for (int i = 0; i < 127; i += 17) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 2);
    for (int i = 0; i < 127; i += 7) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 119);
    for (int i = 0; i < 127; i += 7) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 2);
    ht.Resize(2003);
    for (int i = 0; i < 127; i += 17) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
   
    ht.Resize(4001);
    Size(loctestnum, loctesterr, ht, true, 125);
    ht.Resize(61);
    CountHT(loctestnum, loctesterr, ht, vec, 2);
    Empty(loctestnum, loctesterr, ht, false);
    ht.Clear();
    Empty(loctestnum, loctesterr, ht, true);
    Size(loctestnum, loctesterr, ht, true, 0);
    InsertC(loctestnum, loctesterr, ht, con);
    Empty(loctestnum, loctesterr, ht, false);
    Size(loctestnum, loctesterr, ht, true, 125);
    CountHT(loctestnum, loctesterr, ht, vec,2);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test HashMap (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

template <typename Data>
void InsertCCheck(uint & testnum, uint & testerr, lasd::DictionaryContainer<Data> & con, const lasd::TraversableContainer<Data> & mc, bool chk) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Insertion in the dictionary container of the values of the given linear container: ";
    std::cout << ((tst = (con.InsertAll(mc) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}


template <typename Data>
void RemoveCCheck(uint & testnum, uint & testerr, lasd::DictionaryContainer<Data> & con, const lasd::TraversableContainer<Data> & mc, bool chk) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Insertion in the dictionary container of the values of the given linear container: ";
    std::cout << ((tst = (con.RemoveAll(mc) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}


void ZeroTestHashMapCLS(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************HashMapCLS<int> Zero Test:*****************" << endl;
  try {
    
    lasd::Vector<int> vec(0);

    lasd::HashTableClsAdr<int> htclsadr{0};
    Empty(loctestnum, loctesterr, htclsadr, true);
    Size(loctestnum, loctesterr, htclsadr, true, 0);
    CountHT(loctestnum, loctesterr, htclsadr, vec, 0);
    InsertCCheck(loctestnum, loctesterr, htclsadr, vec, true);
    RemoveCCheck(loctestnum, loctesterr, htclsadr, vec, true);
    htclsadr.Resize(0);
    Empty(loctestnum, loctesterr, htclsadr, true);
    Size(loctestnum, loctesterr, htclsadr, true, 0);
    CountHT(loctestnum, loctesterr, htclsadr, vec, 0);
    InsertC(loctestnum, loctesterr, htclsadr, vec);
    htclsadr.Resize(1000);
    Size(loctestnum, loctesterr, htclsadr, true, 0);
    Empty(loctestnum, loctesterr, htclsadr, true);
    htclsadr.Resize(0);
    lasd::HashTableClsAdr<int> htclsadr2{htclsadr};
    Size(loctestnum, loctesterr, htclsadr2, true, 0);
    Empty(loctestnum, loctesterr, htclsadr2, true);

    lasd::HashTableClsAdr<int> htclsadr3{0,vec};
    Size(loctestnum, loctesterr, htclsadr3, true, 0);
    Empty(loctestnum, loctesterr, htclsadr3, true);

    lasd::HashTableClsAdr<int> htclsadr6{vec};
    Size(loctestnum, loctesterr, htclsadr6, true, 0);
    Empty(loctestnum, loctesterr, htclsadr6, true);

    lasd::Vector<int> vec2 = vec;

    lasd::HashTableClsAdr<int> htclsadr7{std::move(vec)};
    Size(loctestnum, loctesterr, htclsadr7, true, 0);
    Empty(loctestnum, loctesterr, htclsadr7, true);

  
    lasd::HashTableClsAdr<int> htclsadr4{0,std::move(vec2)};
    Size(loctestnum, loctesterr, htclsadr4, true, 0);
    Empty(loctestnum, loctesterr, htclsadr4, true);

    lasd::HashTableClsAdr<int> htclsadr5{std::move(htclsadr)};
    Size(loctestnum, loctesterr, htclsadr5, true, 0);
    Empty(loctestnum, loctesterr, htclsadr5, true);


    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test HashMap (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void TestHashMapRandomNumberGN(uint & testnum, uint & testerr,lasd::HashTable<int> & ht, const lasd::LinearContainer<int> & con){
  uint loctestnum = 0, loctesterr = 0;
  try {

    lasd::Vector<int> vec(120);
    for (uint i = 0; i < 120; i++) {
      vec[i] = pow(-3, i % 14) * ((61 * i + 19) % 120);
    }

    //Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    Size(loctestnum, loctesterr, ht, true, 293);
    for (int i = 0; i < 300; i += 10) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 27);
    for (int i = 0; i < 300; i += 2) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 150);

    for (int i = 0; i < 300; i += 150) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 13);

    for (int i = 0; i <300; i += 12) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }

    Size(loctestnum, loctesterr, ht, true, 175);
    for (int i = 0; i < 300; i += 12) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }

    ht.Resize(50000);
    Size(loctestnum, loctesterr, ht, true, 175);
    ht.Resize(258);
    CountHT(loctestnum, loctesterr, ht, vec, 15);
    Empty(loctestnum, loctesterr, ht, false);
    ht.Clear();
    Empty(loctestnum, loctesterr, ht, true);
    Size(loctestnum, loctesterr, ht, true, 0);
    InsertC(loctestnum, loctesterr, ht, con);
    Empty(loctestnum, loctesterr, ht, false);
    Size(loctestnum, loctesterr, ht, true, 293);
    CountHT(loctestnum, loctesterr, ht, vec, 27);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test HashMap (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void TestHashMapRandomNumberGNM(uint & testnum, uint & testerr,lasd::HashTable<int> & ht, const lasd::LinearContainer<int> & con){
  uint loctestnum = 0, loctesterr = 0;
  try {

    lasd::Vector<int> vec(120);
    for (uint i = 0; i < 120; i++) {
      vec[i] = pow(-3, i % 14) * ((61 * i + 19) % 120);
    }

    //Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    Size(loctestnum, loctesterr, ht, true, 293);
    for (int i = 0; i < 300; i++) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }

    for (int i = 0; i < 300; i += 10) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 27);
    for (int i = 0; i < 300; i += 2) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 150);

    for (int i = 0; i < 300; i += 150) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 13);

    for (int i = 0; i <300; i += 12) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }

    Size(loctestnum, loctesterr, ht, true, 175);
    for (int i = 0; i < 300; i += 12) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }

    ht.Resize(50000);
    Size(loctestnum, loctesterr, ht, true, 175);
    ht.Resize(258);
    CountHT(loctestnum, loctesterr, ht, vec, 15);
    Empty(loctestnum, loctesterr, ht, false);
    ht.Clear();
    Empty(loctestnum, loctesterr, ht, true);
    Size(loctestnum, loctesterr, ht, true, 0);
    InsertC(loctestnum, loctesterr, ht, con);
    Empty(loctestnum, loctesterr, ht, false);
    Size(loctestnum, loctesterr, ht, true, 293);
    CountHT(loctestnum, loctesterr, ht, vec, 27);
    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test HashMap (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}



void TestHashMapRandomNumber(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************HashMapRandomNumber<int> Test:*****************" << endl;
  try {

    lasd::HashTableOpnAdr<int> htopnadr{0};
    htopnadr.Resize(100);

    lasd::Vector<int> vec(300);
    for (uint i = 0; i < 300; i++) {
      vec[i] = pow(-3, i % 14) * ((31 * i + 19) % 300);
    }
    //Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    lasd::HashTableOpnAdr<int> htopnadr2{120, vec};
    cout << endl << "Begin of HashTableOpnAdr<int> Test:" << endl;
    TestHashMapRandomNumberGN(loctestnum, loctesterr, htopnadr2, vec);

    lasd::HashTableClsAdr<int> htclsadr{120, vec};
    cout << endl << "Begin of HashTableClsAdr<int> Test:" << endl;
    TestHashMapRandomNumberGN(loctestnum, loctesterr, htclsadr, vec);
    {
      lasd::Vector<int> vec2 = vec;
      lasd::Vector<int> vec3 = vec;
      lasd::HashTableOpnAdr<int> htopnadr2{120, std::move(vec3)};
      cout << endl << "Begin of HashTableOpnAdr Move<int> Test:" << endl;
      TestHashMapRandomNumberGNM(loctestnum, loctesterr, htopnadr2, vec);

      lasd::HashTableClsAdr<int> htclsadr{120, std::move(vec2)};
      cout << endl << "Begin of HashTableClsAdr Move<int> Test:" << endl;
      TestHashMapRandomNumberGNM(loctestnum, loctesterr, htclsadr, vec);
    }
    

    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "\nFine test HashMapRandomNumber (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void ClsAdr(uint & testnum,uint & testerr){
  uint localtestnum=0;
  uint localtesterr=0;

  try{

    cout << endl << "*****************HashMapTest Closed<int> Test:*****************" << endl;

    {

      lasd::HashTableClsAdr<int> clsHash{5};

      InsertM(localtestnum, localtesterr, clsHash, 5);
      InsertM(localtestnum, localtesterr, clsHash, 6);
      InsertM(localtestnum, localtesterr, clsHash, 7);
      InsertM(localtestnum, localtesterr, clsHash, 8);
      InsertM(localtestnum, localtesterr, clsHash, 9);

      Size(localtestnum, localtesterr, clsHash, true, 5);

      Exists(localtestnum, localtesterr, clsHash, true, 6);
      Exists(localtestnum, localtesterr, clsHash, false, 11);
      Exists(localtestnum, localtesterr, clsHash, true, 9);

      Remove(localtestnum, localtesterr, clsHash, 9);

      Size(localtestnum, localtesterr, clsHash, true, 4);
      Exists(localtestnum, localtesterr, clsHash, false, 9);

      clsHash.Clear();

      Size(localtestnum, localtesterr, clsHash, true, 0);

      InsertM(localtestnum, localtesterr, clsHash, 5);
      InsertM(localtestnum, localtesterr, clsHash, 6);

      Size(localtestnum, localtesterr, clsHash, true, 2);

      clsHash.Resize(1);

      Size(localtestnum, localtesterr, clsHash, true, 2);

      Exists(localtestnum, localtesterr, clsHash, true, 5);
      Exists(localtestnum, localtesterr, clsHash, true, 6);
    }

    {
      lasd::HashTableClsAdr<int> clsHash{0};
      lasd::HashTableClsAdr<int> clsHash2(clsHash);

      EqualHT(localtestnum, localtesterr,clsHash, clsHash2);

      lasd::HashTableClsAdr<int> clsHashCopy{0};

      Empty(localtestnum, localtesterr, clsHash, true);

      Size(localtestnum, localtesterr, clsHash, true, 0);

      InsertC(localtestnum, localtesterr, clsHash, 1);
      InsertC(localtestnum, localtesterr, clsHash, 67);
      InsertC(localtestnum, localtesterr, clsHash, 92);
      InsertC(localtestnum, localtesterr, clsHash, 6);

      Empty(localtestnum, localtesterr, clsHash, false);

      Size(localtestnum, localtesterr, clsHash, true, 4);

      Empty(localtestnum, localtesterr, clsHashCopy, true);

      Size(localtestnum, localtesterr, clsHashCopy, true, 0);


      clsHashCopy=clsHash;

      Empty(localtestnum, localtesterr, clsHashCopy, false);


      Exists(localtestnum, localtesterr, clsHashCopy, true, 1);
      Exists(localtestnum, localtesterr, clsHashCopy, true, 67);
      Exists(localtestnum, localtesterr, clsHashCopy, true, 92);
      Exists(localtestnum, localtesterr, clsHashCopy, true, 6);

      lasd::HashTableClsAdr<int> clsHashCopy2{std::move(clsHashCopy)};

      Exists(localtestnum, localtesterr, clsHashCopy2, true, 1);
      Exists(localtestnum, localtesterr, clsHashCopy2, true, 67);
      Exists(localtestnum, localtesterr, clsHashCopy2, true, 92);
      Exists(localtestnum, localtesterr, clsHashCopy2, true, 6);

      lasd::HashTableClsAdr<int> clsHashCopy3;

      clsHashCopy3=std::move(clsHashCopy2);

      Exists(localtestnum, localtesterr, clsHashCopy3, true, 1);
      Exists(localtestnum, localtesterr, clsHashCopy3, true, 67);
      Exists(localtestnum, localtesterr, clsHashCopy3, true, 92);
      Exists(localtestnum, localtesterr, clsHashCopy3, true, 6);

      Empty(localtestnum, localtesterr, clsHashCopy2, true);

      clsHashCopy2=std::move(clsHashCopy3);

      Empty(localtestnum, localtesterr, clsHashCopy2, false);

      Exists(localtestnum, localtesterr, clsHashCopy2, true, 1);
      Exists(localtestnum, localtesterr, clsHashCopy2, true, 67);
      Exists(localtestnum, localtesterr, clsHashCopy2, true, 92);
      Exists(localtestnum, localtesterr, clsHashCopy2, true, 6);

      //clsHashCopy2.Resize();


    }

  }catch(...){
    cout<<"UNMANAGED ERROR"<< endl;
  }

  testnum+=localtestnum;
  testerr+=localtesterr;

}



void EquelTestDoubleCls(uint & testnum, uint & testerr,lasd::HashTableClsAdr<double> & ht, const lasd::LinearContainer<double> & con){
  uint loctestnum = 0, loctesterr = 0;
  try {

    lasd::Vector<double> vec(120);
    for (uint i = 0; i < 120; i++) {
      vec[i] = (pow(-3, i % 17) * ((41 * i + 88) % 120)) / (31 * pow(-6, i % 3));
    }

    lasd::HashTableClsAdr<double> Hash = ht;
    EqualHT(loctestnum,loctesterr,Hash,ht);
    
    //Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    Size(loctestnum, loctesterr, ht, true, 490);
    CountHT(loctestnum, loctesterr, ht, con, 500);
    CountHT(loctestnum, loctesterr, ht, vec, 7);

    for (int i = 0; i < 120; i++) {
      Remove(loctestnum, loctesterr, ht, vec[i]);
    }

    NonEqualHT(loctestnum,loctesterr,Hash,ht);

    Size(loctestnum, loctesterr, ht, true, 483);
    CountHT(loctestnum, loctesterr, ht, vec, 0);

    vec.Clear();
    vec.Resize(300);
    for (uint i = 0; i < 300; i++) {
      vec[i] = (pow(-3, i % 27) * ((41 * i + 88) % 300)) / (31 * pow(-6, i % 12));
    }

    lasd::HashTableClsAdr<double> Hash4 = Hash;

    ht = std::move(Hash);
    NonEqualHT(loctestnum,loctesterr,Hash,ht);

    
    ht = Hash4;
    EqualHT(loctestnum,loctesterr,Hash4,ht);

    for (int i = 0; i < 300; i++) {
      InsertC(loctestnum, loctesterr, ht, vec[i]);
    }


    Size(loctestnum, loctesterr, ht, true, 780);
    CountHT(loctestnum, loctesterr, ht, vec, 300);
    //ht.stamp();

    //Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    for (int i = 0; i < 500; i++) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }

    CountHT(loctestnum, loctesterr, ht, vec, 292);
    Size(loctestnum, loctesterr, ht, true, 290);
    NonEqualHT(loctestnum,loctesterr,Hash,ht);
    lasd::HashTableClsAdr<double> Hash2 = ht;

    ht.Resize(350);
    EqualHT(loctestnum,loctesterr,Hash2,ht);
    ht.Resize(1);
    EqualHT(loctestnum,loctesterr,Hash2,ht);
    ht.Resize(0);
    NonEqualHT(loctestnum,loctesterr,Hash2,ht);
  
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test HashMap (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}


void EquelTestDoubleOpn(uint & testnum, uint & testerr,lasd::HashTableOpnAdr<double> & ht, const lasd::LinearContainer<double> & con){
  uint loctestnum = 0, loctesterr = 0;
  try {

    lasd::Vector<double> vec(120);
    for (uint i = 0; i < 120; i++) {
      vec[i] = (pow(-3, i % 17) * ((41 * i + 88) % 120)) / (31 * pow(-6, i % 3));
    }

    lasd::HashTableOpnAdr<double> Hash = ht;
    EqualHT(loctestnum,loctesterr,Hash,ht);
    
    //Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    Size(loctestnum, loctesterr, ht, true, 490);
    CountHT(loctestnum, loctesterr, ht, con, 500);
    CountHT(loctestnum, loctesterr, ht, vec, 7);

    for (int i = 0; i < 120; i++) {
      Remove(loctestnum, loctesterr, ht, vec[i]);
    }

    NonEqualHT(loctestnum,loctesterr,Hash,ht);

    Size(loctestnum, loctesterr, ht, true, 483);
    CountHT(loctestnum, loctesterr, ht, vec, 0);

    vec.Clear();
    vec.Resize(300);
    for (uint i = 0; i < 300; i++) {
      vec[i] = (pow(-3, i % 27) * ((41 * i + 88) % 300)) / (31 * pow(-6, i % 12));
    }

    lasd::HashTableOpnAdr<double> Hash4 = Hash;

    ht = std::move(Hash);
    NonEqualHT(loctestnum,loctesterr,Hash,ht);

    
    ht = Hash4;
    EqualHT(loctestnum,loctesterr,Hash4,ht);

    for (int i = 0; i < 300; i++) {
      InsertC(loctestnum, loctesterr, ht, vec[i]);
    }


    Size(loctestnum, loctesterr, ht, true, 780);
    CountHT(loctestnum, loctesterr, ht, vec, 300);

    //Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    for (int i = 0; i < 500; i++) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }

    CountHT(loctestnum, loctesterr, ht, vec, 292);
    Size(loctestnum, loctesterr, ht, true, 290);
    NonEqualHT(loctestnum,loctesterr,Hash,ht);
    lasd::HashTableOpnAdr<double> Hash2 = ht;
    ht.Resize(350);
    EqualHT(loctestnum,loctesterr,Hash2,ht);
    ht.Resize(1);
    EqualHT(loctestnum,loctesterr,Hash2,ht);
    ht.Resize(0);
    NonEqualHT(loctestnum,loctesterr,Hash2,ht);
  
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "Fine test HashMap (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}

void EuqalTest(uint & testnum, uint & testerr){
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "*****************HashMapEqual<Double> Test Test:*****************" << endl;
  try {


    lasd::List<double> lst;
    for (uint i = 0; i < 500; i++) {
      lst.InsertAtFront((pow(-3, i % 17) * ((41 * i + 88) % 500)) / (31 * pow(-6, i % 3)));
    }

    lasd::HashTableClsAdr<double> clsHash{lst};
    //TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
    cout << endl << "Begin of HashTableClsAdr<double> Test:" << endl;
    EquelTestDoubleCls(loctestnum, loctesterr,clsHash, lst);
    lasd::HashTableOpnAdr<double> opnHash{lst};
    //TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
    cout << endl << "Begin of HashTableOpnAdr<double> Test:" << endl;
    EquelTestDoubleOpn(loctestnum, loctesterr,opnHash, lst);
    

    
  }catch(...){
      loctestnum++; loctesterr++;
      cout << endl << "Unmanaged error! qui" << endl;
  }
  cout << "\nFine test HashMapRandomNumber (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;

}


void TestFlorindoC(uint & testnum, uint & testerr) {
  cout << endl << "~*~#~*~ HashMap ~*~#~*~ " << endl;
  HashMapTestCLS(testnum,testerr);
  ZeroTestHashMapCLS(testnum,testerr);
  TestHashMapRandomNumber(testnum,testerr);
  ClsAdr(testnum,testerr);
  EuqalTest(testnum,testerr);
  

  cout << endl << "Test C(Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}