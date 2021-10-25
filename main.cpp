#include <iostream>
#include <map>
#include <any>

class ObjectBuilder{
protected:
    mutable std::map<std::string,std::any> data;
public:
    ObjectBuilder & setData(std::string a,std::any obj){
        data[a]=obj;
        return *this;
    }
    ObjectBuilder & build(){
        return *this;
    }
    template<class T>
    T getElement(std::string name)const{
        if(data.find(name)==data.end())
            return T();
        return std::any_cast<T>(data[name]);
    }
    std::any getRawElementData(std::string name)const{
        return data[name];
    }
    const int size()const{
        return data.size();
    }
};

int main(){
    ObjectBuilder a=ObjectBuilder()
                        .setData("test",15)
                        .setData("str","string");

    std::cout<<a.getElement<const char*>("str");

    return 0;
}
