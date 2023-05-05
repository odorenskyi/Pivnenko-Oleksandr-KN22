#include <string>
#include <exception>

class ClassLab12_Pivnenko{
    public:
        float calc_volume(){
            return length_edge * length_edge * length_edge;
        }

        float rtn_edge(){
            return length_edge;
        }

        ClassLab12_Pivnenko(float edge);

    private:
        float length_edge = 0;

};

ClassLab12_Pivnenko::ClassLab12_Pivnenko(float edge){
    if(edge < static_cast<float>(0))
        throw std::invalid_argument("Length will be > 0");
    length_edge = edge;
}



