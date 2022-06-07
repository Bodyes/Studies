#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//Declaration of const N
const int N = 9;

class Complex{      //Complex class
    public:
        float re_;
        float im_;
        float mod_;

        void complex_modulus();    //definition of complex_modulus method
        Complex(float re, float im);            //definition of constructor
};

void Complex::complex_modulus() {      //method complex_modulus to calculate modulus of a complex number
    this->mod_ = sqrt(this->im_*this->im_+this->re_*this->re_);
}

Complex::Complex(float re, float im) {      //constructor of Complex class
    re_ = re;
    im_ = im;
    mod_ = 0;
}

void trigonometry_values(float *values, float *sin_array, float *cos_array){       //function to calculate trigonometry values from pre-written array
    for(size_t i = 0; i<N; i++){
        sin_array[i] = sin(values[i]);
        cos_array[i] = cos(values[i]);
    }
}

int main() {
    //declaration of arrays
    float values[N];
    float sin_array[N];
    float cos_array[N];

    //Declaration of vector array to store Complex type objects
    vector<Complex> complex_array;

    //assign values to values array
    for (size_t i = 0; i<N; i++){
        values[i] = i*0.2;
    }

    //usage of function to convert values from values array to trigonometry values
    trigonometry_values(values, sin_array, cos_array);

    //creating and assigning Complex-type objects to complex_array
    for(size_t i = 0; i<N; i++){
        Complex temp(cos_array[i], sin_array[i]);
        temp.complex_modulus();
        complex_array.push_back(temp);
    }

    //Display each element of each object from complex_array
    cout<<"Re:    Im:     Mod:"<<endl;
    for(size_t i = 0; i<N; i++){
        cout<<complex_array[i].re_<<" "<<complex_array[i].im_<<" "<<complex_array[i].mod_<<endl;
    }
}
