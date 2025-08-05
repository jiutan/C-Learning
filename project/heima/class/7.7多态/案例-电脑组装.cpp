#include<iostream>
#include<string>

/*
    电脑组成：CPU（计算），显卡（显示），内存条（存储）
    将每个零件 封装成 抽象的基类，提供不同的厂商 生成不同的 零件
    创建 电脑类：提供 让 电脑工作的函数，并且调用 每个零件工作的接口
    目的：组装 三台不同的 电脑 进行工作
*/

// CPU 抽象类
class CPU
{
public:
    CPU(/* args */);
    virtual ~CPU() = 0;             // 纯虚析构

    // 抽象 计算 函数
    virtual void Calculate() = 0;
};
CPU::CPU(/* args */)
{
}

CPU::~CPU()
{
    
}

// 显卡 抽象类
class GPU
{
public:
    GPU(/* args */);
    virtual ~GPU() = 0;

    // 虚函数：显示 函数
    virtual void Display() = 0;
};
GPU::GPU(/* args */)
{
}
GPU::~GPU()
{
}

// 内存条 抽象类
class RAM
{
public:
    RAM(/* args */);
    virtual ~RAM() = 0;

    // 存储虚函数
    virtual void Memory() = 0;
};
RAM::RAM(/* args */)
{
}

RAM::~RAM()
{
}

// 电脑类   （具体类）
class Computer
{
private:
    /* 由 三个零件 组成： 创建 三个 类的对象 */
    // 抽象类 不能 实例化，但是 可以定义一个 指向该抽象类的 指针    
    /* 类似 准备 一个 插槽 用于 之后 插入 CPU等 */    
    CPU* m_cpu;                   // 创建 CPU类 的 指针 成员，用于 接收子类对象（还没有指向）
    GPU* m_gpu;                   // 创建 GPU类 的 指针 成员
    RAM* m_ram;                   // 创建 RAM类 的 指针 成员

public:
    Computer(CPU *cpu,GPU *gpu,RAM *ram);       // 构造函数中 传入 三个零件 的 指针
    ~Computer();

    // 提供工作 的 函数，调用每个 零件(子类)工作 的 接口
    void Work(){
        // 让 零件 工作起来，调用 接口
        m_cpu -> Calculate();
        m_gpu -> Display();
        m_ram -> Memory();

    }

};
Computer::Computer(CPU *cpu,GPU *gpu,RAM *ram)
{   
    // 对 传入的 三个零件的 指针 进行 接收
    m_cpu = cpu;
    m_gpu = gpu;
    m_ram = ram;

}
Computer::~Computer()
{
    if(m_cpu != NULL){
        delete m_cpu;
        m_cpu = NULL;
    }
    if(m_gpu != NULL){
        delete m_gpu;
        m_gpu = NULL;
    }
    if(m_ram != NULL){
        delete m_ram;
        m_ram = NULL;
    }
}

// 具体 厂商类
class IntelCpu:public CPU
{
private:
    /* data */
public:
     // 子类要 复现 父类的 纯虚函数
    virtual void Calculate(){
        std::cout << "这是 Intel的CPU 开始计算" << std::endl;
    }
};
class IntelGpu:public GPU
{
private:
    /* data */
public:
    virtual void Display(){
        std::cout << "这是 Intel的GPU 开始显示" << std::endl;
    }
};
class IntelRam:public RAM
{
private:
    /* data */
public:
    virtual void Memory(){
        std::cout << "这是 Intel的RAM 开始存储" << std::endl;
    }
};

class AMDCpu:public CPU
{
private:
    /* data */
public:
     // 子类要 复现 父类的 纯虚函数
    virtual void Calculate(){
        std::cout << "这是 AMD的CPU 开始计算" << std::endl;
    }
};
class AMDGpu:public GPU
{
private:
    /* data */
public:
    virtual void Display(){
        std::cout << "这是 AMD的GPU 开始显示" << std::endl;
    }
};
class AMDRam:public RAM
{
private:
    /* data */
public:
    virtual void Memory(){
        std::cout << "这是 AMD的RAM 开始存储" << std::endl;
    }
};


// 开始 测试
void test01(){

    // 第一台 电脑 的 零件(使用 指针 去 指向)
    CPU* intelcpu = new IntelCpu;              // 父类 指针 指向 子类 对象
    GPU* intelgpu = new AMDGpu;
    RAM* intelram = new IntelRam;

    // 创建第一台电脑
    Computer* computer1 = new Computer(intelcpu,intelgpu,intelram);
    computer1 -> Work();        // 工作
    delete computer1;           // 工作完，释放内存

    std::cout << "--------------------------------------------" << std::endl;

    // 创建 第二台 电脑
    Computer* computer2 = new Computer(new AMDCpu , new IntelGpu , new AMDRam);   // 直接在 实例化 实参 中 new 一个类
    computer2->Work();
    delete computer2;

}

int main(){

    test01();

    return 0;
}
