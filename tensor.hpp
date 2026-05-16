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
    std::vector<float> data;
    _shape * tensor_shape; 

public:
    Tensor() = default;
    Tensor(const std::vector<int>& dims);
    
    bool validate_dims(const std::vector<int>& dims) const;

    std::shared_ptr<Tensor> operator*(const std::shared_ptr<Tensor>& other);
    std::shared_ptr<Tensor> operator+(const std::shared_ptr<Tensor>& other);

    inline const std::vector<int>& get_dims() const {
        return dims;
    }

    inline const std::vector<float>& get_data() const {
        return data;
    }
    
    size_t rows() const {
        return tensor_shape->rows;
    }

    size_t cols() const {
        return tensor_shape->cols;
    }
};