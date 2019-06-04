#include <iostream>
#include <cmath>

using namespace std;
/*
Objects of the class v3d store coordinates of vectors in a 3-dimensional space.
A single object of this class contains a pointer to an array of 3 elements of the type double (for coordinates: x, y and z):

class v3d
{
  double *arr;  // the array of 3 doubles should be allocated dynamically
};

1. Complete this class with:
- a constructor, assigning an initial value of (0.0, 0.0, 0.0) to (x, y, z) (3p),
- a destructor (2p),
- a member function vlen, returning the length of the vector [x y z] (2p),
- an assignment operator (3p),
- an adding operator (adding vectors) (3p).

2. Write a function accepting a pointer to an array of v3d objects and the length
 of the array (in elements) and returning the index of the longest vector in the array.
 Use the vlen function (5p).


*/

class v3d{

private:
    double * arr;

public:
    v3d(){   //a constructor, assigning an initial value of (0.0, 0.0, 0.0) to (x, y, z) (3p)
        arr = new double[3];

        for (int i=0; i<3; i++){
            arr[i]=0.0;
        }
    }

    v3d(double a, double b, double c){
     arr = new double[3];
     arr[0]=a;
     arr[1]=b;
     arr[2]=c;
    }

    double vlen(){ //a member function vlen, returning the length of the vector [x y z] (2p)
        cout<<"arr 0: "<<arr[0]<<"arr 1: "<<arr[1]<<"arr 2: "<<arr[2]<<endl;
        return sqrt(arr[0]*arr[0]+arr[1]*arr[1]+arr[2]*arr[2]);
    }

    ~v3d(){ //- a destructor (2p)
    delete arr;
    cout<<"duuuuupaaaaa"<<endl;
    };

    v3d& operator=(const v3d& drugi){ //an assignment operator (3p),
        this->arr[0] = drugi.arr[0];
        this->arr[1] = drugi.arr[1];
        this->arr[2] = drugi.arr[2];

        return *this;
    }

    /*

    v3d operator=(initializer_list<double> coords){
        int currentIndex = 0;

        for (double coord : coords) {
            this->arr[currentIndex] = coord;
            currentIndex++;
        }

        return *this;
    }
    */

    v3d operator+(const v3d& dod){ //an adding operator (adding vectors)
       v3d zygmunt;
       for (int i=0; i<3; i++){
        zygmunt.arr[i] = this->arr[i]+dod.arr[i];
        cout<<"this array "<<this->arr[i]<<endl;
        cout<<"log zygmuncik: "<<zygmunt.arr[i]<<endl;
       }
      return zygmunt;
    }

};

int get_longest_v3d_index(v3d *vectors, int length) {
    double max_len = vectors[0].vlen();
    int index = 0;
    for(int i=1; i<length; i++){
        if (vectors[i].vlen() > max_len) {
            max_len = vectors[i].vlen();
            index = i;
        }
    }
    return index;
}

int main()
{
    v3d dupa;
    v3d drugi(2.0, 3.0, 4.0);
    v3d trzeci(1.0, 2.4, 8.0);
    cout<<drugi.vlen()<<endl;

    dupa = drugi;

    v3d czwarty;
    czwarty = drugi + trzeci;
    cout << "aaaaa "<<czwarty.vlen() << endl;
    //dupa = { 4.2, 3.3, 7.1 };

    cout << "Dlugosc dupy: " <<dupa.vlen() << endl;

    int test[4] = { 1, 2, 4, 7 };
    for (int i=0; i<4; i++){
        cout<<test[i]<<endl;
    }
}
