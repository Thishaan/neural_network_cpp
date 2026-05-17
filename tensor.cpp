#include "tensor.hpp"


Tensor::Tensor() {
    // Constructor implementation (if needed)

    this->tensor_shape = new _shape{0, 0}; // Initialize shape to zero
    this->data =  {};
    this->dims  =  {};
}


std::shared_ptr<Tensor> Tensor::operator *(const std::shared_ptr<Tensor>& other) {
    // Implement tensor multiplication logic here

    Tensor t{};
    size_t my_rows = rows();
    size_t my_cols = cols();

    size_t other_rows = other->rows();
    size_t other_cols = other->cols();
    std::vector<std::vector<float>> res(2);
    std::vector <std::vector<float>> other_data = other->get_data();


    if(my_cols != other_rows){
        throw std::invalid_argument("rows and columns don't match ");
    }

    // case of 2d x 1d
    if(my_cols  == 2 && my_rows == 1 ){
      for(size_t i = 0;  i < 2; ++i){
        for (size_t j = 0; j < 2; ++j){
            res[i].push_back(data[i][j]*other_data[0][0] + data[i][j]*other_data[0][1]);
        }
        }
    }
    // case of 1d x 1d

    else if( my_cols == 1 && my_rows == 1){
        res.push_back({data[0][0]* other_data[0][0]});

        res.resize(1);  // resize to a vector of size 1
    }

    // case of 2d x 2d;
    else{
     for(size_t i = 0;  i < 2; ++i){
         for (size_t j = 0; j < 2; ++j){
            res[i].push_back(data[i][j]*other_data[0][0] + data[i][j+1]*other_data[0][1]);
             res[i].push_back(data[i+1][j]*other_data[1][0] + data[i+1][j+1]*other_data[1][1]);
        }
        }

    }

    t.set_data(res);

    // This is a placeholder implementation and should be replaced with actual logic
    return std::make_shared<Tensor>(t);
}


 void Tensor::set_data(std::vector<std::vector<float>> data_to_set){
        data =  data_to_set;
 }


std::shared_ptr<Tensor> Tensor::operator +(const std::shared_ptr<Tensor>& other)  {
    // Implement tensor addition logic here
    Tensor t{};
    size_t my_rows = rows();
    size_t my_cols = cols();

    size_t other_rows = other->rows();
    size_t other_cols = other->cols();


    std::vector<std::vector<float>> other_data =  other->get_data();

    if(my_cols != other_cols  && my_rows != other_rows ){
        throw std::invalid_argument("rows and columns don't match ");
    }

    std::vector<std::vector<float>> res(my_rows);


    for( size_t i =0 ; i < my_rows; ++i){
        for(size_t j =0; j < my_cols; ++j)
            res[i].push_back(other_data[i][j]  + data[i][j]);        
    }


    t.set_data(res);
    return std::make_shared<Tensor>(t);
}


