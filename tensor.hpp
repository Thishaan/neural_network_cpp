#include <vector>
#include <stdexcept>
#include <memory>


typedef struct shape{
    size_t rows;
    size_t cols;
} _shape;

class Tensor {
private:
    std::vector<int> dims;
    std::vector<std::vector<float> > data;
    _shape * tensor_shape; 
    bool gradient_required;


public:
    Tensor();
    Tensor(const std::vector<int>& dims);
    //~Tensor();

    std::shared_ptr<Tensor> operator*(const std::shared_ptr<Tensor>& other);
    std::shared_ptr<Tensor> operator+(const std::shared_ptr<Tensor>& other);

    inline const std::vector<int>& get_dims() const {
        return dims;
    }

    inline const std::vector<std::vector<float>>& get_data() const {
        return data;
    }
    
    size_t rows() const {
        return tensor_shape->rows;
    }

    size_t cols() const {
        return tensor_shape->cols;
    }



    void set_data(std::vector<std::vector<float>> data_to_set);

    void zero_gradient();

 
};