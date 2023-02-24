#ifndef SINGLETON_H
#define SINGLETON_H
/**
 *@brief The SingleTon class
 *@brief 单例模式
 */
template <typename T>
class SingleTon
{
private:
    inline SingleTon(){}
    SingleTon(const SingleTon&)=delete;
    SingleTon(SingleTon&&)=delete;

    T instance;
public:
    static T* getInstance(){
        static SingleTon* instance=nullptr;
        if(instance==nullptr)instance=new SingleTon;
        return &(instance->instance);
    }

    static T& getReference(){
        return *getInstance();
    }
};
#endif // SINGLETON_H
