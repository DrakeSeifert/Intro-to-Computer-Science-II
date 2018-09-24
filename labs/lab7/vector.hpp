#include <stdlib.h>
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	 s=0;
	 v=NULL;
      }
      ~vector(){
	 delete [] v;
      }
      vector (vector<T> &a) { //copy constructor
         s = a.s;
         v = new T[s];
         for(int i = 0; i < s; i++) {
            v[i] = a.v[i];
         }
      }
      void operator = (vector<T> &a) { //operator overload
         if (v != NULL)
		delete [] v;
	s = a.s;
	v = new T[s];
	for(int i = 0; i< s; i++) {
		v[i] = a.v[i];
	}
      } 
      int size() {
	 return s;
      }
      void push_back(T ele) {
	 T *temp;
	 temp = new T[s];
	 for(int i=0; i<s-1; i++)
	    temp[i]=v[i];

	 delete [] v;
	 s++;
	 v = new T[s];

	 for(int i=0; i<s-1; i++)
	    v[i]=temp[i];

	 v[s-1]=ele;
	 delete [] temp;
      }

	T operator [] (int a) { //makes the vector class a vector
		
	}

	void resize() { //make push_back better (add ~10 elements or so when size == cap)
		T *temp;

		temp = new T[s];
		for(int i = 0; i < s-1; i++)
			temp[i] = v[i];

		delete [] v;
		s += 10;
		v = new T[s];

		for(int i = 0; i < s-1; i++)
			v[i] = temp[i];

		delete [] temp;
	}

	T at(int a) {
		
	}

};
