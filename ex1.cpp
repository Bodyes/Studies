#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Product{   //Class Product
    public:
        string name_ = "New Product";
        int code_;
        int price_;
        void decode_price(int code);    //Definition of decode_price method
        Product(string name, int code){     //Constructor of Product class
            name_ = std::move(name);
            code_ = code;
            price_=0;
            decode_price(code);
        }
};

class Weight_product : public Product{     //Weight_product class, inheriting public od Product class
    public:
        int kg_price_;
        int weight_;
        void calculate_price();    //definition od calculate_price method to calculate full price of product
        Weight_product(string name, int code, int weight, int kg_price) : Product(std::move(name), code){       //constructor of Weight_product
            weight_ = weight;
            code_ = code;
            code_ = code;
            kg_price_ = kg_price;
            calculate_price();
        }

};

void Weight_product::calculate_price() {  //function to calculate price
    this->price_ = this->weight_ * this->kg_price_;
}

void Product::decode_price(int code) {  //Function to calculate price (3 last numbers of code)
     price_ = code%1000;
}

void display(const Product& product_weight){    //Function to display every element of object
    cout<<"\n";
    cout <<"Name: "<<product_weight.name_<<endl;
    cout <<"Price: "<<product_weight.price_<<endl;
    cout <<"Code: "<<product_weight.code_<<endl;
    cout<<"\n";
}

void display(const Weight_product& product_weight){    //overloading function to display each element of Weight_product object
    cout<<"\n";
    cout <<"Name: "<<product_weight.name_<<endl;
    cout <<"Price: "<<product_weight.price_<<endl;
    cout <<"Kg price: "<<product_weight.kg_price_<<endl;
    cout <<"Code: "<<product_weight.code_<<endl;
    cout <<"Weight: "<<product_weight.weight_<<endl;
    cout<<"\n";
}


int main() {
    vector<Product> products_array;
    Product first("first", 413892);
    Product second("second", 543718);
    Product third("third", 123847);
    Weight_product fourth("fourth", 437819, 12, 3);
    Weight_product fifth("fifth", 548198, 8, 5);

    display(first);
    display(fourth);

    products_array.push_back(first);
    products_array.push_back(second);
    products_array.push_back(third);


    for(const Product& n:products_array){  //Displaying each element of each object from products_array
        cout<<n.name_<<' ';
        cout<<n.code_<<' ';
        cout<<n.price_<<endl;
    }

}
