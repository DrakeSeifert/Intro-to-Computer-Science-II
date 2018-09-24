#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct mult_div_values {
   int mult;
   float div;
};

bool is_valid_dimensions(char *m, char *n){ 
   int j = 0;
   for (int i = 1; i < 3; i++) {
      while (n[j] != '\0') {
         if (n[j] < '0' || n[j] > '9'){
            cout << "Error! Please enter a non-zero integer: ";
	    cin >> *n;
	    is_valid_dimensions(m, n);
	 }
         j++;
      }       
   }
}

void set_mult_values(mult_div_values**, int, int);

void set_div_values(mult_div_values**, int, int);

void delete_table(mult_div_values **table, int m);

mult_div_values** create_table(int m, int n) {
   mult_div_values **table;
   table = new mult_div_values*[m];
   for (int i = 0; i < m; i++) {
      table[i] = new mult_div_values[n];
   }
   cout << endl << "Multiplication table: " << endl;
   set_mult_values(table, m, n);
   cout << endl << "Division table: " << endl;
   set_div_values(table, m, n);
   cout << endl;
   delete_table(table, m);
}

void set_mult_values(mult_div_values **table, int m, int n) {
   for (int x = 0; x < m; x++) {
      cout << endl;
      for (int y = 0; y < n; y++){
	 table[x][y].mult = (x+1)*(y+1);
         if (table[x][y].mult < 10)
	    cout << "0";
	 cout << table[x][y].mult << " ";
      }
   }
   cout << endl;
}

void set_div_values(mult_div_values **table, int m, int n) {
   for (int x = 0; x < m; x++) {
      cout << endl;
      for (int y = 0; y < n; y++){
	 table[x][y].div = (float(x+1))/(float(y+1));
	 cout << setprecision(2) << fixed << table[x][y].div << " ";
      }
   }
   cout << endl;
}

void delete_table(mult_div_values **table, int m){
   delete [] *table;
   delete [] table;
}

int main(int argc, char* argv[]){
   if (argc != 3) {
      cout << "Please enter a valid number of dimensions" << endl;
      exit(EXIT_FAILURE);
   }
   int rows, cols;
   if (is_valid_dimensions(argv[1], argv[2]))
      exit(EXIT_FAILURE);
   rows = atoi(argv[1]);
   cols = atoi(argv[2]);
   create_table(rows, cols);
   return 0;
}
