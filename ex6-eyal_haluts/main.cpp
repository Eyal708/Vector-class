//#include "vl_vector.h"
//int main()
//{
//  //new tests
//  vl_vector<char,6>char_vec;
//  vl_vector<int,6>int_vec;
//  //push_back
//  char_vec.push_back('a');
//  char_vec.push_back('b');
//  char_vec.push_back('e');
//  int_vec.push_back(1);
//  int_vec.push_back(2);
//  int_vec.push_back(5);
//  std::cout<<"char_vector should contain a,b,e, cap:6 size:3"<<std::endl;
//  for(auto i:char_vec)
//    {
//      std::cout<<i<<", ";
//    }
//    std::cout<<"char_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//    std::cout<<std::endl;
//  std::cout<<"int_vector should contain 1,2,5 cap:6 size:3"<<std::endl;
//  for(auto i:int_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"int_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //insert at position
//  char_vec.insert(char_vec.begin()+2,'d');
//  int_vec.insert(int_vec.begin()+2,4);
//  char_vec.insert(char_vec.begin()+2,'c');
//  int_vec.insert(int_vec.begin()+2,3);
//  std::cout<<"char_vector should contain a,b,c,d,e, cap:6 size:5"<<std::endl;
//  for(auto i:char_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"char_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  std::cout<<"int_vector should contain 1,2,3,4,5, cap:6 size:5"<<std::endl;
//  for(auto i:int_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"int_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //insert sequence
//  int int_arr[3]={10,20,30};
//  char char_arr[3]={'x','y','z'};
//  char_vec.insert(char_vec.end()-1,&char_arr[0],&char_arr[3]);
//  int_vec.insert(int_vec.end()-1,&int_arr[0],&int_arr[3]);
//  std::cout<<"char_vector should contain a,b,c,d,x,y,z,e, cap:12 size:8"<<std::endl;
//  for(auto i:char_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"char_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  std::cout<<"int_vector should contain 1,2,3,4,10,20,30,5, cap:12 size:8"<<std::endl;
//  for(auto i:int_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"int_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //clear by position
//  char_vec.erase(char_vec.begin()+5);
//  int_vec.erase(int_vec.begin()+5);
//  std::cout<<"char_vector should contain a,b,c,d,x,z,e, cap:12 size:7"<<std::endl;
//  for(auto i:char_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"char_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  std::cout<<"int_vector should contain 1,2,3,4,10,30,5, cap:12 size:7"<<std::endl;
//  for(auto i:int_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"int_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //clear sequence
//  char_vec.erase(char_vec.begin()+4,char_vec.end());
//  int_vec.erase(int_vec.begin()+4,int_vec.end());
//  std::cout<<"char_vector should contain a,b,c,d, cap:6 size:4"<<std::endl;
//  for(auto i:char_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"char_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  std::cout<<"int_vector should contain 1,2,3,4, cap:6 size:4"<<std::endl;
//  for(auto i:int_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"int_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //pop_back
//  char_vec.pop_back();
//  int_vec.pop_back();
//  std::cout<<"char_vector should contain a,b,c,, cap:6 size:3"<<std::endl;
//  for(auto i:char_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"char_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  std::cout<<"int_vector should contain 1,2,3, cap:6 size:3"<<std::endl;
//  for(auto i:int_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"int_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //test data
//  const int* int_data= int_vec.data();
//  const char* char_data= char_vec.data();
//  std::cout<< "should print 1: "<<*int_data<<std::endl;
//  std::cout<< "should print a: "<<*char_data<<std::endl;
//  //test contains
//  int two=2;
//  char d='d';
//  bool int_contains= int_vec.contains(two);
//  bool char_contains=char_vec.contains(d);
//  std::cout<<"this should be true: "<<int_contains<<" this false: "<<char_contains<<std::endl;
//  //test clear
//  char_vec.clear ();
//  int_vec.clear ();
//  std::cout<<"char_vector should contain nothing cap:6 size:0"<<std::endl;
//  for(auto i:char_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"char_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  std::cout<<"int_vector should contain nothing cap:6 size:0"<<std::endl;
//  for(auto i:int_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"int_vec capacity and size:"<<char_vec.capacity()<<", "<<char_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //test assignment operator
//  vl_vector<int,6> first_vec;
//  int arr[10]={1,2,3,4,5,6,7,8,9,10};
//  first_vec.insert(first_vec.begin(),&arr[0],&arr[6]);
//  std::cout<<"first_vec should contain 1-6 cap:6 size:6"<<std::endl;
//  for(auto i:first_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"first_vec capacity and size:"<<first_vec.capacity()<<", "<<first_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  vl_vector<int,6>second_vec;
//  second_vec.insert(second_vec.begin(),&arr[0],&arr[10]);
//  std::cout<<"second_vec should contain 1-10 cap:15 size:10"<<std::endl;
//  for(auto i:second_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"second_vec capacity and size:"<<second_vec.capacity()<<", "<<second_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  first_vec=second_vec;
//  std::cout<<"first_vec should contain 1-10 cap:15 size:10"<<std::endl;
//  for(auto i:first_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"first_vec capacity and size:"<<first_vec.capacity()<<", "<<first_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //test []
//  std::cout<<"should print 1: "<< first_vec[0]<<std::endl;
//  first_vec[0]=-1;
//  first_vec[9]=-10;
//  std::cout<<"first_vec should contain -1,2-9,-10 cap:15 size:10"<<std::endl;
//  for(auto i:first_vec)
//    {
//      std::cout<<i<<", ";
//    }
//  std::cout<<"first_vec capacity and size:"<<first_vec.capacity()<<", "<<first_vec.size()<<std::endl;
//  std::cout<<std::endl;
//  //test comparison
//  bool not_equal= first_vec!=second_vec;
//  std::cout<< "should print 1: "<<not_equal<<std::endl;
//  //test vector at and empty
//  std::cout<<"should print -10: "<<first_vec.at(9)<<std::endl;
//  try
//    {
//      std::cout<<" out_of_range exception should be caught"<<std::endl;
//      first_vec.at(11);
//      std::cout<<"didn't catch"<<std::endl;
//
//    }
//    catch(std::out_of_range& e)
//      {
//        std::cout<<"caught"<<std::endl;
//
//      }
//
//
//
//
//
//
//
//
//
//}
#include "vl_vector.h"
#include <cassert>
int main ()
{
  /*******************************
** C/C++ spring semester 2021 **
** Ex6 tests                  **
** version 1.1                **
** Written by Erel Debel      **
*******************************/

#define BOOST_TEST_MODULE ex6_tests
//#include <boost/core/ignore_unused.hpp>
//#include <boost/test/included/unit_test.hpp>

/*********************************
* Basic constructors and getters *
*********************************/


  vl_vector<int> v1;
  assert (v1.empty ());
  assert (v1.size () == 0UL);
  assert (v1.capacity () == 16UL);
  assert (!v1.contains (0));

  const vl_vector<double, 3> v2;
  assert (v2.empty ());
  assert (v2.size () == 0UL);
  assert (v2.capacity () == 3UL);
  assert (!v2.contains (0));

//
  vl_vector<float> v1 (8, 0.25);
    assert (!v1.empty ());
    assert (v1.size () == 8);
    assert (v1.capacity () == 16);
    for (auto elem : v1)
    assert (elem == 0.25);
    assert (v1.contains (0.25));
    assert (!v1.contains (0.5));

    const vl_vector<float, 4> v2 (8, 0.25);
    assert (!v2.empty ());
    assert (v2.size () == 8);
    assert (v2.capacity () == 3 * 8 / 2);
    assert (v2.data ()[0] == 0.25);
    for (auto elem : v2)
    assert (elem == 0.25);
    assert (v2.contains (0.25));
    assert (!v2.contains (0.5));

    vl_vector<float> v3 (20, 0.25);
    assert (!v3.empty ());
    assert (v3.size () == 20);
    assert (v3.capacity () == 3 * 20 / 2);
    assert (v3.data ()[0] == 0.25);
    for (auto elem : v3)
    assert (elem == 0.25);
    }


BOOST_AUTO_TEST_CASE (sequence_based_constructor)
    {
  int arr[20];
  for (int i = 0; i < 20; ++i)
    arr[i] = i;
  vl_vector<int> v (arr, arr + 20);
  assert (!v.empty ());
  assert (v.size () == 20);
 assert (v.capacity () == 3 * 20 / 2);
  int i = 0;
 for (auto iter = v.cbegin (); iter < v.cend (); ++iter)
   assert (*iter == i++);
}

BOOST_AUTO_TEST_SUITE_END()


/************
* Iterators *
************/

BOOST_AUTO_TEST_SUITE (iterators)

BOOST_AUTO_TEST_CASE(iterator_static)
    {
  int arr_len = 10;
  int arr[10];
  for (int i = 0; i < arr_len; ++i)
    arr[i] = i;
  vl_vector<int> v (arr, arr + arr_len);
  int i = 0;
  for (auto iter = v.cbegin (); iter != v.cend (); ++i, ++iter)
    assert(*iter == i);
  i = 0;
  for (auto iter = v.begin (); iter != v.end (); ++i, ++iter)
    assert(*iter == i);

  const vl_vector<int> const_v (arr, arr + arr_len);
  i = 0;
  for (auto iter = const_v.begin (); iter != const_v.end (); ++i, ++iter)
    assert(*iter == i);
}

BOOST_AUTO_TEST_CASE(reverse_iterator_static)
    {
  int arr_len = 10;
  int arr[10];
  for (int i = 0; i < arr_len; ++i)
    arr[i] = i;
  vl_vector<int> v (arr, arr + arr_len);
  int i = arr_len - 1;
  for (auto iter = v.crbegin (); iter != v.crend (); --i, ++iter)
    assert(*iter == i);
  i = arr_len - 1;
  for (auto iter = v.rbegin (); iter != v.rend (); --i, ++iter)
    assert(*iter == i);

  const vl_vector<int> const_v (arr, arr + 10);
  i = arr_len - 1;
  for (auto iter = const_v.rbegin (); iter != const_v.rend (); --i, ++iter)
    assert(*iter == i);
}

BOOST_AUTO_TEST_CASE (iterators_dynamic)
    {
  int arr_len = 20;
  int arr[20];
  for (int i = 0; i < arr_len; ++i)
    arr[i] = i;
  vl_vector<int> v (arr, arr + arr_len);
  int i = 0;
  for (auto iter = v.cbegin (); iter != v.cend (); ++i, ++iter)
    assert(*iter == i);
  i = arr_len - 1;
  for (auto iter = v.crbegin (); iter != v.crend (); --i, ++iter)
    assert(*iter == i);
}

BOOST_AUTO_TEST_SUITE_END()


/************************
* Random access methods *
************************/

BOOST_AUTO_TEST_SUITE (random_access_methods)

BOOST_AUTO_TEST_CASE(square_brackets_operator)
    {
  int arr_len = 10;
  int arr1[10];
  for (int i = 0; i < arr_len; ++i)
    arr1[i] = i;
  vl_vector<int> v1 (arr1, arr1 + arr_len);
  for (int i = 0; i < arr_len; ++i)
    assert (v1[i] == i);
  try
    { v1[13]; }
  catch (const std::exception &e)
    {
      assert (false);
    }

  arr_len = 20;
  int arr2[20];
  for (int i = 0; i < arr_len; ++i)
    arr2[i] = i;
  const vl_vector<int> v2 (arr2, arr2 + arr_len);
  for (int i = 0; i < arr_len; ++i)
    assert (v2[i] == i);
}

BOOST_AUTO_TEST_CASE(at_method)
    {
  int arr_len = 10;
  int arr1[10];
  for (int i = 0; i < arr_len; ++i)
    arr1[i] = i;
  vl_vector<int> v1 (arr1, arr1 + arr_len);
  for (int i = 0; i < arr_len; ++i)
    assert (v1.at (i) == i);
  try
    {
      v1.at (13);
      assert (true);
    }
  catch (const std::out_of_range &e)
    { assert (true); }
  catch (const std::exception &e)
    { assert (false); }

  arr_len = 20;
  int arr2[20];
  for (int i = 0; i < arr_len; ++i)
    arr2[i] = i;
  const vl_vector<int> v2 (arr2, arr2 + arr_len);
  for (int i = 0; i < arr_len; ++i)
    assert (v2.at (i) == i);
}

BOOST_AUTO_TEST_SUITE_END()


/**************************
* Operations on vl_vector *
**************************/

BOOST_AUTO_TEST_SUITE (operations_on_vl_vector)

BOOST_AUTO_TEST_CASE (push_back)
    {
  vl_vector<int, 5> v;
  const int *static_vec = v.data ();
  assert (!v.contains (0));
  for (int i = 0; i < 10; ++i)
    v.push_back (i);
  for (int i = 0; i < 10; ++i)
    assert (v.contains (0));
  for (int i = 0; i < 10; ++i)
    assert (v[i] == i);
  assert (static_vec != v.data ());
}

BOOST_AUTO_TEST_CASE (insert_element)
    {
        vl_vector<int, 5> v;
    const int *static_vec = v.data ();
    auto pos = v.cbegin ();
    for (int i = 5; i >= 0; --i)
    {
      assert (v.data () == static_vec);
      pos = v.insert (pos, i * 2);
    }
    assert (v.data () != static_vec);
    assert (v.capacity () == (size_t) (3 * 6) / 2);

    const int *dynamic_vec = v.data ();
    for (int i = 1; i < 10; i += 2)
    v.insert (v.cbegin () + i, i);
    assert (v.size () == (size_t) 11);
    assert (v.capacity () == (size_t) (3 * 10) / 2);
    for (int i = 0; i < 11; ++i)
    assert (v[i] == i);

    assert (static_vec != v.data ());
    assert (dynamic_vec != v.data ());
    }

BOOST_AUTO_TEST_CASE (insert_sequence)
    {
  const int arr_len = 10;
  int arr[10];
  int j = 0;
  for (; j < arr_len / 2; ++j)
    arr[j] = j;
  for (; j < arr_len; ++j)
    arr[j] = j + 10;

  vl_vector<int, arr_len> v (arr, arr + arr_len);
  const int *static_vec = v.data ();

  j = 0;
  for (; j < arr_len / 2; ++j)
    arr[j] = j + 10;
  for (; j < arr_len; ++j)
    arr[j] = j;

  auto pos = v.insert (v.cbegin () + 5, arr, arr + 5);
  assert (static_vec != v.data ());
  assert (v.capacity () == (size_t) (3 * 15) / 2);

  const int *dynamic_vec = v.data ();
  v.insert (pos, arr + 5, arr + 10);
  assert (v.size () == (size_t) 20);
  for (int i = 0; i < 20; ++i)
    assert (v[i] == i);

  assert (static_vec != v.data ());
  assert (dynamic_vec == v.data ());
  assert (v.capacity () == (size_t) (3 * 15) / 2);
}

BOOST_AUTO_TEST_CASE (pop_back)
    {
  int arr_len = 20;
  int arr[20];
  for (int i = 0; i < arr_len; ++i)
    arr[i] = i;
  vl_vector<int, 10> v (arr, arr + arr_len);
  assert (v.capacity () == (size_t) (3 * arr_len) / 2);
  const int *dynamic_vec = v.data ();
  for (int i = 0; i < 10; ++i)
    {
      assert (v.size () == (size_t) (arr_len - i));
      assert (v.capacity () == (size_t) (3 * arr_len) / 2);
      assert (v.data () == dynamic_vec);
      v.pop_back ();
    }
  const int *static_vec = v.data ();
  for (int i = 0; i < 10; ++i)
    {
      assert (v.size () == (size_t) (10 - i));
      assert (v.capacity () == (size_t) 10);
      assert (v.data () != dynamic_vec);
      assert (v.data () == static_vec);
      v.pop_back ();
    }
}

BOOST_AUTO_TEST_CASE(erase_element)
    {
  int arr_len = 20;
  int arr[20];
  for (int i = 0; i < arr_len; ++i)
    arr[i] = i - 2;

  vl_vector<int, 10> v (arr, arr + arr_len);
  assert (v.size () == (size_t) arr_len);
  const int *dynamic_vec = v.data ();
  v.erase (v.begin ());
  v.erase (v.begin ());
  for (int i = 0; i < 8; ++i)
    {
      assert (v.size () == (size_t) (arr_len - 2 - i));
      assert (v.capacity () == (size_t) (3 * arr_len) / 2);
      assert (v.data () == dynamic_vec);
      v.erase (v.begin () + 10);
    }
  assert (v.size () == 10);
  assert (v.capacity () == 10);
  assert (v.data () != dynamic_vec);
  for (int i = 0; i < 10; ++i)
    assert (v[i] == i);
}

BOOST_AUTO_TEST_CASE (erase_sequence)

    int arr_len = 20;
    int arr[20];
    for (int i = 0; i < arr_len; ++i)
      arr[i] = i - 2;

    vl_vector<int, 10> v (arr, arr + arr_len);
    assert (v.size () == (size_t) arr_len);
    const int *dynamic_vec = v.data ();
    v.erase (v.begin (), v.begin () + 2);
    assert (v.data () == dynamic_vec);
    v.erase (v.begin () + 10, v.begin () + 18);
    assert (v.size () == (size_t) 10);
    assert (v.capacity () == (size_t) 10);
    assert (v.data () != dynamic_vec);
    for (int i = 0; i < 10; ++i)
      assert (v[i] == i);
}

BOOST_AUTO_TEST_CASE (clear)
    {
  int arr_len = 20;
  int arr[20];
  for (int i = 0; i < arr_len; ++i)
    arr[i] = i - 2;

  vl_vector<int, 10> v (arr, arr + arr_len);
  assert (v.size () == (size_t) arr_len);
  assert (v.capacity () == (size_t) ((3 * arr_len) / 2));
  const int *dynamic_vec = v.data ();
  v.clear ();
  assert (v.size () == (size_t) 0);
  assert (v.capacity () == (size_t) 10);
  assert (v.data () != dynamic_vec);
  const int *static_vec = v.data ();
  v.clear ();
  assert (v.size () == (size_t) 0);
  assert (v.capacity () == (size_t) 10);
  assert (v.data () != dynamic_vec);
  assert (v.data () == static_vec);
}

BOOST_AUTO_TEST_SUITE_END()


/**********************
* Copy and comparison *
**********************/

BOOST_AUTO_TEST_SUITE (copy_and_comparison)

BOOST_AUTO_TEST_CASE (copy_constructor_dynamic)
    {
  int arr[20];
  for (int i = 0; i < 20; ++i)
    arr[i] = i;
  const vl_vector<int> v (arr, arr + 20);
  vl_vector<int> v_copy (v);
  assert (v == v_copy);
  assert (!(v != v_copy));
  assert (!v_copy.empty ());
  assert (v_copy.size () == 20);
  assert (v_copy.capacity () == 3 * 20 / 2);
  int i = 0;
  for (auto elem : v_copy)
    assert (elem == i++);
  assert (v.data () != v_copy.data ());
  v_copy.pop_back ();
  try
    {
      v.at (19);
      assert (true);
    }
  catch (const std::out_of_range &e)
    {
      assert (false);
    }
  try
    {
      v_copy.at (19);
      assert (false);
    }
  catch (const std::out_of_range &e)
    {
      assert (true);
    }
  v_copy[0] = 3;
  assert (v[0] != v_copy[0]);
  assert (!(v == v_copy));
  assert (v != v_copy);
  assert (v.size () == 20);
  assert (v_copy.size () == 19);
  assert (v.capacity () == 3 * 20 / 2);
  assert (v_copy.capacity () == 3 * 20 / 2);
}

BOOST_AUTO_TEST_CASE (assignment_operator_dynamic)
    {
  int arr[20];
  for (int i = 0; i < 20; ++i)
    arr[i] = i;
  const vl_vector<int> v (arr, arr + 20);
  vl_vector<int> v_copy;
  v_copy = v;
  assert (v == v_copy);
  assert (!v_copy.empty ());
  assert (v_copy.size () == 20);
  assert (v_copy.capacity () == 3 * 20 / 2);
  int i = 0;
  for (auto elem : v_copy)
    assert (elem == i++);
  assert (v.data () != v_copy.data ());
  v_copy.pop_back ();
  try
    {
      v.at (19);
      assert (true);
    }
  catch (const std::out_of_range &e)
    {
      assert (false);
    }
  try
    {
      v_copy.at (19);
      assert (false);
    }
  catch (const std::out_of_range &e)
    {
      assert (true);
    }
  v_copy[0] = 3;
  assert (v[0] != v_copy[0]);
  assert (!(v == v_copy));
  assert (v != v_copy);
  assert (v.size () == 20);
  assert (v_copy.size () == 19);
  assert (v.capacity () == 3 * 20 / 2);
  assert (v_copy.capacity () == 3 * 20 / 2);
}

BOOST_AUTO_TEST_CASE (copy_constructor_static)
    {
        int arr[20];
    for (int i = 0; i < 20; ++i)
    arr[i] = i;
    const vl_vector<int, 20> v (arr, arr + 20);
    vl_vector<int, 20> v_copy (v);
    assert (v == v_copy);
    assert (!(v != v_copy));
    assert (!v_copy.empty ());
    assert (v_copy.size () == 20);
    assert (v_copy.capacity () == 20);
    int i = 0;
    for (auto elem : v_copy)
    assert (elem == i++);
    assert (v.data () != v_copy.data ());
    v_copy.pop_back ();
    try
    {
      v.at (19);
      assert (true);
    }
    catch (const std::out_of_range &e)
    {
      assert (false);
    }
    try
    {
      v_copy.at (19);
      assert (false);
    }
    catch (const std::out_of_range &e)
    {
      assert (true);
    }
    v_copy[0] = 3;
    assert (v[0] != v_copy[0]);
    assert (!(v == v_copy));
    assert (v != v_copy);
    assert (v.size () == 20);
    assert (v_copy.size () == 19);
    assert (v.capacity () == 20);
    assert (v_copy.capacity () == 20);
    }

BOOST_AUTO_TEST_CASE (assignment_operator_static)
    {
  int arr[20];
  for (int i = 0; i < 20; ++i)
    arr[i] = i;
  const vl_vector<int, 20> v (arr, arr + 20);
  vl_vector<int, 20> v_copy;
  v_copy = v;
  assert (v == v_copy);
  assert (!v_copy.empty ());
  assert (v_copy.size () == 20);
  assert (v_copy.capacity () == 20);
  int i = 0;
  for (auto elem : v_copy)
    assert (elem == i++);
  assert (v.data () != v_copy.data ());
  v_copy.pop_back ();
  try
    {
      v.at (19);
      assert (true);
    }
  catch (const std::out_of_range &e)
    {
      assert (false);
    }
  try
    {
      v_copy.at (19);
      assert (false);
    }
  catch (const std::out_of_range &e)
    {
      assert (true);
    }
  v_copy[0] = 3;
  assert (v[0] != v_copy[0]);
  assert (!(v == v_copy));
  assert (v != v_copy);
  assert (v.size () == 20);
  assert (v_copy.size () == 19);
  assert (v.capacity () == 20);
  assert (v_copy.capacity () == 20);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE (mixed_test)

BOOST_AUTO_TEST_CASE (element_invariation)
    {
  vl_vector<long, 5> v (4UL, 6L);
  assert (v.size () == 4);
  assert (v.capacity () == 5);
  const long *static_vec = v.data ();
  long arr[5];
  for (int i = 0; i < 5; ++i)
    arr[i] = i;
  v.insert (v.begin (), arr, arr + 5);
  auto iter = v.begin ();
  for (int i = 0; iter < v.begin () + 5; ++iter, ++i)
    assert (*iter == i);
  for (; iter < v.end (); ++iter)
    assert (*iter == 6);
  assert (v.size () == 9);
  assert (v.capacity () == 13);

  auto pos = v.end ();
  for (int j = 0; j < 6; ++j)
    pos = v.insert (pos, 1000);
  iter = v.begin ();
  for (int i = 0; iter < v.begin () + 5; ++iter, ++i)
    assert (*iter == i);
  for (; iter < v.begin () + 9; ++iter)
    assert (*iter == 6);
  for (; iter < v.end (); ++iter)
    assert (*iter == 1000);
  assert (v.size () == 15);
  assert (v.capacity () == 21);
  const long *dynamic_vec = v.data ();
  pos = v.begin () + 1;
  for (int j = 0; j < 9; ++j)
    {
      assert (v.size () == 15 - j);
      assert (v.capacity () == 21);
      pos = v.erase (pos);
    }
  assert (v.size () == 6);
  assert (v.capacity () == 21);
  assert (v.data () == dynamic_vec);

  assert (*v.begin () == 0);
  iter = v.begin () + 1;
  for (; iter < v.end (); ++iter)
    assert (*iter == 1000);

  v.pop_back ();
  assert (v.size () == 5);
  assert (v.capacity () == 5);
  assert (v.data () != dynamic_vec);
  assert (v.data () == static_vec);

  assert (*v.begin () == 0);
  iter = v.begin () + 1;
  for (; iter < v.end (); ++iter)
    assert (*iter == 1000);
}
//
//

