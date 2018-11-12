template<class T>
class circular_buffer {
	public:
		explicit circular_buffer(size_t capacity = 100) : 
			array_(new T[capacity]),
			array_size_(capacity),
			head_(0), tail_(0),
			contents_size_(0) {};

		~circular_buffer() {delete [] array_; }

	private:
		T *array_;
		size_t array_size_;
		size_t head_;
		size_t tail_;
		size_t contents_size_;

		typedef	T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const 
};


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

template<typename T>
class Tree {
    struct Node {
        T key;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
        Node() : key(), left(), right() {}
        Node(T x) : key(x), left(), right() {}
    };
    
    shared_ptr<Node> root;
    
    public:
        Tree() : root() {}
        ~Tree() {
            while (root) remove(root->key);
        }
        
        Tree(Tree&&) = default;
        Tree& operator =(Tree&&) = default;
        Tree(const Tree&);
        Tree& operator =(const Tree&);
        
        bool push(T);
        bool remove(T);
        
        void inorder();
        shared_ptr<Node> find(T x) {
            return find(x, root);
        }
        void breath_first();
        size_t height() {
            return height(root);
        }
};

template<typename T>
bool Tree<T>::remove(T x, shared_ptr<Node> &p) {
    if (p && x < p->key)
        return remove(x, p->left);
    else if (p && x > p->key) 
        return remove(x, p->right);
    else if (p && p->key == x) {
        if (!p->left)
            p = p->right;
        else if (!p->right)
            p = p->left;
        else {
            shared_ptr<Node> q = p->left;
            while (q->right) q = q->right;
            p->key = q->key;
            remove(q->key, p->left);
        }
        return true;
    }
    return false;
}

int main()
{
    cout<<"Hello World";

    return 0;
}
