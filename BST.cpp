#include <iostream>
#include "BST.h"
#include "Queuet.cpp"
#include <fstream>
#include "Stackt.cpp"
using namespace std;

template <class keytype, class datatype>
BST < keytype, datatype> :: BST()
{

root = NULL; 
size = 0;
}

template <class keytype, class datatype>
bool BST <keytype, datatype>::insert(const keytype &k, const datatype &C, const datatype &LA, const datatype &LO)
{    
	return insert2 (root, k , C, LA, LO);
} 

template <class keytype, class datatype>
bool BST < keytype, datatype> ::insert2(Nodepointer &Root, const keytype &k, const datatype &C, const datatype &LA, const datatype &LO)
{
  // Check for empty tree.
  if  (Root == NULL)
  { // Attach new node
      Root = new node; 
	Root->left = NULL; 
    Root->right = NULL;
    Root->key = k;
	Root->country = C;
    Root->lat = LA;
    Root->lon = LO;
    return true;

  }
  else if (k == root->key)
    return false;  
  else if (k < root->key)
    return insert2(Root->left, k, C, LA, LO); 
  else
    return insert2(Root->right, k, C, LA, LO); 
    size++;
}

template <class keytype, class datatype>
bool BST <keytype, datatype>::retrieve(const keytype &k, datatype &C, datatype &LA, datatype &LO) const
{
    if (root == NULL)      
		return false;                     
    else if (k == root->key)
	{ C = root->data.country;
      LA =  root->data.lat;
      LO =  root->data.lon;
     return true;} 
    else if (k < root->key)
		return retrieve(root->left, k, C, LA, LO); 
    else
		return retrieve(root->right,k, C, LA, LO); 
} // end of private retrieve

template <class keytype, class datatype>
bool BST<keytype, datatype>::search(const keytype &k) const  
{
   return search2(root, k); 
}

template <class keytype, class datatype>
bool BST <keytype, datatype>::search2(Nodepointer & Root, const keytype &k) const
 {
    if (Root == NULL)      
		return false;                     
    else if (k == Root->key)
		return true; 
    else if (k < Root->key)
		return search2(Root->left, k); 
    else
		return search2(Root->right, k); 
 }

template <class keytype, class datatype>
bool  BST <keytype, datatype>:: empty() const
{
    return (root == NULL);
}

template <class keytype, class datatype>
void BST <keytype, datatype>::traverse2 (Nodepointer aRoot) const       
{
   if (aRoot != NULL)
   { // recursive in-order traversal
     traverse2 (aRoot->left);           
     cout << aRoot->key << " " << aRoot->data << endl; 
     traverse2 (aRoot->right); 
   }
   
}

template <class keytype, class datatype>
void BST <keytype, datatype>::traverse() const       
{
    traverse2(root);
   
} // end of private traverse

template <class keytype, class datatype>
 void BST <keytype, datatype>::preorder () const
 {
	Stackt<Nodepointer> s;
	Nodepointer t = root;
	s.push(t);
	while(!s.stackIsEmpty())
	{
		s.pop(t); cout << t->key << endl;
		if ( t->right != NULL ) s.push(t->right);
		if ( t->left  != NULL ) s.push (t->left);
	}
 }
 
template <class keytype, class datatype>
void BST <keytype, datatype> ::levelorder () const
  {
    Queuet<Nodepointer> q;
	  Nodepointer t = root;
	  q.enqueue(t);
	  while(!q.queueIsEmpty())
	  {
		q.dequeue(t); cout << t->key << endl;
		if ( t->left  != NULL ) q.enqueue (t->left);
		if ( t->right != NULL ) q.enqueue (t->right);
	 }
  }
  template <class keytype, class datatype>
  void BST <keytype, datatype> :: remove (const keytype &k)
  {
      	bool found;
	Nodepointer x,parent;
	// Search for element and its parent
	parentSearch (k, found, x, parent);
	if (!found)
	{
		cout << "Item not in BST\n";
		return;
	}
	// else, element is found
	if ((x->left != NULL)&&(x->right != NULL))
	{	// Node has two children
		// Find inorder successor and its parent
		Nodepointer xSucc = x->right;
		parent = x;
		while (xSucc->left != NULL) // descend left
		{ parent = xSucc; xSucc = xSucc->left; }
		// Move contents of xSucc to x and change x
		// to point to successor, which will be removed
		x->key = xSucc->key; x->data = xSucc->data;
		x = xSucc;
	} // end if node has two children
	// Now, node has 0 or 1 child
	Nodepointer subtree = x->left; // subtree of x
	if (subtree == NULL) subtree = x->right;
	if (parent == NULL) root = subtree; //remove root
	else if (parent->left == x) //parent left child 
		parent->left = subtree;
	else parent->right = subtree; // right child
	delete x;
  }


  template <class keytype, class datatype>
void BST <keytype, datatype>:: parentSearch (const keytype &k, bool &found, Nodepointer &locptr, Nodepointer &parent) const
{
	locptr = root;  parent = NULL; found = false;
	while (!found && locptr != NULL)
	{
		if (k < locptr->key) // descend left
		{
			parent = locptr;	locptr = locptr->left;
		}
		else if (locptr->key < k) // descend right
		{
			parent = locptr;	locptr = locptr->right;
		}
		else found = true; // el found
	}// end while
} // end of private parentSearch


template <class keytype, class datatype>
void BST <keytype, datatype>:: save_to_file(ofstream& file, Nodepointer root)
{
	if (root == NULL)
		return;

    Queuet <Nodepointer> q;
	  Nodepointer t = root;
	  q.enqueue(t);
    while(!q.queueIsEmpty())
	  {
		q.dequeue(t); file << t->key << "  " << t->data.lat << "  " << t->data.lon << "  " << t->data.country << endl;
		if ( t->left  != NULL ) q.enqueue (t->left);
		if ( t->right != NULL ) q.enqueue (t->right);
	 }

}

template <class keytype, class datatype>
void BST <keytype, datatype>:: save(Nodepointer root, string& filename)
{
    ofstream file(filename);

    save_to_file(root, file);
}
