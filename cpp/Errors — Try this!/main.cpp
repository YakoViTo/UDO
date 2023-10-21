#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

void inline error(const std::string s) {
    throw std::runtime_error(s);
}

void inline error(const std::string s, const std::string s2) {
    error(s + s2);
}

int area(int length, int width) {
    if (length<=0 || width <=0) 
        return -1;          
    return length*width; 
}

int framed_area(int x, int y)  {  // calculate area within frame
    constexpr int frameWidth {2};         
    if (x - frameWidth <= 0 || y - frameWidth <= 0) {
        std::cerr << "non-positive area() argument called by framed_area()" << std::endl;  
        return -1;
    }
    return area(x-frameWidth,y-frameWidth); 
}

int f(int x, int y, int z) {         
    int area1 = area(x,y);
    
    if (area1<=0) 
        std::cerr << "non-positive area" << std::endl;
    else
        std::cout << "area1: " << area1 << std::endl;
    
    int area2 = framed_area(1,z);     
    
    if (area2 > 0)
        std::cout << "area2: " << area2 << std::endl;
    
    int area3 = framed_area(y,z);  
    
    if (area3 > 0)
        std::cout << "area3: " << area3 << std::endl;
    
    double ratio = double(area1)/area3;
    
    if (ratio > 0)
        std::cout << "ratio: " << ratio << std::endl;
    return 1;
}  

int main() {
    //#1 Try to compile these examples
    /*int s1 = area(7;
    int s2 = area(7)
    Int s3 = area(7);
    int s4 = area('7);*/
    
    //#2 The same
    /*int x0 = arena(7);
    int x1 = area(7);
    int x2 = area("seven", 2);
    int x3 = area(7, 8, 6);
    int x4[] = {32, 25, 14};
    int x5 = area(x4);*/
    
    //#3 - Test this program
    //f(65, 21, 1);
    
    //#4 - Run a small program that uses error() without catching any exceptions
    /*try {
        error("hello");
        return 0;
    }
    catch (...) {
        std::cerr << "Unknown exception!\n";
        system("PAUSE");
        return 2;
    }*/
    
    //#5 - Get this program to run. Try to break the program
    /*std::vector<double> temps;
    
    for(double temp; std::cin>>temp;)
        temps.push_back(temp);
    
    double sum {0};
    double high_temp {0};
    double low_temp {0};
    
    for(int x : temps) {
        if (x > high_temp)
            high_temp = x;
        if (x < low_temp)
            low_temp = x;
        sum += x;
    }
    
    std::cout << "High temperature: " << high_temp << "\n";
    std::cout << "Low temperature: " << low_temp << "\n";
    std::cout << "Average temperature: " << sum / temps.size() << "\n";*/
    
    //#6 - Check info to pick good values for the min_temp
    /*double sum {0};
    double high_temp {-1000};
    double low_temp {1000};
    int noOfTemps {0};
    
    for(double temp; std::cin>>temp; ) {
        ++noOfTemps;
        sum += temp;
        if (temp > high_temp)
            high_temp = temp;
        if (temp < low_temp)
            low_temp = temp;
    }
    std::cout << "High temperature: " << high_temp << "\n";
    std::cout << "Low temperature: " << low_temp << "\n";
    std::cout << "Average temperature: " << sum/noOfTemps;*/
    
    //Drill - 25 Code Fragments
    
    try {
        //std::cout << "Success!\n";
        //std::cout << "Success!\n";
        //std::cout << "Success" << "!\n";
        //std::cout << success << '\n';
        //std::string res = "7"; std::vector<int> v(10); v[5] = std::stoi(res); std::cout << "Success!\n";
        //std::vector<int> v(10); v[5] = 7; if(v[5]==7) std::cout << "Success!\n";
        //bool cond {true};if(cond) std::cout << "Success!\n"; else std::cout << "Fail!\n";
        //bool c {false}; if(!c) std::cout << "Success!\n"; else std::cout << "Fail!\n";
        //std::string s {"ape"}; bool c {"fool" > s}; if(c) std::cout << "Success!\n";
        //std::string s = "ape"; if(s!="fool") std::cout << "Success!\n";
        //std::string s = "ape"; if(s!="fool") std::cout<<"Success!\n";
        //std::string s = "ape"; if(s+"fool" == "apefool") std::cout << "Success!\n";
        //std::vector<char> v(5); for(int i = 0; i < v.size(); ++i); std::cout << "Success!\n";
        //std::vector<char> v(5); for(int i = 0; i <= v.size(); ++i); std::cout << "Success!\n";
        //std::string s = "Success!\n"; for(int i = 0, sLength = s.size(); i < sLength; ++i) std::cout << s[i];
        //if(true) std::cout << "Success!\n"; else std::cout<<"Fail!\n";
        //int x = 2000; char c = x; if(x==2000) std::cout << "Success!\n";
        //std::string s = "Success!\n"; for(int i = 0; i < 10; ++i) std::cout << s[i];
        //std::vector<char> v(5); for(int i = 0, vSize = v.size(); i<= vSize; ++i); std::cout << "Success!\n";
        //int i = 0; int j = 9; while(i<10) ++i; if(j<i) std::cout << "Success!\n";
        //double x = 2; double d = 5/x; if(d==2+0.5) std::cout << "Success!\n";
        //std::string s = "Success!\n"; for(int i = 0; i < 10; ++i) std::cout << s[i];
        //int i = 0; int j = 0; while(j<10) ++j; if(j>i) std::cout << "Success!\n";
        //int x = 4; double d = 5/(x-2); if(d=2*x+0.5) std::cout << "Success!\n";
        //std::cout << "Success!\n";
        return 0;
    }
    catch (std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "Oops: unknown exception!\n";
        return 2;
    }
    return 0;
}
