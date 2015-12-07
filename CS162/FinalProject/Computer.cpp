#include "Computer.hpp"

Computer::Computer(){
}

std::string Computer::getHdd(){
	return this->hdd;
}


Laptop::Laptop(){
	this->greeting = "You've accessed a laptop connected to the network. Let's see what we can find!";
}

void Laptop::setNodeOne(Machine *m){
	this->nodeOne = m;
}
void Laptop::setNodeTwo(Machine *m){
	this->nodeTwo = m;
}
void Laptop::setNodeThree(Machine *m){
	this->nodeThree = m;
}
void Laptop::setNodeFour(Machine *m){
	this->nodeFour = m;
}

Desktop::Desktop(){

}

void Desktop::setNodeOne(Machine *m){
	this->nodeOne = m;
}
void Desktop::setNodeTwo(Machine *m){
	this->nodeTwo = m;
}
void Desktop::setNodeThree(Machine *m){
	this->nodeThree = m;
}
void Desktop::setNodeFour(Machine *m){
	this->nodeFour = m;
}

Work::Work(){

}

void Work::setNodeOne(Machine *m){
	this->nodeOne = m;
}
void Work::setNodeTwo(Machine *m){
	this->nodeTwo = m;
}
void Work::setNodeThree(Machine *m){
	this->nodeThree = m;
}
void Work::setNodeFour(Machine *m){
	this->nodeFour = m;
}
