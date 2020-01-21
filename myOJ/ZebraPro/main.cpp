//unsolved
#include <iostream>
#include <cstdio>
using namespace std;

enum House{red,blue,green,white,yellow};
enum Job{worker,dip,pho,doc,vio};
enum Pet{dog,fox,hor,zebra,snail};
enum Drinks{tea,milk,juice,cof,water};

struct People{
    House house;
    Job job;
    Pet pet;
    Drinks drinks;
    int houseNum; //从左向右依次为12345
}people[5];//0-4依次表示英国，西班牙，日本，意大利，挪威

int main() {

}