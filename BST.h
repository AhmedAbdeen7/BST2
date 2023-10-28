#include <string>
#include <iostream>
using namespace std;


template <class keytype, class datatype>
class BST
{
  private:
     class node
     {
      public:

        node* left;
        node* right;
        keytype key;
        string lat, lon, country;

      
    
     };
    typedef node* Nodepointer;
    Nodepointer root;
    int size;

  public:
      
      BST();

      bool insert2 (Nodepointer &Root, const keytype &k, const datatype &C, const datatype &LA, const datatype &LO);
      
      bool insert(const keytype &k, const datatype &C, const datatype &LA, const datatype &LO);

      bool empty() const;

      bool search2 (Nodepointer &Root, const keytype &k) const;

      bool search(const keytype &k) const;

      bool retrieve (const keytype &k, datatype &C, datatype &LA, datatype &LO) const;
	  
      void traverse2(Nodepointer Root) const;
       
      void traverse() const;

	    void preorder () const;

	    void levelorder () const;
 
      void remove (const keytype &);

      void parentSearch(const keytype &k, bool &found, Nodepointer &locptr, Nodepointer &parent) const;
      
      void save_to_file(ofstream& file, Nodepointer root);
      
      void save(Nodepointer root, string& filename);

};
